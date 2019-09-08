#include "event.h"

using namespace std ;

Event::Event()
{}

Event::~Event()
{}

Event::Event( const string & description ) : description (description)
{}

BadEvent::BadEvent( const string & description ) : Event(description)
{}

GoodEvent::GoodEvent( const string & description ) : Event(description)
{}

void Event::Happen( shared_ptr<MainCharacter> mainCharacter )
{}

void GoodEvent::Happen( shared_ptr<MainCharacter> mainCharacter )
{
  srand (time(NULL)) ;
  int random = rand() % 3 + 1 ;

  //all good events have three possible effects: HP++, luck++ or new item to inventory
  switch(random)
  {
    case 1:
      mainCharacter->increaseHP() ;
      cout << INCREASED_HP ;
      break ;
    case 2:
      mainCharacter->increaseLuck() ;
      cout << INCREASED_LUCK ;
      break ;
    case 3:
      shared_ptr<Weapon> weapon( new Weapon("Lucky dagger", 3 )) ;
      mainCharacter->addItemToInventory(weapon) ;
      cout << LUCKY_DAGGER ;
      break ;
  }
}

void BadEvent::Happen( shared_ptr<MainCharacter> mainCharacter )
{
  srand (time(NULL)) ;
  int random = rand() % 3 + 1 ;

  //all bad events have three possible effects: HP--, luck-- or losing an item
  switch(random)
  {
    case 1:
      mainCharacter->decreaseHP() ;
      cout << DECREASED_HP ;
      break ;
    case 2:
      mainCharacter->decreaseLuck() ;
      cout << DECREASED_LUCK ;
      break ;
    case 3:
      mainCharacter->loseItem() ;
      cout << LOST_ITEM ;
      break ;
  }
}

string Event::getDescription() const
{
  return this->description ;
}

void Event::setDescription( const string & description )
{
  this->description = description ;
}
