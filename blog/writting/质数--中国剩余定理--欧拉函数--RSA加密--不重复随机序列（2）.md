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
		