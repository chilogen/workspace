function img=rgb_simple()
    load('../data/rgb.mat');
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
