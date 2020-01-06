/*
@file BP3Proje2 randevu.h
@description program içerisinde yer alan tüm metodların protipleri bu header altında yer almaktadır ayrıca diğer sınıflarda kullanılan kütüphaneler burada include edilmiştir.
@assignment BLM204 - Bilgisayar Programlama 3 Proje 2
@date Kod son güncelleme tarihi : 18/12/2019 - 19/12/2019 - 20/12/2019 (Çıkan hatalar sonucunda 25/12/2019 tarihinde düzenleme yapılmıştır.)
@author Emre USTA - emreustaa34@gmail.com

*/

#ifndef randevu_h
#define randevu_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void randevuGoster(void);
void menuGoster(void);
void randevuVer(void);
void randevuGun(void);
void randevuIsim(void);
int rSayisi();
void randevuSil(void);
void yenile(void);
int karakterKontrol(char metin[], char aranacak[]);
char **satirBol(char *satir);
#endif /* randevu_h */
