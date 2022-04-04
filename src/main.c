#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clrscr()
{
    system("@cls||clear");
}

int rollDice(int player)
{
    int dice = 4, roll = 0, score = 0;

    printf("Player %d turn.\n", player + 1);

    for (int i = 1; i <= dice; i++)
    {
        system("read -n1 -r -p \"Press any key to roll the dice.\" key");
        roll = rand() % 6 + 1;
        score = roll + score;
        printf("Dice %d: %d\n", i, roll);
    }
    printf("Player %d scored: %d\n", player + 1, score);
    system("read -n1 -r -p \"Press any key to continue...\" key");
    return score;
}

int main()
{
    int players = 0, rounds = 0, round, player, winner = 0;
    srand(time(0));
    do
    {
        clrscr();
        printf("Enter number of players:\n");
        scanf("%d", &players);
        if (players == 0 || players > 4 || players == 1)
        {
            printf("Error: only up to two to four players are allowed to play.\n");
            system("read -n1 -r -p \"Press any key to continue...\" key");
        }
        else
        {
            break;
        }
    } while (players == 0 || players > 4 || players == 1);

    do
    {
        clrscr();
        printf("Enter number of rounds:\n");
        scanf("%d", &rounds);
        if (rounds == 0 || rounds > 10)
        {
            printf("Error: only a maximum of 10 rounds are allowed.\n");
            system("read -n1 -r -p \"Press any key to continue...\" key");
        }
        else
        {
            break;
        }
    } while (rounds == 0 || rounds > 10);

    int scoreboard[players][rounds];

    // Play game
    for (round = 0; round < rounds; round++)
    {
        for (player = 0; player < players; player++)
        {
            clrscr();
            scoreboard[round][player] = rollDice(player);
        }
    }

    // Display player score for each round
    for (round = 0; round < rounds; round++)
    {
        printf("------Round #%d------\n", round + 1);
        for (player = 0; player < players; player++)
        {
            printf("Player %d scored: %d\n", player + 1, scoreboard[round][player]);
        }
    }
}