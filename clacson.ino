#include "pitches.h"
#include "melody.h"

// I/O pinout
#define SWDX  5 // switch destro (selezione canzone)
#define SWSX  6 // switch sinistro (incrementa numero canzone)
#define GATE  4 // pin gate mosfet

#define numCanzoni    15

// Numero visualizzato sul display
int num = 0;

// poi lo moltiplichi per un float, sarebbe da cambiare tipo di variabile
int pauseBetweenNotes = 0;

// Array per i pin dello schermo a 7 segmenti
// La numerazione parte dal pin a fino alla g, dal segmento in alto e ruotando in senso orario
// {a, b, c, d, e, f, g};
int sevSeg[] = {9, 10, 1, 2, 3, 7, 8};

// https://www.hacktronics.com/Tutorials/arduino-and-7-segment-led.html
byte seven_seg_digits[16][7] = { { 1, 1, 1, 1, 1, 1, 0 }, // = 0
                                 { 0, 1, 1, 0, 0, 0, 0 }, // = 1
                                 { 1, 1, 0, 1, 1, 0, 1 }, // = 2
                                 { 1, 1, 1, 1, 0, 0, 1 }, // = 3
                                 { 0, 1, 1, 0, 0, 1, 1 }, // = 4
                                 { 1, 0, 1, 1, 0, 1, 1 }, // = 5
                                 { 1, 0, 1, 1, 1, 1, 1 }, // = 6
                                 { 1, 1, 1, 0, 0, 0, 0 }, // = 7
                                 { 1, 1, 1, 1, 1, 1, 1 }, // = 8
                                 { 1, 1, 1, 0, 0, 1, 1 }, // = 9
                                 { 1, 1, 1, 0, 1, 1, 1 }, // = A
                                 { 0, 0, 1, 1, 1, 1, 1 }, // = B
                                 { 1, 0, 0, 1, 1, 1, 0 }, // = C
                                 { 0, 1, 1, 1, 1, 0, 1 }, // = D
                                 { 1, 0, 0, 1, 1, 1, 1 }, // = E
                                 { 1, 0, 0, 0, 1, 1, 1 }};// = F

void setup() {
  pinMode(GATE, OUTPUT);
  digitalWrite(GATE, LOW);
  pinMode(SWDX, INPUT);
  pinMode(SWSX, INPUT);
  for(int j=0; j<(sizeof(sevSeg)/sizeof(sevSeg[0])); j++) pinMode(sevSeg[j], OUTPUT);

  // Serpentina iniziale
  int snake[] = {a, b, g, e, d, c, g, f, a, b, g, e, d, c, g, f, a, b, g, e, d, c, g, f, a, b, g, e, d, c, g, f};

  for (int i = 0; i < (sizeof(snake) / sizeof(snake[0])); i++) {
    digitalWrite(snake[i], HIGH);
    delay(100);
    digitalWrite(snake[i], LOW);
  }
}

/* Funzione per riprodurre la nota usando tone()
 * Parametri passati:
 * int* melodia : puntatore alla melodia scritta nel file melody.h
 * int* noteDurata : puntatore all'array della durata di ogni singola nota
 * int durata : paramentro per regolare la velocità della nota
 * float pausa : parametro moltiplicativo per impostare la pausa tra le note
 * int sizeMelodia : dimensione array della melodia da riprodurre
 */

void suonaSuoneria(int* melodia, int* noteDurata, int durata, float pausa, int sizeMelodia) {

  for (int thisNote = 0; thisNote < sizeMelodia; thisNote++) {

    int noteDuration = durata / noteDurata[thisNote];
    tone(GATE, melodia[thisNote], noteDuration);

    pauseBetweenNotes = noteDuration * pausa;
    delay(pauseBetweenNotes);

    noTone(GATE);
    
  }
}

/*
 * Funzione per accendre il clacson definendo durata e intervallo a piacere
 */

void suonaGate(int durata, int intervallo) {
  digitalWrite(GATE, HIGH);
  delay(durata);
  digitalWrite(GATE, LOW);
  delay(intervallo);
}

void sevenSegWrite(int digit) {
  for (byte segCount = 0; segCount < 7; ++segCount) {
    digitalWrite(sevSeg[segCount], seven_seg_digits[digit][segCount]);
  }
}

