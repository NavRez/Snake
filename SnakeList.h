#pragma once
#include <conio.h>
#include <iostream>
#include <Windows.h>
#include <time.h>
#include <string>
using namespace std;

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

class SnakeList
{
public:
	SnakeList();
	SnakeList(int,int, SnakeList*, SnakeList*);

	~SnakeList();

	SnakeList* getprev();
	SnakeList* getnext();

	void addHead(SnakeList*,int, int);
	void move(SnakeList*,int, int);
	void print(SnakeList*);
	int getrow();
	int getcol();
	void setcheck(int);
	int getcheck();
	bool exist;

protected:

	int curr_r;
	int curr_c;
	int prev_c;
	int prev_r;
	int checking;
	SnakeList* prev;
	SnakeList* next;
	
};

