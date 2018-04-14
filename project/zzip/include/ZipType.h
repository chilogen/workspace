#ifndef ZIPTYPE_H
#define ZIPTYPE_H

namespace zip
{
	#define ZIPFILE	1
	#define NORFILE 2

	char fileind[]={(char)0xca,(char)0xff,(char)0xee,(char)0xad};
	FILE *F,*fout;
	

	class output
	{
	public:
		void operator<<(std::string s)
		{
			sbuff+=s;
			if(sbuff.length()>8)
			{
				unsigned char c=0;
				int i;
				for(i=0;i<8;i++)
					c=(unsigned char)(((int)c<<1)+(int)(sbuff[i]-'0'));
				fprintf(fout,"%c",c);
				sbuff=sbuff.substr(8,sbuff.length()-8);
			}
		}
		~output()
		{
			int i;
			unsigned char c=0;
			for(i=0;i<sbuff.length();i++)
				c=(unsigned char)(((int)c<<1)+(int)(sbuff[i]-'0'));

			for(;i<8;i++)
				c=(unsigned char)((int)c<<1);
			fprintf(fout,"%c",c);
		}
	private:
		std::string sbuff;
	};

	class huffmannode
	{
	public:
		huffmannode(){};
		bool operator <<(huffmannode a){return val<a.val;}
		int ind;
		LL val;
		LL lson,rson;
	};

	struct cmp
	{
		bool operator()(huffmannode a,huffmannode b)
		{
			return a.val>b.val;
		}
	};

	class hzip
	{
	public:
		hzip();
		~hzip();
		bool open(std::string filename,int opentype);
		bool zzip();
		bool unzip();
		bool write(std::string filename);
		void dfs(std::string &code,LL x);
	private:
		LL freq[300],tp;
		LL Validnum;
		huffmannode tree[600];
		bool canzip,canunzip;
		std::string Tmpfilename;
		bool isfile(int filetype);
		void buildtree();
		void getcode(std::string &code,int ind);
		std::map<LL,std::string> encode;
	};
}
#endif