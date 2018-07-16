#include <bits/stdc++.h>
using namespace std;
int y1;
int main(){
	return 0;
}

/*
 int y1;
     ^~
In file included from /usr/include/features.h:424:0,
                 from /usr/include/x86_64-linux-gnu/c++/7/bits/os_defines.h:39,
                 from /usr/include/x86_64-linux-gnu/c++/7/bits/c++config.h:533,
                 from /usr/include/c++/7/cassert:43,
                 from /usr/include/x86_64-linux-gnu/c++/7/bits/stdc++.h:33,
                 from InterestingError.cpp:1:
/usr/include/x86_64-linux-gnu/bits/mathcalls.h:221:1: note: previous declaration ‘double y1(double)’
 __MATHCALL (y1,, (_Mdouble_));

 no only y1,but also y0,yn....
 all define in mathcalls.h

 the key point is include stdc++.h and define y1 global
*/