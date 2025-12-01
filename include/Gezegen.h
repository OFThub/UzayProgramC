/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin gezegen fonksiyonlarının bulunduğu yerdir.
* </p>
*/

#ifndef GEZEGEN_H
#define GEZEGEN_H
#include "Zaman.h"
#include <string.h>
#include <stdio.h>
struct UZAYARACI;

struct GEZEGEN {
    char gezegenAdi[20];
    int gezegenNufus;

    char* (*getGezegenAdi)(struct GEZEGEN);
    int (*getGezegenNufus)(struct GEZEGEN);
};typedef struct GEZEGEN* Gezegen;

Gezegen gezegenOlustur(const char* gezegenAdi);
char* getGezegenAdi(Gezegen gezegen);
int getGezegenNufus(Gezegen gezegen);

#endif
