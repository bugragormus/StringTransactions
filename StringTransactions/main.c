#include <stdio.h>
#include <string.h>

void ddf(char hayir) {
    printf("....Program Sonlandırılmıştır....\n\n");
}

int k1strlen(const char *str1) {
    int n=0;
    const char *p = str1;
    while(*p++ != '\0')
    {
        n++;
    }
    return n;
}

int k2strlen(const char *str2) {
    int n=0;
    const char *p = str2;
    while(*p++ != '\0')
    {
        n++;
    }
    return n;
}

char kstrcpy (char *str1, const char *str2) {
    while ((*str1 = *str2) != '\0') {
            ++str1;
            ++str2;
        }
        return *str1;
}

int kstrcmp(const char *str1, const char *str2) {
    int retValue = 0 ;
    while( *str1 == *str2 )
    {
        if(*str1 == '\0')
        {
            break;
        }
        ++str1;
        ++str2;
    }
    retValue = *str1 - *str2;
    
    return retValue;
}

char kstrcat (char *str1, const char *str2) {
    strcpy( str1 + strlen(str1), str2);
    return *str1;
}

char kstrncat (char *str1, const char *str2, unsigned int n) {
    char *ptr = str1 + strlen(str1);
    while ( ( n > 0) && ( *str2 != '\0')) {
        *ptr = *str2;
        --n;
        ++str2;
        ++ptr;
    }
    *ptr = '\0';
    
    return *str1;
}

int main (void) {
    
    int secim=0;
    char devam=0;
    char hayir=0;
    unsigned long sayi1;
    unsigned long sayi2;
    
soru:
    printf("\nNe Yapmak İstersiniz ?\n\n");
    printf("1. Dizilerin İçerisine Tanımlanan İfadelerin Kaç Harften Oluştuğunu Öğrenmek İçin ---> 1\n\n2. İkinci Dizideki İfadeyi Birinci Diziye Kopyalamak İçin ---> 2\n\n3. Birinci Ve İkinci Dizilerin İçerisine Tanımlanan İfadeleri Alfabetik Olarak Karşılaştırmak İçin ---> 3\n\n4. İkinci Dizinin İçerisindeki İfadeyi Birinci Dizinin Peşinde Eklemek İçin ---> 4\n\n5. Birinici Dizinin İçerisindeki İfadenin İstediğiniz Kadarını İkinci Dizinin Peşine Eklemek İçin ---> 5\n\n");
    printf("Yapmak İstediğiniz İşlemin Kodunu Giriniz: ");
    scanf("%d", &secim);
    
    switch (secim) {
        case 1:
            goto birinci;
            break;
        case 2:
            goto ikinci;
            break;
        case 3:
            goto ucuncu;
            break;
        case 4:
            goto dorduncu;
            break;
        case 5:
            goto besinci;
            break;
        default: {
            printf("\nGeçersiz İşlem Kodu Girdiniz!\n");
        }
    gecersiz:
            printf("\nBaşka İşlem Yapmak İster Misiniz?\n");
            printf("Evet İçin ---> E/e\nHayır İçin ---> H/h\n");
            scanf("%s", &devam);
            if(devam=='e' || devam=='E') {
                goto soru;
            }
            else if(devam=='h' || devam=='H') {
                ddf(hayir);
                return 0;
            }
            else {
                printf("Geçersiz Bir Karakter Girdiniz.");
                goto gecersiz;
            }
    }
    
birinci:
    {
        char *str1="Kirklareli";
        char *str2="Universitesi";
        sayi1 = k1strlen(str1);
        sayi2 = k2strlen(str2);
        printf("\nBirinci Dizinin İçerisine Tanımlanan İfadenin Karakter Uzunluğu : %lu (%s)\n", sayi1, str1);
        printf("İkinci Dizinin İçerisine Tanımlanan İfadenin Karakter Uzunluğu : %lu (%s)\n", sayi2, str2);
        goto here;
    }
    
ikinci:
    {
        char str1[35]="Kırklareli", *str2="Üniversitesi";
        printf("\nBirinci İfade: %s\n", str1);
        printf("İkinci İfade: %s\n\n", str2);
        kstrcpy (str1, str2);
        printf("Kopyalama İşlemi Gerçekleştirildikten Sonra Birinci İfade: %s\n", str1);
        goto here;
    }
    
ucuncu:
    {
        char str1 [] ="Kırklareli";
        char str2 [] ="Universitesi";
        printf("\nBirinci ifade: %s\n", str1);
        printf("İkinci ifade: %s\n\n", str2);
        if (kstrcmp(str1, str2)>0)
            printf("İkinci İfade Alfabetik Olarak İlk Sırada Yer Alır.\n");
        else if (kstrcmp(str1, str2)<0)
            printf("Birinci İfade Alfabetik Olarak İlk Sırada Yer Alır.\n");
        else {
            printf("İki Kelime Birbirinin Aynısıdır.\n");
        }
        goto here;
    }
    
dorduncu:
    {
        char str1 [] ="Kırklareli";
        char str2 [] =" Üniversitesi";
        printf("\nBirinci İfade: %s\n", str1);
        printf("İkinci İfade: %s\n\n", str2);
        kstrcat(str1, str2);
        printf("Ekleme İşlemi Gerçekleştirildikten Sonra Birinci İfade: %s\n", str1);
        goto here;
    }
    
besinci:
    {
        const char str1 [] ="Kirklareli";
        char str2 [] ="Üniversitesi ";
        unsigned int n;
        printf("\nBirinci İfade: %s\n", str1);
        printf("İkinci İfade: %s\n\n", str2);
    yanlis:
        printf("İkinci İfadenin Sonuna Kaç Adet Karakter Eklemek İstiyorsunuz? : ");
        scanf("%d", &n);
        if (n>=0 && n<=strlen(str1)) {
            kstrncat(str2, str1, n);
            printf("Ekleme İşlemi Gerçekleştirildikten Sonra İkinci İfade: %s\n", str2);
        }
        else {
            printf("\nBirinci İfadenin Karakter Uzunluğundan Daha Büyük Bir Sayı Girilemez!\n");
            sayi1= strlen(str1);
            printf("Birinci İfadenin Karakter Uzunluğu : %lu\n", sayi1);
            printf("Lütfen Tekrar Deneyiniz.\n\n");
            goto yanlis;
        }
        goto here;
    }
    
here:
        printf("\nBaşka İşlem Yapmak İster Misiniz?\n");
        printf("Evet İçin ---> E/e\nHayır İçin ---> H/h\n");
        scanf("%s", &devam);
        if(devam=='e' || devam=='E') {
            goto soru;
        }
        else if(devam=='h' || devam=='H') {
            ddf(hayir);
        }
        else {
            printf("Geçersiz Bir Karakter Girdiniz.");
            goto gecersiz;
        }
    
        return 0;
}

