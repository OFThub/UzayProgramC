/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin kişi fonksiyonlarının bulunduğu yerdir.
* 	Bu sınıftan kişiyle ilgili bilgiler elde edilir.
* </p>
*/

#include "Kisi.h"

Kisi kisiOlustur(char* isim, double yas, double kalanOmur, UzayAraci bulunduguUzayAraci) {
    Kisi k = (Kisi)malloc(sizeof(struct KISI));
    strcpy(k->isim, isim);
    k->yas = yas;
    k->kalanOmur = kalanOmur;
    k->bulunduguUzayAraci= bulunduguUzayAraci;
    return k;
}

char* getIsim(Kisi k) {
    return k->isim;
}

double getYas(Kisi k) {
    return k->yas;
}

double getKalanOmur(Kisi k) {
    return k->kalanOmur;
}

UzayAraci getBulunduguUzayAraci(Kisi k) {
    return k->bulunduguUzayAraci;
}

char* getBulunduguUzayAraciAdi(Kisi k) {
    return k->bulunduguUzayAraci->uzayAraciAdi;
}


bool hayattaMi(Kisi kisi) {
    return kisi->kalanOmur > 0;
}

void kalanOmruAzalt(Kisi kisi,int kayacGezegenSayisi, KayacGezegen kayacGezegenler[],int buzDeviGezegenSayisi, BuzDeviGezegen buzDeviGezegenler[],int gazDeviGezegenSayisi, GazDeviGezegen gazDeviGezegenler[],int cuceGezegenSayisi, CuceGezegen cuceGezegenler[]) {
    if(kisi->kalanOmur > 0) {
            if(strcmp(getDurum(kisi->bulunduguUzayAraci), "Beklemede") == 0) {
                for(int i=0;i<kayacGezegenSayisi;i++) {
                    if(strcmp(getCikisGezegen(getBulunduguUzayAraci(kisi)), getGezegenAdi(kayacGezegenler[i]->super)) == 0) {
                        kisi->kalanOmur-=getKayacGezegenKatsayisi(kayacGezegenler[i]);
                        kisi->yas+=getKayacGezegenKatsayisi(kayacGezegenler[i])/(double)(364*24);
                        return;
                    }
                }
                for(int i=0;i<buzDeviGezegenSayisi;i++) {
                    if(strcmp(getCikisGezegen(getBulunduguUzayAraci(kisi)), getGezegenAdi(buzDeviGezegenler[i]->super)) == 0) {
                        kisi->kalanOmur-=getBuzDeviGezegenKatsayisi(buzDeviGezegenler[i]);
                        kisi->yas+=getBuzDeviGezegenKatsayisi(buzDeviGezegenler[i])/(double)(364*24);
                        return;
                    }
                }
                for(int i=0;i<gazDeviGezegenSayisi;i++) {
                    if(strcmp(getCikisGezegen(getBulunduguUzayAraci(kisi)), getGezegenAdi(gazDeviGezegenler[i]->super)) == 0) {
                        kisi->kalanOmur-=getGazDeviGezegenKatsayisi(gazDeviGezegenler[i]);
                        kisi->yas+=getGazDeviGezegenKatsayisi(gazDeviGezegenler[i])/(double)(364*24);
                        return;
                    }
                }
                for(int i=0;i<cuceGezegenSayisi;i++) {
                    if(strcmp(getCikisGezegen(getBulunduguUzayAraci(kisi)), getGezegenAdi(cuceGezegenler[i]->super)) == 0) {
                        kisi->kalanOmur-=getCuceGezegenKatsayisi(cuceGezegenler[i]);
                        kisi->yas+=getCuceGezegenKatsayisi(cuceGezegenler[i])/(double)(364*24);
                        return;
                    }
                }
            }

            if(strcmp(getDurum(kisi->bulunduguUzayAraci), "Vardi") == 0) {
                for(int i=0;i<kayacGezegenSayisi;i++) {
                    if(strcmp(getVarisGezegen(getBulunduguUzayAraci(kisi)), getGezegenAdi(kayacGezegenler[i]->super)) == 0) {
                        kisi->kalanOmur-=getKayacGezegenKatsayisi(kayacGezegenler[i]);
                        kisi->yas+=getKayacGezegenKatsayisi(kayacGezegenler[i])/(double)(364*24);
                        return;
                    }
                }
                for(int i=0;i<buzDeviGezegenSayisi;i++) {
                    if(strcmp(getVarisGezegen(getBulunduguUzayAraci(kisi)), getGezegenAdi(buzDeviGezegenler[i]->super)) == 0) {
                        kisi->kalanOmur-=getBuzDeviGezegenKatsayisi(buzDeviGezegenler[i]);
                        kisi->yas+=getBuzDeviGezegenKatsayisi(buzDeviGezegenler[i])/(double)(364*24);
                        return;
                    }
                }
                for(int i=0;i<gazDeviGezegenSayisi;i++) {
                    if(strcmp(getVarisGezegen(getBulunduguUzayAraci(kisi)), getGezegenAdi(gazDeviGezegenler[i]->super)) == 0) {
                        kisi->kalanOmur-=getGazDeviGezegenKatsayisi(gazDeviGezegenler[i]);
                        kisi->yas+=getGazDeviGezegenKatsayisi(gazDeviGezegenler[i])/(double)(364*24);
                        return;
                    }
                }
                for(int i=0;i<cuceGezegenSayisi;i++) {
                    if(strcmp(getVarisGezegen(getBulunduguUzayAraci(kisi)), getGezegenAdi(cuceGezegenler[i]->super)) == 0) {
                        kisi->kalanOmur-=getCuceGezegenKatsayisi(cuceGezegenler[i]);
                        kisi->yas+=getCuceGezegenKatsayisi(cuceGezegenler[i])/(double)(364*24);
                        return;
                    }
                }
            }
            
            else{
                kisi->kalanOmur--;
            }
    }

    else{
        kisi->kalanOmur = 0;
    }
}

