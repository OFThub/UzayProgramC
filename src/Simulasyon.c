/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin simülasyon sınıfıdır. Projenin çalışma döngüsünü denetleyen kısımdır.
* </p>
*/

#include "Simulasyon.h"

void SimulasyonBaslat() {
    DosyaOkuma();
    
    while(kontrolSimulasyon()){
        system("cls");
        ZamanIlerlet();
        OmurGuncelle();
        AraclariGuncelle();
        GezegenGuncelle();
        EkranaYazdir();
    }
}

void ZamanIlerlet(){
    for (int i = 0; i < kayacGezegenSayisi; i++) {
        ilerletKayacSaat(kayacGezegenler[i]);
    }
    for (int i = 0; i < buzDeviGezegenSayisi; i++) {
        ilerletBuzDeviSaat(buzDeviGezegenler[i]);
    }
    for (int i = 0; i < gazDeviGezegenSayisi; i++) {
        ilerletGazDeviSaat(gazDeviGezegenler[i]);
    }
    for (int i = 0; i < cuceGezegenSayisi; i++) {
        ilerletCuceSaat(cuceGezegenler[i]);
    }
}

void OmurGuncelle(){
    for (int i = 0; i < kisiSayisi; i++) {
        kalanOmruAzalt(kisiler[i], kayacGezegenSayisi, kayacGezegenler, buzDeviGezegenSayisi, buzDeviGezegenler, gazDeviGezegenSayisi, gazDeviGezegenler, cuceGezegenSayisi, cuceGezegenler);
    }
}

void AraclariGuncelle(){
    for (int i = 0; i < aracSayisi; i++) {
        guncelleAraclari(araclar[i], kayacGezegenSayisi, kayacGezegenler, buzDeviGezegenSayisi, buzDeviGezegenler, gazDeviGezegenSayisi, gazDeviGezegenler, cuceGezegenSayisi, cuceGezegenler, kisiSayisi, kisiler);
    }
}

void EkranaYazdir() {
    GezegenYazdir();
    UzayAraciYazdir();
}

