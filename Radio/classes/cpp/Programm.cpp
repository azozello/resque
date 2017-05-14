//
// Created by azozello on 14.05.17.
//

#include <fstream>
#include <iostream>
#include "../h/Programm.h"

Programm::Programm(const vector<Song> &songs, const vector<Advertise> &advertises) : songs(songs),
                                                                                     advertises(advertises) {}
Programm::Programm() {}

const vector<Song> &Programm::getSongs() const {
    return songs;
}

void Programm::setSongs(const vector<Song> &songs) {
    Programm::songs = songs;
}

const vector<Advertise> &Programm::getAdvertises() const {
    return advertises;
}

void Programm::setAdvertises(const vector<Advertise> &advertises) {
    Programm::advertises = advertises;
}

void Programm::addSong(Song song) {
    songs.insert(songs.end(), song);
}

void Programm::addAdvertise(Advertise advertise) {
    advertises.insert(advertises.end(), advertise);
}

void Programm::deleteSong(Song song){
    vector<Song> newVector;
    for (int i = 0; i < songs.size(); ++i) {
        if (song.getPath() != songs[i].getPath() &&
                song.getPrice() != songs[i].getPrice() &&
                song.getAuthor() != songs[i].getAuthor()){
            newVector.insert(newVector.end(), song);
        }
    }
    setSongs(newVector);
}

void Programm::deleteAdvertise(Advertise advertise) {
    vector<Advertise> newVector;
    for (int i = 0; i < songs.size(); ++i) {
        if (advertise.getPath() != songs[i].getPath() &&
                advertise.getPrice() != songs[i].getPrice() &&
                advertise.getAuthor() != songs[i].getAuthor()){
            newVector.insert(newVector.end(), advertise);
        }
    }
    setAdvertises(newVector);
}

void Programm::getProgramm() {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Radio/files/programm.txt",ios::app);
    for (int i = 0; i < songs.size(); ++i) {
        ifstream file("/home/azozello/CLionProjects/OutSource/Radio/files/songs/"+songs[i].getPath());
        fout<<"Author: "<<songs[i].getAuthor()<<" Price: "<<songs[i].getPrice()<<endl;
        cout<<"Author: "<<songs[i].getAuthor()<<" Price: "<<songs[i].getPrice()<<endl;
        while (file){
            string str;
            getline(file, str);
            fout<<str<<endl;
            cout<<str<<endl;
        }
        fout<<endl;
        cout<<endl;
        file.close();
    }
    for (int i = 0; i < advertises.size(); ++i) {
        ifstream file("/home/azozello/CLionProjects/OutSource/Radio/files/advertises/"+advertises[i].getPath());
        fout<<"Author: "<<advertises[i].getAuthor()<<" Price: "<<advertises[i].getPrice()<<endl;
        cout<<"Author: "<<advertises[i].getAuthor()<<" Price: "<<advertises[i].getPrice()<<endl;
        while (file){
            string str;
            getline(file, str);
            fout<<str<<endl;
            cout<<str<<endl;
        }
        fout<<endl;
        cout<<endl;
        file.close();
    }
    fout.close();
}