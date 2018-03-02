#include "maze.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x,y;
	cin>>x>>y;
	Maze m(x,y,make_pair(0,0),make_pair(15,15));
	m.GenerateMap1();
	cout<<m;
	return 0;
}