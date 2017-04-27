
#include "Game.h"

Game::Game(const string &name, float price, int players) : name(name), price(price), players(players) {}

Game::Game() {}

Game::~Game() {}

int Game::play() {}

const string &Game::getName() const {
    return name;
}

void Game::setName(const string &name) {
    Game::name = name;
}

float Game::getPrice() const {
    return price;
}

void Game::setPrice(float price) {
    Game::price = price;
}

int Game::getPlayers() const {
    return players;
}

void Game::setPlayers(int players) {
    Game::players = players;
}
