function ima=gray2()
    load('../data/array_sample.mat');
    count1=0; count2=0;
    sum1=0; sum2=0;
    for i=1:7696
       if array_sample(i,5)==1
           count1=count1+1;
           f1(count1)=array_sample(i,1);
           sum1=sum1+f1(count1);
       else
           count2=count2+1;
           f2(count2)=array_sample(i,1);
           sum2=sum2+f2(count2);
       end
    end
    sumo1=0; sumo2=0;
    u1=sum1/count1; u2=sum2/count2;
    for i=1:count1
        sumo1=sumo1+(f1(i)-u1)*(f1(i)-u1);
    end
    for i=1:count2
       sumo2=sumo2+(f2(i)-u2)*(f2(i)-u2);
    end
    o1=sqrt(sumo1/count1); o2=sqrt(sumo2/count2);
    %----------------------------------------------------------------
    a=1/sqrt(2*pi);
    ima=imread('../data/309.bmp');
    load('../data/Mask.mat');
    v(:,:,1)=Mask; v(:,:,2)=Mask; v(:,:,3)=Mask;
    Mask=uint8(Mask);
    img=ima.*Mask;
    g=mat2gray(img);
    g=double(g);
    g=g(:,:,2);
    for i=1:240
        for j=1:320
            if g(i,j)~=0
                if a/o1*exp(-(g(i,j)-u1)*(g(i,j)-u1)/(2*o1*o1)) >...
                   a/o2*exp(-(g(i,j)-u2)*(g(i,j)-u2)/(2*o2*o2))
                   ima(i,j,:)=0; ima(i,j,1)=255;
                else ima(i,j,:)=0; ima(i,j,2)=255;
                end 
            end
        end
    end
    image(ima);
end