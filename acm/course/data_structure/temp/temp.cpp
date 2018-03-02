#include <cstdio>
#define lson o<<1, l, m
#define rson o<<1|1, m+1, r
typedef long long LL;
const int maxn = 100005;
  
int n, a, b, c, k, q;
LL sum[maxn<<2], add[maxn<<2], mul[maxn<<2], p;
  
void up(int o) {
    sum[o] = (sum[o<<1]+sum[o<<1|1]) %p;
}
  
void build(int o, int l, int r) {
    add[o] = 0, mul[o] = 1;
    if(l == r) {
        scanf("%lld", &sum[o]);
        return;
    }
    int m = (l+r) >> 1;
    build(lson);
    build(rson);
    up(o);
}
  
void down(int o, int len) {
   // if(add[o] != 0 && mul[o] != 1) {
        add[o<<1] = (add[o<<1] * mul[o] + add[o]) %p;
        add[o<<1|1] = (add[o<<1|1] * mul[o] + add[o]) %p;
        mul[o<<1] = mul[o<<1] * mul[o] %p;
        mul[o<<1|1] = mul[o<<1|1] * mul[o] %p;
        sum[o<<1] = (sum[o<<1] * mul[o] + add[o] * (len-(len>>1))) %p;
        sum[o<<1|1] = (sum[o<<1|1] * mul[o] + add[o] * (len>>1)) %p;
        add[o] = 0, mul[o] = 1;
   // }
}
  
void update(int o, int l, int r, int op) {
    if(a <= l && r <= b) {
        if(op == 1) {
            add[o] = add[o]*c %p;
            mul[o] = mul[o]*c %p;
            sum[o] = sum[o]*c %p;
        } else {
            add[o] = (add[o] + c) %p;
            sum[o] = (sum[o] + (LL)c*(r-l+1)) %p;
        }
        return;
    }
    down(o, r-l+1);
    int m = (l+r) >> 1;
    if(a <= m) update(lson, op);
    if(m < b ) update(rson, op);
    up(o);
}
  
LL query(int o, int l, int r) {
    if(a <= l && r <= b) return sum[o] %p;
    down(o, r-l+1);
    int m = (l+r) >> 1;
    LL ans = 0;
    if(a <= m) ans = query(lson);
    if(m < b ) ans += query(rson);
    return ans %p;
}
  
int main()
{
 //   freopen("abc","r",stdin);
    scanf("%d%lld", &n, &p);
    build(1, 1, n);
    scanf("%d", &q);
    while(q--) {
        scanf("%d%d%d", &k, &a, &b);
        if(k != 3) {
            scanf("%d", &c);
            update(1, 1, n, k);
        } else printf("%lld\n", query(1, 1, n));
    }
//    fclose(stdin);
    return 0;
}