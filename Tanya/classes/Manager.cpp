//
// Created by azozello on 25.05.17.
//

#include "Manager.h"
#include <algorithm>

inline bool space(char c){
    return std::isspace(c);
}

inline bool notspace(char c){
    return !std::isspace(c);
}

vector<string> split(const string& s){
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = s.begin();
    while(i!=s.end()){
        i = find_if(i, s.end(), notspace);
        iter j= find_if(i, s.end(), space);
        if(i!=s.end()){
            ret.push_back(string(i, j));
            i = j;
        }
    }
    return ret;
}

Manager::Manager() {}

void Manager::saveTracks(vector<Track> tracks) {
    ofstream fout("/home/azozello/CLionProjects/OutSource/Tanya/files/tracks.txt",ios::trunc);
    for (int i = 0; i < tracks.size(); i++) {
        fout<<tracks[i].getName()<<" "<<tracks[i].getAge()<<endl;
    }
    fout.close();
}

void Manager::changeTrack(int index, Track track) {
    vector<Track> old = loadTracks();
    old[index] = track;
    saveTracks(old);
}

vector<Track> Manager::loadTracks() {
    vector<Track> result;
    ifstream file("/home/azozello/CLionProjects/OutSource/Tanya/files/tracks.txt");
    while(file) {
        Track *tempItem = new Track();
        string str;
        getline(file, str);
        vector<string> temp = split(str);
        for (int i = 0; i < temp.size(); i++) {
            if (i==0) {
                tempItem->setName(temp[i]);
            } else if(i==1) {
                tempItem->setAge(stoi(temp[i]));
            }
        }
        if (tempItem->getName()!="") {
            result.insert(result.end(), *tempItem);
        }
    }
    file.close();
    return result;
}

const string &Manager::getPassword() const {
    return password;
}

void Manager::setPassword(const string &password) {
    Manager::password = password;
}
