/* This software is licensed under the MIT License: https://github.com/spacehuhntech/usbnova */

#include "selector.h"

#include <Arduino.h> // pinMode(), digitalRead()

#define CHANGE_DELAY 200

namespace selector {
    // ===== PRIVATE ===== //
    bool change_flag = false;
    Mode initial_mode;
    unsigned long change_time = 0;

    void isr() {
        change_flag = true;
        change_time = millis();
    }

    // ===== PUBLIC ===== //
    void init() {
#ifdef MULTI_SELECTOR
        pinMode(SELECTOR_1, INPUT_PULLUP);
        pinMode(SELECTOR_2, INPUT_PULLUP);
        pinMode(SELECTOR_3, INPUT_PULLUP);

        attachInterrupt(digitalPinToInterrupt(SELECTOR_2), isr, CHANGE);
#else
        pinMode(SELECTOR, INPUT_PULLUP);

        attachInterrupt(digitalPinToInterrupt(SELECTOR), isr, CHANGE);
#endif

        initial_mode = read();
    }

    Mode mode() {
        return initial_mode;
    }

    Mode read() {
#ifdef MULTI_SELECTOR
        return (position() == 3) ? SETUP : ATTACK;
#else
        return digitalRead(SELECTOR) ? SETUP : ATTACK;
#endif
    }

#ifdef MULTI_SELECTOR
    int position() {
        if (!digitalRead(SELECTOR_1)) {
            return 1;
        } else if (!digitalRead(SELECTOR_2)) {
            return 2;
        } else if (!digitalRead(SELECTOR_3)) {
            return 3;
        } else {
            return 0;
        }
    }

#endif

    bool changed() {
        if (change_flag && ((millis() - change_time) > CHANGE_DELAY)) {
            change_flag = false;
            return true;
        }
        return false;
    }
}