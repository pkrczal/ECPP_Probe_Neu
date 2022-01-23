//
// Created by paul on 23.01.2022.
//

#ifndef ECPP_PROBE_NEU_FILEIO_H
#define ECPP_PROBE_NEU_FILEIO_H
#pragma once
#include <string>

class FileIO  {

    virtual int write(std::string fileName) = 0;
    virtual int read(std::string fileName) = 0;
    virtual void addElement(int zeile, int spalte, int value) = 0;
    virtual int getElement(int spalte, int zeile) = 0;

};

#endif //ECPP_PROBE_NEU_FILEIO_H
