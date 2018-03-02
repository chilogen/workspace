function c=myfun()
rand('seed',1019);
c=fix(20*rand(10,11));
c(:,3)=c(:,3).^2;
a=c(3,:);
c(3,:)=c(4,:);
c(4,:)=a;
c(10,:)=c(10,:)+c(5,:);
c(7,:)=0;