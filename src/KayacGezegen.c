#include "KayacGezegen.h"

KayacGezegen KayacGezegenOlustur(const char* gezegenAdi, int gezegenGunlukSaat, int gezegenSaat, int gezegenAy, int gezegenYil) {
    KayacGezegen gezegen = (KayacGezegen)malloc(sizeof(struct KAYACGEZEGEN));
    gezegen->gezegenSaat = 0;
    Zaman zaman = zamanOlustur(gezegenSaat, gezegenAy, gezegenYil);
    gezegen->gezegenTarih = zaman;
    gezegen->gezegenGunlukSaat = gezegenGunlukSaat;
    gezegen->super = gezegenOlustur(gezegenAdi);
    gezegen->zamanKatsayisi = 1.0;
    return gezegen;
}

double getKayacGezegenKatsayisi(KayacGezegen gezegen) {
    return gezegen->zamanKatsayisi;
}

void ilerletKayacSaat(KayacGezegen gezegen){
    gezegen->gezegenSaat++;
    if(gezegen->gezegenSaat>=gezegen->gezegenGunlukSaat){
        gezegen->gezegenSaat=0;
        ilerletGun(gezegen->gezegenTarih);
    }
}

Zaman getKayacGezegenTarih(KayacGezegen gezegen) {
    return gezegen->gezegenTarih;
}

int getKayacSaat(KayacGezegen gezegen) {
    return gezegen->gezegenSaat;
}