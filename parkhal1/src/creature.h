/**
 * @file creature.h
 * @brief Class Creature represents a living being in the game world, derivates four types: MainCharacter(player), NPC, Boss and Mob.
 * @author Alexandra Parkhomenko
 * @bugs No known bugs.
 */
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <memory>
#include <cmath>
#include "dictionary.h"
#include "item.h"
#ifndef CREATURE
#define CREATURE

using namespace std ;

class Creature {
public:
  /**
   * @brief Empty constructor for Creature.
   */
  Creature() ;
  virtual ~Creature() ;
  /**
   * @brief Method that states that the creature has died.
   * @return void
   */
  virtual void Die() ;
  /**
   * @brief Creature's name getter.
   * @return string
   */
  string getName() const ;
  /**
   * @brief Creature's name setter.
   * @param name
   * @return void
   */
  void setName( const string & name ) ;
  /**
   * @brief Method that returns current power of the creature.
   * @return int
   */
  virtual int countPower() const ;
  /**
   * @brief Creature's HP getter.
   * @return int
   */
  int getHP() const ;
  /**
   * @brief Creature's HP setter.
   * @param HP
   * @return void
   */
  void setHP( const int & HP ) ;
  /**
   * @brief Method that increases Creatures's HP by 1.
   * @return void
   */
  void increaseHP() ;
  /**
   * @brief Method that decreases Creature's HP by 1.
   * @return void
   */
  void decreaseHP() ;
  /**
   * @brief Method that says wether the Creature is dead or not (for saving purposes).
   * @return  bool
   */
  bool isDead() const ;
protected:
  string name ; /*!< Creature's name */
  int HP ; /*!< Creature's HP */
  bool dead ; /*!< If creature is already dead or not */
} ;

class MainCharacter: public Creature {
public:
  MainCharacter() ;
  /**
   * @brief Constructor for MainCharacter(player).
   * @param name, mClass, HP, luck
   */
  MainCharacter( const string & name, const string & mClass, const int & HP, const int & luck ) ;
  /**
   * @brief Method that handles the fight between the MainCharacter and other creatures.
   * @param enemy, head
   * @return void
   */
  void Fight( shared_ptr<Creature> enemy, const string & head ) ;
  /**
   * @brief Player's inventory getter.
   * @return vector<shared_ptr<Item>>
   */
  vector<shared_ptr<Item>> getInventory() const ;
  /**
   * @brief Method that returns current power of the player.
   * @return int
   */
  int countPower() const ;
  /**
   * @brief Method that selects a class(mage, knight, rogue) for main character.
   * @param mClass
   * @return void
   */
  void selectCLass( int mClass ) ;
  /**
   * @brief Player's class getter.
   * @return string
   */
  string getClass() const ;
  /**
   * @brief Method that adds an item to player's inventory.
   * @param item
   * @return void
   */
  void addItemToInventory( shared_ptr<Item> item ) ;
  /**
   * @brief Method that erases the first item in player's inventory.
   * @return void
   */
  void loseItem() ;
  /**
   * @brief Method that prints player's inventory and stats on the console.
   * @return void
   */
  void ShowInventory() const ;
  /**
   * @brief Player's luck getter.
   * @return double
   */
  double getLuck() const ;
  /**
   * @brief Method that increases player's luck by 0.5.
   * @return void
   */
  void increaseLuck() ;
  /**
   * @brief Method that decreases player's luck by 0.5.
   * @return void
   */
  void decreaseLuck() ;
  /**
   * @brief Method that kills a player and ends the game.
   * @return void
   */
  void Die() ;
private:
  vector<shared_ptr<Item>> inventory ; /*!< Player's inventory */
  string mClass ; /*!< Player's class */
  double luck ; /*!< Player's luck */
} ;

class NPC: public Creature {
public:
  /**
   * @brief NPC's greeting setter.
   * @param greeting
   * @return void
   */
  void setGreeting( const string & greeting ) ;
  /**
   * @brief NPC's greeting getter.
   * @return string
   */
  string getGreeting() const ;
  /**
   * @brief Method that states that the NPC has already greeted the player(for saving purposes).
   * @return void
   */
  void Greet() ;
  /**
   * @brief Method that says whether the NPC has already greeted the player(for saving purposes).
   * @return bool
   */
  bool HasGreeted() const ;
  /**
   * @brief NPC's goodBye setter.
   * @param goodBye
   * @return void
   */
  void setGoodBye( const string & goodBye ) ;
  /**
   * @brief NPC's goodBye getter.
   * @return string
   */
  string getGoodBye() const ;
  /**
   * @brief NPC's thankYou setter.
   * @param thankYou
   * @return void
   */
  void setThankYou( const string & thankYou ) ;
  /**
   * @brief NPC's thankYou getter.
   * @return string
   */
  string getThankYou() const ;
  /**
   * @brief NPC's reward setter.
   * @param reward
   * @return void
   */
  void setReward( shared_ptr<Item> reward ) ;
  /**
   * @brief NPC's reward getter.
   * @return shared_ptr<Item>
   */
  shared_ptr<Item> getReward() const ;
private:
  string greeting ; /*!< a description of the way to the NPC and his greeting words */
  string goodBye ; /*!< NPC's words when you agree to help */
  string thankYou ; /*!< NPC's words when you return to him after defeating the Boss */
  shared_ptr<Item> reward ; /*!< an item which the player gets after returning to the NPC */
  bool hasGreeted ; /*!< if the NPC has already met a player or not */
} ;

class Boss : public Creature {
public:
  /**
   * @brief Boss's threat setter.
   * @param threat
   * @return void
   */
  void setThreat( const string & threat ) ;
  /**
   * @brief Boss's threat getter.
   * @return string
   */
  string getThreat() const ;
  /**
   * @brief Boss's deathFrase setter.
   * @param deathFrase
   * @return void
   */
  void setDeathFrase( const string & deathFrase ) ;
  /**
   * @brief Boss's deathFrase getter.
   * @return string
   */
  string getDeathFrase() const ;
  /**
   * @brief Boss's reward setter.
   * @param reward
   * @return void
   */
  void setReward( shared_ptr<Item> reward ) ;
  /**
   * @brief Boss's reward getter.
   * @return shared_ptr<Item>
   */
  shared_ptr<Item> getReward() const ;
private:
  string threat ; /*!< what the player sees on the console when he meets the Boss */
  string deathFrase ; /*!< what the player sees on the console when he defeats the Boss */
  shared_ptr<Item> reward ; /*!< an item which the player gets after defeating the Boss */
} ;

class Mob : public Creature {
public:
  /**
   * @brief Mob's description setter.
   * @param description
   * @return void
   */
  void setDescription( const string & description ) ;
  /**
   * @brief Mob's description getter.
   * @return string
   */
  string getDescription() const ;
private:
  string description ; /*!< what the player sees on the console when he meets the Mob */
} ;

#endif
