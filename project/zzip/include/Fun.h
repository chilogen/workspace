#ifndef FUN_H
#define FUN_H

#include "Zip.h"
using namespace zip;

hzip::hzip()
{
	Tmpfilename="tmp.zzip";
	memset(freq,0,sizeof(freq));
	canzip=canunzip=false;
	Validnum=0;
	LL i;
	for(i=0;i<600;i++)	tree[i].rson=tree[i].lson=-1,tree[i].ind=i;
}
hzip::~hzip()
{
}

bool hzip::zzip()
{
	int cnt;
	unsigned char c;
	output bout;
	LL i,j,k;
	fout=fopen(Tmpfilename.c_str(),"wb");
	for(i=0;i<4;i++)	fprintf(fout,"%c",fileind[i]);
	fwrite(freq,sizeof(LL),256,fout);
	fwrite(&Validnum,sizeof(LL),1,fout);

	fseek(F,0,SEEK_SET);

	std::string s;
	while(fscanf(F,"%c",&c)!=EOF)
	{
		s=encode[(int)c];
		bout<<s;
	}
	return true;
}

bool hzip::unzip()
{
	unsigned char c;
	int	res;
	std::string s;
	LL i,j,k=0,x=tp;
	fout=fopen(Tmpfilename.c_str(),"w");
	if(fout==NULL)
	{
		error(1);
		return false;
	}

	fseek(F,2060,SEEK_SET);
	while(k<Validnum)
	{
		if(fscanf(F,"%c",&c)==EOF)	break;
		for(i=0;i<8;i++)
		{
			res=c&(1<<(7-i));
			if(res)	x=tree[x].rson;
			else 	x=tree[x].lson;
			if(tree[x].lson==-1)
			{
				fprintf(fout,"%c",(char)tree[x].ind);
				x=tp;
				k++;
				if(k==Validnum)	break;
			}
		}
	}
	return true;
}

bool hzip::open(std::string filename,int opentype)
{
	F=fopen(filename.c_str(),"rb");
	LL i,j,k;
	if(!F)
	{
		error(1);
		return false;
	}
	if(opentype==ZIPFILE)
	{	
		char c[4];
		for(i=0;i<4;i++)	fscanf(F,"%c",&c[i]);
		if(strcmp(c,fileind))	
		{
			error(4);
			return false;
		}
		//if(!isfile(ZIPFILE))	error(4);
		fread(freq,sizeof(LL),256,F);
		fread(&Validnum,sizeof(LL),1,F);
		canunzip=true;
		buildtree();
		return true;
	}
	else if(opentype==NORFILE)
	{
		unsigned char c;
		//if(!isfile(NORFILE))	error(4);
		fseek(F,0,SEEK_SET);
		while(fscanf(F,"%c",&c)!=EOF)	
		{
			k=(unsigned int)c;
			freq[k]++;
			Validnum++;
		}
		buildtree();
		canzip=true;
		return true;
	}
	else
	{
		error(3);
		return false;
	}
}

void hzip::buildtree()
{
	LL i;
	huffmannode t1,t2;
	std::priority_queue<huffmannode,std::vector<huffmannode>,cmp> q ;
	for(i=0;i<256;i++)	tree[i].val=freq[i];
	tp=256;
	for(i=0;i<256;i++)	q.push(tree[i]);
	while(!q.empty())
	{
		t1=q.top(),q.pop();
		if(q.empty())	break;
		t2=q.top(),q.pop();
		tree[tp].val=t1.val+t2.val;
		tree[tp].lson=t1.ind;
		tree[tp].rson=t2.ind;
		q.push(tree[tp++]);
	}
	tp--;

	std::string s="";
	dfs(s,tp);
}

void hzip::dfs(std::string &code,LL x)
{
	if(tree[x].lson==-1)
	{
		encode[x]=code;
		return;
	}
	code.push_back('1');
	dfs(code,tree[x].rson);
	code.pop_back();

	code.push_back('0');
	dfs(code,tree[x].lson);
	code.pop_back();
}

bool hzip::write(std::string filename)
{
	std::string exitcmd="mv "+Tmpfilename+" "+filename;
	system(exitcmd.c_str());
	fclose(F);
	return true;
}

#endif