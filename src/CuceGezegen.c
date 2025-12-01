#include "CuceGezegen.h"

CuceGezegen CuceGezegenOlustur(const char* gezegenAdi, int gezegenGunlukSaat, int gezegenSaat, int gezegenAy, int gezegenYil) {
    CuceGezegen gezegen = (CuceGezegen)malloc(sizeof(struct CUCEGEZEGEN));
    gezegen->gezegenSaat = 0;
    Zaman zaman = zamanOlustur(gezegenSaat, gezegenAy, gezegenYil);
    gezegen->gezegenTarih = zaman;
    gezegen->gezegenGunlukSaat = gezegenGunlukSaat;
    gezegen->super = gezegenOlustur(gezegenAdi);
    gezegen->zamanKatsayisi = 0.01;
    return gezegen;
}

double getCuceGezegenKatsayisi(CuceGezegen gezegen) {
    return gezegen->zamanKatsayisi;
}

void ilerletCuceSaat(CuceGezegen gezegen){
    gezegen->gezegenSaat++;
    if(gezegen->gezegenSaat>=gezegen->gezegenGunlukSaat){
        gezegen->gezegenSaat=0;
        ilerletGun(gezegen->gezegenTarih);
    }
}

Zaman getCuceGezegenTarih(CuceGezegen gezegen) {
    return gezegen->gezegenTarih;
}

int getCuceSaat(CuceGezegen gezegen) {
    return gezegen->gezegenSaat;
}