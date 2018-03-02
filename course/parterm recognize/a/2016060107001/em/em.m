function ima=me()
    load('../data/array_sample.mat');
    u1=0.1; u2=0.1; %suppose E1(x)=0.1 E2(x)=0.1
    o1=1; o2=1;
    a=1/sqrt(2*pi);
    count1=100; count2=100; 
    sum1=70; sum2=30; sumo1=100; sumo2=100;
    x=linspace(0,1,10000);
    k=1
    while abs(sum1/count1-u1)>0.0001 | abs(sum2/count2-u2)>0.0001...
           | abs(sumo1/count1-o1*o1)>0.001 | abs(sumo2/count2-o2*o2)>0.001
       u1=sum1/count1;u2=sum2/count2; o1=sqrt(sumo1/count1); o2=sqrt(sumo2/count2);
       %if k<10
       %subplot(3,3,k);
       %gaoshi(u1,o1);
       %hold on;
       %gaoshi(u2,o2);
       %hold off;
       %k=k+1;
       %end
       sum1=0; sum2=0; sumo1=0; sumo2=0;
       count1=0; count2=0;
       first=0;
       for i=1:7696
           if a/o1*exp(-(array_sample(i,1)-u1)*(array_sample(i,1)-u1)/(2*o1*o1)) >...
              a/o1*exp(-(array_sample(i,1)-u2)*(array_sample(i,1)-u2)/(2*o2*o2))
              sum1=sum1+array_sample(i,1); sumo1=sumo1+(array_sample(i,1)-u1)*(array_sample(i,1)-u1);
              count1=count1+1;
           else sum2=sum2+array_sample(i,1); sumo2=sumo2+(array_sample(i,1)-u2)*(array_sample(i,1)-u2);
                count2=count2+1;
           end
       end
    end
    save('../data/em.mat','u1','u2','o1','o2','a');
    %----------------------------------------------------------------
    ima=imread('../data/309.bmp');
    load('../data/Mask.mat');
    v(:,:,1)=Mask; v(:,:,2)=Mask; v(:,:,3)=Mask;
    Mask=uint8(Mask);
    img=ima.*Mask;
    g=rgb2gray(img);
    g=double(g);
    g=g./255;
    for i=1:240
        for j=1:320
            if g(i,j)~=0
                if a/o1*exp(-(g(i,j)-u1)*(g(i,j)-u1)/(2*o1*o1)) >...
                   a/o1*exp(-(g(i,j)-u2)*(g(i,j)-u2)/(2*o2*o2))
                   ima(i,j,:)=0; ima(i,j,1)=255;
                else ima(i,j,:)=0; ima(i,j,2)=255;
                end 
            end
        end
    end
    image(ima);
end