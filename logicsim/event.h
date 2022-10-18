#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
    bool operator() (Event* first, Event* second) {
        bool firstHasPriority = false;
        if (first->time < second->time) {
            // first has priority
            firstHasPriority = true;
        } 

        return firstHasPriority;
        
    } 
} EventLess;
	
#endif
