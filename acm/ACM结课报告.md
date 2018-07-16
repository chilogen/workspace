## ![Screenshot_20180613_104159](/home/a/Pictures/Screenshot_20180613_104159.png)





> codeforces,atcoder,qsoj帐号密码一样
>
> 帐号:quantu_zo
>
> 密码:linshimima1
>
> 校赛成绩:三等奖

# AC自动机

> 概述:
>
> 自动机是计算理论中的一个概念,一个确定有限状态自动机是由:
>
> * 一个非空有限状态集Q
> * 一个字母表$\sum$
> * 一个转移函数$\delta:Q\times\sum->Q$
> * 一个开始状态$s\in Q$
> * 一个接受状态集合$F\in Q$
>
> 所构成的5元组
>
> ac自动机是指 Aho-Corasick字符串搜索算法,有Alfred V.Aho 和Margaret J.Corasick发明.常用的字符串匹配算法还有KMP.ac自动机与kmp最大不同是可以同时进行多模匹配.

#### 算法详述

* ac自动机和KMP一样,都是需要通过已匹配过的信息加快当前一步的匹配,kmp实在一个线性的字符串上构建转移指针,而因为ac自动机要实现多模板匹配的任务,所以需要在一棵前缀树上构建转移指针.

* fail指针

  首先,需要一个失配指针last[j],当j节点失配后,需要跳到last[j]这一节点继续匹配.,last[j]这一节点代表的字符串是j节点代表字符串的一个最长前缀,比如在前缀树中有abba,abbab,那么abbabc的fail指针就应该指向abbab

* last指针
  当找到一个字符串时,代表它的所有前缀也被找到了,比如找到了abba,也相当于找到了ab.ab是abba的一个前缀,当然可以顺着fail指针(因为fail指针也指向前缀)判断节点是否是单词节点从而找到所有前缀单词.但fail指针指向的并不一定是单词节点,为了加速这一过程,需要另一个指针last[j]指向节点j最长的前缀单词

* 接下来的问题就是计算fail和last指针,其实是一个递推的思想

  * fail

    假设有两个字符串s1:abcdf,s2:fabcde,根据fail的含义,s2中d节点的fail指针显然应该连到s1中d节点.递推的思想在这里就发挥了作用.**在连d之前,c的fail指针已经连好了,所以可以顺着c的fail指针,找到后面接有d节点的c节点,从而找到s1的d节点.**

    因为递推关系要求要算第j位的fail指针,那么j之前的都要先算好,体现在前缀树中就是上层节点先算,符合bfs特性,所以使用bfs一层一层递推算fail指针

  * last

    last的递推思想比fail更好理解一些.算好fail后,每个节点的失配最长前缀就可以顺着fail指针找.如果节点j指向的fail节点也是一个单词节点,那last[j]=fail[j].如果该fail节点不是单词节点,那就等于该fail节点指向的fail节点,即last[j]=last[fail[j]]

* 查找

  将需要匹配的串在前缀树上顺着字母边走,一旦失配,这跳转到fail指针,一旦遇到单词节点,则递归输出所有单词

