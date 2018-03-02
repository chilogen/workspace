function f1=t()
x=linspace(0,1,10000);
fc=1;
for j=1:10000
    f1(j)=0;  f2(j)=0;
end
a1=0;  a2=0;
load('array_sample.mat');
for j=1:7696
    jz=array_sample(j,1);
    if array_sample(j,5)==1
       a1=a1+1;
       for k=1:10000
          f1(k)=1/(sqrt(2*pi)*fc)*exp(-(x(k)-jz)^2/(2*fc^2))+f1(k);
       end
    else
        a2=a2+1;
        for k=1:10000
          f2(k)=1/(sqrt(2*pi)*fc)*exp(-(x(k)-jz)^2/(2*fc^2))+f2(k);
        end
    end;
end
for j=1:10000
    f1(j)=f1(j)/a1;
    f2(j)=f2(j)/a2;
end