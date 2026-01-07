
/*
===================================================================
UZAY FİZİK SİMÜLASYONU – ALGORİTMALAR VE PROGRAMLAMA DERSİ PROJESİ

Hazırlayan:Ayşe GÖKTÜRK
Dönem: 2025-2026 Güz

Bu program Bir bilim insanının, Güneş Sistemi'ndeki gezegenlerin
farklı yerçekimi ivmelerine göre fizik deneylerini simüle eden
konsol tabanlı bir C uygulamasıdır.

Her deney ayrı fonksiyonda yazılmıştır.
Gezegen yer çekimi değerleri için dizi ve pointer kullanılmıştır.
Negatif girdiler ternary operatörü ile pozitife çevrilmiştir.
Bu deneyde tam periyot kullanılmıştır.
=====================================================================
*/

#include <stdio.h>   // printf, scanf fonksiyonları için kullanılır.
#include <math.h>    // sqrt ve pi değeri için kullanılır.
#include <stdlib.h>  //
#define PLANET_COUNT 9   // bu bir sabittir , değiştirilmez. Gezegen sayısı için kullanıldı.
#define PI 3.141592653589793
/*
Gezegen isimleri dizisi
Sırası Güneş'e yakınlığa göredir.
*/
const char *PlanetNames[PLANET_COUNT] = {
    "Mercury", "Venus", "Earth", "Mars",
    "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"
};

/*
Gezegenlerin yerçekimi ivmeleri (m/s^2)
pointer mantığıyla kullanılmak zorundadır.
*/
double gValues[PLANET_COUNT] = {
    3.7, 8.87, 9.81, 3.71, 24.79, 10.44, 8.69, 11.15, 0.62
};

// negatif girdi değerleri ternary operatörü kullanılarak pozitife çevrilmiştir.
double absValue(double x) {
    return x < 0 ? -x : x;
}

/*
-------------------- 1. SERBEST DÜŞME --------------------
Formül: h = 1/2 * g * t^2
Kullanıcıdan süre (t) alınır
Her gezegen için ayrı ayrı yol hesaplanır
----------------------------------------------------------
*/
void serbestDusme(double *g) {
    double t;

    printf("Sureyi giriniz (s): ");
    scanf("%lf", &t);

    // Negatif süre girilirse mutlak değere çevrilir
    t = absValue(t);

    printf("\nDeney: Serbest Dusme Deneyi\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        // Pointer ile dizi elemanına erişim
        double h = 0.5 * (*(g + i)) * t * t;
        // g dizinin başlangıç adresi
        //g+i i.elemanın adresi
        // *(g+i) i.elemanın değeri

        printf("************\n");
        printf("Gezegen: %s\n",PlanetNames[i]);
        printf("Sonuc: %.2f metre\n", h);
    }
}

/*
-------------------- 2. YUKARI ATIŞ --------------------
Formül: h_max = v0^2 / (2g)
Kullanıcıdan ilk hız alınır
--------------------------------------------------------
*/
void yukariAtis(double *g) {
    double v0;

    printf("Ilk hizi giriniz (m/s):");
    scanf("%lf", &v0);

    v0 = absValue(v0);
    printf("\nDeney: Yukari Atis Deneyi\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        double hmax = (v0 * v0) / (2 * (*(g + i)));
        printf("************\n");
        printf("Gezegen: %s\n",PlanetNames[i]);
        printf("Sonuc: %.2f metre\n", hmax);
    }
}

/*
-------------------- 3. AĞIRLIK DENEYİ ---------------------
Formül: G = m * g
------------------------------------------------------------
*/
void agirlikDeneyi(double *g) {
    double m;

    printf("Kutleyi giriniz(kg):");
    scanf("%lf", &m);

    m = absValue(m);
    printf("\nDeney: Agirlik Deneyi\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        double G = m * (*(g+ i));
        printf("************\n");
        printf("Gezegen: %s\n", PlanetNames[i]);
        printf("Sonuc: %.2f Newton\n", G);
    }
}

/*
---------------------4. POTANSİYEL ENERJİ --------------------
Formül: Ep = m * g * h
--------------------------------------------------------------
*/
void potansiyelEnerji(double *g) {
    double m, h;

    printf("Kutle (kg):");
    scanf("%lf", &m);
    printf("Yukseklik (m):");
    scanf("%lf", &h);

    m = absValue(m);
    h = absValue(h);

    printf("\nDeney: Kutlecekimsel Potansiyel Enerji\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        double Ep = m * (*(g+ i)) * h;
        printf("************\n");
        printf("Gezegen: %s\n", PlanetNames[i]);
        printf("Sonuc: %.2f Joule\n", Ep);
    }
}

