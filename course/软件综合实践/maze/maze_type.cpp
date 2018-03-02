#include "Maze.h"
using namespace maze;

Maze::Maze(ll h,ll w)::height(h*2+1),width(w*2+1){}

Maze::~Maze(){delete [][] m;}

Maze::void generate()
{
	ll i,j,k;
	m=new bool*[height];
	for(i=0;i<height;i++)	m[i]=new bool[width];

	for(i=0;i<height;i++)	for(j=0;j<width;j++)	m[i][j]=1;
	for(i=0;i<height;i=i+2)	for(j=0;j<width;j++)	m[i][j]=0;
	for(j=0;j<width;j=j+2)	for(i=0;i<height;i++)	m[i][j]=0;

	
}