void loop() {

  // Gestione del numero di melodia
  if (digitalRead(SWSX)) {
    // Debouncer molto zozzo, ma pratico
    while (digitalRead(SWSX)) delay(10);
    num++;
  }
  // Ciclo tra le canzone disponibili
  if (num >= numCanzoni) num = 0;
  sevenSegWrite(num);

  switch (num) {
    case 0:           // Clacson normale

      while (digitalRead(SWDX)) {
        digitalWrite(GATE, HIGH);
      }
      digitalWrite(GATE, LOW);

      break;

    case 1:         // Clacson corriera
      if (digitalRead(SWDX)) {
        digitalWrite(GATE, LOW);
      }
      break;

    case 2:         // Copa la vecia col flint
      if (digitalRead(SWDX)) {
        suonaGate(50, 100);
        suonaGate(50, 50);
        suonaGate(50, 50);
        suonaGate(50, 100);
        suonaGate(50, 200);
        suonaGate(50, 100);
        suonaGate(50, 100);
      }

      break;

    case 3:         // Tetris

      if (digitalRead(SWDX)) {
        suonaSuoneria(melody3, noteDurations3, 1000, 1.30, (sizeof(melody3) / sizeof(melody3[0])));
      }

      digitalWrite(GATE, LOW);

      break;

    case 4:         // Clacson Hazard

      if (digitalRead(SWDX)) {
        suonaSuoneria(melody4, noteDurations4, 800, 1.30, (sizeof(melody4) / sizeof(melody4[0])));
      }

      digitalWrite(GATE, LOW);

      break;

    case 5:         // Seven nation army

      if (digitalRead(SWDX)) {
        suonaSuoneria(melody5, noteDurations5, 3200, 1.20, (sizeof(melody5) / sizeof(melody5[0])));
      }

      digitalWrite(GATE, LOW);

      break;

    case 6:         // Campioni del mondo

      if (digitalRead(SWDX)) {
        suonaSuoneria(melody6, noteDurations6, 2400, 1.30, (sizeof(melody6) / sizeof(melody6[0])));
      }

      digitalWrite(GATE, LOW);

      break;

    case 7:         // Bevo Bevo

      if (digitalRead(SWDX)) {
        suonaSuoneria(melody7, noteDurations7, 2400, 1.20, (sizeof(melody7) / sizeof(melody7[0])));
      }
      
      digitalWrite(GATE, LOW);

      break;

    case 8:         // Best Brau Theme

      if (digitalRead(SWDX)) {

        for (int bb = 0; bb < 3; bb++) {
          suonaSuoneria(melody82, noteDurations82, 2000, 1.30, (sizeof(melody82) / sizeof(melody82[0])));
          suonaSuoneria(melody82, noteDurations82, 2000, 1.30, (sizeof(melody82) / sizeof(melody82[0])));
          suonaSuoneria(melody81, noteDurations81, 2000, 1.30, (sizeof(melody81) / sizeof(melody81[0])));
        }
      }

      digitalWrite(GATE, LOW);

      break;

    case 9:         // Best Brau Theme (Only rit)

      if (digitalRead(SWDX)) {
        suonaSuoneria(melody9, noteDurations9, 1400, 1.30, (sizeof(melody9) / sizeof(melody9[0])));
      }
      digitalWrite(GATE, LOW);

      break;

    case 10:         // Che la sia crucca o terona

      if (digitalRead(SWDX)) {
          suonaSuoneria(melody10, noteDurations10, 2000, 1.00, (sizeof(melody10) / sizeof(melody10[0])));
        }

        digitalWrite(GATE, LOW);

        break;

      case 11:         // Maza la vecia ??

        if (digitalRead(SWDX)) {
          suonaSuoneria(melody11, noteDurations11, 1400, 1.30, (sizeof(melody11) / sizeof(melody11[0])));
        }

        digitalWrite(GATE, LOW);

        break;

      case 12:         // Gne gne gne gne gne gne gnee

        if (digitalRead(SWDX)) {

          suonaSuoneria(melody12, noteDurations12, 1000, 1.30, (sizeof(melody12) / sizeof(melody12[0])));
        }

        digitalWrite(GATE, LOW);

        break;

      case 13:         // Rumore piu fastioso del mondo

        if (digitalRead(SWDX)) {

          suonaSuoneria(melody13, noteDurations13, 6000, 1.30, (sizeof(melody13) / sizeof(melody13[0])));
        }

        digitalWrite(GATE, LOW);

        break;

      case 14:         // Koala

        if (digitalRead(SWDX)) {

          for (int k = 0; k < 6; k++) {

            suonaSuoneria(melody14, noteDurations14, 800, 1.30, (sizeof(melody14) / sizeof(melody14[0])));
          }
        }

        digitalWrite(GATE, LOW);

        break;
      }
      delay(10);
  }
}
