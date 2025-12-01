/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin kayaç gezegen fonksiyonlarının bulunduğu yerdir.
* </p>
*/

#ifndef KAYACGEZEGEN_H
#define KAYACGEZEGEN_H

#include "Gezegen.h"

typedef struct KAYACGEZEGEN* KayacGezegen;
struct KAYACGEZEGEN {
    Gezegen super; 
    double zamanKatsayisi;
    int gezegenGunlukSaat;
    int gezegenSaat;
    Zaman gezegenTarih;

    Zaman (*getKayacGezegenTarih)(struct KAYACGEZEGEN);
    double (*getKayacGezegenKatsayisi)(struct KAYACGEZEGEN);
    void (*ilerletSaat)(struct KAYACGEZEGEN);
    int (*getKayacSaat)(struct KAYACGEZEGEN);
};

KayacGezegen KayacGezegenOlustur(const char* gezegenAdi, int gezegenGunlukSaat, int gezegenSaat, int gezegenAy, int gezegenYil);
double getKayacGezegenKatsayisi(KayacGezegen gezegen);
void ilerletKayacSaat(KayacGezegen gezegen);
Zaman getKayacGezegenTarih(KayacGezegen gezegen);
int getKayacSaat(KayacGezegen gezegen);
#endif
