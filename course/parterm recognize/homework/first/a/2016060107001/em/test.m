function test()
    load('../data/array_sample.mat');
    c1=0;c2=0;
    for i=1:7696
       if array_sample(i,5)==1 
           c1=c1+1;
           f1(c1)=array_sample(i,1);
       else c2=c2+1; f2(c2)=array_sample(i,1); 
       end
    end
    x1=linspace(0,1,c1);
    x2=linspace(0,1,c2);
    subplot(1,2,1);
    scatter(f1,x1,'p');
    subplot(1,2,2);
    scatter(f2,x2,'r');
end