void guncelleAraclari(UzayAraci uzayAraci, int kayacGezegenSayisi, KayacGezegen kayacGezegenler[],int buzDeviGezegenSayisi, BuzDeviGezegen buzDeviGezegenler[],int gazDeviGezegenSayisi, GazDeviGezegen gazDeviGezegenler[],int cuceGezegenSayisi, CuceGezegen cuceGezegenler[], int kisiSayisi, Kisi kisiler[]) {
    bool yasayanVar = false;
    
    for (int i = 0; i < kisiSayisi; i++) {
        if (hayattaMi(kisiler[i])) {
            char* aracAdi = getBulunduguUzayAraciAdi(kisiler[i]);
            if (aracAdi != NULL && strcmp(aracAdi, uzayAraci->uzayAraciAdi) == 0) {
                yasayanVar = true;
                break;
            }
        }
    }

    if (!yasayanVar) {
        strcpy(uzayAraci->durum, "IMHA");
        uzayAraci->mesafe = 0;
        return;
    }

    Zaman cikisGezegen = NULL;
    for (int i = 0; i < kayacGezegenSayisi; i++) {
        if (strcmp(getGezegenAdi(kayacGezegenler[i]->super), getCikisGezegen(uzayAraci)) == 0) {
            cikisGezegen = getKayacGezegenTarih(kayacGezegenler[i]);
            break;
        }
    }

    for (int i = 0; i < buzDeviGezegenSayisi; i++) {
        if (strcmp(getGezegenAdi(buzDeviGezegenler[i]->super), getCikisGezegen(uzayAraci)) == 0) {
            cikisGezegen = getBuzDeviGezegenTarih(buzDeviGezegenler[i]);
            break;
        }
    }

    for (int i = 0; i < gazDeviGezegenSayisi; i++) {
        if (strcmp(getGezegenAdi(gazDeviGezegenler[i]->super), getCikisGezegen(uzayAraci)) == 0) {
            cikisGezegen = getGazDeviGezegenTarih(gazDeviGezegenler[i]);
            break;
        }
    }

    for (int i = 0; i < cuceGezegenSayisi; i++) {
        if (strcmp(getGezegenAdi(cuceGezegenler[i]->super), getCikisGezegen(uzayAraci)) == 0) {
            cikisGezegen = getCuceGezegenTarih(cuceGezegenler[i]);
            break;
        }
    }

    if (!uzayAraci->yolda && !uzayAraci->hedefeVardi && cikisGezegen != NULL && esitMi(cikisGezegen, uzayAraci->cikisTarihi)) {
        uzayAraci->yolda = true;
        strcpy(uzayAraci->durum, "Yolda");
    }

    if (uzayAraci->yolda && uzayAraci->mesafe > 0) {
        uzayAraci->mesafe--;
        if (uzayAraci->mesafe == 0) {
            uzayAraci->yolda = false;
            uzayAraci->hedefeVardi = true;
            strcpy(uzayAraci->durum, "Vardi");
        }
    }
}

void gezegenNufusuGuncelle(Gezegen gezegen, UzayAraci uzayAraci[], int aracSayisi, Kisi kisiler[], int kisiSayisi) {
    gezegen->gezegenNufus = 0;

    for (int i = 0; i < aracSayisi; i++) {
        for (int j = 0; j < kisiSayisi; j++) {
            if (strcmp(getBulunduguUzayAraciAdi(kisiler[j]), uzayAraci[i]->uzayAraciAdi) == 0) {
                if (!hayattaMi(kisiler[j])) continue;

                if (strcmp(uzayAraci[i]->durum, "Beklemede") == 0) {
                    if (strcmp(uzayAraci[i]->cikisGezegen, gezegen->gezegenAdi) == 0) {
                        gezegen->gezegenNufus++;
                    }
                } else if (strcmp(uzayAraci[i]->durum, "Vardi") == 0) {
                    if (strcmp(uzayAraci[i]->varisGezegen, gezegen->gezegenAdi) == 0) {
                        gezegen->gezegenNufus++;
                    }
                }
            }
        }
    }
}

bool yoldaMi(UzayAraci uzayAraci) {
    return uzayAraci->yolda;
}

bool hedefeVardiMi(UzayAraci uzayAraci) {
    return uzayAraci->hedefeVardi;
}

bool imhaMi(UzayAraci uzayAraci) {
    return strcmp(uzayAraci->durum, "IMHA") == 0;
}