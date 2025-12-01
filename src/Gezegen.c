/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin gezegen fonksiyonlarının bulunduğu yerdir.
* </p>
*/

#include "Gezegen.h"

Gezegen gezegenOlustur(const char* gezegenAdi) {
    Gezegen gezegen = (Gezegen)malloc(sizeof(struct GEZEGEN));

    strcpy(gezegen->gezegenAdi, gezegenAdi);

    gezegen->gezegenNufus = 0;

    return gezegen;
}

char* getGezegenAdi(Gezegen gezegen) {
    return gezegen->gezegenAdi;
}


int getGezegenNufus(Gezegen gezegen) {
    return gezegen->gezegenNufus;
}

void setGezegengezegenNufus(Gezegen gezegen, int gezegenNufus) {
    gezegen->gezegenNufus = gezegenNufus;
}