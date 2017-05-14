//
// Created by azozello on 14.05.17.
//

#ifndef RADIO_SONG_H
#define RADIO_SONG_H


#include "Item.h"

class Song : public Item{
private:
    string path;
public:
    Song();

    Song(float price, const string &author, const string &path);

    const string &getPath() const;

    void setPath(const string &path);
};


#endif //RADIO_SONG_H
