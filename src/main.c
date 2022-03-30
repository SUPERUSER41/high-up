#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clrscr()
{
    system("@cls||clear");
}

int rollDice(int player)
{
    int points = 0;
    printf("Player %d turn...\n", player + 1);
    srand(time(NULL));
    int dice = 5;
    int roll = 0;
    for (int i = 1; i <= dice; i++)
    {
        roll = rand() % 6 + 1;
        points = roll + points;
        printf("Dice %d: %d\n", i, roll);
    }
    system("read -n1 -r -p \"Press any key to continue...\" key");
    return points;
}

int main()
{
    int numOfPlayers = 0, numOfRounds = 0, points = 0, winner = 0, p, r;

    do
    {
        clrscr();
        printf("Enter number of players:\n");
        scanf("%d", &numOfPlayers);
        if (numOfPlayers == 0 || numOfPlayers > 4 || numOfPlayers == 1)
        {
            printf("Error: only up to two to four players are allowed to play.\n");
            // pause screen
            system("read -n1 -r -p \"Press any key to continue...\" key");
        }
        else
        {
            break;
        }
    } while (numOfPlayers == 0 || numOfPlayers > 4 || numOfPlayers == 1);

    do
    {
        clrscr();
        printf("Enter number of rounds:\n");
        scanf("%d", &numOfRounds);
        if (numOfRounds == 0 || numOfRounds > 10)
        {
            printf("Error: only a maximum of 10 rounds are allowed.\n");
            system("read -n1 -r -p \"Press any key to continue...\" key");
        }
        else
        {
            break;
        }
    } while (numOfRounds == 0 || numOfRounds > 10);

    printf("Number of players:\t\t%d\nNumber of Rounds:\t\t%d\n", numOfPlayers, numOfRounds);

    // Game Loop
    for (r = 1; r <= numOfRounds; r++)
    {
        // Each player rolls a dice
        for (p = 1; p <= numOfPlayers; p++)
        {
            points = rollDice(p);
            printf("Player %d points: %d\n", p, points);
        }
    }

    return 0;
}