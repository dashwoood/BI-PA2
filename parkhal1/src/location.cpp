#include "location.h"

using namespace std ;

Location::Location( const string & name ) : name ( name )
{
  this->finished = false ;
}

Location::~Location()
{}

string Location::getName() const
{
  return this->name ;
}

void Location::Finish()
{
  this->finished = true ;
  cout << LEAVE << this->getName() << "." << endl ;
}

bool Location::isFinished() const
{
  return this->finished ;
}

void Location::setWelcome( const string & welcome )
{
  this->welcome = welcome ;
}

string Location::getWeclome() const
{
    return this->welcome ;
}

void Location::setNPC( shared_ptr<NPC> npc )
{
  this->npc = npc ;
}

shared_ptr<NPC> Location::getNPC() const
{
  return this->npc ;
}

shared_ptr<Boss> Location::getBoss() const
{
  return this->boss ;
}

void Location::setMobsNumber( const int & mobsNumber )
{
  this->mobsNumber = mobsNumber ;
}

int Location::getMobsNumber() const
{
  return this->mobsNumber ;
}

void Location::setEventsNumber( const int & eventsNumber )
{
  this->eventsNumber = eventsNumber ;
}

int Location::getEventsNumber() const
{
  return this->eventsNumber ;
}

void Location::popMob()
{
  this->mobs.pop() ;
}

void Location::popEvent()
{
  this->events.pop() ;
}

void Location::addMob( shared_ptr<Mob> mob )
{
  this->mobs.push( mob ) ;
}

void Location::addEvent( shared_ptr<Event> event )
{
  this->events.push( event ) ;
}

queue<shared_ptr<Mob>> Location::getMobs() const
{
  return this->mobs ;
}

queue<shared_ptr<Event>> Location::getEvents() const
{
  return this->events ;
}

void Location::setBoss( shared_ptr<Boss> boss )
{
  this->boss = boss ;
}
