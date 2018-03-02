#<center>第一专题作业解题报告</center>
##2016060107001 韦嗣千

* Problem A
	建立结构体如下：
---
	struct tree
	{	
		int left;
		int right;
		int max;
		int min;
	};
---

求极差只要 findmax(l,r,1)-findmin(l,r,1);
>时间复杂度：
	* 建树 :相当于遍历整棵树，复杂度为 O(n);
	* 更新 :对于`p`次更新，由二叉树性质得复杂度为 O(plog(n));
	* 查询: 对于 `q`次查询，复杂度为O(qlog(n));
	总复杂度: O(klog(n));

时间估计:
> 数据规模 n<=50000,k<=200000
最坏情况运行次数为：200000*$\log_{2}50000\approx3$x$10^7$
差不多能在1秒内

*Problem B
	建立结构体如下：
---
	struct tree
	{
		int left;
		int right;
		int max;
		int flag;//flag 代表该段最右段数值，以判定是否可以与另一端相加
	}
---
建树不啰嗦，find()函数如下:
	
	int find(int start,int end,int x)
	{
		if(a[x].left==start && a[x].right==end)
		return a[x].max;
		int m=(a[x].left+a[x].right)/2;
		if(m>=end) return find(start,end,2*x);
		else if(m<start) return find(start,end,2*x+1);
		else if(a[2*x].flag==1)return find(start,m,2*x)+find(m+1,end,2*x+1);//若flag为 ‘1’，则说明两端可以连接，  
		最大连续值取两边相加
		else return max(find(start,m,2*x),find(m+1,end,2*x+1));//否则最大连续值取二者最大
	}
---
change()函数取类似思路，每段flag值与其右子树相同。
>时间复杂度：
* 建树：同样是