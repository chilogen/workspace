#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
stack<char> syms;
stack<LL> ints;
const int mod = 1e9+7;
const int MAXN = 1e5+7 + 10;
int size;
char strs[MAXN];
LL temp[MAXN];
int tsize;
int trees;

int main()
{
    // freopen("in.txt", "r", stdin);
    char ch;
    while((ch = getchar()) != EOF)
    {
        if(ch == ' ' || ch == '\n' || ch == EOF)
            continue;
        strs[size++] = ch;
    }
    for(int i = size - 1; i >= 0; i--)
    {
        if(strs[i] == '<')
        {
            strs[i] = '(';
            continue;
        }
        if(strs[i] == 'S')
        {
            // i --;
            if(strs[i-1] == '>' && strs[i-2] == '>')
            {
                strs[i-1] = ' ';
                strs[i-2] = '*';
                i -= 2;
                continue;
            }
        }
        if(isdigit(strs[i]))
        {
            while(isdigit(strs[--i]));
            if(strs[i] == '>' && strs[i-1] == '>')
            {
                strs[i] = ' ';
                strs[i-1] = '*';
                i --;
                continue;
            }
            i ++;
            continue;
        }
        if(strs[i] == '>')
        {
            strs[i] = ')';
        }
    }
    for(int i = 0; i < size; i++)
    {
        if(strs[i] != ' ' && strs[i] != '\n' && strs[i] != EOF)
            strs[trees++] = strs[i];
    }
    for(int i = 0; i < trees; i++)
    {
        if(strs[i] == 'S')
        {
            syms.push(strs[i+1]);
            i++;
        }
        else if(isdigit(strs[i]))
        {
            int tmp = 0;
            sscanf(strs+i, "%d", &tmp);
            ints.push(tmp);
            while(isdigit(strs[++i]));
            i --;
        }
        else if(strs[i] == ')')
        {
            if(syms.top() != '(')
            {
                LL tmp = 0;
                tsize = 0;
                temp[tsize++] = ints.top();
                ints.pop();
                temp[tsize++] = ints.top();
                ints.pop();
                syms.pop();
                while(syms.top() == '*')
                {
                    syms.pop();
                    temp[tsize++] = ints.top();
                    ints.pop();
                }
                for(int i = tsize-1; i > 0; i--)
                    if(temp[i-1] <= 32)
                        temp[i-1] = temp[i] / (1ll<<temp[i-1]);
                    else
                        temp[i-1] = 0;
                ints.push(temp[0]);
            }
            // syms.pop();
            syms.pop();
            LL tmp = ints.top();
            ints.pop();
            tmp = ((tmp%mod)*(tmp%mod))%mod;
            ints.push(tmp);
        }
        else if(strs[i] == '*')
        {
            syms.push(strs[i]);
        }
    }
    while(!syms.empty())
    {
        LL tmp = 0;
        tsize = 0;
        temp[tsize++] = ints.top();
        ints.pop();
        temp[tsize++] = ints.top();
        ints.pop();
        syms.pop();
        while(!syms.empty() && syms.top() == '*')
        {
            syms.pop();
            temp[tsize++] = ints.top();
            ints.pop();
        }
        for(int i = tsize-1; i > 0; i--)
            if(temp[i-1] <= 32)
                temp[i-1] = temp[i] / (1ll<<temp[i-1]);
            else
                temp[i-1] = 0;
        ints.push(temp[0]);
    }
    printf("%lld\n", ints.top());
    return 0;
}