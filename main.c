/**
 * This program counts frequencies from the input
 * Uncomment the block of code in the section countInput(){}
 * for count which frequencies reaches input twice!
 * #UPDATE1: REACHES TWICE got own function
 * AdoC 2018 #day1 && day2
 * **/

#include <stdio.h>

int countInput(int *counterLines);
int reachesTwice(int lines);

int main(int argc, char **argv)
{
    int counterLines = 0;
    printf("----------------\n");
    printf("    SUM IS:\n");
    printf("      %d\n", countInput(&counterLines));
    printf("----------------\n");
    printf(" REACHES TWICE:\n");
    printf("      %d\n", reachesTwice(counterLines));
    printf("----------------\n");

    return 0;
}

int countInput(int *counterLines)
{
    FILE *f;
    f = fopen("input2", "r");
    int loadedNumber;
    int counter = 0;
    int sum = 0;

    while (fscanf(f, "%d", &loadedNumber) != EOF){
        sum += loadedNumber;
        counter++;
    }

    *counterLines = counter;                        //count lines, so we dont have to use dynamicaly allocated mem
                                                    //bcs in next function we will use array
    fclose(f);
    return sum;
}

int reachesTwice(int lines)
{
    FILE *f;
    f = fopen("input2", "r");

    //ARRAYS
    int array[lines];

    //VARIABLES
    int loadedNumber;
    int i = 0;
    int sum = 0;

    int toBreak = 0;

    while (fscanf(f, "%d", &loadedNumber) != EOF){  //we knew that the input will be only numbers
        sum += loadedNumber;                        //so we dont have to use strtol and control input
        array[i] = sum;

        for (int j = (i-1); j >= 0; j--){           //everytime new sum is added
            if (array[j] == array[i]){              //loop check if there isnt same sum before
                toBreak = 1;                        //if yes, breaks through both loops
                break;
            }
        }
        if (toBreak == 1){                          //condition for second break
            break;
        }
        i++;
    }

    fclose(f);

    return array[i];
}

