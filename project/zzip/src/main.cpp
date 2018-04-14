#include <bits/stdc++.h>
#include "Zip.h"
using namespace zip;
int main(int argc,char **argv)
{
	hzip a;
	if(argc==1||argc>4||(argv[1][0]!='e'&&argv[1][0]!='c'))
	{
		error(5);
	}
	std::string infile=argv[2],outfile=argv[3];
	if(argv[1][0]=='c')
	{
		if(!a.open(infile,NORFILE))		return 0;
		if(!a.zzip())					return 0;
		a.write(outfile);
	}
	else
	{
		if(!a.open(infile,ZIPFILE))		return 0;
		if(!a.unzip())					return 0;
		a.write(outfile);
	}
	return 0;
}