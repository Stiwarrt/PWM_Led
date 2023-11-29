#ifndef LUZLED_H
#define LUZLED_H

#include <Arduino.h>

class LED {
public:
    int pinLedR, pinLedG, pinLedB, pinBtn1, pinBtn2, pinBtn3, pinDipSwitch;

    int intensityR, intensityG, intensityB;
    bool dipSwitchState;

public:
    LED (int pinRed, int pinGreen, int pinBlue, int btn1, int btn2, int btn3, int dipSwitch) :
        pinLedR(pinRed),
        pinLedG(pinGreen),
        pinLedB(pinBlue),
        pinBtn1(btn1),
        pinBtn2(btn2),
        pinBtn3(btn3),
        pinDipSwitch(dipSwitch),
        intensityR(0),
        intensityG(0),
        intensityB(0),
        dipSwitchState(false) {
        
        pinMode(pinLedR, OUTPUT);
        pinMode(pinLedG, OUTPUT);
        pinMode(pinLedB, OUTPUT);
        pinMode(pinBtn1, INPUT_PULLUP);
        pinMode(pinBtn2, INPUT_PULLUP);
        pinMode(pinBtn3, INPUT_PULLUP);
        pinMode(pinDipSwitch, INPUT_PULLUP);

        setColor(0, 0, 0); // Inicialmente, apagar el LED
    }

    void setColor(int redValue, int greenValue, int blueValue) {
        analogWrite(pinLedR, redValue);
        analogWrite(pinLedG, greenValue);
        analogWrite(pinLedB, blueValue);
    }

    void increaseIntensity(char color) {
        if (dipSwitchState) {
            if (color == 'R' && intensityR < 255) {
                intensityR += 10;
                if (intensityR > 255) intensityR = 255;
            } else if (color == 'G' && intensityG < 255) {
                intensityG += 10;
                if (intensityG > 255) intensityG = 255;
            } else if (color == 'B' && intensityB < 255) {
                intensityB += 10;
                if (intensityB > 255) intensityB = 255;
            }
            setColor(intensityR, intensityG, intensityB);
        } else {
            decreaseIntensity(color);
        }
    }

    void decreaseIntensity(char color) {
        if (color == 'R' && intensityR > 0) {
            intensityR -= 10;
            if (intensityR < 0) intensityR = 0;
        } else if (color == 'G' && intensityG > 0) {
            intensityG -= 10;
            if (intensityG < 0) intensityG = 0;
        } else if (color == 'B' && intensityB > 0) {
            intensityB -= 10;
            if (intensityB < 0) intensityB = 0;
        }
        setColor(intensityR, intensityG, intensityB);
    }

    void setDipSwitchState(bool state) {
        dipSwitchState = state;
    }
};

#endif
