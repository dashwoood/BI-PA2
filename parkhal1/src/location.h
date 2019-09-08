/**
 * @file location.h
 * @brief This class is a storage for creatures and events of which the game location consists.
 * @author Alexandra Parkhomenko
 * @bugs No known bugs.
 */
#include <cstdio>
#include <iostream>
#include <list>
#include <queue>
#include "event.h"
#include "creature.h"
#include "dictionary.h"
#ifndef LOCATION
#define LOCATION

using namespace std ;

class Location {
public:
  /**
   * @brief Constructor for Location.
   * @param name
   */
  Location( const string & name ) ;
  ~Location() ;
  /**
   * @brief Method that checks wether the player has already finished the location.
   * @return bool
   */
  bool isFinished() const ;
  /**
   * @brief Method that states that the location has been already finished.
   * @return void
   */
  void Finish() ;
  /**
   * @brief Location's name getter.
   * @return string
   */
  string getName() const ;
  /**
   * @brief Location's welcome frase getter.
   * @return string
   */
  string getWeclome() const ;
  /**
   * @brief Method that returns a pointer to the Locations's main Boss.
   * @return shared_ptr<Boss>
   */
  shared_ptr<Boss> getBoss() const ;
  /**
   * @brief Method that returns a pointer to the Locations's NPC.
   * @return shared_ptr<NPC>
   */
  shared_ptr<NPC> getNPC() const ;
  /**
   * @brief Method that returns an initial mob's count.
   * @return int
   */
  int getMobsNumber() const ;
  /**
   * @brief Method that returns an initial event's count.
   * @return int
   */
  int getEventsNumber() const ;
  /**
   * @brief Locations's welcome frase setter.
   * @param welcome
   * @return void
   */
  void setWelcome( const string & welcome ) ;
  /**
   * @brief Locations's NPC setter.
   * @param npc
   * @return void
   */
  void setNPC( shared_ptr<NPC> npc ) ;
  /**
   * @brief Locations's Boss setter.
   * @param boss
   * @return void
   */
  void setBoss( shared_ptr<Boss> boss ) ;
  /**
   * @brief Locations's initial mobs count setter.
   * @param mobsNumber
   * @return void
   */
  void setMobsNumber( const int & mobsNumber ) ;
  /**
   * @brief Locations's initial events count setter.
   * @param eventsNumber
   * @return void
   */
  void setEventsNumber( const int & eventsNumber ) ;
  /**
   * @brief Method that adds a new mob to the Location.
   * @param mob
   * @return void
   */
  void addMob( shared_ptr<Mob> mob ) ;
  /**
   * @brief Method that adds a new event to the location.
   * @param event
   * @return void
   */
  void addEvent( shared_ptr<Event> event ) ;
  /**
   * @brief Method that deletes the first mob in the queue.
   * @return void
   */
  void popMob() ;
  /**
   * @brief Method that deletes the first event in the queue.
   * @return void
   */
  void popEvent() ;
  /**
   * @brief Location's mobs getter.
   * @return queue<shared_ptr<Mob>>
   */
  queue<shared_ptr<Mob>> getMobs() const ;
  /**
   * @brief Location's events getter.
   * @return queue<shared_ptr<Event>>
   */
  queue<shared_ptr<Event>> getEvents() const ;
private:
  shared_ptr<NPC> npc ; /*!< location's NPC: each location has only one */
  shared_ptr<Boss> boss ; /*!< locations's Boss: each location has only one */
  queue<shared_ptr<Mob>> mobs ; /*!< location's mobs: the amount is defined in the world file */
  queue<shared_ptr<Event>> events ; /*!< location's events: the amount is defined in the world file */
  string name ; /*!< location's name */
  string welcome ; /*!< location's welcome frase */
  int mobsNumber ; /*!< initial number of mobs (for parsing purposes) */
  int eventsNumber ; /*!< initial number of events (for parsing purposes) */
  bool finished ; /*!< if the player has already finished the location or not */
} ;

#endif
