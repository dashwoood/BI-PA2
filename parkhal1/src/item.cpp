#include <cstdio>
#include <iostream>
#include "item.h"
#include "dictionary.h"

using namespace std ;

Item::Item(){}

void Item::Destroy() {}

int Item::getPower() const {
  return this->power ;
}

string Item::getName() const {
  return this->name ;
}
