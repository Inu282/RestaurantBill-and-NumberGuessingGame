#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int caseQ()
{
    return 1;
}
int startScreen()
{
    int userIn;
    printf("\nWelcome to the number guessing game! \n");
    printf("To begin select 1\n");
    printf("To change the max value select 2\n");
    printf("To quit select 3\n");
    scanf("%d", &userIn);
    return userIn;
}

int newMax()
{
    int newNum;
    printf("\nPlease choose a new max number up to 10: ");
    scanf("%d", &newNum);
    if (newNum > 0 && newNum <= 10)
    {
        return newNum;
    }
    else
    {
        printf("Number is invalid, please try again: ");
        newMax();
    }
}

int main()
{
    FILE *fp;
    bool check = false;
    time_t t;
    srand((unsigned)time(&t));
    int max = 10;
    int random = rand() % max;

    while (check == false)
    {
        int start = startScreen();
        if (start == 1)
        {
            bool check2 = false;
            while (check2 == false)
            {
                int guess;
                printf("Please enter a guess between 1 and %d: ", max);
                scanf("%d", &guess);
                if (guess == random)
                {
                    printf("Congrats on guessing correctly! You will now be sent back to the menu.\n");
                    check2 = true;
                }
                else if (guess > random)
                {
                    printf("Guess was too high, please try again.\n");
                }
                else if (guess < random)
                {
                    printf("Guess was too low, please try again.\n");
                }
            }
        }
        else if (start == 2)
        {
            max = newMax();
            fp = fopen("userMax.txt", "w");

            putw(max, fp);
            fclose(fp);
            printf("New max has been set to %d, now returning to start\n", max);
        }
        else if (start == 3)
        {
            printf("Thanks for playing!");
            check = true;
        }
        else
        {
            printf("This game has ended.");
            break;
        }
    }
}
