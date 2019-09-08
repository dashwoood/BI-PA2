#include "creature.h"

using namespace std ;

Creature::Creature()
{
  this->dead = false ;
}

MainCharacter::MainCharacter() : Creature()
{}

MainCharacter::MainCharacter( const string & name, const string & mClass, const int & HP, const int & luck ) : Creature()
{
  this->name = name ;
  this->mClass = mClass ;
  this->HP = HP ;
  this->luck = luck ;
}

Creature::~Creature()
{}

void MainCharacter::Die()
{
  printf("\033c") ;
  cout << DEATH ;
  exit(0) ;
}

void Creature::Die()
{
  this->dead = true ;
}

bool NPC::HasGreeted() const
{
  return this->hasGreeted ;
}

bool Creature::isDead() const
{
  return this->dead ;
}

string MainCharacter::getClass() const
{
  return this->mClass ;
}

string Creature::getName() const
{
  return this->name ;
}

void Creature::setName( const string & name )
{
  this->name = name ;
}

int Creature::getHP() const
{
  return this->HP ;
}

void Creature::setHP( const int & HP )
{
  this->HP = HP ;
}

int Creature::countPower() const
{
  int power = 11 ;
  srand (time(NULL)) ;
  double random = rand() % 25 + 2.5 ;

  power += floor(random/2.5) ;

  return power ;
}

int MainCharacter::countPower() const
{
  int power = 6 ;
  for ( auto & item : this->inventory )
    power += item->getPower() ;

  if ( luck != 0 )
    power *= luck ;

  return power ;
}

void MainCharacter::Fight( shared_ptr<Creature> enemy, const string & head )
{
  int enemyPower = enemy->countPower() * enemy->getHP() ;
  cout << FIGHT ;
  cout << "       YOU      ENEMY" << endl ;
  cout << "HP:    " << this->getHP()      << "        " << enemy->getHP() << endl ;
  cout << "POWER: " << this->countPower() << "       "  << enemyPower    << endl ;

  cout << ATTACK ;
  string input ;
  cin >> input ;

  //Player may choose to heal himself during the battle
  if ( input == "i" || input == "I" )
  {
    unsigned i = 0 ;
    for ( ; i < this->inventory.size() ; i++ )
    {
      if ( this->inventory[i]->isUsable() )
      {
        this->inventory.erase(inventory.begin() + i) ;
        this->increaseHP() ;
        printf("\033c") ;
        cout << head << endl ;
        break ;
      }
    }

    if ( i  == this->inventory.size() ) {
      printf("\033c") ;
      cout << head << endl ;
      cout << NO_ITEM_TO_USE ;
    }

  } else if ( input == "l" || input == "L" )
  {
    srand (time(NULL)) ;
    int random = rand() % 5 + 1 ;
    printf("\033c") ;
    cout << head << endl ;

    //If the player chooses to test his luck, he may take or do damage
    //The result will depend on both: actual luck and character's luck number
    if ( this->getLuck() > random  )
    {
      enemy->decreaseHP() ;
      cout << SUCCESS ;
    } else
    {
      this->decreaseHP() ;
      this->increaseLuck() ;
      cout << FAIL ;
    }
  } else
  {
    //Option "Attack" is simple - the most powerful wins
    if ( this->countPower() > enemyPower )
      enemy->decreaseHP() ;
    else
    {
      this->decreaseHP() ;
      this->increaseLuck() ;
    }
    printf("\033c") ;
    cout << head << endl ;
  }

  //The fight is not going to end unless one of them dies
  if ( enemy->getHP() != 0 )
    Fight( enemy, head ) ;
}

vector<shared_ptr<Item>> MainCharacter::getInventory() const
{
  return this->inventory ;
}

void MainCharacter::selectCLass( int mClass )
{
  map<string, string> defaultWeapons = {{"Mage", "Wooden staff"},{"Knight", "Wooden blade"},{"Rogue", "Wooden Bow"}} ;
  switch( mClass )
  {
    case 1 :  this->mClass = "Mage" ;
              this->luck = 1.5 ;
              break ;
    case 2 :  this->mClass = "Knight" ;
              this->luck = 1.2 ;
              break ;
    case 3 :  this->mClass = "Rogue" ;
              this->luck = 2.4 ;
              break ;
    default : this->mClass = "Mage" ;
              this->luck = 1.7 ;
  }

  shared_ptr<Weapon> weapon( new Weapon(defaultWeapons[this->mClass], 5 )) ;
  this->addItemToInventory(weapon) ;
}

void MainCharacter::ShowInventory() const
{
  cout << "Name: " << this->getName() << endl << "Class: " << this->mClass << endl << "HP: " << this->getHP() << endl << endl ;

  for( unsigned i = 0 ; i < this->inventory.size() ; i++ )
    cout << i+1 << ": " << inventory[i]->getName() << endl ;
}

void MainCharacter::loseItem()
{
  //if player has at least one item, he is going to lose the first one he aquired
  if( !this->inventory.empty() )
    this->inventory.erase( this->inventory.begin() ) ;
}

void MainCharacter::addItemToInventory( shared_ptr<Item> item )
{
  this->inventory.push_back(item) ;
}

double MainCharacter::getLuck() const
{
  return this->luck ;
}

void MainCharacter::increaseLuck()
{
  if ( this->luck < 4.5 )
    this->luck+= 0.5 ;
}

void Creature::increaseHP()
{
  this->HP++ ;
}

void MainCharacter::decreaseLuck()
{
  if( this->luck < 0.5 )
    this->luck = 0 ;
  else
    this->luck-= 0.5 ;
}

void Creature::decreaseHP()
{
  this->HP-- ;
  if ( this->HP == 0 )
    Die() ;
}

void NPC::setGreeting( const string & greeting )
{
    this->greeting = greeting ;
    this->hasGreeted = false ;
}

string NPC::getGreeting() const
{
  return this->greeting ;
}

void NPC::Greet()
{
  this->hasGreeted = true ;
}

void NPC::setGoodBye( const string & goodBye )
{
  this->goodBye = goodBye ;
}

string NPC::getGoodBye() const
{
  return this->goodBye ;
}

void NPC::setThankYou( const string & thankYou )
{
  this->thankYou = thankYou ;
}

string NPC::getThankYou() const
{
  return this->thankYou ;
}

void NPC::setReward( shared_ptr<Item> reward )
{
  this->reward = reward ;
}

shared_ptr<Item> NPC::getReward() const
{
  return this->reward ;
}

void Mob::setDescription( const string & description )
{
  this->description = description ;
}

string Mob::getDescription() const
{
  return this->description ;
}

void Boss::setThreat( const string & threat )
{
  this->threat = threat ;
}

string Boss::getThreat() const
{
  return this->threat ;
}

void Boss::setDeathFrase( const string & deathFrase )
{
  this->deathFrase = deathFrase ;
}

string Boss::getDeathFrase() const
{
  return this->deathFrase ;
}

void Boss::setReward( shared_ptr<Item> reward )
{
  this->reward = reward ;
}

shared_ptr<Item> Boss::getReward() const
{
  return this->reward ;
}
