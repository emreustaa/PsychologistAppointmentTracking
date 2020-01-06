/*
@file BP3Proje2 randevu.c 
@description randevu gösterme, randevu verme, randevu ekleme, randevu silme ve randevu arama işlemleri bu sınıf altında yapılmıştır ayrıca satır bölme ve karakter karakter eşleştirme metodları bu sınıf altında yazılmıştır.
@assignment BLM204 - Bilgisayar Programlama 3 Proje 2
@date Kod son güncelleme tarihi : 18/12/2019 - 19/12/2019 - 20/12/2019 (Çıkan hatalar sonucunda 25/12/2019 tarihinde düzenleme yapılmıştır.)
@author Emre USTA - emreustaa34@gmail.com

*/

#include "randevu.h"
#define SIZE 64
#define PATTERN ","

int randevuSayisi = 1;

struct Randevu
{
    char ad[20];
    int gun;
    int saat;

} randevu;

int rSayisi()
{

    randevuSayisi = 1;
    char c;
    FILE *dosya = fopen("randevu.txt", "r");

    if (dosya == NULL)
    {
        printf("Dosya açma hatası!");
    }
    while (feof(dosya) == 0)
    {
        if (getc(dosya) == '\n')
        {
            randevuSayisi++;
        }
    }

    fclose(dosya);

    return randevuSayisi;
}

void randevuGoster()
{

    FILE *dosya;
    dosya = fopen("randevu.txt", "r+");
    int c;
    char ad[50];
    char soyad[50];
    int i = 0;
    if (dosya == NULL)
    {
        printf("Boyle bir dosya bulunmamaktadir.\n");
    }
    else

    {
        while (fscanf(dosya, "%s %s\n", ad, soyad) != EOF)
        {
            char **data = satirBol(soyad);
            i++;
            switch (i)
            {
            case 1:
                printf("%s %s,%s,%s.00\n", ad, soyad, "Pazartesi", data[2]);
                break;
            case 2:
                printf("%s %s,%s,%s.00\n", ad, soyad, "Sali", data[2]);
                break;
            case 3:
                printf("%s %s,%s,%s.00\n", ad, soyad, "Carsamba", data[2]);
                break;
            case 4:
                printf("%s %s,%s,%s.00\n", ad, soyad, "Sali", data[2]);
                break;
            case 5:
                printf("%s %s,%s,%s.00\n", ad, soyad, "Cumartesi", data[2]);
                break;
            }
        }
    }

    fclose(dosya);
}

void randevuGun()

{
    FILE *dosya;

    char ad[50];
    char soyad[50];
    char girilecekGun[50];
    char gun[5];
    int saat;
    printf("Aradiginiz gunu giriniz\n");
    scanf("%s", girilecekGun);
    dosya = fopen("randevu.txt", "r");

    if (dosya == NULL)
    {
        printf("Dosya acma hatasi\n");
        exit(1);
    }

    while (fscanf(dosya, "%s %s\n", ad, soyad) != EOF)
    {
        char **data = satirBol(soyad);
        if (karakterKontrol(data[1], girilecekGun) != -1)
        {

            printf("%s %s,%s,%s\n", ad, soyad, data[1], data[2]);
        }
    }

    fclose(dosya);
}

void randevuIsim()
{
    FILE *dosya;

    char ad[50];
    char soyad[50];
    char girilecek[50];
    int gun, saat;
    printf("Aradiginiz ismi giriniz\n");
    scanf("%s", girilecek);
    dosya = fopen("randevu.txt", "r");

    if (dosya == NULL)
    {
        printf("Dosya acma hatasi\n");
        exit(1);
    }

    while (fscanf(dosya, "%s %s", ad, soyad) != EOF)
    {
        if (karakterKontrol(ad, girilecek) != -1)
        {

            printf("%s %s\n", ad, soyad);
        }
    }

    fclose(dosya);
}
void randevuVer()
{
    FILE *dosya;
    dosya = fopen("randevu.txt", "a+");

    if (dosya == NULL)
    {
        printf("Dosya bulunmamaktadir./n");
    }
    else
    {
        printf("Kisinin adini giriniz\n");
        scanf("%s", randevu.ad);
        printf("Randevu gununu giriniz\n");
        scanf("%d", &randevu.gun);
        printf("Randevu saatini giriniz\n");
        scanf("%d", &randevu.saat);

        printf("Girilen isim : %s\n", randevu.ad);
        printf("Randevu verilen gun : %d\n", randevu.saat);
        printf("Randevu verilen saat :%d\n", randevu.gun);
        while (!feof(stdin))
        {

            fprintf(dosya, "\n%s,%d,%d", randevu.ad, randevu.gun, randevu.saat);

            break;
        }
        }
    fclose(dosya);
}
void randevuSil()

{
    FILE *dosya;
    FILE *yeniDosya;

    dosya = fopen("randevu.txt", "r");
    yeniDosya = fopen("deneme.txt", "w+");
    char ad[50];
    char soyad[50];
    char girilecek[50];
    int gun, saat;
    printf("Silinecek ismi giriniz\n");
    scanf("%s", girilecek);

    if (dosya == NULL)
    {
        printf("Dosya acma hatasi\n");
        exit(1);
    }

    while (fscanf(dosya, "%s %s", ad, soyad) != EOF)
    {

        if (karakterKontrol(ad, girilecek) == -1)
        {

            fprintf(yeniDosya, "%s %s\n", ad, soyad);
        }
    }

    fclose(dosya);
    fclose(yeniDosya);

    remove("randevu.txt");
    rename("deneme.txt", "randevu.txt");
}

char **satirBol(char *satir)
{
    int size = SIZE, durum = 0;
    char **temps = malloc(size * sizeof(char *));
    char *temp;

    if (!temps)
    {

        return NULL;
    }

    temp = strtok(satir, PATTERN);
    while (temp != NULL)
    {
        temps[durum] = temp;
        durum++;

        if (durum >= size)
        {
            durum += SIZE;
            temps = realloc(temps, size * sizeof(char *));
            if (!temps)
            {

                return NULL;
            }
        }

        temp = strtok(NULL, PATTERN);
    }
    temps[durum] = NULL;
    return temps;
}
int karakterKontrol(char metin[], char aranacak[])
{
    int c, d, e, metinUzunluk, aranacakUzunluk, durum = -1;

    metinUzunluk = strlen(metin);
    aranacakUzunluk = strlen(aranacak);

    if (aranacakUzunluk > metinUzunluk)
    {
        return -1;
    }

    for (c = 0; c <= metinUzunluk - aranacakUzunluk; c++)
    {
        durum = e = c;

        for (d = 0; d < aranacakUzunluk; d++)
        {
            if (aranacak[d] == metin[e])
            {
                e++;
            }
            else
            {
                break;
            }
        }
        if (d == aranacakUzunluk)
        {
            return durum;
        }
    }

    return -1;
}

void menuGoster()
{

    printf("Menu\n");
    printf("--------\n");
    printf("1- Randevulari Goster\n");
    printf("2- Randevu Ara\n");
    printf("   2.1- Ada Gore\n");
    printf("   2.2- Gune Gore\n");
    printf("   2.3- Geri Don\n");
    printf("3- Randevu Ver\n");
    printf("4- Randevu Sil\n");
    printf("5- Exit\n");
}