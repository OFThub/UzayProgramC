/**
*
* @author Ömer Faruk Türkdoğdu  \\//  omer.turkdogdu@ogr.sakarya.edu.tr
* @since 15.05.2025
* <p>
* 	Bu sınıf projenin simülasyon sınıfıdır. Projenin çalışma döngüsünü denetleyen kısımdır.
* </p>
*/

#ifndef SIMULASYON_H
#define SIMULASYON_H
#include "DosyaOkuma.h"
#include <stdio.h>

void SimulasyonBaslat();
void EkranaYazdir();
void GezegenYazdir();
void UzayAraciYazdir();
void ZamanIlerlet();
void OmurGuncelle();
void AraclariGuncelle();
void GezegenGuncelle();
bool kontrolSimulasyon();
bool tumAraclarVardiVeyaImhaOldu();

#endif