```c
//模板代码
#include <bits/stdc++.h>
using namespace std;
#define MXnode 510000
#define sigma 26
#define reset(a,b)	memset(a,b,sizeof(a))
char s[1000010],pattern[60];
int t,n,ans;

int ch[MXnode][sigma];
int fail[MXnode],last[MXnode],val[MXnode];
int sz;
queue<int>q;

void init(){
	sz=0;
	reset(ch[0],0);
	reset(fail,0);
	reset(last,0);reset(s,0);
	reset(val,0);
	ans=0;
}

//第一步先正常的构造前缀树(字典树)
void insert(char *s){
	int i,j,k,len=strlen(s);
	for(i=0,k=0;i<len;i++){
		j=s[i]-'a';
		if(!ch[k][j]){
			ch[k][j]=++sz;
			reset(ch[sz],0);
		}
		k=ch[k][j];
	}
	val[k]++;
}

//第二步用构造好的前缀树计算fail和last指针
void getfail(){
	int i,j,k;
    
    /*递推初始状态根节点(最顶层)fail[0]=0,第一层节点的fail指针同样指向0,
    所以直接把第一层节点压入队列中*/
	for(i=0;i<sigma;i++)	if(ch[0][i])q.push(ch[0][i]);
	
    while(!q.empty()){			//bfs递推fail指针
		k=q.front();q.pop();	//当前要计算节点的上一层节点为k	
		for(i=0;i<sigma;i++){
			if(!ch[k][i])continue;	//找到要计算的节点
			j=fail[k];			//对应上边讲的加粗部分
			q.push(ch[k][i]);	//本次计算完ch[k][j]这个节点,压入队列用于计算它的下一层节点
			while(j&&!ch[j][i])j=fail[j];	//同样对应加粗部分,一直找到根节点或是一个前缀后面接												着字符('a'+i)
			fail[ch[k][i]]=ch[j][i];
            
            //这两句就是上面讲的算last指针的递推
			if(val[fail[ch[k][i]]]!=0)last[ch[k][i]]=ch[j][i];
			else last[ch[k][i]]=last[fail[ch[k][i]]];
		}
	}
}

//尾递归统计找到的单词
void add(int x){
	while(x){
		ans+=val[x];
		x=last[x];
	}
}

//查找串s
void find(char *s){
	int i,j,k,len=strlen(s);
	for(i=0,k=0;i<len;i++){
		j=s[i]-'a';
		while(k&&!ch[k][j])k=fail[k];//若失配则顺着失配指针跳转
		k=ch[k][j];
		add(k);
	}
}
```

#### 题目

```c
/*uvalive 4670  先上一道模板题
* 给出模板串和匹配串,求那个模板串出现次数最多,并输出该模板串
* 思路:
* 单词节点不在只是以01标识是否为单词节点,而需要记录是第几个单词,非单词节点就以-1代替,每找到一个单词,就* 给它的出现次数加一,最终输出出现次数最多的单词
*/

#include <bits/stdc++.h>
using namespace std;
#define Mxnode 11000
#define Sigma 26
#define reset(a,b)	memset(a,b,sizeof(a))
#define copy(a,b)	memcpy(a,b.c_str(),sizeof(char)*b.length());
int freq[200],n;
string s[200];
char c[1000010];
class Trie{
private:
	int ch[Mxnode][Sigma],sz,fail[Mxnode],last[Mxnode];
	vector<int>v[Mxnode];
	int idx(char c){return c-'a';}
	void getfail(){
		int i,j,k;
		queue<int>q;
		for(i=0;i<Sigma;i++){
			if(ch[0][i])q.push(ch[0][i]);
		}
		while(!q.empty()){
			i=q.front();q.pop();
			k=fail[i];
			for(j=0;j<26;j++){
				if(!ch[i][j])continue;
				q.push(ch[i][j]);
				while(k&&!ch[k][j])k=fail[k];
				fail[ch[i][j]]=ch[k][j];
				last[ch[i][j]]=v[ch[k][j]].size()?ch[k][j]:last[ch[k][j]];
			}
		}
	}
	void add(int x){
		vector<int>::iterator p=v[x].begin();
		while(p!=v[x].end()){
			freq[*p]++;
			p++;
		}
	}
public:
	Trie(){
		reset(ch,0);
		reset(fail,0);
		reset(last,0);
		sz=0;
	}
	void insert(char *s,int x){
		int i,j,k,len=strlen(s);
		for(i=0,k=0;i<len;i++){
			j=idx(s[i]);
			if(!ch[k][j])ch[k][j]=++sz;
			k=ch[k][j];
		}
		v[k].push_back(x);
	}
	void find(char *s,int len){
		int i,j,k;
		getfail();
		for(i=0,k=0;i<len;i++){
			j=idx(s[i]);
			while(k&&!ch[k][j])k=fail[k];
			k=ch[k][j];
			if(v[k].size()!=0)add(k);
			if(v[last[k]].size()!=0)add(last[k]);
		}
	}
}*p;
inline void init(){
	reset(freq,0);
	p=new Trie();
}
int main(){
	int i,j;
	while(cin>>n){
		if(n==0)break;
		init();
		for(i=0;i<n;i++){
			cin>>s[i];
			reset(c,0);
			copy(c,s[i]);
			p->insert(c,i);
		}
		cin>>s[199];
		reset(c,0);
		copy(c,s[199]);
		p->find(c,s[199].length());
		for(i=0,j=0;i<n;i++){if(freq[i]>j)j=freq[i];}
		cout<<j<<endl;
		for(i=0;i<n;i++){if(freq[i]==j)cout<<s[i]<<endl;}
		delete p;
	}
	return 0;
}
```

