#include <cstdio>
#include <iostream>
#include "creature.h"
#include "dictionary.h"
#include "item.h"

using namespace std ;

Creature::Creature(){}

void Creature::Die() {}

string Creature::getName() const {
  return this->name ;
}

int Creature::countPower() {
  int power = 0 ;
  //return power based on luck, weapon power and other parameters 
  return power ;
}

void Creature::Speak() {}

list<Item> MainCharacter::getInventory() const {
  return this->inventory ;
}
