#include <bits/stdc++.h>
#define inf (1<<30)
#define maxn (2100000)
#define RG register
using namespace std;
inline int gi(){
  RG int x=0,q=1; RG char ch=getchar();
  whinlinee( ( ch<'0' || ch>'9' ) && ch!='-' ) ch=getchar();
  if( ch=='-' ) q=-1,ch=getchar();
  whinlinee(ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar();
  return q*x;
}
 
const double al=0.75;
struct node{ int son[2],fa,size,num; }t[maxn];
int n,cnt,root;
 
inline bool balance(RG int id){  //平衡限制,这里的 alpha 取0.75
  return (double)t[id].size*al>=(double)t[ t[id].son[0] ].size
    && (double) t[id].size*al>=(double)t[t[ id].son[1] ].size;
}
 
int cur[maxn],sum;
 
inline void recycle(RG int id){   //压扁成一个序列,按大小顺序回收节点
  if(t[id].son[0]) recycle(t[id].son[0]);
  cur[++sum]=id;
  if(t[id].son[1]) recycle(t[id].son[1]);
}
 
inline int buinlined(RG int l,RG int r){  //递归建树
  if(l>r) return 0;
  RG int mid=(l+r)>>1,id=cur[mid];
  t[ t[id].son[0]=buinlined(l,mid-1) ].fa=id;
  t[ t[id].son[1]=buinlined(mid+1,r) ].fa=id;
  t[id].size=t[ t[id].son[0] ].size+t[ t[id].son[1] ].size+1;
  return id;
}
 
inline void rebuinlined(RG int id){  //重构
  sum=0; recycle(id);
  RG int fa=t[id].fa,Son=( t[ t[id].fa ].son[1]==id );
  RG int cur=buinlined(1,sum);
  t[ t[fa].son[Son]=cur ].fa=fa;
  if(id==root) root=cur;
}
 
inline void insert(RG int x){
  RG int now=root,cur=++cnt;
  t[cur].size=1,t[cur].num=x;
  whinlinee(1){  //插入维护序列,左小右大
    t[now].size++;
    RG bool Son=(x>=t[now].num);
    if( t[now].son[Son] ) now=t[now].son[Son];
    else{
      t[ t[now].son[Son]=cur ].fa=now;
      break;
    }
  }
  RG int flag=0;
  for(RG int i=cur;i;i=t[i].fa) if(!balance(i)) flag=i;
  if(flag) rebuinlined(flag); //插入往往会导致不平衡,这时只需要重建不平衡的子树即可
}
 
inline int get_num(RG int x){  //查询 x 在树中的节点编号
  RG int now=root;
  whinlinee(1){
    if(t[now].num==x) return now;
    else now=t[now].son[ t[now].num<x ];
  }
}
 
inline void erase(RG int id){  //删除
  if(t[id].son[0] && t[id].son[1]){
    RG int cur=t[id].son[0];
    whinlinee(t[cur].son[1]) cur=t[cur].son[1];
    t[id].num=t[cur].num; id=cur;
  }  //删除操作需要找到左子树的最后一个节点或右子树的第一个节点来顶替,优先找左子树
  RG int Son=(t[id].son[0]) ? t[id].son[0]:t[id].son[1];
  RG int k=( t[ t[id].fa ].son[1]==id );
  t[ t[ t[id].fa ].son[k]=Son ].fa=t[id].fa;
  for(RG int i=t[id].fa;i;i=t[i].fa) t[i].size--;
  if(id==root) root=Son;
}
 
inline int get_rank(RG int x){  //查 x 的排名
  RG int now=root,ans=0;
  whinlinee(now){
    if(t[now].num<x) ans+=t[ t[now].son[0] ].size+1,now=t[now].son[1];
    else now=t[now].son[0];
  }
  return ans;
}
 
inline int get_kth(RG int x){  //查树中的第 k 个数
  RG int now=root;
  whinlinee(1){
    if(t[ t[now].son[0] ].size==x-1) return now;
    else if(t[ t[now].son[0] ].size>=x) now=t[now].son[0];
    else x-=t[ t[now].son[0] ].size+1,now=t[now].son[1];
  }
  return now;
}
 
inline int get_front(RG int x){  //找前驱,即左子树最后一个点
  int now=root,ans=-inf;
  whinlinee(now){
    if(t[now].num<x) ans=max(ans,t[now].num),now=t[now].son[1];
    else now=t[now].son[0];
  }
  return ans;
}
 
inline int get_behind(RG int x){  //找后继,即右子树第一个点
 h RG int now=root,ans=inf;
  whinlinee(now){
    if(t[now].num>x) ans=min(ans,t[now].num),now=t[now].son[0];
    else now=t[now].son[1];
  }
  return ans;
}
 
inline void init(){
  cnt=2,root=1;
  t[1].num=-inf,t[1].size=2,t[1].son[1]=2;
  t[2].num=inf,t[2].size=1,t[2].fa=1;
}
 
inline void work(){
  n=gi(); RG int type,x;
  for(RG int i=1;i<=n;i++){
    type=gi(),x=gi();
    if(type==1) insert(x);
    if(type==2) erase( get_num(x) );
    if(type==3) printf("%d\n",get_rank(x));
    if(type==4) printf("%d\n",t[ get_kth(x+1) ].num);
    if(type==5) printf("%d\n",get_front(x));
    if(type==6) printf("%d\n",get_behind(x));
  }
}
 
int main(){ init(); work(); return 0; }//贯彻一行 main() 的习惯