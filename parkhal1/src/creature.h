#include <cstdio>
#include <iostream>
#include <list>
#include "item.h"
#ifndef CREATURE
#define CREATURE

using namespace std ;

class Creature {
public:
  Creature() ;
  ~Creature() ;
  void Die() ;
  string getName() const ;
  virtual int countPower() ;
  virtual void Speak() ;
private:
  string name ;
} ;

class MainCharacter: public Creature {
public:
  void Create() ;
  list<Item> getInventory() const ;
private:
  list<Item> inventory ;
} ;

class NPC: public Creature {

} ;

class Boss : public Creature {

} ;

class Mob : public Creature {

} ;

#endif
