/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin zaman fonksiyonlarının bulunduğu yerdir.
* </p>
*/

#ifndef ZAMAN_H
#define ZAMAN_H

#include <stdbool.h>
#include <stdlib.h>

struct ZAMAN {
    int gun;
    int ay;
    int yil;

    bool (*esitMi)(struct ZAMAN,struct ZAMAN);
    int (*getGun)(struct ZAMAN);
    int (*getAy)(struct ZAMAN);
    int (*getYil)(struct ZAMAN);
};typedef struct ZAMAN* Zaman;

Zaman zamanOlustur(int gun, int ay, int yil);
void ilerletGun(Zaman z);
bool esitMi(Zaman z1, Zaman z2);
int getGun(Zaman z);
int getAy(Zaman z);
int getYil(Zaman z);

#endif