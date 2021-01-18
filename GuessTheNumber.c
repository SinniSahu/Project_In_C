#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int number, guess, nguesses=1;
    srand(time(0));   // time(0) return time in seconds to provide different value                    
                      // if srand(time (0)) is not used, rand() gives only one value.
    number = rand()%100 + 1;  // Generates a random number between 1 and 100
                              // ( + 1 ) to start from 1 ; can do (+ 2) to start from 2;
    // printf(" num is %d \n", number);

    // keep running loop until the number is guessed
                    // Why do while??
                    // Had to give atleast one chance to user.
    do{
        printf("Guess the number between 1 to 100 \n");
        scanf("%d", &guess);

        if(guess > number){
            printf("Lower number please! \n");
        }
        else if (guess < number){
            printf("Higher number please! \n");
        }
        else{
            printf("You guessed it in %d attempts \n", nguesses);
        }
        nguesses++;
        
    }while(guess != number);

    return 0;
}