/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#pragma once

#include <string>
#include <cstdint>

namespace preferences {
    void load();
    void save();
    void reset();
    void print();

    bool mscEnabled();
    bool ledEnabled();
    bool hidEnabled();

#ifdef MULTI_SELECTOR
    uint16_t getVID1();
    uint16_t getPID1();
    uint16_t getVersion1();

    std::string getSerial1();
    std::string getManufacturer1();
    std::string getProduct1();

    uint16_t getVID2();
    uint16_t getPID2();
    uint16_t getVersion2();

    std::string getSerial2();
    std::string getManufacturer2();
    std::string getProduct2();
#else
    uint16_t getVID();
    uint16_t getPID();
    uint16_t getVersion();

    std::string getSerial();
    std::string getManufacturer();
    std::string getProduct();
#endif

    std::string getDefaultLayout();
    int getDefaultDelay();

#ifndef MULTI_SELECTOR
    std::string getMainScript();
#endif

    int* getAttackColor();
    int* getSetupColor();
    int* getIdleColor();

    bool getFormat();
    std::string getDriveName();

    bool getDisableCapslock();
    bool getRunOnIndicator();

    int getInitialDelay();
}