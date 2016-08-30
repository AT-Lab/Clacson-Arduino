/* 
    sarebbe da strutturare le melodie come matrice invece che array, per maggior pulizia
*/
//Tetris [20 note]
int melody3[] = {NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_B4, 0, NOTE_C5,NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A4, NOTE_A4};
int noteDurations3[] = {4,8,8,4,8,8,4,8,8,4,8,8,4,8,8,4,4,4,4,2};


// Hazard (Dixie) [12 note] ---------------------------------------
int melody4[] = {NOTE_G5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_E5};
int noteDurations4[] = {8,8,4,4,8,8,8,8,4,4,4,4};


//Seven nation army [7 note] ---------------------------------------
int melody5[] = {NOTE_F5, NOTE_F5, NOTE_GS5, NOTE_F5, NOTE_DS5, NOTE_CS5, NOTE_C5};
int noteDurations5[] = {6,16,12,12,16,4,4};


//Campioni del mondo [10 note] ---------------------------------------
int melody6[] = {NOTE_C5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_F5};
int noteDurations6[] = {8,8,4,8,8,4,8,3,8,3};


//Bevo Bevo [26 note 10+16] ---------------------------------------
int melody7[] = {NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_AS5, NOTE_AS5, NOTE_AS5, NOTE_A5, NOTE_G5, NOTE_A5, NOTE_F5, NOTE_F5, NOTE_A5, NOTE_G5, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_F5};
int noteDurations7[] = {8,4,8,4,8,8,8,8,8,4,16,16,8,4,16,16,16,8,4,16,16,8,8,8,8,4};


//Best Brau Theme [27 note] ---------------------------------------
int melody81[] = {NOTE_G5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_B5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G5};
int noteDurations81[] = {16,16,8,8,8,16,3,16,16,8,8,8,16,3,16,16,4,8,16,3,16,16,8,8,8,16,3};

int melody82[] = {NOTE_G5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_B5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_G5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G5, NOTE_G5};
int noteDurations82[] = {16,16,8,8,8,16,8,4,16,16,8,8,8,16,8,4,16,16,8,8,8,16,8,4,16,16,8,8,8,16,8,4};


//Best Brau Theme (Only rit) [27 note] ---------------------------------------
int melody9[] = {NOTE_G5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_E5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_A5, NOTE_A5, NOTE_B5, NOTE_G5, NOTE_G5, NOTE_G5, NOTE_F5, NOTE_F5, NOTE_F5, NOTE_G5, NOTE_E5, NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_G5};
int noteDurations9[] = {16,16,8,8,8,16,3,16,16,8,8,8,16,3,16,16,4,8,16,3,16,16,8,8,8,16,3};


//Che la sia crucca o terona [42 note] ---------------------------------------
int melody10[] = {NOTE_B5, NOTE_B5, NOTE_CS6, NOTE_B5, NOTE_E5, NOTE_GS5, NOTE_B5, NOTE_B5, NOTE_A5, NOTE_FS5, NOTE_B5, NOTE_DS6, NOTE_CS6, NOTE_CS6, NOTE_B5, NOTE_GS5, NOTE_B5, NOTE_GS5, NOTE_GS5, NOTE_B5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5, NOTE_CS6, NOTE_CS6, NOTE_CS6, NOTE_CS6, NOTE_CS6, NOTE_CS6, NOTE_B5, NOTE_B5, NOTE_B5, NOTE_CS6, NOTE_B5, NOTE_A5, NOTE_GS5, NOTE_FS5, NOTE_E5};
int noteDurations10[] = {16,16,16,10,3,5,6,6,6,4,6,6,8,8,10,6,10,12,10,10,12,10,12,12,12,12,12,4,12,10,12,12,10,12,10,12,10,12,10,12,10,4};


//Maza la vecia [7 note] ---------------------------------------
int melody11[] = {NOTE_G5, NOTE_G5, NOTE_G5, NOTE_A5, NOTE_G5, NOTE_B5, NOTE_C6};
int noteDurations11[] = {8,16,8,8,4,8,8};

//Gne gne gne gne gne gne gnee [7 note] ---------------------------------------
int melody12[] = {NOTE_G5, NOTE_G5, NOTE_E5, NOTE_A5, NOTE_G5, NOTE_G5, NOTE_E5};
int noteDurations12[] = {8,8,8,8,8,8,4};


//Rumore piu fastioso del mondo [1 note] ---------------------------------------
int melody13[] = {NOTE_A6};
int noteDurations13[] = {1};


//Koala [32 note] ---------------------------------------
int melody14[] = { NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4, NOTE_CS4};
int noteDurations14[] = {16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16};
