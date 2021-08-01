//Projeto Final - ECOP14
//Docente: Otávio Gomes
//Discente: Luiz Guilherme de Godoy Gerulaitis
//Matricula: 2020011186

#include <pic18f4520.h>
#include "atraso.h"
#include "bits.h"
#include "config.h"
#include "keypad.h"
#include "lcd.h"
#include "notas.h"
#include "notas_bemol.h"
#include "notas_sustenido.h"
#include "pwm.h"
#include "serial.h"
#include "ssd.h"
#include "timer.h"

char MusicNote1[8] = {0x0F, 0x09, 0x09, 0x09, 0x09, 0x1B, 0x1B, 0x00};
char MusicNote2[8] = {0x0F, 0x08, 0x08, 0x08, 0x08, 0x18, 0x18, 0x00};

void Intro(void);
void ImprimeInicio(void);
void Menu(void);
void Bemol(void);
void Sustenido(void);

void Intro() {
    char logo[48] = {
        0x01, 0x03, 0x03, 0x0E, 0x1C, 0x18, 0x08, 0x08, //0,0
        0x11, 0x1F, 0x00, 0x01, 0x1F, 0x12, 0x14, 0x1F, //0,1
        0x10, 0x18, 0x18, 0x0E, 0x07, 0x03, 0x02, 0x02, //0,2
        0x08, 0x18, 0x1C, 0x0E, 0x03, 0x03, 0x01, 0x00, //1,0
        0x12, 0x14, 0x1F, 0x08, 0x00, 0x1F, 0x11, 0x00, //1,1
        0x02, 0x03, 0x07, 0x0E, 0x18, 0x18, 0x10, 0x00 //1,2
    };
    lcdInit();

    lcdCommand(0x40);

    for (char i = 0; i < 48; i++) {
        lcdData(logo[i]);
    }
    for (unsigned char i = 0; i < 14; i++) {
        lcdPosition(0, i);
        lcdData(0);
        lcdData(1);
        lcdData(2);
        lcdPosition(1, i);
        lcdData(3);
        lcdData(4);
        lcdData(5);
        if (i > 0) {
            lcdPosition(0, i - 1);
            lcdData(6);
            lcdPosition(1, i - 1);
            lcdData(6);
        }
        for (int i = 0; i < 5; i++) {
            atraso_ms(100);
        }
    }

    lcdCommand(0x01);

}

void ImprimeInicio() {
    char msg [16] = "Afinador Musical";

    lcdInit();

    //Escreve "Afinador Musical" no display de LCD
    lcdPosition(0, 4);
    for (char i = 0; i < 16; i++) {
        lcdData(msg[i]);
        if (msg[i] == ' ') {
            lcdPosition(1, 4);
        }
    }

    //Escreve as notas musicais da primeira linha
    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote1[i]);
    }
    for (unsigned char i = 0; i < 3; i++) {
        lcdPosition(0, i);
        lcdData(0);
        if (i > 0) {
            lcdPosition(0, i - 1);
            lcdData(6);
        }
        for (int i = 0; i < 5; i++) {
            atraso_ms(100);
        }
    }

    //Escreve as notas musicais da segunda linha
    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote2[i]);
    }
    for (unsigned char i = 0; i < 3; i++) {
        lcdPosition(1, i);
        lcdData(0);
        if (i > 0) {
            lcdPosition(1, i - 1);
            lcdData(6);
        }
        for (int i = 0; i < 5; i++) {
            atraso_ms(100);
        }
    }

    //Escreve as notas musicais da primeira linha
    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote1[i]);
    }
    for (unsigned char i = 15; i > 12; i--) {
        lcdPosition(0, i);
        lcdData(0);
        if (i < 15) {
            lcdPosition(0, i + 1);
            lcdData(6);
        }
        for (int i = 0; i < 5; i++) {
            atraso_ms(100);
        }
    }

    //Escreve as notas musicais da segunda linha
    lcdCommand(0x40);

    for (char i = 0; i < 8; i++) {
        lcdData(MusicNote2[i]);
    }
    for (unsigned char i = 15; i > 12; i--) {
        lcdPosition(1, i);
        lcdData(0);
        if (i < 15) {
            lcdPosition(1, i + 1);
            lcdData(6);
        }
        for (int i = 0; i < 5; i++) {
            atraso_ms(100);
        }
    }

    lcdCommand(0x01);
}

