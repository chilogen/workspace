function ima=gray()
    x=linspace(0,1,10000);
    fc=1;
    for j=1:10000
        f1(j)=0;  f2(j)=0;
    end
    a1=0;  a2=0;
    load('../data/array_sample.mat');
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
        f1(j)=f1(j)/a1;  f2(j)=f2(j)/a2;
    end
    save('../data/gray.mat');
    %-----------------------------------------------------------%
    ima=imread('../data/309.bmp');
    load('../data/Mask.mat');
    v(:,:,1)=Mask; v(:,:,2)=Mask; v(:,:,3)=Mask;
    Mask=uint8(Mask);
    img=ima.*Mask;
    g=mat2gray(img);
    g=g(:,:,2);
    g=g*10000;
    g=fix(g);
    for i=1:240
        for j=1:320
            if g(i,j)~=0
                if f1(g(i,j))>f2(g(i,j)) ima(i,j,1)=100; ima(i,j,2)=100; ima(i,j,3)=100;
                else ima(i,j,1)=120; ima(i,j,2)=180; ima(i,j,3)=255;
                end
            end
        end
    end
    image(ima);
end