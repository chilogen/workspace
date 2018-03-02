#include<stdio.h>
#include<malloc.h>
#include<string.h>
typedef struct
{
    char name[20];
    int gendar;
    char birthday[9];
    float height;
    int course_c;
    int course_calculus;
}student;
int n;
student *p,**s;
int main()
{
    int c_average,c_max,c_min,calculus_max,calculus_average,calculus_min;
    float sum_c=0,sum_calculus=0;
    void sortc();
    void sortcalculus();
    scanf("%d",&n);
    p=(student *)malloc(sizeof(student)*n);
    s=(student **)malloc(sizeof(student)*n);
    for(int lop=0;lop<n;lop++)
    {
        scanf("%s%d%s%f%d%d",p[lop].name,&p[lop].gendar,p[lop].birthday, \
                             &p[lop].height,&p[lop].course_c,&p[lop].course_calculus);
        p[lop].birthday[8]='\0';
        s[lop]=&p[lop];
    }
    for(int lop=0;lop<n;lop++)
    {
        sum_c+=p[lop].course_c;
        sum_calculus+=p[lop].course_calculus;
    }
    c_average=sum_c/(float)n;
    calculus_average=sum_calculus/(float)n;
    sortc();
    c_max=s[0]->course_c;
    c_min=s[n-1]->course_c;
    printf("C_average:%d\nC_max:%d\n",c_average,c_max);
    for(int point=0;s[point]->course_c==c_max;point++)
    {
        printf("%s %d %s %.2f %d %d\n",s[point]->name,s[point]->gendar,s[point]->birthday \
                                    ,s[point]->height,s[point]->course_c,s[point]->course_calculus);
    }
    printf("C_min:%d\n",c_min);
    for(int lop=0;lop<n;lop++)
        s[lop]=&p[lop];//为了应付SB matu
    sortcalculus();
    calculus_max=s[0]->course_calculus;
    calculus_min=s[n-1]->course_calculus;
    printf("Calculus_average:%d\nCalculus_max:%d\n",calculus_average,calculus_max);
    for(int point=0;s[point]->course_calculus==calculus_max;point++)
    {
        printf("%s %d %s %.2f %d %d\n",s[point]->name,s[point]->gendar,s[point]->birthday \
                                    ,s[point]->height,s[point]->course_c,s[point]->course_calculus);
    }
    printf("Calculus_min:%d\n",calculus_min);
    return 0;
}
void sortc()
{
    student *t;
    for(int lop=0;lop<n;lop++)
        for(int loop=lop+1;loop<n;loop++)
        {
            if(s[lop]->course_c<s[loop]->course_c)
            {
                t=s[lop];
                s[lop]=s[loop];
                s[loop]=t;
            }
        }
}
void sortcalculus()
{
    student *t;
    for(int lop=0;lop<n;lop++)
        for(int loop=lop;loop<n;loop++)
        {
            if(s[lop]->course_calculus<s[loop]->course_calculus)
            {
                t=s[lop];
                s[lop]=s[loop];
                s[loop]=t;
            }
        }
}