void Menu() {
    lcdCommand(0x01);

    char menu [5] = {"MENU:"};
    char opcao1 [7] = {"1-Do(C)"};
    char opcao2 [7] = {"2-Re(D)"};
    char opcao3 [7] = {"3-Mi(E)"};
    char opcao4 [7] = {"4-Fa(F)"};
    char opcao5 [8] = {"5-Sol(G)"};
    char opcao6 [7] = {"6-La(A)"};
    char opcao7 [7] = {"7-Si(B)"};
    char opcao8 [7] = {"*-Bemol"};
    char opcao9 [11] = {"#-Sustenido"};
    char opcao0 [6] = {"0-Menu"};

    pwmSet1(0);
    pwmSet2(0);


    lcdPosition(0, 5);

    for (char i = 0; i < 5; i++) {
        ssdUpdate();
        PORTD = 0x00;
        lcdData(menu[i]);
    }

    for (int i = 0; i < 10; i++) {
        atraso_ms(100);
    }
    lcdCommand(0x01);

    lcdPosition(1, 5);

    for (char i = 0; i < 7; i++) {
        lcdData(opcao1[i]);
    }
    for (int i = 0; i < 10; i++) {
        atraso_ms(100);
    }
    lcdCommand(0x01);

    lcdPosition(1, 5);

    for (char i = 0; i < 7; i++) {
        lcdData(opcao2[i]);
    }
    for (int i = 0; i < 10; i++) {
       atraso_ms(100);
    }
    lcdCommand(0x01);

    lcdPosition(1, 5);

    for (char i = 0; i < 7; i++) {
        lcdData(opcao3[i]);
    }
    for (int i = 0; i < 10; i++) {
        atraso_ms(100);
    }
    lcdCommand(0x01);

    lcdPosition(1, 5);

    for (char i = 0; i < 7; i++) {
        lcdData(opcao4[i]);
    }
    for (int i = 0; i < 10; i++) {
        atraso_ms(100);
    }
    lcdCommand(0x01);

    lcdPosition(1, 5);

    for (char i = 0; i < 8; i++) {
        lcdData(opcao5[i]);
    }
    for (int i = 0; i < 10; i++) {
        atraso_ms(100);
    }
    lcdCommand(0x01);

    lcdPosition(1, 5);

    for (char i = 0; i < 7; i++) {
        lcdData(opcao6[i]);
    }
    for (int i = 0; i < 10; i++) {
        atraso_ms(100);
    }
    lcdCommand(0x01);

    lcdPosition(1, 5);

    for (char i = 0; i < 7; i++) {
        lcdData(opcao7[i]);
    }
    for (int i = 0; i < 10; i++) {
        atraso_ms(100);
    }
    lcdCommand(0x01);

    lcdPosition(1, 4);

    for (char i = 0; i < 7; i++) {
        lcdData(opcao8[i]);
    }
    for (int i = 0; i < 10; i++) {
        atraso_ms(100);
    }
    lcdCommand(0x01);

    lcdPosition(1, 3);

    for (char i = 0; i < 11; i++) {
        lcdData(opcao9[i]);
    }
    for (int i = 0; i < 10; i++) {
        atraso_ms(100);
    }
    lcdCommand(0x01);

    lcdPosition(1, 5);

    for (char i = 0; i < 6; i++) {
        lcdData(opcao0[i]);
    }
    for (int i = 0; i < 10; i++) {
        ssdUpdate();
        PORTD = 0x00;
        atraso_ms(100);
    }
    lcdCommand(0x01);

    pwmSet1(0);
    pwmSet2(0);
}

