function a=myfun()
v=[9,8,13];
a=v;
for i=1:9
    a=[a;v];
end
a=a';