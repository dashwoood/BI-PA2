#include <cstdio>
#include <iostream>
#include <list>
#ifndef LOCATION
#define LOCATION
#include "event.h"
#include "creature.h"

using namespace std ;

class Location {
public:
  Location() ;
  ~Location() ;
  string getName() const ;
  string getWeclome() const ;
private:
  list<Creature> creatures ;
  list<Event> events ;
  string name ;
  string welcome ;
} ;

#endif
