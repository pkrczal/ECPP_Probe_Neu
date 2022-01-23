//
// Created by paul on 22.01.2022.
//

#ifndef ECPP_PROBE_NEU_METADATA_H
#define ECPP_PROBE_NEU_METADATA_H
#pragma once
#include <string>

class MetaData {

public:

    MetaData(std::string key, std::string value) : key(std::move(key)), value(std::move(value)) {}

    MetaData(MetaData &m1)  {
        key = m1.key;
        value = m1.value;
    }

    ~MetaData() = default;

    std::string getKey() {return key;}

    std::string getValue() {return value;}

private:
    std::string key;
    std::string value;

};


#endif //ECPP_PROBE_NEU_METADATA_H
