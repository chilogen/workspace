#include<iostream>
#include<stdio.h>
#include<cstring>

using namespace std;

int main()
{
    char c[100005];
    int a[26];
    int b[26]= {0};
    int num=0;
    scanf("%s",c);
    for(int i=0; i<26; i++)
    {
        scanf("%d",&a[i]);
        num+=a[i];
    }
    int len=strlen(c);
    for(int i=0; i<num; i++)
        b[c[i]-'a']++;
    bool flag=1;
    for(int i=1; i<=len-num;i++)
    {
        b[c[i-1]-'a']--;
        b[c[i+num-1]-'a']++;
        flag=1;
        for(int i=0; i<26; i++)
        {
            if(a[i]!=b[i])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            cout<<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}