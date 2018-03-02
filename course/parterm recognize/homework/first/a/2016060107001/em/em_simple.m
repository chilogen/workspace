function ima=em_simple()
    load('../data/em.mat');
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
    subplot(1,2,2);
    image(ima);
    subplot(1,2,1);
    gaoshi(u1,o1);
    hold on;
    gaoshi(u2,o2);
    hold off;
end