#软件开发综合实践作业

data struct

4byte		filetype flag						char	0xca 0xff 0xee 0xad
8*256byte	character freqency					long
others		zip data							char


usage:
#include "Zip.h"
	zip a;
	a.open(filename);
	a.zip()	or z.unzip();
	a.write(filename);

open(filename):
	if(checkfiletype(file)==zipped file)	canunzip=true,getattachinfo();
	if(checkfiletype(file)==normal file)	canzip=true;

zip()
	if(canzip)	
	{
		read data and build huffman frequency tree
		read data and write zipped data in tmp file
	}
unzip()
	if(canunzip)	read data,decode and write in tmp file

write()
	change tmpfile's name
