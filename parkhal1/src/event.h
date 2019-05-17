#include <cstdio>
#include <iostream>
#ifndef EVENT
#define EVENT

using namespace std ;

class Event {
public:
  Event() ;
  ~Event() ;
  virtual void Happen() ;
  string getName() const ;
private:
  string name ;
} ;

class GoodEvent: public Event {

} ;

class BadEvent: public Event {

} ;

#endif
