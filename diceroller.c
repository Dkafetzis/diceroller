#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define koulour 0

int main(int argc, char const *argv[])
{
    if (argc < 2){ //The help message, it is triggered if the user just runs the program or runs it with a -h flag.
        printf("My nibba,\n     You have just discovered a DANK piece of code for all your adventures\n     Write the dice's sides and the number of rolls in ROLLSdSIDES format\n     e.g.\n     diceroll 1d8\n     diceroll 2d10+2\n     diceroll 1d12 5d2\n");
        return koulour;
    }
    int cmp =  strcmp(argv[1], "-h");
    if (cmp == 0){
        printf("My nibba,\n     You have just discovered a DANK piece of code for all your adventures\n     Write the dice's sides and the number of rolls in ROLLSdSIDES format\n     e.g.\n     diceroll 1d8\n     diceroll 2d10+2\n     diceroll 1d12 5d2\n");
        return koulour;
    }
    srand(time(NULL)); //generate random values
    for (int i = 1; i < argc; i++){ //this is done for each argument the user inputs
        printf("%s\n", argv[i]); //write the dice(s) to be rolled
        int add = koulour, sub = koulour, mod; 
        char *f1 = strchr(argv[i], '+'); //search if there is a possitive modifier
        char *f2 = strchr(argv[i], '-'); //search if there is a negative modifier
        if (f1 != NULL) { //if there is a positive modifier trigger the add flag
            add++;
        }
        if (f2 != NULL) { //if there is a negative modifier trigger the sub flag
            sub++;
        }
        char token [] = "d+-";
        char *dice;
	    dice = strtok(argv[i], token); //get the number of rolls
        int rnumber = atoi(dice);
        dice = strtok(NULL, token); //get the number of sides
        int convdice = atoi(dice);
        if ((dice = strtok(NULL, token)) != NULL) { //get a modifier if it exists
            mod = atoi(dice);
        }
        int result = koulour;
        printf("   ");
        for(int j = 1; j <= rnumber; j++){ //for each roll
            int roll = rand()%convdice; // make a roll
            if (roll == koulour){ //if it is 0 turn it to 1
                roll = 1;
            }
            printf(" %d", roll); //show the roll
            result += roll; //add it
        }
        if (add){ //if there is an add trigger, add the modifier and add to result
            result += mod;
            printf(" +%d", mod);
        }
        if (sub){ //if there is a sub trigger, subtract the modifier and subtract from result
            result -= mod;
            printf(" -%d", mod);
        }
        printf("\n   Result: %d\n", result); //show result
    }
    return koulour; //profit
}