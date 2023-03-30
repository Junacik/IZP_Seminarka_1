#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int VypisMena(char meno[], char *argv[])
{
    char pre2[] = {'a', 'b', 'c','\0'};
    char pre3[] = {'d', 'e', 'f','\0'};
    char pre4[] = {'g', 'h', 'i','\0'};
    char pre5[] = {'j', 'k', 'l','\0'};
    char pre6[] = {'m', 'n', 'o','\0'};
    char pre7[] = {'p', 'q', 'r', 's','\0'};
    char pre8[] = {'t', 'u', 'v','\0'};
    char pre9[] = {'w', 'x', 'y', 'z','\0'};
    char pre0[] = {'+','\0'};
    char *zhoda;
    int i = 0;
    for (;argv[1][i] != '\0'; i++)  
    {
        if (argv[1][i] == '1')
        {
            return 0;
        }
        else if (argv[1][i] == '2')
        {
            zhoda = pre2;
        }
        else if (argv[1][i] == '3')
        {
            zhoda = pre3;
        }
        else if (argv[1][i] == '4')
        {
            zhoda = pre4;   
        }
        else if (argv[1][i] == '5')
        {
            zhoda = pre5;
        }
        else if (argv[1][i] == '6')
        {
            zhoda = pre6;
        }
        else if (argv[1][i] == '7')
        {
            zhoda = pre7;
        }
        else if (argv[1][i] == '8')
        {
            zhoda = pre8;
        }
        else if (argv[1][i] == '9')
        {
            zhoda = pre9;
        }
        else
        {
            zhoda = pre0;
        }
        int j = 0;
        for (; zhoda[j] != '\0'; j++)
        {
            if (zhoda[j] == meno[i])
            {
                meno[i] -= 32;
                break;
            }
        }
        if (zhoda[j] == '\0')
        {
            return 0;
        }
    }
    return 1;
}

int VypisCisla(char cislo[], char *argv[])
{
    int i = 0;
    for (;argv[1][i] != '\0'; i++)  
    {
        if (argv[1][i] >= 48 && argv[1][i] <= 57)
        {
                if (argv[1][i] == cislo[i])
                {
                    
                }
                else
                {
                    return 0;
                }   
        }
        else
        {
                fprintf(stderr,"Chyba: Nespravny format cisla\n");
                return 0;
        }
    }
    return 1;
}



int main(int argc, char *argv[])
{
    char meno[102] = {0};
    char cislo[102] = {0};
    char meno_s[42][102] = {0};
    char cislo_s[42][102] = {0};
    int x = 0;

    while ((fgets(meno, 102, stdin)) && (fgets(cislo, 102, stdin)))
    {
        // Dlzka max 100 znakov
        if ((meno[100] != '\n' && meno[100] != '\0') || (cislo[100] != '\n' && cislo[100] != '\0'))
        {
            fprintf(stderr,"Chyba: Nespravna dlzka mena/cisla\n");
            return 1;
        }
        
        // Format cisla
        for (int i = 0; (cislo[i] != '\n'); i++)
        {
            if (cislo[i] < 48 || cislo[i] > 57 )
            {
                fprintf(stderr,"Chyba: Nespravny format cisla\n");
                return 1;
            }
                         
        }
        
        // Format mena
        for (int i = 0; (meno[i] != '\n'); i++)
        {
            if ((meno[i] < 65 || meno[i] > 90) && (meno[i] < 97 || meno[i] > 122) && meno[i] != 32 && meno[i] != 46)
            {
                fprintf(stderr,"Chyba: Nespravny format mena\n");
                return 1;
            }
                         
        }

        //Ulozenie kontaktu
        for (int i = 0; meno[i] != '\n'; i++)
        {
            meno_s[x][i] = meno[i];
            if (meno_s[x][i] >= 'A' && meno_s[x][i] <= 'Z')
                    {
                        meno_s[x][i] += 32;
                    }  
        }
        for (int i = 0; cislo[i] != '\n'; i++) 
        {
            cislo_s[x][i] = cislo[i];
        }
        x++;

        
    }

    // Bez zadania parametrov vystup vypise vsetky kontakty
    if (argc <= 1)
    {
        for (int i = 0; i < x; i++)
        {
            printf("%s, ", meno_s[i]);
            printf("%s\n", cislo_s[i]); 
        }
        return 0;
    }
    else
    {
        // Nespravne zadane parametre
        for (int i = 0;argv[1][i] != '\0'; i++)  
        {
            if (argv[1][i] >= 48 && argv[1][i] <= 57)
            {

            }
            else
            {
                fprintf(stderr,"Chyba: Nespravne zadane parametre\n");
                return 1;
            }
        }
    }
    
    //Vypis kontaktov zacinajucich na zadany parameter podla mena a cisla
    int z = 0;
    for (int y = 0; y < x; y++)
    {
        if (VypisMena(meno_s[y], argv) == 1 || VypisCisla(cislo_s[y], argv) == 1) 
        {   
            printf("%s, ", meno_s[y]);
            printf("%s\n", cislo_s[y]);
            z+= 1;
        }
    }
    if (z == 0)
    {
        printf("Kontkakt(y) nenalezen(y)\n");
    }

    return 0;
}