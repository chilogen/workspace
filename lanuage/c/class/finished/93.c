#include<stdio.h>
#include<math.h>
int main()
{
	double n;
	int sn,lop,loop;
	for(lop=2;lop<=100;lop++)
	{
		sn=(int)sqrt((double)lop);
		for(loop=2;loop<=sn;loop++)
		{
			if(lop%loop==0) break;
		}
		if(loop==sn+1) printf("%d,",lop);
	}
	return 0;
}
