#ifndef MAZEFUN_H
#define MAZEFUN_H

#include <iostream>

#ifdef DEBUG

#include <cstdio>
#include <cstdlib>

#endif // DEBUG

#include "Maze.h"
using namespace Maze;

void init()
{
	LL x, y;
	std::cout << "Give the width and the height of the map(n  X  n)" << std::endl;

	while (1)
	{
		std::cout << "The num should between 5 and 100" << std::endl;
		std::cin >> x;
		if (x >= 5 && x <= 100)	break;
	}
	y=x;
	mm.clear();
	mm.generate(x, y);
}

bool maze::generate(LL x, LL y)
{
	std::vector<LL> X = { -2,2,0,0 }, Y = { 0,0,-2,2 }, a = { 0,1,2,3 };
	std::queue<std::pair<LL, LL> >bfs;
	LL i, j;
	srand((unsigned)time(NULL));
	w = x, h = y;
	height = h * 2 + 1, width = w * 2 + 1;
	m = new bool*[height];
	for (i = 0; i < height; i++)
	{
		m[i] = new bool[width];
		for (j = 0; j < width; j++)	m[i][j] = 0;
	}
	nowpos.first = (rand() % w) * 2 + 1;
	nowpos.second = (rand() % h) * 2 + 1;
	i = rand() % 4;
	switch (i)
	{
	case 0:
	{
		endpos.first = 1;
		endpos.second = (rand() % h) * 2 + 1;
		break;
	}
	case 1:
	{
		endpos.second = height - 2;
		endpos.first = ((rand()) % w) * 2 + 1;
		break;
	}
	case 2:
	{
		endpos.first = width - 2;
		endpos.second = (rand() % h) * 2 + 1;
		break;
	}
	case 3:
	{
		endpos.second = 1;
		endpos.first = (rand() % w) * 2 + 1;
		break;
	}
	}
	bfs.push(std::make_pair(1, 1));
	
	LL tx, ty;
	std::pair<LL,LL>tp;
	while (!bfs.empty())
	{
		for (i = 0; i < 4; i++)	std::swap(a[i], a[rand() % 4]);
		tp = bfs.front();	bfs.pop();

		for (i = 0; i < 4; i++)
		{
			tx = tp.first + X[a[i]];
			ty = tp.second + Y[a[i]];
			if (tx < 0 || ty < 0 || tx >= width || ty >= height)	continue;
			if (!m[tx][ty])
			{
				if (rand() % 2 != 0 && i != 3)
				{
					bfs.push(tp);
					break;
				}
				m[tx][ty] = 1;
				bfs.push(std::make_pair(tx, ty));
				tx = tp.first + X[a[i]] / 2;
				ty = tp.second + Y[a[i]] / 2;
				m[tx][ty] = 1;
			}
			else if(rand() % 10 == 1)
			{
				tx = tp.first + X[a[i]] / 2;
				ty = tp.second + Y[a[i]] / 2;
				m[tx][ty] = 1;
			}
		}
	}

	return true;
}

void maze::findpath()
{
	std::pair<LL, LL> **p;
	std::queue<std::pair<LL, LL> >bfs;
	std::pair<LL, LL> tp;
	std::vector<LL> X = { 1,-1,0,0 }, Y = { 0,0,1,-1 };
	LL i, j, tx, ty;
	
	p = new std::pair<LL, LL> *[height];
	for (i = 0; i < height; i++)
	{
		p[i] = new std::pair<LL, LL>[width];
		for (j = 0; j < width; j++)	p[i][j].first = p[i][j].second = -1;
	}

	bfs.push(endpos);	p[endpos.first][endpos.second].first=999999;
	while (!bfs.empty())
	{
		tp = bfs.front();	bfs.pop();
		for (i = 0; i < 4; i++)
		{
			tx = tp.first + X[i], ty = tp.second + Y[i];
			if (tx < 0 || ty < 0 || tx >= width || ty >= height)	continue;
			if(p[tx][ty].first!=-1)	continue;
			if (m[tx][ty])
			{
				p[tx][ty] = tp;
				if (nowpos == std::make_pair(tx, ty))	break;
				bfs.push(std::make_pair(tx, ty));
			}
		}
	}

	tp = nowpos;
	path.clear();
	while (tp.second != -1)
	{
		path.push_back(tp);
		tp = p[tp.first][tp.second];
	}

}
void maze::getrect(LL x, LL y, int **p)
{
	LL i, j, halflenx = x >> 1, halfleny = y >> 1;
	
	if (nowpos.first - halflenx < 0)	SX = 0;
	else if (nowpos.first + halflenx >= width)	SX = width - halflenx * 2;
	else if (nowpos.first - halflenx >= 0 && nowpos.first + halflenx <= width)
		SX = nowpos.first - halflenx;
	else
	{
		SX = 0;
		halflenx = width >> 1;
		ShowAreaBlockX = width / Rectlen;
	}

	if (nowpos.second - halfleny < 0)	SY = 0;
	else if (nowpos.second + halfleny >= height)	SY = height - halfleny * 2;
	else if(nowpos.second - halfleny >= 0&& nowpos.second + halfleny < height)
		SY = nowpos.second - halfleny;
	else
	{
		SY = 0;
		halfleny = height >> 1;
		ShowAreaBlockY = height / Rectlen;
	}

	for (i = 0; i < halflenx << 1; i++)
	{
		for (j = 0; j < halfleny << 1; j++)
			if (m[SX + i][SY + j])	p[i][j] = 1;
			else p[i][j] = 0;
	}
}

void maze::move(LL x,LL y)
{
	LL tx = nowpos.first+x, ty = nowpos.second + y;
	if (tx < 0 || ty < 0 || tx >= width || ty >= height)	return;
	if (m[tx][ty])	nowpos = std::make_pair(tx, ty), trace.push_back(nowpos);
}

void maze::clear()
{
	trace.clear();
	path.clear();
	delete [] m;
}

#endif // !MAZEFUN_H
