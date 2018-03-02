function ima=partition()
    x=imread('309.bmp');
    load('Mask.mat');
    load('array_sample.mat');
    ima=x;
    v(:,:,1)=Mask;
    v(:,:,2)=Mask;
    v(:,:,3)=Mask;
    Mask=uint8(v);
    i=x.*Mask;
    g=mat2gray(i);
    s=resort(array_sample);
    for i=1:240
        for j=1:320
        if g(i,j,1)~=0 | g(i,j,2)~=0 |g(i,j,3)~=0
            if found(g(i,j,2),s,0,7696)==1 ima(i,j,:)=0; ima(i,j,1)=255;
            else ima(i,j,:)=0; ima(i,j,3)=255;
            end
        end
        end
    end
    image(ima);
end
function s=resort(sample)
    s=rand(7696,2);
    s(:,1)=sample(:,1);
    s(:,2)=sample(:,5);
    for i=1:7696
        for j=i:7696
            if s(i,1)<s(j)
                t=s(i,1);
                s(i,1)=s(j,1);
                s(j,1)=t;
                t=s(i,2);
                s(i,2)=s(j,2);
                s(j,2)=t;
            end
        end
    end
end
function re=found(f,s,ranges,rangee)
    i=fix((ranges+rangee)/2);
    if i==ranges|i==rangee re=1;
    elseif abs(s(i,1)-f)<0.0005 re=s(i,2);
    elseif s(i,1)<f re=found(f,s,ranges,i);
    elseif s(i,1)>f re=found(f,s,i,rangee);
    elseif s(i,1)==f re=s(i,2);
    else re=-1;
    end
end