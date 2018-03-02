function em()
    load('array_sample.mat');
    u1=1; u2=1; %suppose E1(x)=1 E2(x)=1
    fc=1;
    a=1/(sqrt(2*pi)*fc); b=-2*fc*fc;
    count1=100; count2=100; 
    sum1=2; sum2=5;
    first=1;
    x=linspace(0,1,10000);
    while first==1 | abs(sum1/count1-u1)>0.0001 | abs(sum2/count2-u2)>0.0001
       u1=sum1/count1;u2=sum2/count2;
       sum1=0; sum2=0;
       count1=0; count2=0;
       first=0;
       for i=1:10000
           if a*exp((x(i)-u1)*(x(i)-u1)/b) >...
              a*exp((x(i)-u2)*(x(i)-u2)/b)
              sum1=sum1+x(i);
              count1=count1+1;
           else sum2=sum2+x(i);
                count2=count2+1;
           end
       end
    end
    for i=1:10000
       f1(i)=0; f2(i)=0; 
    end
    count1=0; count2=0;
    for i=1:7696
        if a*exp((x(i)-u1)*(x(i)-u1)/b) >...
           a*exp((x(i)-u2)*(x(i)-u2)/b)
           for j=1:10000
               f1(j)=f1(j)+a*exp((x(j)-u1)*(x(j)-u1)/b);
           end
           count1=count1+1;
        else
           for j=1:10000
               f2(j)=f2(j)+a*exp((x(j)-u2)*(x(j)-u2)/b);
           end
           count2=count2+1;
        end
    end
    for i=1:10000
       f1(i)=f1(i)/count1;
       f2(i)=f2(i)/count2;
    end
    plot(x,f1);
    hold on;
    plot(x,f2);
    hold off;
end