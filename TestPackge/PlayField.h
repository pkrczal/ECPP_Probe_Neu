//
// Created by paul on 22.01.2022.
//

#ifndef ECPP_PROBE_NEU_PLAYFIELD_H
#define ECPP_PROBE_NEU_PLAYFIELD_H

#include <utility>

#include "MetaData.h"
#include "vector"
#include "FileIO.h"

class PlayField : public FileIO{

public:

    PlayField(std::string name, int spalten, int zeilen) : name(std::move(name)), spalten(spalten), zeilen(zeilen) {
        field = nullptr;
        allocateArrayDynamic();
    }

    ~PlayField() {
        for (int i = 0; i < zeilen; i++) {
            delete[] field[i];
        }
        delete[] field;
        for (MetaData *m: metaData) {
            delete m;
        }
    }

    PlayField(PlayField &f1) :name(f1.name), spalten(f1.spalten), zeilen(f1.zeilen) {
        field = f1.field;
    }

    void addPair(std::string key, std::string value);

    MetaData *getPair(const std::string &key);

    void deletePair(const std::string &key);

    int ** getField() {return field;}

    int write(std::string fileName) override;

    int read(std::string fileName) override;

    int deleteMetaDataElement(int index);

    void addElement(int zeile, int spalte, int value) override;

    int getElement(int spalte, int zeile) override;

private:
    void allocateArrayDynamic() {
        field = new int *[zeilen]();
        for (int i = 0; i < zeilen; i++) {
            field[i] = new int[spalten]();
            for (int t = 0; t < spalten; t++) { field[i][t] = 0; }
        }
    }

private:
    int **field;
    std::string name;
    int spalten;
    int zeilen;
    std::vector<MetaData *> metaData;

};


#endif //ECPP_PROBE_NEU_PLAYFIELD_H
