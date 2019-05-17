#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include "game.h"
#include "dictionary.h"

using namespace std ;

Game::Game() {
  this->started = false ;
}

Game::~Game() {}

void Game::Load () {
  printf("\033c" ) ;
  this->started = true ;
  cout << LOADING ;
  // go to savings
  // read and process the last game file
}

void Game::Save() {
  // go to savings
  // write game file
}

vector<string> TokenizeInput( string & input ) {
  vector<string> tokens;

  return tokens ;
}

void Game::ParseWorldFile() {
  // WorldFile preliminary structure & keywords :
  // Greeting: "some text to greet a player"
  // Location 1: "location name"
  // NPC: task, name, speech
  // Boss: power, name, speech
  // Possible events: names, bad/good
  // Location 2: ..
  // Location 3: ..
  // Items: type, power, name ..
}

void Game::LoadWorld() {
  // go to worlds/ repo
  // if empty: ERROR
  // if not: parse world file
  printf("\033c" ) ;
  this->started = true ;
  cout << CREATION_ERROR ;
}

bool Game::isStarted() const {
  return started ;
}
