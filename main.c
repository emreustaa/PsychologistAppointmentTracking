/*
@file BP3Proje2 main.c 
@description programda yer alan metodların çağrılması, menü işlemlerinin gerçekleşmesi burada sağlanmıştır. Kullanılan switch case yapısıyla menü oluşturulmuştur.
@assignment BLM204 - Bilgisayar Programlama 3 Proje 2
@date Kod son güncelleme tarihi : 18/12/2019 - 19/12/2019 - 20/12/2019 (Çıkan hatalar sonucunda 25/12/2019 tarihinde düzenleme yapılmıştır.)
@author Emre USTA - emreustaa34@gmail.com

*/

#include "randevu.h"

int main()
{

    typedef enum
    {
        false = 0,
        true = 1
    } bool;

    bool isExitting = true;
    menuGoster();
    while (isExitting)
    {

        int secilen = 0;
        int secilenTip = 0;

        printf("Lutfen yapmak istediginiz islemi seciniz\n");
        scanf("%d", &secilen);
        switch (secilen)
        {
        case 1:
            randevuGoster();
            printf("\n");
            break;
        case 2:
            printf("Lutfen arama yapmak istediginiz tipi seciniz\n");
            scanf("%d", &secilenTip);
            switch (secilenTip)
            {
            case 1:

                randevuIsim();

                break;
            case 2:
                randevuGun();
                printf("\n");
                break;
            case 3:
                menuGoster();
                break;
            default:
                break;
            }
            break;
        case 3:
            randevuVer();
            break;
        case 4:
            randevuSil();
            break;
        case 5:
            isExitting = false;
            break;
        default:
            break;
        }
    }
}
