# ST.cpp

> ST算法使用动态规划，以O(nlogn)的时间对数组进行预处理，以O(1)的时间完成区间查询

令 **ST\[i][j]**代表以**i**为起点，区间长度为$$2^j$$的区间的最值，则**$$ST[i][j]=cmp(ST[i][j-1],ST[i+2^{j-1}][j-1])$$**

