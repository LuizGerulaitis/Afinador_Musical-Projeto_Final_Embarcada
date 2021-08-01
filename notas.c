#include <pic18f4520.h>
#include "atraso.h"
#include "notas.h"
#include "lcd.h"
#include "pwm.h"
#include "ssd.h"
#include "bits.h"

char MusicNote1[8] = {0x0F, 0x09, 0x09, 0x09, 0x09, 0x1B, 0x1B, 0x00};
char MusicNote2[8] = {0x0F, 0x08, 0x08, 0x08, 0x08, 0x18, 0x18, 0x00};

void NotaDo() {
    char titulo [11] = {"Nota Do (C)"};
    char freq [13] = {"Freq : 264 Hz"};

    lcdCommand(0x01);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote1[i]);
    }

    lcdPosition(0, 0);
    lcdData(0);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote2[i]);
    }

    lcdPosition(0, 15);
    lcdData(0);

    lcdPosition(0, 2);
    for (char i = 0; i < 11; i++) {
        lcdData(titulo[i]);
    }

    lcdPosition(1, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(freq[i]);
    }


    ssdInit();
    ssdDigit(12, 0);
    ssdDigit(2, 1);
    ssdDigit(6, 2);
    ssdDigit(4, 3);

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

void NotaRe() {
    char titulo [11] = {"Nota Re (D)"};
    char freq [13] = {"Freq : 297 Hz"};

    pwmSet2(0);

    lcdCommand(0x01);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote1[i]);
    }

    lcdPosition(0, 0);
    lcdData(0);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote2[i]);
    }

    lcdPosition(0, 15);
    lcdData(0);

    lcdPosition(0, 2);
    for (char i = 0; i < 11; i++) {
        lcdData(titulo[i]);
    }

    lcdPosition(1, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(freq[i]);
    }

    ssdInit();
    ssdDigit(13, 0);
    ssdDigit(2, 1);
    ssdDigit(9, 2);
    ssdDigit(7, 3);

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

void NotaMi() {
    char titulo [11] = {"Nota Mi (E)"};
    char freq [13] = {"Freq : 330 Hz"};

    lcdCommand(0x01);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote1[i]);
    }

    lcdPosition(0, 0);
    lcdData(0);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote2[i]);
    }

    lcdPosition(0, 15);
    lcdData(0);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote1[i]);
    }

    lcdPosition(0, 0);
    lcdData(0);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote2[i]);
    }

    lcdPosition(0, 15);
    lcdData(0);

    lcdPosition(0, 2);
    for (char i = 0; i < 11; i++) {
        lcdData(titulo[i]);
    }

    lcdPosition(1, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(freq[i]);
    }

    ssdInit();
    ssdDigit(14, 0);
    ssdDigit(3, 1);
    ssdDigit(3, 2);
    ssdDigit(0, 3);

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

void NotaFa() {
    char titulo [11] = {"Nota Fa (F)"};
    char freq [13] = {"Freq : 352 Hz"};

    lcdCommand(0x01);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote1[i]);
    }

    lcdPosition(0, 0);
    lcdData(0);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote2[i]);
    }

    lcdPosition(0, 15);
    lcdData(0);

    lcdPosition(0, 2);
    for (char i = 0; i < 11; i++) {
        lcdData(titulo[i]);
    }

    lcdPosition(1, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(freq[i]);
    }

    ssdInit();
    ssdDigit(15, 0);
    ssdDigit(3, 1);
    ssdDigit(5, 2);
    ssdDigit(2, 3);

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

void NotaSol() {
    char titulo [12] = {"Nota Sol (G)"};
    char freq [13] = {"Freq : 396 Hz"};

    lcdCommand(0x01);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote1[i]);
    }

    lcdPosition(0, 0);
    lcdData(0);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote2[i]);
    }

    lcdPosition(0, 15);
    lcdData(0);

    lcdPosition(0, 2);
    for (char i = 0; i < 12; i++) {
        lcdData(titulo[i]);
    }

    lcdPosition(1, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(freq[i]);
    }

    ssdInit();
    ssdDigit(16, 0);
    ssdDigit(3, 1);
    ssdDigit(9, 2);
    ssdDigit(6, 3);

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

void NotaLa() {
    char titulo [11] = {"Nota La (A)"};
    char freq [13] = {"Freq : 440 Hz"};

    lcdCommand(0x01);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote1[i]);
    }

    lcdPosition(0, 0);
    lcdData(0);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote2[i]);
    }

    lcdPosition(0, 15);
    lcdData(0);

    lcdPosition(0, 2);
    for (char i = 0; i < 11; i++) {
        lcdData(titulo[i]);
    }

    lcdPosition(1, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(freq[i]);
    }

    ssdInit();
    ssdDigit(10, 0);
    ssdDigit(4, 1);
    ssdDigit(4, 2);
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

void NotaSi() {
    char titulo [11] = {"Nota Si (B)"};
    char freq [13] = {"Freq : 495 Hz"};

    lcdCommand(0x01);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote1[i]);
    }

    lcdPosition(0, 0);
    lcdData(0);

    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote2[i]);
    }

    lcdPosition(0, 15);
    lcdData(0);

    lcdPosition(0, 2);
    for (char i = 0; i < 11; i++) {
        lcdData(titulo[i]);
    }

    lcdPosition(1, 1);
    for (char i = 0; i < 13; i++) {
        lcdData(freq[i]);
    }

    ssdInit();
    ssdDigit(11, 0);
    ssdDigit(4, 1);
    ssdDigit(9, 2);
    ssdDigit(5, 3);

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

