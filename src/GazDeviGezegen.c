#include "GazDeviGezegen.h"

GazDeviGezegen GazDeviGezegenOlustur(const char* gezegenAdi, int gezegenGunlukSaat, int gezegenSaat, int gezegenAy, int gezegenYil) {
    GazDeviGezegen gezegen = (GazDeviGezegen)malloc(sizeof(struct GAZDEVIGEZEGEN));
    gezegen->gezegenSaat = 0;
    Zaman zaman = zamanOlustur(gezegenSaat, gezegenAy, gezegenYil);
    gezegen->gezegenTarih = zaman;
    gezegen->gezegenGunlukSaat = gezegenGunlukSaat;
    gezegen->super = gezegenOlustur(gezegenAdi);
    gezegen->zamanKatsayisi = 0.1;
    return gezegen;
}

double getGazDeviGezegenKatsayisi(GazDeviGezegen gezegen) {
    return gezegen->zamanKatsayisi;
}

void ilerletGazDeviSaat(GazDeviGezegen gezegen){
    gezegen->gezegenSaat++;
    if(gezegen->gezegenSaat>=gezegen->gezegenGunlukSaat){
        gezegen->gezegenSaat=0;
        ilerletGun(gezegen->gezegenTarih);
    }
}

Zaman getGazDeviGezegenTarih(GazDeviGezegen gezegen) {
    return gezegen->gezegenTarih;
}

int getGazDeviSaat(GazDeviGezegen gezegen) {
    return gezegen->gezegenSaat;
}