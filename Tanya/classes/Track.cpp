//
// Created by azozello on 24.05.17.
//

#include "Track.h"

Track::Track() {}

const vector<Player> &Track::getPlayers() const {
    return players;
}

void Track::setPlayers(const vector<Player> &players) {
    Track::players = players;
}

const string &Track::getName() const {
    return name;
}

void Track::setName(const string &name) {
    Track::name = name;
}

int Track::getAge() const {
    return age;
}

void Track::setAge(int age) {
    Track::age = age;
}
