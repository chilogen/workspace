    #include <bits/stdc++.h>
    using namespace std;
    const int maxn = 2e6+233;
    #define DB double
    const DB pi = acos(-1);
     
    struct CP {
        DB x, y; CP(){} inline CP(DB a, DB b):x(a),y(b){}
        inline CP operator + (const CP&r) const { return CP(x + r.x, y + r.y); }
        inline CP operator - (const CP&r) const { return CP(x - r.x, y - r.y); }
        inline CP operator * (const CP&r) const { return CP(x*r.x-y*r.y, x*r.y+y*r.x); }
        inline CP conj() { return CP(x, -y); }
    } a[maxn], b[maxn], t;
     
    int n, m;
    inline void Swap(CP&a, CP&b) { t = a; a = b; b = t; }
    const int BUF=8096000,OUT=8000000;
     
    char Buf[BUF],*buf=Buf,Out[OUT],*ou=Out;int Outn[64],Outcnt;
    inline int read() {int a;for(a=0;*buf<48;buf++);while(*buf>47)a=a*10+*buf++-48;return a;}
    inline void print(int x){ if(!x) *ou ++ = 48; else { for(Outcnt=0;x;x/=10) Outn[++Outcnt]=x%10+48; while(Outcnt)*ou++=Outn[Outcnt--]; } *ou++=' '; }
     
    void FFT(CP*a, int n, int f) {
        int i, j, k;
        for(i = j = 0; i < n; ++ i) {
            if(i > j) Swap(a[i], a[j]);
            for(k = n>>1; (j ^= k) < k; k >>= 1);
        }
        for(i = 1; i < n; i <<= 1) {
            CP wn(cos(pi/i), f*sin(pi/i));
            for(j = 0; j < n; j += i<<1) {
                CP w(1, 0);
                for(k = 0; k < i; ++ k, w=w*wn) {
                    CP x = a[j+k], y = w*a[i+j+k];
                    a[j+k] = x+y; a[i+j+k] = x-y;
                }
            }
        }
        if(-1 == f) for(i = 0; i < n; ++ i) a[i].x /= n;
    }
    int main() {
        fread(Buf, 1, BUF, stdin);
        n = read(); m = read();
        for(int i = 0; i <= n; ++ i) a[i].x = read();
        for(int i = 0; i <= m; ++ i) a[i].y = read();
        for(m += n, n = 1; n <= m; n <<= 1);
        FFT(a, n, 1); CP Q(0, -0.25);
        for(int i = 0, j; i < n; ++ i) j = (n-i)&(n-1), b[i] = (a[i]*a[i]-(a[j]*a[j]).conj())*Q;
        FFT(b, n,-1);
        for(int i = 0; i <= m; ++ i) print(int(b[i].x+0.2));
        fwrite(Out, 1, ou-Out, stdout);
        return 0;
    }