/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin kişi fonksiyonlarının bulunduğu yerdir.
* 	Bu sınıftan kişiyle ilgili bilgiler elde edilir.
* </p>
*/

#ifndef KISI_H
#define KISI_H
#include <stdlib.h>  
#include <string.h>
#include "KayacGezegen.h"
#include "BuzDeviGezegen.h"
#include "GazDeviGezegen.h"
#include "CuceGezegen.h"
#include "UzayAraci.h"
#include "Zaman.h"

struct KISI {
    char isim[20];
    double yas;
    double kalanOmur;
    UzayAraci bulunduguUzayAraci;

    char*(*getIsim)(struct KISI);
    double(*getYas)(struct KISI);
    double(*getKalanOmur)(struct KISI);
    UzayAraci(*getBulunduguUzayAraci)(struct KISI);
    char*(*getBulunduguUzayAraciAdi)(struct KISI);
    void(*kalanOmruAzalt)(struct KISI,int, struct KAYACGEZEGEN,int, struct BUZDEVIGEZEGEN,int, struct GAZDEVIGEZEGEN,int, struct CUCEGEZEGEN);
    bool(*hayattaMi)(struct KISI);
    bool (*yoldaMi)(struct UZAYARACI);
    bool (*hedefeVardiMi)(struct UZAYARACI);
    bool (*imhaMi)(struct UZAYARACI);
    void(*yoket)(struct KISI*);
    void(*guncelleAraclari)(struct UZAYARACI, int, struct KAYACGEZEGEN,int, struct BUZDEVIGEZEGEN,int, struct GAZDEVIGEZEGEN,int, struct CUCEGEZEGEN, int, struct KISI);
    void(*gezegenNufusuGuncelle)(struct GEZEGEN, struct UZAYARACI[], int, struct KISI*[], int);
};
typedef struct KISI* Kisi;

Kisi kisiOlustur(char* isim, double yas, double kalanOmur, UzayAraci bulunduguUzayAraci);
char* getIsim(Kisi k);
double getYas(Kisi k);
double getKalanOmur(Kisi k);
UzayAraci getBulunduguUzayAraci(Kisi k);
char* getBulunduguUzayAraciAdi(Kisi k);
void yoket(Kisi k);
void kalanOmruAzalt(Kisi kisi,int kayacGezegenSayisi, KayacGezegen kayacGezegenler[],int buzDeviGezegenSayisi, BuzDeviGezegen buzDeviGezegenler[],int gazDeviGezegenSayisi, GazDeviGezegen gazDeviGezegenler[],int cuceGezegenSayisi, CuceGezegen cuceGezegenler[]);
bool hayattaMi(Kisi kisi);
void guncelleAraclari(UzayAraci uzayAraci,int kayacGezegenSayisi, KayacGezegen kayacGezegenler[],int buzDeviGezegenSayisi, BuzDeviGezegen buzDeviGezegenler[],int gazDeviGezegenSayisi, GazDeviGezegen gazDeviGezegenler[],int cuceGezegenSayisi, CuceGezegen cuceGezegenler[], int kisiSayisi, Kisi kisiler[]);
void gezegenNufusuGuncelle(Gezegen gezegen, UzayAraci uzayAraci[], int aracSayisi, Kisi kisiler[], int kisiSayisi);
bool yoldaMi(UzayAraci uzayAraci);
bool hedefeVardiMi(UzayAraci uzayAraci);
bool imhaMi(UzayAraci uzayAraci);

#endif