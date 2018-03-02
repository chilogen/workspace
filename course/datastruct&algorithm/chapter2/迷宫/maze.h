#ifndef GENERATE_H
#define GENERATE_H

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

typedef struct maze
{
	int **m,width,heigth,row,col;
	pii s,e;
	void GenerateMap1();
	void GenerateMap2();
	vector<pii>GetPath();
	vector<pii>GetShorestPath();
	maze(int,int,pii,pii);
}Maze;

ostream &operator <<(ostream &out,Maze &a);

#endif