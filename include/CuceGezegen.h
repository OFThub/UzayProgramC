/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin cuce gezegen fonksiyonlarının bulunduğu yerdir.
* </p>
*/

#ifndef CUCEGEZEGEN_H
#define CUCEGEZEGEN_H

#include "Gezegen.h"

struct CUCEGEZEGEN {
    Gezegen super; 
    double zamanKatsayisi;
    int gezegenGunlukSaat;
    int gezegenSaat;
    Zaman gezegenTarih;

    Zaman (*getCuceGezegenTarih)(struct CUCEGEZEGEN);
    double (*getCuceGezegenKatsayisi)(struct CUCEGEZEGEN);
    void (*ilerletSaat)(struct CUCEGEZEGEN);
    int (*getCuceSaat)(struct CUCEGEZEGEN);
};typedef struct CUCEGEZEGEN* CuceGezegen;

CuceGezegen CuceGezegenOlustur(const char* gezegenAdi, int gezegenGunlukSaat, int gezegenSaat, int gezegenAy, int gezegenYil);
double getCuceGezegenKatsayisi(CuceGezegen gezegen);
void ilerletCuceSaat(CuceGezegen gezegen);
Zaman getCuceGezegenTarih(CuceGezegen gezegen);
int getCuceSaat(CuceGezegen gezegen);
#endif