```c
/*codeforces 963D
* 给定一个字符串S和多个模板串和每个模板串对应的出现次数k,需要求出对于每一个模板串最短需要多长的S的子串能* 出现k次
* 思路:对与每一个模板串,我们维护一个出现位置(串结尾,比如abbb中bbb的位置是4不是2)列表v,假设串a需要出现* 3次,且它的长度为len,则满足它条件的S子* 串长度为min(v[i+3]-v[i]+len),所以关键是求v.
* 因为ac自动机在查找串S时是有头到尾进行,所以每找到一个单词,把当前便利到的串S位置加入它的位置列表,位置列* 表就是有序的
*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 100010
#define sigma 26
#define reset(a,b)	memset(a,b,sizeof(a))
char s[maxn],pattern[maxn];
int t,n,query[maxn],len[maxn];

int ch[maxn][sigma];
int fail[maxn],last[maxn];
vector<int>val[maxn],ans[maxn];
int sz;
queue<int>q;

void init(){
	sz=0;
	reset(ch[0],0);
	reset(fail,0);
	reset(last,0);reset(s,0);
}

//构造前缀树
void insert(char *s,int x){
	int i,j,k,len=strlen(s);
	for(i=0,k=0;i<len;i++){
		j=s[i]-'a';
		if(!ch[k][j]){
			ch[k][j]=++sz;
			reset(ch[sz],0);
		}
		k=ch[k][j];
	}
	val[k].push_back(x);
}

//获取fail和last指针
void getfail(){
	int i,j,k;
	for(i=0;i<sigma;i++)	if(ch[0][i])q.push(ch[0][i]);
	while(!q.empty()){
		k=q.front();q.pop();
		for(i=0;i<sigma;i++){
			if(!ch[k][i])continue;
			j=fail[k];
			q.push(ch[k][i]);
			while(j&&!ch[j][i])j=fail[j];
			fail[ch[k][i]]=ch[j][i];
			if(val[fail[ch[k][i]]].size()!=0)last[ch[k][i]]=ch[j][i];
			else last[ch[k][i]]=last[fail[ch[k][i]]];
		}
	}
}

//当前单词节点为x,对应串S中的位置为y
void add(int x,int y){
	while(x){
		vector<int>::iterator p=val[x].begin();
		while(p!=val[x].end()){
			ans[*p].push_back(y);//加如位置列表
			p++;
		}
		x=last[x];
	}
}

void find(char *s){
	int i,j,k,len=strlen(s);
	for(i=0,k=0;i<len;i++){
		j=s[i]-'a';
		while(k&&!ch[k][j])k=fail[k];
		k=ch[k][j];
		add(k,i);	//到第k个节点,位置为i
	}
}
int main(){
	int i,j,k,tans;
	scanf("%s%d",s,&n);
	for(i=0;i<n;i++){
		reset(pattern,0);
		scanf("%d%s",&query[i],pattern);
		insert(pattern,i);
		len[i]=strlen(pattern);
	}
	getfail();
	find(s);
	for(i=0;i<n;i++){
		tans=maxn;
		for(j=0,k=j+query[i]-1;k<(int)ans[i].size();j++,k++){
			tans=min(tans,ans[i][k]-ans[i][j]+len[i]);//最小的最后出现位置减最先出现位置加串长
		}
		if(tans==maxn)printf("-1\n");
		else printf("%d\n",tans);
	}
	return 0;
}
```

