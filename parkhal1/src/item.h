/**
 * @file item.h
 * @brief Class Item represents things player can aquire during the game, derivates two types of collectibles: UsableItem and Weapon.
 * @author Alexandra Parkhomenko
 * @bugs No known bugs.
 */
#include <cstdio>
#include <iostream>
#ifndef ITEM
#define ITEM

using namespace std ;

class Item {
public:
  /**
   * @brief Item empty constructor.
   */
  Item() ;
  virtual ~Item() ;
  /**
   * @brief Item constructor.
   * @param name
   */
  Item( const string & name ) ;
  /**
   * @brief Item's power getter, return 0 for non-weapon item.
   * @return int
   */
  virtual int getPower() const ;
  /**
   * @brief Method that checks whether an item could be used or not.
   * @return bool
   */
  virtual bool isUsable() const ;
  /**
   * @brief Item's name getter.
   * @return string
   */
  string getName() const ;
  /**
   * @brief Item's name setter.
   * @param name
   * @return void
   */
  void setName( const string & name ) ;
protected:
  string name ; /*!< item's name */
} ;

class UsableItem: public Item {
public:
  UsableItem( const string & name ) ;
  /**
   * @brief Method that checks wheher an item could be used or not. Always returns true for UsableItems.
   * @return bool
   */
  bool isUsable() const ;
} ;

class Weapon: public Item {
public:
  /**
   * @brief Constructor for Weapons.
   * @param name, power
   */
  Weapon( const string & name, const int & power ) ;
  /**
   * @brief Weapon's power getter.
   * @return int
   */
  int getPower() const ;
private:
  int power ; /*!< power of the weapon */
} ;

#endif
