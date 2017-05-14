//
// Created by azozello on 14.05.17.
//

#ifndef RADIO_PROGRAMM_H
#define RADIO_PROGRAMM_H

#include <vector>
#include "Song.h"
#include "Advertise.h"

using namespace std;

class Programm {
private:
    vector<Song> songs;
    vector<Advertise> advertises;
public:
    Programm();

    Programm(const vector<Song> &songs, const vector<Advertise> &advertises);

    const vector<Song> &getSongs() const;
    const vector<Advertise> &getAdvertises() const;

    void setSongs(const vector<Song> &songs);
    void setAdvertises(const vector<Advertise> &advertises);

    void addSong(Song song);
    void addAdvertise(Advertise advertise);

    void deleteSong(Song song);
    void deleteAdvertise(Advertise advertise);

    void getProgramm();
};


#endif //RADIO_PROGRAMM_H
