#include <cstdio>
#include <iostream>
#include <list>
#include <vector>
#include "creature.h"
#include "location.h"
#include "event.h"

using namespace std ;

class Game {
  public :
    Game () ;
    ~Game () ;
    void Load () ;
    void LoadWorld () ;
    vector<string> TokenizeInput( string & input ) ;
    void ParseWorldFile() ;
    void Save () ;
    bool isStarted() const ;
    void Go() ;

  private :
    bool started ;
    list<Location> locations ;
    MainCharacter mainCharacter ;
} ;
