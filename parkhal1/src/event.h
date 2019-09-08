/**
 * @file event.h
 * @brief This class represents an event to happen in the game world, derivates two types of events: good and bad for the player.
 * @author Alexandra Parkhomenko
 * @bugs No known bugs.
 */
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "creature.h"
#include "dictionary.h"
#ifndef EVENT
#define EVENT

using namespace std ;

class Event {
public:
  /**
   * @brief Empty constructor for Event.
   */
  Event() ;
  virtual ~Event() ;
  /**
   * @brief Constructor for Event.
   * @param description
   */
  Event( const string & description ) ;
  /**
   * @brief Method that applies an effect of the Event on the player.
   * @param mainCharacter
   * @return void
   */
  virtual void Happen( shared_ptr<MainCharacter> mainCharacter ) ;
  /**
   * @brief Events's description getter.
   * @return string
   */
  string getDescription() const ;
  /**
   * @brief Event's description setter.
   * @param description
   * @return void
   */
  void setDescription( const string & description ) ;
protected:
  string description ; /*!< description of the event */
} ;

class GoodEvent: public Event {
public:
  /**
   * @brief Constructor for GoodEvent.
   * @param description
   */
  GoodEvent( const string & description ) ;
  /**
   * @brief Method that applies a good effect of the Event on the player.
   * @param mainCharacter
   * @return void
   */
  void Happen( shared_ptr<MainCharacter> mainCharacter ) ;
} ;

class BadEvent: public Event {
public:
  /**
   * @brief Constructor for BadEvent.
   * @param description
   */
  BadEvent( const string & description ) ;
  /**
   * @brief Method that applies a bad effect of the Event on the player.
   * @param mainCharacter
   * @return void
   */
  void Happen( shared_ptr<MainCharacter> mainCharacter ) ;
} ;

#endif
