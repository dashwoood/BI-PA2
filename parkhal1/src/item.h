#include <cstdio>
#include <iostream>
#ifndef ITEM
#define ITEM

using namespace std ;

class Item {
public:
  Item() ;
  ~Item() ;
  void Destroy() ;
  int getPower() const ;
  string getName() const ;
private:
  string name ;
  int power ;
} ;

class QuestItem: public Item {

} ;

class Weapon: public Item {

} ;

#endif
