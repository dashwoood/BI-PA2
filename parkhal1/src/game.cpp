#include "game.h"

using namespace std ;

Game::Game( const bool & started ) : started( started )
{}

Game::~Game()
{}

void Game::Load ()
{
  cout << LOADING ;
  sleep(1.5) ;

  ifstream savingFile ;
  savingFile.open( "src/saving/saving", ios::in ) ;

  if ( savingFile.fail() )
  {
    cout << LOADING_ERROR ;
    return ;
  }

  try
  {
    //splitting saved game into world declaration and its current state
    stringstream str ;
    str << savingFile.rdbuf() ;
    this->worldFile = str.str().substr( 0,  str.str().find_last_of("@") + 2 ) ;
    string saving = str.str().substr( str.str().find_last_of("@") + 2, str.str().length() ) ;

    //first parsing world's declaration and then changing its state into the one written in saving file
    ParseWorldFile() ;
    shared_ptr<MainCharacter> mainCharacter(new MainCharacter(getLine(saving), getLine(saving), stoi(getLine(saving)), stod(getLine(saving)))) ;
    this->mainCharacter = mainCharacter ;

    int inventorySize = stoi(getLine(saving)) ;
    for ( int i = 0 ; i < inventorySize ; i++ )
    {
      string name = getLine(saving) ;
      int power = stoi(getLine(saving)) ;

      if ( power > 0 )
      {
        shared_ptr<Weapon> weapon(new Weapon( name, power )) ;
        this->mainCharacter->addItemToInventory(weapon) ;
      } else
      {
        shared_ptr<UsableItem> item(new UsableItem( name )) ;
        this->mainCharacter->addItemToInventory(item) ;
      }
    }

    string locNum = getLine(saving) ;
    if( locNum == "the end" )
      this->locations.clear() ;
    else
    {
      if( stoi(locNum) > 0 )
      {
        this->locations.erase( this->locations.begin(), this->locations.begin() + stoi(locNum) ) ;
      }

      if( getLine(saving) == "1" )
        this->locations[0]->getNPC()->Greet() ;

      int mobsToPop = stoi(getLine(saving)) ;
      for( int i = 0 ; i < this->locations[0]->getMobsNumber() - mobsToPop ; i++ )
        this->locations[0]->popMob() ;

      int eventsToPop = stoi(getLine(saving)) ;
      for( int i = 0 ; i < this->locations[0]->getEventsNumber() - eventsToPop ; i++ )
        this->locations[0]->popEvent() ;

      if( saving == "1\n" )
        this->locations[0]->getBoss()->Die() ;
    }

  } catch (...)
  {
    cout << PARSING_ERROR ;
    return ;
  }

  printf("\033c") ;
  Play() ;
  this->started = true ;
}

void Game::Save()
{
  ofstream saving("src/saving/saving") ;

  if ( saving.fail() )
  {
    cout << ERROR ;
    return ;
  }

  saving << this->worldFile ;

  //saving the player's current stats and inventory content
  saving << this->mainCharacter->getName() << endl << this->mainCharacter->getClass() << endl << this->mainCharacter->getHP() << endl << this->mainCharacter->getLuck() << endl ;
  saving << this->mainCharacter->getInventory().size() << endl ;
  for ( auto & item : this->mainCharacter->getInventory() )
    saving << item->getName() << endl << item->getPower() << endl ;

  //if the player has finished all the locations and saved the game right before it had to end
  if ( this->locations.back()->isFinished() )
    saving << "the end" << endl ;
  else
  {
    for ( unsigned i = 0 ; i < this->locations.size() ; i++ )
    {
      //saving the information about the last location the player has visited
      if ( !this->locations[i]->isFinished() )
      {
        saving << i + this->numberOfLocations - this->locations.size() << endl ;
        saving << this->locations[i]->getNPC()->HasGreeted() << endl ;
        saving << this->locations[i]->getMobs().size() << endl << this->locations[i]->getEvents().size() << endl ;
        saving << this->locations[i]->getBoss()->isDead() << endl ;
        break ;
      }
    }
  }

  saving.close() ;
  cout << SAVING ;
}

