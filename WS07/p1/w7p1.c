/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  : Kiet Dung Truong
Student ID#: 122088230
Email      :kdtruong@myseneca.ca
Section    :ZII

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define maximumPathLength 70
#include <stdio.h>
struct playerInfo
{
    int remainingLives, treasureFound;
    char playerName;
    int enteredPosition[maximumPathLength];
};
struct gameInfo
{
    struct playerInfo player;
    int pathLength, numberOfMoves;
    int bombs[maximumPathLength], buriedTreasure[maximumPathLength];
};

int main(void)
{
    int flag[maximumPathLength] = {0}, i;
    struct playerInfo player = {0, 0, ' ', {0}};
    struct gameInfo game; // 70*4*2=560 bytes

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");
    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &player.playerName);
    while (flag[0] == 0)
    {
        printf("Set the number of lives: ");
        scanf("%d", &player.remainingLives);
        if (player.remainingLives < 1 || player.remainingLives > 10)
        {
            printf("     Must be between 1 and 10!\n");
        }
        else
        {
            flag[0] = 1;
        }
    }
    printf("Player configuration set-up is complete\n");
    printf("\n");
    printf("GAME Configuration\n");
    printf("------------------\n");
    while (flag[1] == 0)
    {
        printf("Set the path length (a multiple of 5 between 10-70): ");
        scanf("%d", &game.pathLength);
        if (game.pathLength > 70 || game.pathLength < 10 || game.pathLength % 5 != 0)
        {
            printf("     Must be a multiple of 5 and between 10-70!!!\n");
        }
        else
            flag[1] = 1;
    }
    while (flag[2] == 0)
    {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &game.numberOfMoves);
        if (game.numberOfMoves < 3 || game.numberOfMoves > 26)
        {
            printf("    Value must be between 3 and 26\n");
        }
        else

            flag[2] = 1;
    }
    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);

    /* for(i=0, i<length, i++) => for (i=0, i<legth, i+=5)
    {
        scanf("%d %d %d %d %d", &game.bombs[i], &game.bombs[i+1],&game.bombs[i+2],&game.bombs[i+3],&game.bombs[i+4])
    }*/
    for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.bombs[i], &game.bombs[i + 1], &game.bombs[i + 2], &game.bombs[i + 3], &game.bombs[i + 4]);
    }
    printf("BOMB placement set\n");
    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are 35 to set!\n");
        for (i = 0; i < game.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d %d %d %d %d", &game.buriedTreasure[i], &game.buriedTreasure[i + 1], &game.buriedTreasure[i + 2], &game.buriedTreasure[i + 3], &game.buriedTreasure[i + 4]);
    }
    printf("TREASURE placement set\n");
    printf("\n");
    printf("GAME configuration set-up is complete...\n");
        printf("\n");
printf("------------------------------------\n");
printf("TREASURE HUNT Configuration Settings\n");
printf("------------------------------------\n");
printf("Player:\n");
printf("   Symbol     : %c\n", player.playerName);
printf("   Lives      : %d\n", player.remainingLives);
printf("   Treasure   : [ready for gameplay]\n");
printf("   History    : [ready for gameplay]\n");
printf("\n");
printf("Game:\n");
printf("   Path Length: %d\n", game.pathLength);
printf("   Bombs      : ");
for ( i = 0; i < game.pathLength; i++)
{
    printf("%d", game.bombs[i]);

}
    printf("\n");
printf("   Treasure   : ");
for ( i = 0; i < game.pathLength; i++)
{
    printf("%d", game.buriedTreasure[i]);

}
    printf("\n");
    printf("\n");
printf("====================================\n");
printf("~ Get ready to play TREASURE HUNT! ~\n");
printf("====================================\n");

    return 0;
}
