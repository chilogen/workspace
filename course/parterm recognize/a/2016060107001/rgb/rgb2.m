function ima=rgb2()
    load('../data/array_sample.mat');
    count1=0; count2=0;
    sum11=0; sum12=0; sum13=0;
    sum21=0; sum22=0; sum23=0
    for i=1:7696
       if array_sample(i,5)==1
           count1=count1+1;
           f11(count1)=array_sample(i,2);
           sum11=sum11+f11(count1);
           f12(count1)=array_sample(i,3);
           sum12=sum12+f12(count1);
           f13(count1)=array_sample(i,4);
           sum13=sum13+f13(count1);
       else
           count2=count2+1;
           f21(count2)=array_sample(i,2);
           sum21=sum21+f21(count2);
           f22(count2)=array_sample(i,3);
           sum22=sum22+f22(count2);
           f23(count2)=array_sample(i,4);
           sum23=sum23+f23(count2);
       end
    end
    sumo11=0; sumo12=0; sumo13=0;
    sumo21=0; sumo22=0; sumo23=0;
    u11=sum11/count1; u12=sum12/count1; u13=sum13/count1;
    u21=sum21/count2; u22=sum22/count2; u23=sum23/count2;
    for i=1:count1
        sumo11=sumo11+(f11(i)-u11)*(f11(i)-u11);
        sumo12=sumo12+(f12(i)-u12)*(f12(i)-u12);
        sumo13=sumo13+(f13(i)-u13)*(f13(i)-u13);
    end
    for i=1:count2
        sumo21=sumo21+(f21(i)-u21)*(f21(i)-u21);
        sumo22=sumo22+(f22(i)-u22)*(f22(i)-u22);
        sumo23=sumo23+(f23(i)-u23)*(f23(i)-u23);
    end
    o11=sqrt(sumo11/count1); o12=sqrt(sumo12/count1); o13=sqrt(sumo13/count1);
    o21=sqrt(sumo21/count2); o22=sqrt(sumo22/count2); o23=sqrt(sumo23/count2);
    %----------------------------------------------------------------
    a=1/sqrt(2*pi);
    ima=imread('../data/309.bmp');
    load('../data/Mask.mat');
    v(:,:,1)=Mask; v(:,:,2)=Mask; v(:,:,3)=Mask;
    Mask=uint8(Mask);
    img=ima.*Mask;
    g=mat2gray(img);
    g=double(g);
    for i=1:240
        for j=1:320
            if g(i,j)~=0
                if a/o11*exp(-(g(i,j,1)-u11)*(g(i,j,1)-u11)/(2*o11*o11))+...
                   a/o12*exp(-(g(i,j,2)-u12)*(g(i,j,2)-u12)/(2*o12*o12))+...
                   a/o13*exp(-(g(i,j,3)-u13)*(g(i,j,3)-u13)/(2*o13*o13)) >...
                   a/o21*exp(-(g(i,j,1)-u21)*(g(i,j,1)-u21)/(2*o21*o21))+...
                   a/o22*exp(-(g(i,j,2)-u22)*(g(i,j,2)-u22)/(2*o22*o22))+...
                   a/o23*exp(-(g(i,j,3)-u23)*(g(i,j,3)-u23)/(2*o23*o23))
                   ima(i,j,:)=0; ima(i,j,1)=255;
                else ima(i,j,:)=0; ima(i,j,2)=255;
                end 
            end
        end
    end
    image(ima);
end