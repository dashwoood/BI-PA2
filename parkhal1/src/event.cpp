#include <cstdio>
#include <iostream>
#include "event.h"
#include "dictionary.h"

using namespace std ;

Event::Event(){}

void Event::Happen() {}

string Event::getName() const {
  return this->name ;
}
