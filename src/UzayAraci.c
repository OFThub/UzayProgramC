/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin uzay aracı fonksiyonlarının bulunduğu yerdir.
* </p>
*/

#include "UzayAraci.h"

UzayAraci uzayAraciOlustur(char* uzayAraciAdi, char* cikisGezegen, char* varisGezegen, int gun, int ay, int yil, int mesafe) {
    UzayAraci uzayAraci = (UzayAraci)malloc(sizeof(struct UZAYARACI));
    strcpy(uzayAraci->uzayAraciAdi, uzayAraciAdi);
    strcpy(uzayAraci->cikisGezegen, cikisGezegen);
    strcpy(uzayAraci->varisGezegen, varisGezegen);
    strcpy(uzayAraci->durum, "Beklemede");
    Zaman cikis = zamanOlustur(gun,ay,yil);
    uzayAraci->cikisTarihi = cikis;
    uzayAraci->mesafe = mesafe;
    uzayAraci->hedefeVarisGun = mesafe/24;
    uzayAraci->yolda = false;
    uzayAraci->hedefeVardi = false;

    return uzayAraci;
}


char* getUzayAraciAdi(UzayAraci uzayAraci) {
    return uzayAraci->uzayAraciAdi;
}

char* getCikisGezegen(UzayAraci uzayAraci) {
    return uzayAraci->cikisGezegen;
}

char* getVarisGezegen(UzayAraci uzayAraci) {
    return uzayAraci->varisGezegen;
}

Zaman getCikisTarihi(UzayAraci uzayAraci) {
    return uzayAraci->cikisTarihi;
}

int getMesafe(UzayAraci uzayAraci) {
    return uzayAraci->mesafe;
}

char* getDurum(UzayAraci uzayAraci) {
    return uzayAraci->durum;
}

void setMesafe(UzayAraci uzayAraci) {
    uzayAraci->mesafe--;
}

void setDurum(UzayAraci uzayAraci, char* durum) {
    strcpy(uzayAraci->durum, durum);
}



Zaman getHedefeVarisTarihi(UzayAraci uzayAraci) {
    Zaman varisTarihi = zamanOlustur(getGun(getCikisTarihi(uzayAraci)), getAy(getCikisTarihi(uzayAraci)), getYil(getCikisTarihi(uzayAraci)));
    for(int i = 0; i < uzayAraci->hedefeVarisGun; i++) {
        ilerletGun(varisTarihi);
    }
    return varisTarihi;
}

