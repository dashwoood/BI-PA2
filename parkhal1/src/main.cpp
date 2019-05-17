#include <cstdio>
#include <iostream>
#include <string>
#include "dictionary.h"
#include "game.h"

using namespace std ;

int main ( int argc, char * argv[] ) {
  cout << WELCOME << CREATE_A_NEW_GAME << LOAD_GAME << DEMO << EXIT ;
  Game game = Game() ;

  while ( !game.isStarted() ) {
    string input ;
    cin >> input ;

    if ( input == "1" || input == "start" )
        game.LoadWorld() ;
    else if ( input == "2" || input == "load" )
        game.Load() ;
    else if ( input == "0" || input == "exit" ) {
        printf("\033c" ) ;
        cout << BYE ;
        return 0 ;
    } else if ( input == "3" || input == "demo" ) {
        // no demo yet :)
        cout << "'DEMO ..'" << endl ;
        return 0 ;
    } else {
        printf("\033c" ) ;
        cout << WELCOME << CREATE_A_NEW_GAME << LOAD_GAME << DEMO << EXIT ;
        cout << ERROR ;
    }
  }

  return 0 ;
}