void Bemol() {
    char titulo[10] = {"Bemol (b):"};
    char legenda[12] = {"Use o serial"};
    char tmp;

    lcdCommand(0x01);
    lcdPosition(0, 3);
    for (char i = 0; i < 10; i++) {
        ssdUpdate();
        PORTD = 0x00;
        lcdData(titulo[i]);
    }

    lcdPosition(1, 2);
    for (char i = 0; i < 12; i++) {
        lcdData(legenda[i]);
    }

    serial_init();
    TRISCbits.TRISC7 = 1; //RX
    TRISCbits.TRISC6 = 0; //TX
    PORTB = 0;

    serial_tx_str(" Selecione uma Nota (C,D,E,F,G,A,B):\r\n");

    for (unsigned int i = 0; i < 32; i++) {

        tmp = serial_rx(2000);
        serial_tx(tmp);

        if (tmp == 'C') {
            NotaDob();
            break;
        } else {
            if (tmp == 'D') {
                NotaReb();
                break;
            } else {
                if (tmp == 'E') {
                    NotaMib();
                    break;
                } else {
                    if (tmp == 'F') {
                        NotaFab();
                        break;
                    } else {
                        if (tmp == 'G') {
                            NotaSolb();
                            break;
                        } else {
                            if (tmp == 'A') {
                                NotaLab();
                                break;
                            } else {
                                if (tmp == 'B') {
                                    NotaSib();
                                    break;
                                } else {
                                    if (tmp == '0') {
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void Sustenido() {
    char titulo[14] = {"Sustenido (#):"};
    char legenda[12] = {"Use o serial"};
    char tmp;

    lcdCommand(0x01);
    lcdPosition(0, 1);
    for (char i = 0; i < 14; i++) {
        ssdUpdate();
        PORTD = 0x00;
        lcdData(titulo[i]);
    }

    lcdPosition(1, 2);
    for (char i = 0; i < 12; i++) {
        lcdData(legenda[i]);
    }

    serial_init();
    TRISCbits.TRISC7 = 1; //RX
    TRISCbits.TRISC6 = 0; //TX
    PORTB = 0;

    serial_tx_str(" Selecione uma Nota (C,D,E,F,G,A,B):\r\n");

    for (unsigned int i = 0; i < 32; i++) {

        tmp = serial_rx(2000);
        serial_tx(tmp);

        if (tmp == 'C') {
            NotaDoS();
            break;
        } else {
            if (tmp == 'D') {
                NotaReS();
                break;
            } else {
                if (tmp == 'E') {
                    NotaMiS();
                    break;
                } else {
                    if (tmp == 'F') {
                        NotaFaS();
                        break;
                    } else {
                        if (tmp == 'G') {
                            NotaSolS();
                            break;
                        } else {
                            if (tmp == 'A') {
                                NotaLaS();
                                break;
                            } else {
                                if (tmp == 'B') {
                                    NotaSiS();
                                    break;
                                } else {
                                    if (tmp == '0') {
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void main() {
    unsigned int tecla = 16;

    pwmInit();
    pwmFrequency(523);
    for (char k = 0; k < 3; k++) {
        for (char j = 1; j > 0; j = j * 2) {
            bitSet(TRISC, 1);
            atraso_ms(100);
            break;
        }
        bitClr(TRISC, 1);
    }
    PORTB = 0x00;
    PORTD = 0x00;

    Intro();

    ImprimeInicio();

    Menu();

    kpInit();
    pwmInit();
    pwmFrequency(2000);

    for (;;) {
        bitClr(TRISC, 1);
        kpDebounce();
        if (kpRead() != tecla) {
            tecla = kpRead();

            if bitTst(tecla, 3) {
                NotaDo();
            }
            if bitTst(tecla, 7) {
                NotaRe();
            }
            if bitTst(tecla, 11) {
                NotaMi();
            }
            if bitTst(tecla, 2) {
                NotaFa();
            }
            if bitTst(tecla, 6) {
                NotaSol();
            }
            if bitTst(tecla, 10) {
                NotaLa();
            }
            if bitTst(tecla, 1) {
                NotaSi();
            }
            if bitTst(tecla, 4) {
                Menu();
            }
            if bitTst(tecla, 0) {
                Bemol();
            }
            if bitTst(tecla, 8) {
                Sustenido();
            }
        }

        for (int tempo = 0; tempo < 350; tempo++);

        ssdUpdate();
    }
}