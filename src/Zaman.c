/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin zaman fonksiyonlarının bulunduğu yerdir.
* </p>
*/

#include "Zaman.h"

int AY_GUNLERI[12] = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

Zaman zamanOlustur(int gun, int ay, int yil) {
    Zaman z = (Zaman)malloc(sizeof(struct ZAMAN));  
    z->gun = gun;
    z->ay = ay;
    z->yil = yil;
    return z;
}

void ilerletGun(Zaman z) {
    z->gun++;
    if (z->gun > AY_GUNLERI[z->ay - 1]) {
        z->gun = 1;
        z->ay++;
        if (z->ay > 12) {
            z->ay = 1;
            z->yil++;
        }
    }
}


bool esitMi(Zaman z1, Zaman z2) {
    return (z1->gun == z2->gun && z1->ay == z2->ay && z1->yil == z2->yil);
}

int getGun(Zaman z) {
    return z->gun;
}

int getAy(Zaman z) {
    return z->ay;
}

int getYil(Zaman z) {
    return z->yil;
}
