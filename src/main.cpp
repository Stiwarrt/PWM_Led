#include <Arduino.h>
#include "LUZLED.h"


LED rgb(15, 2, 4, 36, 39, 34, 35);

void setup() {
    
}

void loop() {

    bool dipSwitchState = digitalRead(rgb.pinDipSwitch); 
    rgb.setDipSwitchState(dipSwitchState);

    bool btnState1 = !digitalRead(rgb.pinBtn1); 
    bool btnState2 = !digitalRead(rgb.pinBtn2);
    bool btnState3 = !digitalRead(rgb.pinBtn3); 

    if (dipSwitchState==1) {
        if (btnState1) {
            rgb.increaseIntensity('R'); 
            delay(100); 
        } else if (btnState2) {
            rgb.increaseIntensity('G'); 
            delay(100);
        } else if (btnState3) {
            rgb.increaseIntensity('B'); 
            delay(100);
        }
    } else {
        if (btnState1) {
            rgb.decreaseIntensity('R'); 
            delay(100);
        } else if (btnState2) {
            rgb.decreaseIntensity('G'); 
            delay(100);
        } else if (btnState3) {
            rgb.decreaseIntensity('B'); 
            delay(100);
        }
    }

    delay(50); 
}
