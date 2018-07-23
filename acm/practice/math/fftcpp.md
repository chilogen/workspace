# fftcpp

使用说明：

求值：fft(a,len,1)

点值乘法：c[i]=a[i]*b[i]

差值：fft(c,len,-1)

len为大于原位数的二次幂：

size=size<<1;len=1;

while(len<size)len<<=1;



差值后还原十进制：

d[i]=a[i].real()/len+0.5;

d[i]高位在后，地位在前，进位和输出需逆向



n位乘n位，结果应至少开3*n位