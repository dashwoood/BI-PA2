#include "dictionary.h"

using namespace std ;

extern const string WELCOME           = "Welcome to the Gamebook Engine!\n\n" ;
extern const string CREATE_A_NEW_GAME = "To create a new game --------------------------------- TYPE 1\n" ;
extern const string DEMO              = "To play demo ----------------------------------------- TYPE 3\n\n" ;
extern const string LOAD_GAME         = "To load the last game you played --------------------- TYPE 2\n" ;
extern const string EXIT              = "To exit the engine ----------------------------------- TYPE 0\n\n" ;
extern const string BYE               = "See you soon!\n" ;
extern const string ERROR             = "\nINPUT ERROR\n\n" ;
extern const string LOADING           = "\n... Loading ...\n" ;
extern const string CREATION_ERROR    = "\nMake sure you've put your WorldFile into 'src/world/' and try again.\n\n" ;
extern const string PARSING_ERROR     = "\nMake sure your WorldFile matches the required structure.\n\n" ;
extern const string PROCEED           = "\nTo open your inventory ---------- TYPE I\nTo save and exit ---------------- TYPE S\nTo proceed -----------------------TYPE G\n\n" ;
extern const string ENTER_NAME        = "\nEnter your character's name: \n\n" ;
extern const string SELECT_CLASS      = "\nSelect your character's class: \n\nMage ---- TYPE 1\nKnight -- TYPE 2\nRogue --- TYPE 3\n\n" ;
extern const string READY             = "\nYou are now ready to start your adventure, " ;
extern const string LEAVE             = "You are now leaving the " ;
extern const string HELP_OR_NOT       = "\nTo help ------------------------------------- TYPE H\nTo ignore and proceed to the next location -- TYPE O\n\n";
extern const string FIGHT             = "\n⚔⚔⚔⚔⚔⚔ FIGHT ⚔⚔⚔⚔⚔⚔\n\n" ;
extern const string ATTACK            = "\nTo attack -------------------- TYPE A\nTo test your luck ------------ TYPE L\nTo use item ------------------ TYPE I\n\n" ;
extern const string NO_ITEM_TO_USE    = "\nYou have no item to use!\n\n" ;
extern const string VICTORY           = "\nCongratulations! You won the battle.\n\n" ;
extern const string INCREASED_HP      = "\nYour HP has been increased.\n\n" ;
extern const string INCREASED_LUCK    = "\nYour Luck has been increased.\n\n"  ;
extern const string LUCKY_DAGGER      = "\nYou've got a new item!\n\n" ;
extern const string DECREASED_HP      = "\nYour HP has been decreased.\n\n" ;
extern const string DECREASED_LUCK    = "\nYour Luck has been decreased.\n\n"  ;
extern const string LOST_ITEM         = "\nYou've lost an item.\n\n" ;
extern const string SUCCESS           = "\nSomething happened and the monster took damage..\n\n" ;
extern const string FAIL              = "\nNot lucky enough! You took damage.\n\n" ;
extern const string DEATH             = "☠ ☠ ☠ ☠ ☠ ☠ ☠ YOU DIED ☠ ☠ ☠ ☠ ☠ ☠ ☠\nUnfortunately, you couldn't handle this adventure and your journey is over.\n" ;
extern const string SAVING            = "Your progress has been saved.\n" ;
extern const string LOADING_ERROR     = "\nFailed to load game!\n\n" ;