void Game::CreateCharacter() {
  string name ;
  shared_ptr<MainCharacter> mainCharacter(new MainCharacter) ;
  this->mainCharacter = mainCharacter ;
  printf("\033c") ;

  cout << ENTER_NAME ;
  cin >> name ;
  this->mainCharacter->setName( name ) ;

  cout << SELECT_CLASS ;
  string mClass ;
  cin >> mClass ;

  try
  {
    this->mainCharacter->selectCLass( stoi(mClass) ) ;
  } catch(...)
  {
    //if you dont follow the rules - the game decides for you
    this->mainCharacter->selectCLass(1) ;
  }
  //player's HP depends on the game length
  this->mainCharacter->setHP( this->numberOfLocations * 3 + 1 ) ;

  //Knights are not as lucky as other classes, but have a bit more HP
  if ( this->mainCharacter->getClass() == "Knight")
    this->mainCharacter->setHP( ceil(this->mainCharacter->getHP() * 1.5) ) ;

  cout << READY << this->mainCharacter->getName() << "!" << endl ;
}

bool Game::ClearScreen()
{
  cout << PROCEED ;
  string input ;
  cin >> input ;
  printf("\033c") ;

  if ( input == "s" || input == "S" )
  {
    Save() ;
    return false ;
  } else if ( input == "i" || input == "I" )
  {
    this->mainCharacter->ShowInventory() ;
    return ClearScreen() ;
  }

  return true ;
}

void Game::Play()
{
  cout << this->mainGreeting << endl ;
  if ( !ClearScreen() ) return ;

  //Each location has the same structure:
  //meeting the NPC -> fighting mobs & handling the events -> Boss fight -> returning to the NPC
  for ( auto & loc : this->locations )
  {
    //if the game has been loaded and the player has alredy met NPC, he won't meet him again
    if ( !loc->getNPC()->HasGreeted() )
    {
      cout << loc->getWeclome() << endl << endl ;
      loc->getNPC()->Greet() ;

      //Meeting the NPC
      cout << loc->getNPC()->getGreeting() << endl << HELP_OR_NOT ;
      string input ;
      cin >> input ;

      if ( input == "O" || input == "o" )
      {
        printf("\033c") ;
        loc->Finish() ;
        if ( !ClearScreen() ) return ;
        continue ;
      }

      printf("\033c") ;
      cout << loc->getNPC()->getGoodBye() << endl ;
      if ( !ClearScreen() ) return ;
    }

    unsigned eventsNumber = loc->getEvents().size() ;
    unsigned mobsNumber = loc->getMobs().size() ;

    //All the events and mobs declared in WorldFile (mixed so that the player is able to reach the end)
    for ( unsigned i = 0 ; i < max(eventsNumber, mobsNumber) ; i++ )
    {
      if ( !loc->getMobs().empty() )
      {
        cout << loc->getMobs().front()->getDescription() << endl ;
        this->mainCharacter->Fight( loc->getMobs().front(), loc->getMobs().front()->getDescription() ) ;
        loc->popMob() ;
        cout << VICTORY ;
        if ( !ClearScreen() ) return ;
      }

      if ( !loc->getEvents().empty() )
      {
        cout << loc->getEvents().front()->getDescription() << endl ;
        loc->getEvents().front()->Happen( this->mainCharacter ) ;
        loc->popEvent() ;
        if ( !ClearScreen() ) return ;
      }
    }

    //Boss Fight
    if ( !loc->getBoss()->isDead() )
    {
      cout << loc->getBoss()->getThreat() << endl ;
      this->mainCharacter->Fight( loc->getBoss(), loc->getBoss()->getThreat() ) ;
      cout << VICTORY ;
      cout << loc->getBoss()->getDeathFrase() << endl ;
      this->mainCharacter->addItemToInventory( loc->getBoss()->getReward() ) ;
      if ( !ClearScreen() ) return ;
    }

    //Returning to the NPC and leaving the location
    cout << loc->getNPC()->getThankYou() << endl << endl ;
    this->mainCharacter->addItemToInventory( loc->getNPC()->getReward() ) ;
    loc->Finish() ;
    if ( !ClearScreen() ) return ;
  }

  cout << this->mainGoodbye << endl ;
}

