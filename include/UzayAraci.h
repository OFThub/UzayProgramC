/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin uzay aracı fonksiyonlarının bulunduğu yerdir.
* </p>
*/

#ifndef UZAYARACI_H
#define UZAYARACI_H
#include "Zaman.h"
#include "Gezegen.h"
#include <string.h>

struct UZAYARACI {
    char uzayAraciAdi[20];
    char cikisGezegen[20];
    char varisGezegen[20];
    Zaman cikisTarihi;
    int mesafe;
    int hedefeVarisGun;
    char durum[10];
    bool yolda;
    bool hedefeVardi;

    char* (*getUzayAraciAdi)(struct UZAYARACI);
    char* (*getCikisGezegen)(struct UZAYARACI);
    char* (*getVarisGezegen)(struct UZAYARACI);
    Zaman (*getCikisTarihi)(struct UZAYARACI);
    int (*getMesafe)(struct UZAYARACI);
    char* (*getDurum)(struct UZAYARACI);
    void (*setMesafe)(struct UZAYARACI);
    void (*setDurum)(struct UZAYARACI, char*);
    Zaman (*getHedefeVarisTarihi)(struct UZAYARACI);
};typedef struct UZAYARACI* UzayAraci;

UzayAraci uzayAraciOlustur(char* uzayAraciAdi, char* cikisGezegen, char* varisGezegen,  int gun, int ay, int yil, int mesafe);
char* getUzayAraciAdi(UzayAraci uzayAraci);
char* getCikisGezegen(UzayAraci uzayAraci);
char* getVarisGezegen(UzayAraci uzayAraci);
Zaman getCikisTarihi(UzayAraci uzayAraci);
int getMesafe(UzayAraci uzayAraci);
char* getDurum(UzayAraci uzayAraci);
void setMesafe(UzayAraci uzayAraci);
void setDurum(UzayAraci uzayAraci, char* durum);
Zaman getHedefeVarisTarihi(UzayAraci uzayAraci);

#endif