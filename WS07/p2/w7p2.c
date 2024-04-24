/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P2)
Full Name  :Kiet Dung Truong
Student ID#:122088230
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
    int lives, treasureFound;
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
    struct playerInfo player;
    struct gameInfo game; // 70*4*2=560 bytes
    int remainingMove, remainingLives, nextMove = maximumPathLength + 1;

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
        scanf("%d", &player.lives);
        if (player.lives < 1 || player.lives > 10)
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
        if (game.numberOfMoves < 3 || game.numberOfMoves > 15)
        {
            printf("    Value must be between 3 and 15\n");
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
    printf("Enter the treasure placements in sets of 5 where a value\nof 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", game.pathLength);
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
    printf("   Lives      : %d\n", player.lives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");
    printf("\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", game.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.bombs[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < game.pathLength; i++)
    {
        printf("%d", game.buriedTreasure[i]);
    }
    printf("\n");
    printf("\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");
    printf("\n");
    remainingMove = game.numberOfMoves;
    remainingLives = player.lives;
    player.treasureFound = 0;
    int v_Count = 0;

    char positionItem[maximumPathLength];
    char currentPosition[maximumPathLength];
    for (i = 0; i < game.pathLength; i++)
    {
        player.enteredPosition[i] = 0;
    }
    for (i = 0; i < game.pathLength; i++)
    {
        positionItem[i] = '-';
    }
    for (i = 0; i < game.pathLength; i++)
    {
        currentPosition[i] = ' ';
    }

    do
    {
        // line 1
        for (i = 0; i < game.pathLength; i++)
        {
            if (currentPosition[i] == 'V')
            {
                v_Count++;
            }
        }
        if (v_Count == 0)
        {
            printf("\n");
        }
        else
        {
            printf("  ");
            for (i = 0; i < game.pathLength; i++)
            {
                if (currentPosition[i] == 'V')
                {
                    printf("%c\n", currentPosition[i]);
                    break;
                }
                else
                {
                    printf("%c", currentPosition[i]);
                }
            }
        }

        // Tracking current position requires the previous pointer to dissapear
        for (i = 0; i < game.pathLength; i++)
        {
            currentPosition[i] = ' ';
        }
        // line 2: the game path

        printf("  ");
        for (i = 0; i < game.pathLength; i++)
        {
            printf("%c", positionItem[i]);
        }
        printf("\n");

        // for (i = 0; i < game.pathLength; i++)
        // {
        //     if (player.enteredPosition[i] == 0)
        //         printf("-");
        //     else if (player.enteredPosition[i] == 1)
        //     {
        //         printf("!");
        //     }
        //     else if (player.enteredPosition[i] == 2)
        //     {
        //         printf("$");
        //     }
        //     else if (player.enteredPosition[i] == 3)
        //     {
        //         printf("&");
        //     }
        //     else if (player.enteredPosition[i] == 4)
        //     {
        //         printf(".");
        //     }
        // }
        // line 3
        printf("  ");
        for (i = 1; i <= game.pathLength; i++)
        {
            if (i % 10 == 0)
            {
                printf("%d", i / 10);
            }
            else
                printf("|");
        }
        printf("\n");
        // line 4
        printf("  ");
        for (i = 0; i < game.pathLength; i += 10)
        {
            printf("1234567890");
        }
        printf("\n");

        // 4. Display player's statics

        printf("+---------------------------------------------------+\n");
        printf(" Lives: %2d | Treasures: %2d | Moves Remaining: %2d\n", remainingLives, player.treasureFound, remainingMove);
        printf("+---------------------------------------------------+\n");
        if (remainingLives == 0)
        {
            break; // use flag
        }
        if (remainingMove == 0)
        {
            break;
        }

        // Prompt player next move
        // while (flag[3] == 0)
        do
        {
            printf("Next Move [1-%2d]: ", game.pathLength);
            scanf(" %2d", &nextMove);
            if (nextMove < 1 || nextMove > game.pathLength)
            {
                printf("  Out of Range!!!\n");
            }
            // else
            // {
            //     flag[3] = 1;
            // }
        }while(nextMove<1 || nextMove> game.pathLength);
        printf("\n");

        // 6. check if previuosly visit?
        if (player.enteredPosition[nextMove - 1] == 1)
        {
            printf("===============> Dope! You've been here before!\n");
            remainingMove++;
            currentPosition[nextMove - 1] = 'V';
        }
        else if (game.bombs[nextMove - 1] == 1 && game.buriedTreasure[nextMove - 1] == 1)
        {
            currentPosition[nextMove - 1] = 'V';

            remainingLives--;
            player.treasureFound++;
            // player.enteredPosition[i] = 3;
            positionItem[nextMove - 1] = '&';
            printf("===============> [&] !!! BOOOOOM !!! [&]\n");
            printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
        }

        else if (game.bombs[nextMove - 1] == 1)
        {
            printf("===============> [!] !!! BOOOOOM !!! [!]\n");
            currentPosition[nextMove - 1] = 'V';

            positionItem[nextMove - 1] = '!';
            // player.enteredPosition[i] = 1;
            remainingLives--;
        }
        else if (game.buriedTreasure[nextMove - 1] == 1)
        {
            printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
            positionItem[nextMove - 1] = '$';
            // player.enteredPosition[i] = 2;
            player.treasureFound++;
            currentPosition[nextMove - 1] = 'V';
        }
        else
        {
            printf("===============> [.] ...Nothing found here... [.]\n");
            currentPosition[nextMove - 1] = 'V';
            positionItem[nextMove - 1] = '.';
        }

        player.enteredPosition[nextMove - 1] = 1;
        remainingMove--;
        if (remainingLives == 0)
        {
            printf("No more LIVES remaining!\n");
        }
        if (remainingMove == 0)
        {
            printf("No more MOVES remaining!\n\n");
        }

        // else // 7.
        // {
        //     player.enteredPosition[nextMove - 1] = 1;
        //     game.numberOfMoves -= 1;
        //     if (game.bombs[nextMove - 1] == 1)
        //     {
        //         player.lives -= 1;
        //     }
        // }
    } while (remainingLives >= 0 && remainingMove >= 0);
    printf("\n");
    printf("##################\n");
    printf("# Game over! #\n");
    printf("##################\n");
    printf("\n");
    printf("You should play again and try to beat your score!\n");
    return 0;
}
