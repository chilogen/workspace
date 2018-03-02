function gashi(e,f)
    x=linspace(-2,2,200000);
    a=1/(sqrt(2*pi)*f);
    b=-2*f*f;
    for i=1:200000
       c=(x(i)-e)*(x(i)-e);
       f(i)=a*exp(c/b);
    end
    plot(x,f);
end