#include <cstdio>
#include <iostream>
#include "location.h"

using namespace std ;

Location::Location(){}

Location::~Location(){}

string Location::getName() const {
  return this->name ;
}

string Location::getWeclome() const {
    return this->welcome ;
}
