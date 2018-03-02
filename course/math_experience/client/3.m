function s=myfun()
s=[];
for i=100:500
    if mod(i,4)==0 | mod(i,9)==0 && mod(i,36)~=0
        s=[s,i];
    end
end