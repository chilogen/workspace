function svm()
load('test_data.mat');
load('test_label.mat');
load('train_data.mat');
load('train_label.mat');
%---------------------------%
cl=-2;  cr=2;
gl=-3;  gr=1;
max=0;  bool=0;
%---------------------------%
while (cr-cl)>0.1 || (gr-gl>0.1)
    c=logspace(cl,cr,3);
    g=logspace(gl,gr,3);
    bool=0;
    for i=1:3
        for j=1:3
            opt=['-t 1 ','-v 10 ','-c ',num2str(c(i)),'-g ',num2str(g(i))];
            acc=svmtrain(train_label,train_data,opt);%用训练样本根据不同的 c、g 进行交叉验证，找最大的acc
            if acc>max 
                max=acc;
                k=cl;   l=cr;
                cl=c(i)-(l-k)/8;
                cr=c(i)+(l-k)/8;
                k=gl;   l=gr;
                gl=g(i)-(l-k)/8;
                gr=g(i)+(l-k)/8;
                rc=num2str(c(i));    rg=num2str(g(i));
                bool=1;
            end
        end
    end
    if bool==0 
        k=cl;   l=cr;
        cl=k+(l-k)/8;
        cr=l-(l-k)/8;
        k=gl;   l=gr;
        gl=k+(l-k)/8;
        gr=l-(l-k)/8;
    end;
end
opt=['-t 1 ','-c ',rc,' -g ',rg];
mode=svmtrain(train_label,train_data,opt);%由得出最大acc值的参数再次训练，将得到的mode用于对test预测
[pre, accc, dec] =svmpredict(test_label,test_data, mode);
disp(accc(1));