void GezegenYazdir(){
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("Gezegenler:");
    for (int i = 0; i < kayacGezegenSayisi; i++) {
        printf("\t---%s---", getGezegenAdi(kayacGezegenler[i]->super));
    }
    for (int i = 0; i < buzDeviGezegenSayisi; i++) {
        printf("\t---%s---", getGezegenAdi(buzDeviGezegenler[i]->super));
    }
    for (int i = 0; i < gazDeviGezegenSayisi; i++) {
        printf("\t---%s---", getGezegenAdi(gazDeviGezegenler[i]->super));
    }
    for (int i = 0; i < cuceGezegenSayisi; i++) {
        printf("\t---%s---", getGezegenAdi(cuceGezegenler[i]->super));
    }
    printf("\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("Tarih:\t");
    for (int i = 0; i < kayacGezegenSayisi; i++) {
        printf("\t%d.%d.%d", getGun(getKayacGezegenTarih(kayacGezegenler[i])), getAy(getKayacGezegenTarih(kayacGezegenler[i])), getYil(getKayacGezegenTarih(kayacGezegenler[i])));
    }
    for (int i = 0; i < buzDeviGezegenSayisi; i++) {
        printf("\t%d.%d.%d", getGun(getBuzDeviGezegenTarih(buzDeviGezegenler[i])), getAy(getBuzDeviGezegenTarih(buzDeviGezegenler[i])), getYil(getBuzDeviGezegenTarih(buzDeviGezegenler[i])));
    }
    for (int i = 0; i < gazDeviGezegenSayisi; i++) {
        printf("\t%d.%d.%d", getGun(getGazDeviGezegenTarih(gazDeviGezegenler[i])), getAy(getGazDeviGezegenTarih(gazDeviGezegenler[i])), getYil(getGazDeviGezegenTarih(gazDeviGezegenler[i])));
    }
    for (int i = 0; i < cuceGezegenSayisi; i++) {
        printf("\t%d.%d.%d", getGun(getCuceGezegenTarih(cuceGezegenler[i])), getAy(getCuceGezegenTarih(cuceGezegenler[i])), getYil(getCuceGezegenTarih(cuceGezegenler[i])));
    }
    printf("\n");
    printf("Nufus:\t");
    for (int i = 0; i < kayacGezegenSayisi; i++) {
        printf("\t  %d\t", getGezegenNufus(kayacGezegenler[i]->super));
    }
    for (int i = 0; i < buzDeviGezegenSayisi; i++) {
        printf("\t  %d\t", getGezegenNufus(buzDeviGezegenler[i]->super));
    }
    for (int i = 0; i < gazDeviGezegenSayisi; i++) {
        printf("\t  %d\t", getGezegenNufus(gazDeviGezegenler[i]->super));
    }
    for (int i = 0; i < cuceGezegenSayisi; i++) {
        printf("\t  %d\t", getGezegenNufus(cuceGezegenler[i]->super));
    }
    printf("\n");
    printf("Saat:\t");
    for (int i = 0; i < kayacGezegenSayisi; i++) {
        printf("\t %d:00\t", getKayacSaat(kayacGezegenler[i]));
    }
    for (int i = 0; i < buzDeviGezegenSayisi; i++) {
        printf("\t %d:00\t", getBuzDeviSaat(buzDeviGezegenler[i]));
    }
    for (int i = 0; i < gazDeviGezegenSayisi; i++) {
        printf("\t %d:00\t", getGazDeviSaat(gazDeviGezegenler[i]));
    }
    for (int i = 0; i < cuceGezegenSayisi; i++) {
        printf("\t %d:00\t", getCuceSaat(cuceGezegenler[i]));
    }
    printf("\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
}

void UzayAraciYazdir(){
    printf("Uzay Araclari:\n");
    printf("%-20s %-15s %-10s %-10s %-20s %-10s\n", 
        "Arac Adi", 
        "Durum", 
        "Cikis", 
        "Varis", 
        "Hedefe Kalan Saat", 
        "Hedefe Varacagi tarih");
    printf("--------------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < aracSayisi; i++) {
        Zaman varisTarihi = getHedefeVarisTarihi(araclar[i]);
        printf("%-20s %-15s %-10s %-10s %-20d %02d/%02d/%04d\n", 
            getUzayAraciAdi(araclar[i]), 
            getDurum(araclar[i]), 
            getCikisGezegen(araclar[i]), 
            getVarisGezegen(araclar[i]), 
            getMesafe(araclar[i]),
            getGun(varisTarihi),
            getAy(varisTarihi),
            getYil(varisTarihi));

    }
    
    printf("--------------------------------------------------------------------------------------------------------\n");
}

void GezegenGuncelle(){
    for (int i = 0; i < kayacGezegenSayisi; i++) {
        gezegenNufusuGuncelle(kayacGezegenler[i]->super, araclar, aracSayisi, kisiler, kisiSayisi);
    }
    for (int i = 0; i < buzDeviGezegenSayisi; i++) {
        gezegenNufusuGuncelle(buzDeviGezegenler[i]->super, araclar, aracSayisi, kisiler, kisiSayisi);
    }
    for (int i = 0; i < gazDeviGezegenSayisi; i++) {
        gezegenNufusuGuncelle(gazDeviGezegenler[i]->super, araclar, aracSayisi, kisiler, kisiSayisi);
    }
    for (int i = 0; i < cuceGezegenSayisi; i++) {
        gezegenNufusuGuncelle(cuceGezegenler[i]->super, araclar, aracSayisi, kisiler, kisiSayisi);
    }
}

bool kontrolSimulasyon(){
    if(tumAraclarVardiVeyaImhaOldu()){
        return false;
    }
    return true;
}

bool tumAraclarVardiVeyaImhaOldu() {
    int sayac = 0;
    for (int i = 0; i < aracSayisi; i++) {
        if (hedefeVardiMi(araclar[i]) || imhaMi(araclar[i])) {
            sayac++;
        }
    }
    if (sayac == aracSayisi) {
        return true;
    }
    else {
        return false;
    }
}