#ifndef MAZETYPE_H
#define MAZETYPE_H

#include "Maze.h"

namespace Maze
{
	class maze
	{
	public:
		std::vector<std::pair<LL, LL> >trace,path;
		~maze() { delete [] m; }
		bool generate(LL x,LL y);
		void findpath();
		void getrect(LL x, LL y, int **p);
		void move(LL x,LL y);
		void clear();

	private:
		bool **m;
		LL w, h, width, height;
	};
}


#endif // !MazeType.h
