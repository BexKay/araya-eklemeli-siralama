#include <stdio.h>

/*
Ad Soyad   : Bedirhan Karaismailoğlu
Numara     : 2420171010
Sertifika  : https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=L8dcN6128o
*/

void dizi_yazdir(int dizi[], int sol, int sag) {
    int i;
    for (i = sol; i <= sag; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

void arayaeklemeli_siralama(int dizi[], int sol, int sag) {
    int i, j, key;
    int iterasyon = 1;

    for (i = sol + 1; i <= sag; i++) {
        key = dizi[i];
        j = i - 1;

        /* Büyükten küçüğe */
        while (j >= sol && dizi[j] < key) {
            dizi[j + 1] = dizi[j];
            j--;
        }

        dizi[j + 1] = key;

        printf("iter. %2d: ", iterasyon);
        dizi_yazdir(dizi, sol, sag);
        iterasyon++;
    }
}

int ikili_arama(int dizi[], int sol, int sag, int aranan) {
    int orta;

    while (sol <= sag) {
        orta = (sol + sag) / 2;

        if (dizi[orta] == aranan)
            return orta;
        else if (dizi[orta] < aranan)
            sag = orta - 1;
        else
            sol = orta + 1;
    }
    return -1;
}

int main() {
    int A[] = {42, 17, 8, 29, 55, 13};
    int n = sizeof(A) / sizeof(A[0]);
    int aranan, sonuc;

    printf("\n");
    dizi_yazdir(A, 0, n - 1);

    arayaeklemeli_siralama(A, 0, n - 1);

    printf("\n");
    dizi_yazdir(A, 0, n - 1);

    printf("\nAranacak sayi: ");
    scanf("%d", &aranan);

    sonuc = ikili_arama(A, 0, n - 1, aranan);

    if (sonuc != -1)
        printf("Sayi bulundu. Indeks: %d\n", sonuc);
    else
        printf("Sayi bulunamadi.\n");

    return 0;
}
