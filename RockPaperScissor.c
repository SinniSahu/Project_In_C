#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int RockPaperScissor(char you, char comp)
{
    // Condition for draw
    if (you == comp)
    {
        return 0;
    }

    // Win or Lose 
    
    if (you=='r' && comp=='s')
        return 1;
    else if (you=='s' && comp=='p')
        return -1;

    if (you=='p' && comp=='r')
        return 1;
    else if (you=='r' && comp=='p')
        return -1;
    
    if (you=='s' && comp=='p')
        return 1;
    else if (you=='p' && comp=='s')
        return -1;
    
}

int main()
{       
    char you, comp;
    srand(time(NULL));
    int num = rand()%100 + 1;  // Generates a random number between 1 and 100
                              // ( + 1 ) to start from 1 ; can do (+ 2) to start from 2;

    if (num<33)             // 1/3 probability
        comp = 'r';
    else if (num>=33 && num<66)
        comp = 'p';
    else
        comp = 's';
    

    printf("Enter 'r' for rock, 'p' for paper and 's' for scissors \n" );  
    scanf("%c", &you);

    int result = RockPaperScissor(you, comp);


    if (result == 0)
        printf("Game draw \n");
    else if (result == 1)
        printf("You Win \n");
    else
        printf("You Lose \n");
    
    printf("You chose ' %c ' and computer chose ' %c '\n", you, comp);

    return 0;
}