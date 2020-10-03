#ifndef Room_H
#define Room_H
#include <iostream>
#include "Bat.h"
#include "Wumpus.h"
#include "Gold.h"
#include "Pit.h"
using namespace std;

class Room{
	private:
		Event* eptr;
		bool starting_room;
		bool has_adventurer;
	public:
		Room();
		~Room();
		Room(const Room&);
		Room& operator = (const Room&);
		void set_starting_room();
		bool check_adventurer();
		bool check_starting();
		void move_adventurer(bool);
		void set_event(int);
		Event* get_eptr() const;
};

#endif
