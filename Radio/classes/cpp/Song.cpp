//
// Created by azozello on 14.05.17.
//

#include "../h/Song.h"

Song::Song(float price, const string &author, const string &path) : Item(price, author), path(path) {}

Song::Song() {}

const string &Song::getPath() const {
    return path;
}

void Song::setPath(const string &path) {
    Song::path = path;
}
