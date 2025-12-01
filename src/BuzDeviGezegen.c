#include "BuzDeviGezegen.h"

BuzDeviGezegen BuzDeviGezegenOlustur(const char* gezegenAdi, int gezegenGunlukSaat, int gezegenSaat, int gezegenAy, int gezegenYil) {
    BuzDeviGezegen gezegen = (BuzDeviGezegen)malloc(sizeof(struct BUZDEVIGEZEGEN));
    gezegen->gezegenSaat = 0;
    Zaman zaman = zamanOlustur(gezegenSaat, gezegenAy, gezegenYil);
    gezegen->gezegenTarih = zaman;
    gezegen->gezegenGunlukSaat = gezegenGunlukSaat;
    gezegen->super = gezegenOlustur(gezegenAdi);
    gezegen->zamanKatsayisi = 0.5;
    return gezegen;
}

double getBuzDeviGezegenKatsayisi(BuzDeviGezegen gezegen) {
    return gezegen->zamanKatsayisi;
}

void ilerletBuzDeviSaat(BuzDeviGezegen gezegen){
    gezegen->gezegenSaat++;
    if(gezegen->gezegenSaat>=gezegen->gezegenGunlukSaat){
        gezegen->gezegenSaat=0;
        ilerletGun(gezegen->gezegenTarih);
    }
}

Zaman getBuzDeviGezegenTarih(BuzDeviGezegen gezegen) {
    return gezegen->gezegenTarih;
}

int getBuzDeviSaat(BuzDeviGezegen gezegen) {
    return gezegen->gezegenSaat;
}