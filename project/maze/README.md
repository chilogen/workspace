#maze--软件综合实验作业
CopyRight 2017.12.5 chilogen on github


* 启动后输入 **N** 将生成 **N \* N **迷宫和若游戏中需要生成新地图请按 'n',输入  
地图大小后新的地图将会生成

* 按键功能：
	* w,a,s,d	移动
	* p		显示答案
	* t		显示走过的路径
	* e		退出
	
* 傻瓜版本，你走到终点后并不会跳出一个程序员安慰师，也就是，什么也不会发生

* 颜色我随便选的，随缘，若丑莫怪


---------

* 编译问题：
	* 首先得确保正确安装opengl,不同平台安装方法请百度
	* cmake
		Pro 1：
		
		
		`CMake Error: The following variables are used in this project, but they `
		`are set to NOTFOUND.`
		`GLUT_Xmu_LIBRARY (ADVANCED)`
		
		安装 libxmu-dev	libxi-dev