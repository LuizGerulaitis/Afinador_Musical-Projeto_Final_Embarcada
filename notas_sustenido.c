#include <pic18f4520.h>
#include "atraso.h"
#include "notas_sustenido.h"
#include "lcd.h"
#include "pwm.h"
#include "ssd.h"
#include "bits.h"

void NotaDoS() {
    char titulo [13] = {"Nota Do # (C)"};
    char freq [13] = {"Freq : 280 Hz"};

    lcdCommand(0x01);
    
    lcdPosition(0, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(titulo[i]);
    }

    lcdPosition(1, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(freq[i]);
    }


    ssdInit();
    ssdDigit(12, 0);
    ssdDigit(2, 1);
    ssdDigit(8, 2);
    ssdDigit(0, 3);

    pwmInit();
    pwmFrequency(280);
    pwmSet1(280);
    for (char k = 0; k < 1; k++) {
        ssdUpdate();
        PORTD = 0x00;
        for (char j = 1; j > 0; j = j * 2) {
            bitSet(TRISC, 1);
            atraso_ms(700);
            break;
        }
        bitClr(TRISC, 1);
    }

    PORTB = 0x00;
    PORTD = 0x00;
}

void NotaReS() {
    char titulo [13] = {"Nota Re # (D)"};
    char freq [13] = {"Freq : 314 Hz"};

    lcdCommand(0x01);

    lcdPosition(0, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(titulo[i]);
    }

    lcdPosition(1, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(freq[i]);
    }

    ssdInit();
    ssdDigit(13, 0);
    ssdDigit(3, 1);
    ssdDigit(1, 2);
    ssdDigit(4, 3);

    pwmFrequency(297);
    pwmSet1(297);
    for (char k = 0; k < 1; k++) {
        ssdUpdate();
        PORTD = 0x00;
        for (char j = 1; j > 0; j = j * 2) {
            bitSet(TRISC, 1);
            atraso_ms(700);
            break;
        }
        bitClr(TRISC, 1);
    }

    PORTB = 0x00;
    PORTD = 0x00;
}

void NotaMiS() {
    char titulo [13] = {"Nota Mi # (E)"};
    char freq [13] = {"Freq : 352 Hz"};

    lcdCommand(0x01);
    
    lcdPosition(0, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(titulo[i]);
    }

    lcdPosition(1, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(freq[i]);
    }

    ssdInit();
    ssdDigit(14, 0);
    ssdDigit(3, 1);
    ssdDigit(5, 2);
    ssdDigit(2, 3);

    pwmFrequency(310);
    pwmSet1(310);
    for (char k = 0; k < 1; k++) {
        ssdUpdate();
        PORTD = 0x00;
        for (char j = 1; j > 0; j = j * 2) {
            bitSet(TRISC, 1);
            atraso_ms(700);
            break;
        }
        bitClr(TRISC, 1);
    }

    PORTB = 0x00;
    PORTD = 0x00;
}

void NotaFaS() {
    char titulo [13] = {"Nota Fa # (F)"};
    char freq [13] = {"Freq : 373 Hz"};

    lcdCommand(0x01);
    
    lcdPosition(0, 2);
    for (char i = 0; i < 13; i++) {
        lcdData(titulo[i]);
    }

    lcdPosition(1, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(freq[i]);
    }

    ssdInit();
    ssdDigit(15, 0);
    ssdDigit(3, 1);
    ssdDigit(7, 2);
    ssdDigit(3, 3);

    pwmFrequency(332);
    pwmSet1(332);
    for (char k = 0; k < 1; k++) {
        ssdUpdate();
        PORTD = 0x00;
        for (char j = 1; j > 0; j = j * 2) {
            bitSet(TRISC, 1);
            atraso_ms(700);
            break;
        }
        bitClr(TRISC, 1);
    }

    PORTB = 0x00;
    PORTD = 0x00;
}

void NotaSolS() {
    char titulo [14] = {"Nota Sol # (G)"};
    char freq [13] = {"Freq : 419 Hz"};

    lcdCommand(0x01);
    
    lcdPosition(0, 1);
    for (char i = 0; i < 14; i++) {
        lcdData(titulo[i]);
    }

    lcdPosition(1, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(freq[i]);
    }

    ssdInit();
    ssdDigit(16, 0);
    ssdDigit(4, 1);
    ssdDigit(1, 2);
    ssdDigit(9, 3);

    pwmFrequency(340);
    pwmSet1(340);
    for (char k = 0; k < 1; k++) {
        ssdUpdate();
        PORTD = 0x00;
        for (char j = 1; j > 0; j = j * 2) {
            bitSet(TRISC, 1);
            atraso_ms(700);
            break;
        }
        bitClr(TRISC, 1);
    }

    PORTB = 0x00;
    PORTD = 0x00;
}

void NotaLaS() {
    char titulo [13] = {"Nota La # (A)"};
    char freq [13] = {"Freq : 470 Hz"};

    lcdCommand(0x01);
    
    lcdPosition(0, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(titulo[i]);
    }

    lcdPosition(1, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(freq[i]);
    }

    ssdInit();
    ssdDigit(10, 0);
    ssdDigit(4, 1);
    ssdDigit(7, 2);
    ssdDigit(0, 3);

    pwmFrequency(390);
    pwmSet1(390);
    for (char k = 0; k < 1; k++) {
        ssdUpdate();
        PORTD = 0x00;
        for (char j = 1; j > 0; j = j * 2) {
            bitSet(TRISC, 1);
            atraso_ms(700);
            break;
        }
        bitClr(TRISC, 1);
    }

    PORTB = 0x00;
    PORTD = 0x00;
}

void NotaSiS() {
    char titulo [13] = {"Nota Si # (B)"};
    char freq [13] = {"Freq : 528 Hz"};

    lcdCommand(0x01);
    
    lcdPosition(0, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(titulo[i]);
    }

    lcdPosition(1, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(freq[i]);
    }

    ssdInit();
    ssdDigit(11, 0);
    ssdDigit(5, 1);
    ssdDigit(2, 2);
    ssdDigit(8, 3);

    pwmFrequency(450);
    pwmSet1(450);
    for (char k = 0; k < 1; k++) {
        ssdUpdate();
        PORTD = 0x00;
        for (char j = 1; j > 0; j = j * 2) {
            bitSet(TRISC, 1);
            atraso_ms(700);
            break;
        }
        bitClr(TRISC, 1);
    }

    PORTB = 0x00;
    PORTD = 0x00;
}

