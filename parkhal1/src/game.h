/**
 * @file game.h
 * @brief This class handles everything happening while the engine is running: parsing, loading, saving and playing.
 * @author Alexandra Parkhomenko
 * @bugs No known bugs.
 */
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <unistd.h>
#include <memory>
#include "creature.h"
#include "location.h"
#include "event.h"
#include "dictionary.h"

using namespace std ;

class Game {
  public :
    /**
     * @brief Constuctor for a game.
     * @param started
     */
    Game( const bool & started ) ;
    ~Game() ;
    /**
     * @brief Method that looks for a saving in src/saving, parses it and starts a game from the moment it has been saved at.
     * @return void
     */
    void Load() ;
    /**
     * @brief Method that handles the game cycle.
     * @return void
     */
    void Play() ;
    /**
     * @brief Method that creates a main character and saves a pointer to it.
     * @return void
     */
    void CreateCharacter() ;
    /**
     * @brief Method that waits for player's interaction: open inventory, save and exit or proceed; then clears a console.
     * @return bool
     */
    bool ClearScreen() ;
    /**
     * @brief Method that loads a world file( the required structure is shown in examples/worldFile ) from filePath, sends it to parser and then starts a game.
     * @param filePath
     * @return void
     */
    void LoadWorld( const string & filePath ) ;
    /**
     * @brief Method that works with a copy of a world file: returns a next line to parse and erases it.
     * @param worldFile
     * @return string
     */
    string getNextLine( string & worldFileCopy ) ;
    string getLine( string & saving ) ;
    /**
     * @brief Method that parses the world file: puts each line at its place.
     * @return void
     */
    void ParseWorldFile() ;
    shared_ptr<NPC> ParseNPC( string & worldFileCopy ) ;
    shared_ptr<Mob> ParseMob( string & worldFileCopy ) ;
    shared_ptr<Boss> ParseBoss( string & worldFileCopy ) ;
    shared_ptr<Event> ParseEvent( string & worldFileCopy ) ;
    void ParseLocation( string & worldFileCopy ) ;
    /**
     * @brief Method that saves the game current state to src/saving.
     * @return void
     */
    void Save() ;
    /**
     * @brief Method that says if the game has started or not.
     * @return bool
     */
    bool isStarted() const ;

  private :
    bool started ; /*!< if the game has started or not */
    int numberOfLocations ; /*!< number of locations in the initial game file */
    vector<shared_ptr<Location>> locations ; /*!< all the locations which were defined in the game file */
    shared_ptr<MainCharacter> mainCharacter ; /*!< player's character */
    string worldFile ; /*!< initial game file ( stored to save the game properly ) */
    string mainGreeting ; /*!< frase to greet a player every time he enters this particular world */
    string mainGoodbye ; /*!< ending frase which appears after the player finished all the locations */
} ;
