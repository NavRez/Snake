#include "SnakeList.h"



SnakeList::SnakeList()
{
	curr_r = -1;
	curr_c = -1;
	prev_r = -1;
	prev_c = -1;
	prev = nullptr;
	next = nullptr;
}

SnakeList::SnakeList(int row,int col, SnakeList* p1, SnakeList* p2)
{
	curr_r = row;
	curr_c = col;
	prev_r = curr_r;
	prev_c = curr_c;
	prev = p1;
	next = p2;
}


SnakeList::~SnakeList()
{
	delete next;
}

SnakeList* SnakeList::getprev() {

	return prev;
}

SnakeList* SnakeList::getnext() {

	return next;
}

void SnakeList::addHead(SnakeList* temp,int newrow, int newcol) {





	temp->curr_r = newrow;
	temp->curr_c = newcol;

	

	if (temp->next != nullptr) {

		
		addHead(temp->next, temp->prev_r, temp->prev_c);

	}
	else {

		temp->next = new SnakeList(temp->prev_r, temp->prev_c, temp, nullptr);
	}

	temp->prev_r = temp->curr_r;
	temp->prev_c = temp->curr_c;

	exist = false;
}

void SnakeList::move(SnakeList* snake, int newrow, int newcol) {

	if (snake->prev == nullptr && snake->next == nullptr) {
	
		snake->curr_c = newcol;
		snake->curr_r = newrow;
		snake->prev_c = newcol;
		snake->prev_r = newrow;

	}
	else if (snake->prev == nullptr && snake->next != nullptr) {
	
		snake->curr_c = newcol;
		snake->curr_r = newrow;

	}
	else if (snake->prev != nullptr && snake->next == nullptr)
	{
		snake->curr_c = snake->prev->prev_c;
		snake->curr_r = snake->prev->prev_r;
		snake->prev_c = snake->prev->prev_c;
		snake->prev_r = snake->prev->prev_r;

		snake->prev->prev_c = snake->prev->curr_c;
		snake->prev->prev_r = snake->prev->curr_r;
	}
	else {
	
		snake->curr_c = snake->prev->prev_c;
		snake->curr_r = snake->prev->prev_r;

		snake->prev->prev_c = snake->prev->curr_c;
		snake->prev->prev_r = snake->prev->curr_r;
	}



	if (snake->next != nullptr) {

		move(snake->next, newrow, newcol);

	}

	

}

void SnakeList::print(SnakeList* temp) {

	while (temp != nullptr) {

		cout << "row : " << temp->curr_r << "| col : " << temp->curr_c << "\n";

		temp = temp->next;

	}

}

int SnakeList::getrow() {

	return curr_r;
}

int SnakeList::getcol() {

	return curr_c;
}


void SnakeList::setcheck(int num) {

	checking = num;

}

int SnakeList::getcheck() {

	return checking;

}

