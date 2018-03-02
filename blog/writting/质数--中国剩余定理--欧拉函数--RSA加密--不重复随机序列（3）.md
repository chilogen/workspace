#RSA加密篇

参考：[阮一峰的网络日志](http://www.ruanyifeng.com/blog/2013/06/rsa_algorithm_part_one.html)

* 唯一分解性定理  
`对于任一个大于n的正整数，都可以唯一并存在的分解为若干素数的乘积`<sup>[1]</sup>

* 拓展欧几里得算法：gcd(a,b)=gcd(b,a mod b){a>B}<sup>[2]</sup>
 * 用途1：快速求取a,b的最小公约数。
 ```c
 int gcd(int a,int b)
{
      if(a/b==0) return b
      else return gcd(b,a%b);
}
 ```

 * 用途2：求a在模b意义下的逆。
 引理(BEZOUT'S THEORY)：gcd(a,b)=sa+tb<sup>[3]</sup>
 如果gcd(a,b)=1,则s是a在模b意义下的逆，反之亦然。
 求解s,t:
 >gcd(a,b)=sa+tb
 gcd(b,a%b)=s'b+t'(a%b)=s'a+t'(a-(a/b)b)=t'a+[s'-t'(a/b)]b
$\Rightarrow$s=t',t=s'-t'(a/b)
直到b=0，则s'=1,t'=0,根据递归公式一直算到s,t

		```c
		void gcd_inv(int a,int b,int &s,int &t)
		{
			if(b==0)
			{
			  s=1;
			  t=0;
			}
			gcd_inv(b,a%b,s,t);
		}
		```


   * 求逆拓展---费马小定理：a<sup>p-1</sup>$\equiv$1 mod (p)
所以，a在模p意义下的逆为 a<sup>p-2</sup>。
	```
long long int getinv(long long int a,long long int mod)
{
      long long int p=mod-2,ans=1; 
      if(p)
      {
        ans=(ans*a)%mod;
        p=p>>1;
        a=(a*a)%mod;
      }
      return ans;
}
	```

* 中国剩余定理（孙子定理）<sup>[4]</sup>
	* 来源：今有物不知其数，三三数之剩二，五五数之剩三，七七数之剩二。问物几何？
	* 抽象为数学语言：  
	3k1+2=x  
	5k2+3=x  
	7k3+2=x  
	泛化为线性同余方程组：  
x $\equiv$a<sub>1 </sub> mod m <sub>1</sub>
x $\equiv$a<sub>2 </sub> mod m <sub>2</sub>
.
.
.
x $\equiv$a<sub>n </sub> mod m <sub>n</sub>
  * 求解：
  令M=$\Pi$

* 证明部分：
[1]
[2]
[3]扩展欧几里得算法---gcd(a,b)=gcd(b,a mod b){a>B}<sup>[2]</sup>
  >设：
  >a=k<sub>1</sub>gcd(a,b)
  >b=k<sub>2</sub>gcd(a,b)
  >a>b
  >所以：
  >a=((k<sub>1</sub>/k<sub>2</sub>)k<sub>2</sub>+k<sub>3</sub>)gcd(a,b)=(k<sub>1</sub>/k<sub>2</sub>)k<sub>2</sub>gcd(a,b)+k<sub>3</sub>gcd(a,b)
   
 
   [4]中国剩余定理
   
   > 设:
   >    m=m<sub>1</sub>*m<sub>2</sub>*...m<sub>n</sub>,M<sub>k</sub>=m/m<sub>k</sub>则必存在0$\leq$x$\leq$m，x=a<sub>1</sub>M<sub>1</sub>M<sub>1</sub><sup>-1</sup> +a<sub>2</sub>M<sub>2</sub>M2<sup>-1</sup>+...+a<sub>n</sub>M<sub>n</sub>M<sub>n</sub><sup>-1</sup>
   >   存在性：
   >   唯一性：
		