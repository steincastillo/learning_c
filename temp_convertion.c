#include <stdio.h>

#define INF -30
#define SUP 100

float fahrenheit;

float convertion (int c);

int main()
{
    int centigrade;
    int delta = 2;

    centigrade = INF;
    while (centigrade <= SUP)
    {
        fahrenheit = convertion(centigrade);
        printf ("%10d C %10.2f F \n", centigrade, fahrenheit);
        centigrade += delta;
    };
    return 0;
}

float convertion (int cent)
{
    float fahr;
    fahr = 9.0/5.0*cent+32;
    return(fahr);
}
