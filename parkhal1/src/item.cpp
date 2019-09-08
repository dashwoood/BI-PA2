#include "item.h"

using namespace std ;

Item::Item()
{}

Item::Item( const string & name ) : name( name )
{}

Item::~Item()
{}

Weapon::Weapon( const string & name, const int & power ) : Item( name )
{
  this->power = power ;
}

UsableItem::UsableItem( const string & name ) : Item( name )
{}

bool Item::isUsable() const
{
  return false  ;
}

bool UsableItem::isUsable() const
{
  return true ;
}

int Item::getPower() const
{
  return 0 ;
}

int Weapon::getPower() const
{
  return this->power ;
}

string Item::getName() const
{
  return this->name ;
}

void Item::setName( const string & name )
{
  this->name = name ;
}
