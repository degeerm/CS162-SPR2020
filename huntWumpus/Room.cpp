#include "Room.h"

using namespace std;

/*********************************************************************
 * ** Description: Default constructor for the room class. Sets the starting
 * ** room to false, has_adventurer to false, and the event pointer to null 
 * ** Parameters: None.
 * ** Pre-Conditions:  None.
 * ** Post-Conditions: Room object is created.
 * *********************************************************************/
Room::Room(){
	starting_room=false;
	has_adventurer = false;
	eptr = NULL;
}

/*********************************************************************
 * ** Description: Destructor for event class; deletes eptr on the heap. 
 * ** Parameters: None.
 * ** Pre-Conditions: Room object has been declared.
 * ** Post-Conditions: If event pointer is not null, it's deleted off the
 * ** heap.
 * *********************************************************************/
Room::~Room(){
	delete eptr;
}

/*********************************************************************
 * ** Description: Copy constructor for the room class. Takes in another
 * ** room object, copies all of the elements over. 
 * ** Parameters: const Room&
 * ** Pre-Conditions: r has been declared elsewhere.
 * ** Post-Conditions: New object is created with values of old object.
 * *********************************************************************/
Room::Room(const Room &r){
	starting_room = r.starting_room;
	has_adventurer = r.has_adventurer;
	if (r.get_eptr() == NULL){	
		eptr =NULL;
	}else{
		set_event(r.get_eptr() -> get_event_num());
	}
}

/*********************************************************************
 * ** Description: Assignment operator overload for room class. Takes in
 * ** another room object, deletes old information on heap.
 * ** Parameters: const &r
 * ** Pre-Conditions: r has been declared elsewhere.
 * ** Post-Conditions: Values of old object are assigned to this one.
 * *********************************************************************/
Room& Room::operator = (const Room &r){
	starting_room = r.starting_room;
	has_adventurer = r.has_adventurer;
	if (r.get_eptr() == NULL){
		delete eptr;
		eptr = NULL;
	}else{
		set_event(r.get_eptr() -> get_event_num());
	}
	return *this;
}

/*********************************************************************
 * ** Description: Takes in an integer to set the event. 0 for wumpus,
 * ** 1 for gold, 2 for bat, 3 for bit, 4 for null (nothing)
 * ** Parameters: int
 * ** Pre-Conditions: int and room object have been declared elsewhere  
 * ** Post-Conditions: Event for room is set to selected object.
 * *********************************************************************/
void Room::set_event(int c){
	delete eptr;
	if (c == 0){
		eptr = new Wumpus();
	}else if (c==1){
		eptr = new Gold();
	}else if(c == 2){
		eptr = new Bat();
	}else if (c == 3){
		eptr = new Pit();
	}else if (c == 4){
		eptr = NULL;
	}
}

/*********************************************************************
 * ** Description: Sets this room as the starting room. Places the adventurer
 * ** there, and sets the room to be the starter.
 * ** Parameters: None.
 * ** Pre-Conditions:  Room object declared elswhere.
 * ** Post-Conditions: Adventurer placed in room, room selected as starter.
 * *********************************************************************/
void Room::set_starting_room(){
	starting_room = true;
	has_adventurer = true;
}

/*********************************************************************
 * ** Description: Returns the event pointer to be used in other classes. 
 * ** Parameters: None.
 * ** Pre-Conditions:  Room object has been declared elsewhere.
 * ** Post-Conditions: Event pointer returned.
 * *********************************************************************/
Event* Room::get_eptr() const{
	return eptr;
}

/*********************************************************************
 * ** Description: Returns whether or not the room is the room with the
 * ** adventurer.
 * ** Parameters: None.
 * ** Pre-Conditions: Room has been declared at some point.
 * ** Post-Conditions: Returns true if room has adventurer, false
 * ** otherwise.
 * *********************************************************************/
bool Room::check_adventurer(){
	if (has_adventurer){
		return true;
	}
	return false;
}

/*********************************************************************
 * ** Description: Returns whether or not the room is the starting room.
 * ** Parameters: None.
 * ** Pre-Conditions: Room has been declared at some point.
 * ** Post-Conditions: Returns true if room is starting room, false
 * ** otherwise.
 * *********************************************************************/
bool Room::check_starting(){
	if(starting_room){
		return true;
	}
	return false;
}

/*********************************************************************
 * ** Description: changes whether or not the adventurer is located
 * ** in the current room. 
 * ** Parameters: bool
 * ** Pre-Conditions: bool and room have been declared elsewhere. 
 * ** Post-Conditions: has_adventurer is changed to a.
 * *********************************************************************/
void Room::move_adventurer(bool a){
	has_adventurer = a;
}
