/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin dosya okuma fonksiyonlarının bulunduğu yerdir.
* </p>
*/

#ifndef DOSYAOKUMA_H
#define DOSYAOKUMA_H
#include "UzayAraci.h"
#include "Kisi.h"
#include <string.h>
#define MAX_GEZEGENLER 100
#define MAX_KISILER 600
#define MAX_ARACLAR 100

void DosyaOkuma();

extern KayacGezegen kayacGezegenler[MAX_GEZEGENLER];
extern int kayacGezegenSayisi;
extern BuzDeviGezegen buzDeviGezegenler[MAX_GEZEGENLER];
extern int buzDeviGezegenSayisi;
extern GazDeviGezegen gazDeviGezegenler[MAX_GEZEGENLER];
extern int gazDeviGezegenSayisi;
extern CuceGezegen cuceGezegenler[MAX_GEZEGENLER];
extern int cuceGezegenSayisi;

extern Kisi kisiler[MAX_KISILER];
extern int kisiSayisi;

extern UzayAraci araclar[MAX_ARACLAR];
extern int aracSayisi;

#endif