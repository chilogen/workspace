# lca2rmq.cpp

> lca 最近公共祖先
>
> rmq 区间最值查询

算法思想：

结合先序遍历和后续遍历，将根记录到其所有子节点遍历结果的两侧，即在两个相同节点标号中间的所有节点的最近公共祖先就是该相同节点：

```c
dfs(x):
	log(x);
	dfs(x->son);
	log(x);
```

通过将节点与其深度相互对应，通过对深度记录的区间最值查询得到最近公共祖先