/*
=------------------ 5. HİDROSTATİK BASINÇ ---------------------
Formül: P = ρ * g * h
---------------------------------------------------------------
*/
void hidrostatikBasinc(double *g) {
    double rho, h;

    printf("Sivi yogunlugu (kg/m^3):");
    scanf("%lf", &rho);
    printf("Derinlik (m):");
    scanf("%lf", &h);

    rho = absValue(rho);
    h = absValue(h);

    printf("\nDeney: Hidrostatik Basinc\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        double P = rho * (*(g+ i)) * h;
        printf("************\n");
        printf("Gezegen: %s\n", PlanetNames[i]);
        printf("Sonuc: %.2f Pascal\n", P);
    }
}

/*
-------------------- 6. ARŞİMET KUVVETİ --------------------
Formül: Fk = ρ * g * V
------------------------------------------------------------
*/
void arsimet(double *g) {
    double rho, V;

    printf("Sivi yogunlugu (kg/m^3):");
    scanf("%lf", &rho);
    printf("Batan hacim (m^3):");
    scanf("%lf", &V);

    rho = absValue(rho);
    V = absValue(V);

    printf("\nDeney: Arsimet Kaldirma Kuvveti\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        double Fk = rho * (*(g+ i)) * V;
        printf("************\n");
        printf("Gezegen: %s\n",PlanetNames[i]);
        printf("Sonuc: %.2f Newton\n", Fk);
    }
}

/*
-------------------- 7. BASİT SARKAÇ --------------------
Formül: T = 2π * sqrt(L / g)
---------------------------------------------------------
*/
void basitSarkac(double *g) {
    double L;

    printf("Sarkac uzunlugu (m):");
    scanf("%lf", &L);

    L = absValue(L);

    printf("\nDeney: Basit Sarkac Periyodu\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        double T = 2 * M_PI * sqrt(L / (*(g+ i)));
        printf("************\n");
        printf("Gezegen: %s\n",PlanetNames[i]);
        printf("Sonuc: %.2f saniye\n", T);
    }
}

/*
------------------- 8. İP GERİLMESİ --------------------
Formül: T = m * g
--------------------------------------------------------
*/
void ipGerilmesi(double *g) {
    double m;

    printf("Kutle (kg):");
    scanf("%lf", &m);

    m = absValue(m);

    printf("\nDeney: Sabit Ip Gerilmesi\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        double T = m * (*(g+ i));
        printf("************\n");
        printf("Gezegen: %s\n",PlanetNames[i]);
        printf("Sonuc: %.2f Newton\n", T);
    }
}

/*
-------------------- 9. ASANSÖR DENEYİ -------------------
Asansör ivmesine bağlı olarak etkin ağırlık hesaplanır
-----------------------------------------------------------
*/
void asansor(double *g) {
    double m, a;

    printf("Kutle (kg):");
    scanf("%lf", &m);
    printf("Asansor ivmesi (m/s^2):");
    scanf("%lf", &a);

    m = absValue(m);

    printf("\nDeney: Asansor Deneyi\n");
    for (int i = 0; i < PLANET_COUNT; i++) {
        double N;
// Asansörün yukarı-aşağı gitmesi durumunda ivmenin alınma şekli
        if (a >= 0)
            N = m * ((*(g+ i)) + a);
        else
            N = m * ((*(g+ i)) - absValue(a));

        printf("************\n");
        printf("Gezegen: %s\n", PlanetNames[i]);
        printf("Sonuc: %.2f Newton\n", N);
    }
}

/*
Bilim insanının adı alınır
Menü sürekli döner -1 girildiğinde program sonlanır
*/
int main() {
    char scientist[50];
    int secim;
    printf("\n--- GUNES SISTEMI FIZIK DENEYLERI SIMULASYONU ---\n");
    printf("Bilim insaninin adini giriniz: ");
    scanf("%s", scientist);

    do {

        printf("Bilim insani: %s\n", scientist);
        printf("1. Serbest Dusme\n");
        printf("2. Yukari Atis\n");
        printf("3. Agirlik\n");
        printf("4. Potansiyel Enerji\n");
        printf("5. Hidrostatik Basinc\n");
        printf("6. Arsimet Kaldirma Kuvveti\n");
        printf("7. Basit Sarkac\n");
        printf("8. Ip Gerilmesi\n");
        printf("9. Asansor\n");
        printf("-1. Cikis\n");
        printf("Seciminiz: ");

        scanf("%d", &secim);

        switch (secim) {
            case 1: serbestDusme(gValues); break;
            case 2: yukariAtis(gValues); break;
            case 3: agirlikDeneyi(gValues); break;
            case 4: potansiyelEnerji(gValues); break;
            case 5: hidrostatikBasinc(gValues); break;
            case 6: arsimet(gValues); break;
            case 7: basitSarkac(gValues); break;
            case 8: ipGerilmesi(gValues); break;
            case 9: asansor(gValues); break;
            case -1: printf("Program sonlandiriliyor...\n"); break;
            default: printf("Gecersiz secim! Lutfen tekrar deneyiniz.\n");
        }

    } while (secim != -1);

    return 0;
}

