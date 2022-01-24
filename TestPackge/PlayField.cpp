//
// Created by paul on 22.01.2022.
//

#include "PlayField.h"

#include <utility>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

void PlayField::addPair(std::string key, std::string value) {
    metaData.push_back(new MetaData(std::move(key), std::move(value)));
}

MetaData *PlayField::getPair(const std::string &key) {
    MetaData *rValue = nullptr;
    for (MetaData *m: metaData) {
        if (m->getKey() == key) {
            rValue = m;
        }
    }
    return rValue;
}

void PlayField::deletePair(const std::string &key) {
    for (int i = 0; i < metaData.size(); i++) {
        if (metaData[i]->getKey() == key) {
            metaData.erase(metaData.begin() + i);
        }
    }
}

int PlayField::write(std::string fileName) {
    std::ofstream out;
    out.open(fileName);
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    out << "TestGame" << "\n";
    out << "Erstellt am: " << std::put_time(&tm, "%d-%m-%Y") << "\n";
    out << "Spielfeld: " << name << "\n";
    out << "Anzahl Infos: " << metaData.size() << "\n";
    for (MetaData *m: metaData) {
        out << m->getKey() << ": " << m->getValue() << "\n";
    }
    out << "Anzahl Zeilen: " << zeilen << "\n";
    out << "Anzahl Spalten: " << spalten << "\n";
    for (int i = 0; i < zeilen; i++) {
        for (int k = 0; k < spalten; k++) {
            out << field[i][k] << " ";
        }
    }
    return 0;
}

int PlayField::read(std::string fileName) {
    std::ifstream in;
    in.open(fileName);
    char buff[1000] = "";
    in.getline(buff, sizeof buff);
    in.getline(buff, sizeof buff);
    in.getline(buff, sizeof buff);
    std::string playerName, numberOfPairs;
    int numberPais_int;
    std::istringstream ss(buff);
    std::getline(ss, playerName, ' ');
    std::getline(ss, playerName, '\n');
    in.getline(buff, sizeof buff);
    std::stringstream ss1(buff);
    std::getline(ss1, numberOfPairs, ':');
    std::getline(ss1, numberOfPairs, ' ');
    std::getline(ss1, numberOfPairs, '\n');
    numberPais_int = std::stol(numberOfPairs);
    for (int i = 0; i < numberPais_int; i++) {
        std::string key, value;
        in.getline(buff, sizeof buff);
        std::stringstream ss2(buff);
        std::getline(ss2, key, ':');
        std::getline(ss2, value, ' ');
        std::getline(ss2, value, '\n');
        metaData.push_back(new MetaData(key, value));
    }
    in.getline(buff, sizeof buff);
    std::string myCols, myRows;
    std::stringstream ss3(buff);
    std::getline(ss3, myCols, ':');
    std::getline(ss3, myCols, ' ');
    std::getline(ss3, myCols, '\n');
    in.getline(buff, sizeof buff);
    std::stringstream ss4(buff);
    std::getline(ss4, myRows, ':');
    std::getline(ss4, myRows, ' ');
    std::getline(ss4, myRows, '\n');
    int c_int, r_int;
    c_int = std::stol(myCols);
    r_int = std::stol(myRows);
    in.getline(buff, sizeof buff);
    std::stringstream ss5(buff);
    std::string valueBuff;
    for (int i = 0; i < c_int; i++) {
        for (int k = 0; k < r_int; k++) {
            std::getline(ss5, valueBuff, ' ');
            int value = std::stol(valueBuff);
            field[i][k] = value;
        }
    }
    return 0;
}

void PlayField::addElement(int zeile, int spalte, int value) {
    field[zeile][spalte] = value;
}

int PlayField::getElement(int spalte, int zeile) {
    return field[zeile][spalte];
}

int PlayField::deleteMetaDataElement(int index) {
    MetaData *m = metaData.at(index);
    delete m;
    metaData.erase(metaData.begin() + index);
    return 0;
}
