function f=gaoshi(u,o)
    x=linspace(0,1,10000);
    for i=1:10000
        f(i)=0;
    end
    for i=1:10000
       f(i)=1/(sqrt(2*pi)*o)*exp(-(x(i)-u)*(x(i)-u)/(2*o*o)); 
    end
    plot(x,f);
end