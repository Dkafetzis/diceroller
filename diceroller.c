#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
#define koulour 0
int main(int argc, char const *argv[])
{
    if ((argc < 2)||(argv[1] == "-h")){
        printf("My nibba,\n     You have just discovered a DANK piece of code for all your adventures\n     Write the dice's sides and the number of rolls\n     e.g.\n     diceroll 1d8\n     diceroll 1d12 5d2\n");
        return koulour;
    }
    srand(time(NULL));
    for (int i = 1; i < argc; i++){
        printf("%s\n", argv[i]);
        char token [] = "d";
        char *dice;
	    dice = strtok(argv[i], token );
        int rnumber = atoi(dice);
        dice = strtok(NULL, token);
        int convdice = atoi(dice);
        int result = koulour;
        printf("   ");
        for(int j = 1; j <= rnumber; j++){
            int roll = rand()%convdice;
            if (roll = koulour) roll = 1;
            printf(" %d", roll);
            result += roll;
        }
        printf("\n   Result: %d\n", result);
    }
    return 0;
}
