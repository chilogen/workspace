function ima=gray_simple()
    ima=imread('../data/309.bmp');
    load('../data/Mask.mat');
    load('../data/gray.mat');
    v(:,:,1)=Mask; v(:,:,2)=Mask;  v(:,:,3)=Mask;
    Mask=uint8(v);
    img=ima.*Mask;
    g=mat2gray(img);
    g=g(:,:,2);
    g=fix(g*10000);
    for i=1:240
        for j=1:320
            if g(i,j)~=0
                if f1(g(i,j))>f2(g(i,j)) ima(i,j,:)=0; ima(i,j,1)=255;
                else ima(i,j,:)=0; ima(i,j,3)=255;
                end
            end
        end
    end
    subplot(1,2,2);
    image(ima);
    x=linspace(0,1,10000);
    subplot(1,2,1);
    plot(x,f1);
    hold on;
    plot(x,f2);
    hold off;
end