string Game::getNextLine( string & worldFileCopy )
{
  string line = worldFileCopy.substr(0, worldFileCopy.find_first_of("@")) ;
  worldFileCopy = worldFileCopy.substr(worldFileCopy.find_first_of("@")+2, worldFileCopy.length()) ;

  if ( line == "" )
    throw length_error("Invalid line.") ;

  return line ;
}

string Game::getLine( string & saving )
{
  string line = saving.substr(0, saving.find_first_of("\n")) ;
  saving = saving.substr(saving.find_first_of("\n")+1, saving.length()) ;

  if ( line == "" )
    throw length_error("Invalid line.") ;

  return line ;
}

shared_ptr<NPC> Game::ParseNPC( string & worldFileCopy )
{
  shared_ptr<NPC> npc(new NPC) ;
  npc->setGreeting(getNextLine(worldFileCopy)) ;
  shared_ptr<Weapon> reward (new Weapon(getNextLine(worldFileCopy), 7)) ;
  npc->setReward(reward) ;
  npc->setGoodBye(getNextLine(worldFileCopy)) ;
  npc->setThankYou(getNextLine(worldFileCopy)) ;

  return npc ;
}

shared_ptr<Mob> Game::ParseMob( string & worldFileCopy )
{
  shared_ptr<Mob> mob(new Mob) ;
  mob->setDescription(getNextLine(worldFileCopy)) ;
  mob->setHP(1) ;

  return mob ;
}

shared_ptr<Boss> Game::ParseBoss( string & worldFileCopy )
{
  shared_ptr<Boss> boss(new Boss) ;
  boss->setThreat(getNextLine(worldFileCopy)) ;
  shared_ptr<UsableItem> reward (new UsableItem(getNextLine(worldFileCopy))) ;
  boss->setReward(reward) ;
  boss->setHP(2) ;
  boss->setDeathFrase(getNextLine(worldFileCopy)) ;

  return boss ;
}

shared_ptr<Event> Game::ParseEvent( string & worldFileCopy )
{
  if( getNextLine(worldFileCopy) == "+" )
  {
    shared_ptr<GoodEvent> event (new GoodEvent(getNextLine(worldFileCopy))) ;
    return event ;
  } else
  {
    shared_ptr<BadEvent> event (new BadEvent(getNextLine(worldFileCopy))) ;
    return event ;
  }
}

void Game::ParseLocation( string & worldFileCopy )
{
  shared_ptr<Location> loc( new Location(getNextLine(worldFileCopy))) ;
  loc->setWelcome(getNextLine(worldFileCopy)) ;
  loc->setNPC(ParseNPC(worldFileCopy)) ;

  loc->setMobsNumber(stoi(getNextLine(worldFileCopy))) ;
  for( int i = 0 ; i < loc->getMobsNumber() ; i++ )
    loc->addMob(ParseMob(worldFileCopy)) ;

  loc->setEventsNumber(stoi(getNextLine(worldFileCopy))) ;
  for( int i = 0 ; i < loc->getEventsNumber() ; i++ )
    loc->addEvent(ParseEvent(worldFileCopy)) ;

  loc->setBoss(ParseBoss(worldFileCopy)) ;
  this->locations.push_back(loc) ;
}

void Game::ParseWorldFile()
{
  string worldFileCopy = this->worldFile ;
  this->mainGreeting = getNextLine(worldFileCopy) ;
  this->numberOfLocations = stoi(getNextLine(worldFileCopy)) ;

  for ( int i = 0 ; i < this->numberOfLocations ; i++ )
    ParseLocation( worldFileCopy ) ;

  this->mainGoodbye = getNextLine(worldFileCopy) ;

  if ( worldFileCopy != "" )
      throw length_error("Invalid worldFile.") ;
}

void Game::LoadWorld( const string & filePath )
{
  ifstream worldFile ;
  worldFile.open( filePath, ios::in ) ;

  if ( worldFile.fail() )
  {
    cout << CREATION_ERROR ;
    return ;
  }

  stringstream str ;
  str << worldFile.rdbuf() ;
  this->worldFile = str.str() ;

  try
  {
    ParseWorldFile() ;
  } catch (...)
  {
    cout << PARSING_ERROR ;
    return ;
  }

  worldFile.close() ;
  this->started = true ;
  CreateCharacter() ;
  if ( !ClearScreen() ) return ;
  Play() ;
}

bool Game::isStarted() const
{
  return started ;
}
