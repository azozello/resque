//
// Created by azozello on 25.05.17.
//

#ifndef TANYA_MANAGER_H
#define TANYA_MANAGER_H

#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
#include <array>
#include "Human.h"
#include "Track.h"

using namespace std;

class Manager : public Human {
private:
    string password;
    void saveTracks(vector<Track> tracks);

public:
    Manager();

    const string &getPassword() const;

    vector<Track> loadTracks();

    void changeTrack(int index, Track track);

    void setPassword(const string &password);
};


#endif //TANYA_MANAGER_H
