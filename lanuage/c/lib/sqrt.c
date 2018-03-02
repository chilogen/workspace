#include<stdio.h>
#include<math.h>
int main()
{
	float q_sqrt(float);
	float a;
	for(int i=0;i<2;i++)
	{
		scanf("%f",&a);
		printf("\n%f\n%f\n",q_sqrt(a),sqrt(a));
	}
	return 0;
}
float q_sqrt(float a)
{
	long i;
	float x2,y;
	const float thr=1.5F;
	x2=a*0.5F;
	y=a;
	i=*(long *)&y;
	i=0x5f3759df-(i>>1);
	y=*(float*)&i;
	y=y*(thr-(x2*y*y));
	y=y*(thr-(x2*y*y));
	return y;
}
