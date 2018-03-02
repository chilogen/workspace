function s=myfun()
s=0;
p=1.07;
for i=1:33
    s=s+p;
    p=p*1.07;
end