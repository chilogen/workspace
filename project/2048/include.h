#ifndef INCLUDE_H
#define INCLUDE_H

#define startmenu 0
#define howtoplay 1
#define resultfail 2
#define resultwin 3

#define mode1 1
#define mode2 2

#define FAIL 0
#define WIN 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void show(int);
void disp();
void play(int);
int add(int p[4]);
void append(int q[4],int x,int y,int m[4][4]);
int p1();
int p2();
void action(char command,int map[4][4]);
int judge();
extern int map[4][4];
extern int score;
#endif
