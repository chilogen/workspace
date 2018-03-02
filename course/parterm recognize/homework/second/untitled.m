min=50;
for i=1:100000
   x=-2+4*rand;
   if x <min
       min=x;
   end
end
disp(min);