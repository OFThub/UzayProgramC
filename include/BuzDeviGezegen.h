/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin buz devi gezegen fonksiyonlarının bulunduğu yerdir.
* </p>
*/

#ifndef BUZDEVIGEZEGEN_H
#define BUZDEVIGEZEGEN_H

#include "Gezegen.h"

struct BUZDEVIGEZEGEN {
    Gezegen super; 
    double zamanKatsayisi;
    int gezegenGunlukSaat;
    int gezegenSaat;
    Zaman gezegenTarih;

    Zaman (*getBuzDeviGezegenTarih)(struct BUZDEVIGEZEGEN);
    double (*getBuzDeviGezegenKatsayisi)(struct BUZDEVIGEZEGEN);
    void (*ilerletSaat)(struct BUZDEVIGEZEGEN);
    int (*getBuzDeviSaat)(struct BUZDEVIGEZEGEN);
};typedef struct BUZDEVIGEZEGEN* BuzDeviGezegen;

BuzDeviGezegen BuzDeviGezegenOlustur(const char* gezegenAdi, int gezegenGunlukSaat, int gezegenSaat, int gezegenAy, int gezegenYil);
Zaman getBuzDeviGezegenTarih(BuzDeviGezegen gezegen);
double getBuzDeviGezegenKatsayisi(BuzDeviGezegen gezegen);
void ilerletBuzDeviSaat(BuzDeviGezegen gezegen);
int getBuzDeviSaat(BuzDeviGezegen gezegen);
#endif
