#include <stdio.h>
#include <math.h>

double silnia(int a)   //deklaracja funkcji silnia zwracajacej silnie z argumentu
{
    double b = 1, i = 1;
    if (a == 0) return 1;
    else
    {
        while(i <= a)
        {
            b = b*i;
            i += 1;
        }
        return b;
    }     
}
int main()
{
    double x, y1 = 0, y2 = 0, blad1, blad2;
    int i = 0, n;
    printf("Podaj dokladnosc (n):\n");
    scanf("%i", &n);
    if (n < 0) {printf("blad! n musi byc nieujemna!"); return 1;}
    printf("Podaj argument (x):\n");
    scanf("%lf", &x);
    while (i <= n)
    {  
        y1 = y1 + (pow(x,i)/silnia(i));        //sposob 1 - liczenie i dodawanie wyrazow po kolei  
        i += 1;                                //wieksza dokladnosc dla malych n, ale dziala tylko dla n < 647 
    }
    y2 = pow(1+(x/n),n);  //sposob 2 - skorzystanie z granicy (dla malych n horrendalnie wysoki blad, ale im n wieksze, tym blad mniejszy)
                          //przy czym n moze byc na tyle duze na ile pozwala mu uzyty typ danych, np dla inta 2147483647
    printf("%f - wartosc y dla sposobu 1\n", y1);                                               //ladne  
    printf("%f - wartosc y dla sposobu 2\n", y2);                                               //zaprezentowanie
    printf("%f - wartosc y uzysk. przez uzycie standardowej funkcji bibliotecznej\n", exp(x));  //wynikow
    blad1 = (y1 - exp(x))/exp(x);  //obliczanie bledow wzglednych
    blad2 = (y2 - exp(x))/exp(x);
    printf("%f%% - blad wzgledny co do metody 1\n", fabs(blad1*100));
    printf("%f%% - blad wzgledny co do metody 2\n", fabs(blad2*100));
    return 0;
}
