#ifndef MAZETYPE_H
#define MAZETYPE_H

#include "Maze.h"

namespace maze
{
	class Maze
	{
	public:
		std::vector<std::pair<ll> > path,trace;
		void generate(ll h,ll w);
		ll solve(std::pair<ll,ll>now,ll nowdis);
		Maze(ll h,ll w);
		~Maze(){delete [][] m;}
	private:
		bool **m;
		ll height,width;
		std::pair<ll,ll>nowpos,endpos;
	}
}

#endif