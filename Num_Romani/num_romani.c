/*
*
* Date: 21/09/2021
*
* Contributors:
*   Visual Laser 10 New
*   Giova-Bell
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LIMITR 9999 //max number
#define NUMLEN 8

char let[] = {'I','V','X','L','C','D','M','N'};
int  num[] = { 1,  5, 10, 50, 100,500,1000,100000};
int  dif[] = { 0,  0,  0,  2,  2,  4,  4, 6};//index to point
            // 0,  1,  1, 10, 10,100,100, 1000 //the last number does not exist, it's only to avoid the program block
void toRoman(unsigned input)
{
    while(input > 0)
    {
        for(int i = 0; i < NUMLEN; i++)
        {
            if(input < num[i])
            {
                if((num[i] - input) == num[dif[i]])
                {
                    printf("%c%c", let[dif[i]], let[i]);
                    input -= (num[i] - num[dif[i]]);
                    break;
                }
                printf("%c", let[i-1]);
                input -= num[i-1];
                break;
            }
        }
    }
}

int main(void)
{
    while(1){
        unsigned num;
        unsigned cifre[5] = {0};
        unsigned cont = 0; // index

        do
        {
            printf("inserisci un numero: ");
            scanf("%u", &num);
        }while(num > LIMITR || num <= 0);
        
        while(num > 0)
        {
            cifre[cont] = (num % 10)*pow(10,cont);
            num = num / 10;
            cont++;
        }

        for(;cont > 0; cont--)
        {
            toRoman(cifre[cont-1]);
        }
        printf("\n");
    }
    return 0;
}
