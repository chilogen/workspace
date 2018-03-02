#include<stdio.h>
#include<math.h>
float q_sqrt(float number) 
{ 
    long i; 
    float x2,y; 
    const float threehalfs=1.5F ;
    x2=number*0.5F; 
    y=number; 
    i=*(long*)&y;
    i=0x5f3759df-(i>>1);
//    i=0x5f375a86-(i>>1);
    y=*(float*)&i; 
    y=y*(threehalfs-(x2*y*y));
//    y=y*(threehalfs-(x*y*y));
    return 1/y;
}
int main()
{
	printf("%f\n%f",sqrt(3),q_sqrt(3));
	return 0;
}
