/*
* Visual Laser 10 New
*/
#include <stdio.h>
#include <string.h>

int is_vowels(char c)
{
    char *vocali = "aeiou";

    if (strchr(vocali, c) != NULL)
    {
        return 1;
    }
    return 0;
}

void check1(int count2, char *flag, char temp[], char num[][20][12])
{
    if(count2>=1 && count2<=3 && *flag == 0)
    {
        strcat(temp, num[count2+2][0]);
        (*flag) = 1;
    }
}

void wv(char first[], char second[])
{
    if(second[0]==0)
        return;
    
    size_t chToCheck = strlen(first)-1;

    if(is_vowels(first[chToCheck]) && is_vowels(second[0]))
    {
        first[chToCheck] = '\0';
    }
}

int from_int_to_string(long long int n, char **output)
{
    char num[][20][12] =
    {
        {"zero", "uno", "due", "tre", "quattro", "cinque", "sei", "sette", "otto", "nove", "dieci", "undici", "dodici", "tredici", "quattordici", "quindici", "sedici", "diciassette", "diciotto", "diciannove"},

        {"np", "np", "venti", "trenta", "quaranta", "cinquanta", "sessanta", "settanta", "ottanta", "novanta"},
        {"cento"},
        {"mila"},
        {"milioni"},
        {"miliardi"},

        {"cento"},
        {"mille"},
        {"un milione"},
        {"un miliardo"}
    };

    char str1[1000] = {'\0'};
    char temp[1000] = {'\0'};

    int cifra = 0;
    int count = 0, count2 = 0;
    char flag = 0;
        
    long long int copy = n;  //copia di n
        
    if(copy == 0)
    {
        strcat(str1, num[0][0]);
    }
        
    while(copy > 0)//da fare che stampa al contrario
    {
        if(count == 0)
        {
            cifra = copy % 100;
            if (cifra > 0 && cifra <= 19)
            {
                if(cifra == 1 && count2 != 0)
                {
                    if(count2>=1 && count2<=3){
                        strcpy(temp, str1);
                        wv(num[count2+6][0], temp);
                        sprintf(str1, "%s%s", num[count2+6][0], temp);
                    }
                    copy /= 10;
                }
                else
                {
                    strcpy(temp, "\0");
                    char temp2[1000] = {'\0'};
                    strcat(temp, num[0][cifra]);
                    copy /= (cifra >= 0 && cifra <= 9) ? 10 : 100;
                    
                    check1(count2, &flag, temp, num);
                    
                    strcpy(temp2, str1);
                    wv(temp, temp2);
                    sprintf(str1, "%s%s", temp, temp2);
                    count = (cifra >= 0 && cifra <= 9) ? count + 1 : count + 2;
                }
                continue;
            }
        }

        cifra = copy % 10;
        copy /= 10;
            
        if(cifra != 0)
        {
            if(count < 2)
            {
                if(count2>=1 && count2<=3 && flag == 0)
                {
                    strcpy(temp, str1);
                    wv(num[count2+2][0], temp);
                    sprintf(str1, "%s%s",  num[count2+2][0], temp);
                    flag = 1;
                }
                strcpy(temp, str1);
                wv(num[count][cifra], temp);
                sprintf(str1, "%s%s", num[count][cifra], temp);
            }
            else
            {
                strcpy(temp, "\0"); // svuota temp
                char temp2[1000] = {'\0'};
                if(cifra == 1)
                {
                    strcat(temp2, num[count+4][0]);
                    check1(count2, &flag, temp2, num);
                }
                else
                {                    
                    strcat(temp2, num[0][cifra]);
                    strcat(temp2, num[count][0]);
                    check1(count2, &flag, temp2, num);
                }
                strcpy(temp, str1);
                wv(temp2, temp);
                sprintf(str1, "%s%s", temp2, temp);
            }
        }
            
        if (count >= 2)
        {
            count = 0;
            count2++;
            flag = 0;
        }
        else
        {
            count++;
        }
    }

    (*output) = str1;
    return 0;
}

int main()
{
    long long int n;
    char *output;
    printf("Inserisci un numero: ");
    scanf("%lld", &n);
    
    from_int_to_string(n, &output);
    printf("%s\n",output);

    return 0;
}