/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin gaz devi gezegen fonksiyonlarının bulunduğu yerdir.
* </p>
*/

#ifndef GAZDEVIGEZEGEN_H
#define GAZDEVIGEZEGEN_H

#include "Gezegen.h"

struct GAZDEVIGEZEGEN {
    Gezegen super; 
    double zamanKatsayisi;
    int gezegenGunlukSaat;
    int gezegenSaat;
    Zaman gezegenTarih;

    Zaman (*getGazDeviGezegenTarih)(struct GAZDEVIGEZEGEN);
    double (*getGazDeviGezegenKatsayisi)(struct GAZDEVIGEZEGEN);
    void (*ilerletSaat)(struct GAZDEVIGEZEGEN);
    int (*getGazDeviSaat)(struct GAZDEVIGEZEGEN);
};typedef struct GAZDEVIGEZEGEN* GazDeviGezegen;

GazDeviGezegen GazDeviGezegenOlustur(const char* gezegenAdi, int gezegenGunlukSaat, int gezegenSaat, int gezegenAy, int gezegenYil);
double getGazDeviGezegenKatsayisi(GazDeviGezegen gezegen);
void ilerletGazDeviSaat(GazDeviGezegen gezegen);
Zaman getGazDeviGezegenTarih(GazDeviGezegen gezegen);
int getGazDeviSaat(GazDeviGezegen gezegen);
#endif
