/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin dosya okuma fonksiyonlarının bulunduğu yerdir.
* 	Bu sınıfta 3 dosya da okunup içindeki bilglier ait olduğu sınıflara aktarılır
* </p>
*/

#include "DosyaOkuma.h"

KayacGezegen kayacGezegenler[MAX_GEZEGENLER];
int kayacGezegenSayisi = 0;
BuzDeviGezegen buzDeviGezegenler[MAX_GEZEGENLER];
int buzDeviGezegenSayisi = 0;
GazDeviGezegen gazDeviGezegenler[MAX_GEZEGENLER];
int gazDeviGezegenSayisi = 0;
CuceGezegen cuceGezegenler[MAX_GEZEGENLER];
int cuceGezegenSayisi = 0;
Kisi kisiler[MAX_KISILER];
int kisiSayisi = 0;
UzayAraci araclar[MAX_ARACLAR];
int aracSayisi = 0;

void DosyaOkuma(){
    FILE *gezegenDosyasi = fopen("resources/Gezegenler.txt", "r");
    if (gezegenDosyasi) {
        char satir[256];
        while (fgets(satir, sizeof(satir), gezegenDosyasi)) {
            char ad[20];
            int gezegenTuru, gunlukSaat, gun, ay, yil;

            if (sscanf(satir, "%49[^#]#%d#%d#%d.%d.%d", ad, &gezegenTuru, &gunlukSaat, &gun, &ay, &yil) == 6) {
                if (gezegenTuru == 0) {
                    kayacGezegenler[kayacGezegenSayisi++] = KayacGezegenOlustur(ad, gunlukSaat, gun, ay, yil);
                } else if (gezegenTuru == 1) {
                    gazDeviGezegenler[gazDeviGezegenSayisi++] = GazDeviGezegenOlustur(ad, gunlukSaat, gun, ay, yil);
                } else if (gezegenTuru == 2) {
                    buzDeviGezegenler[buzDeviGezegenSayisi++] = BuzDeviGezegenOlustur(ad, gunlukSaat, gun, ay, yil);
                } else if (gezegenTuru == 3) {
                    cuceGezegenler[cuceGezegenSayisi++] = CuceGezegenOlustur(ad, gunlukSaat, gun, ay, yil);
                }
            }
        }
        fclose(gezegenDosyasi);
    }

    FILE *aracDosyasi = fopen("resources/Araclar.txt", "r");
    if (aracDosyasi) {
        char satir[256];
        while (fgets(satir, sizeof(satir), aracDosyasi)) {
            char ad[50], cikis[50], varis[50];
            int gun, ay, yil, mesafe;

            if (sscanf(satir, "%49[^#]#%49[^#]#%49[^#]#%d.%d.%d#%d", ad, cikis, varis, &gun, &ay, &yil, &mesafe) == 7) {
                UzayAraci arac = uzayAraciOlustur(ad, cikis, varis, gun, ay, yil, mesafe);
                araclar[aracSayisi++] = arac;
            }
        }
        fclose(aracDosyasi);
    }

    FILE *kisiDosyasi = fopen("resources/Kisiler.txt", "r");
    if (kisiDosyasi) {
        char satir[256];
        while (fgets(satir, sizeof(satir), kisiDosyasi)) {
            char isim[20], aracAdi[20];
            int yas, kalanOmur;

            if (sscanf(satir, "%49[^#]#%d#%d#%49[^\n]", isim, &yas, &kalanOmur, aracAdi) == 4) {

                for (int i = 0; i < aracSayisi; i++) {
                    if (strcmp(araclar[i]->uzayAraciAdi, aracAdi) == 0) {
                        Kisi kisi = kisiOlustur(isim, yas, kalanOmur, araclar[i]);
                        kisiler[kisiSayisi++] = kisi;
                    }
                }
            }
        }
        fclose(kisiDosyasi);
    }
}