function img=rgb()
    x=linspace(0,1,10000);
    fc=1;
    a1=0;  a2=0;
    for j=1:10000
        f11(j)=0; f12(j)=0; f13(j)=0; 
        f21(j)=0; f22(j)=0; f23(j)=0;
    end
    load('../data/array_sample.mat');
    for j=1:7696
        jz1=array_sample(j,2);
        jz2=array_sample(j,3);
        jz3=array_sample(j,4);
        if array_sample(j,5)==1
            a1=a1+1;
            for k=1:10000
                f11(k)=1/(sqrt(2*pi)*fc)*exp(-(x(k)-jz1)^2/(2*fc^2))+f11(k);
                f12(k)=1/(sqrt(2*pi)*fc)*exp(-(x(k)-jz2)^2/(2*fc^2))+f12(k);
                f13(k)=1/(sqrt(2*pi)*fc)*exp(-(x(k)-jz3)^2/(2*fc^2))+f13(k);
            end
        else
            a2=a2+1;
            for k=1:10000
                f21(k)=1/(sqrt(2*pi)*fc)*exp(-(x(k)-jz1)^2/(2*fc^2))+f21(k);
                f22(k)=1/(sqrt(2*pi)*fc)*exp(-(x(k)-jz2)^2/(2*fc^2))+f22(k);
                f23(k)=1/(sqrt(2*pi)*fc)*exp(-(x(k)-jz3)^2/(2*fc^2))+f23(k);
            end
        end;
    end
    for j=1:10000
        f11(j)=f11(j)/a1; f12(j)=f12(j)/a1; f13(j)=f13(j)/a1;
        f21(j)=f21(j)/a2; f22(j)=f22(j)/a2; f23(j)=f23(j)/a2;
    end
    save('../data/rgb.mat','f11','f12','f13','f21','f22','f23');
%-------------------------------------------------------
    img=imread('../data/309.bmp');
    load('../data/Mask.mat');
    v(:,:,1)=Mask; v(:,:,2)=Mask; v(:,:,3)=Mask;
    ima=double(img);
    ima=ima.*v;
    ima=fix(ima./255*10000);
    for i=1:240
        for j=1:320
            if ima(i,j,1)~=0 | ima(i,j,2)~=0 | ima(i,j,3)~=0
               if (f11(ima(i,j,1))+f12(ima(i,j,2))+f13(ima(i,j,3)))>...
                  (f12(ima(i,j,1))+f12(ima(i,j,2))+f12(ima(i,j,3)))
                   img(i,j,:)=0; img(i,j,1)=255;
               else img(i,j,:)=0; img(i,j,3)=255;
               end
            end
        end
    end
    image(img);
end