#include <stdio.h>
#include <stdlib.h>
void winner(), process(), board(), format();
const char h = 'H';
int c = 0;
char game[3][3] = {{h, h, h},
                   {h, h, h},
                   {h, h, h}};
char player1, player2, choice;
int main()
{
    printf("\nPlayer 1 choose a character:");
    scanf(" %c", &choice);
    if (choice == 'x')
    {
        player1 = choice;
        player2 = 'o';
    }
    else if (choice == 'o')
    {
        player1 = choice;
        player2 = 'x';
    }
    else if (choice != 'x' && choice != 'o')
    {
        printf("Wrong character chosen.");
        main();
    }
    format();
    process();
    return 0;
}
void board()
{printf("\n");
    for (int i = 0; i < 3; i++)
    {  
        for (int j = 0; j < 3; j++)
        {
            printf("%c\t", game[i][j]);
        }
        printf("\n");
    }
}
void format()
{
    printf("00 | 01 | 02\n10 | 11 | 12\n20 | 21 | 22\n");
    printf("Format of board = (row)(column)\n");
}
void process()
{
    board();
    int a, b;
    if (c % 2 == 0)
    {
        printf("Player 1 turn: ");
        scanf("%d %d", &a, &b);
            if (game[a][b] == 'o' || game[a][b] == 'x')
            {
                printf("\nInvalid location selected.\nTry again!\n");
                process();
            }
            else
            {
                game[a][b] = player1;
            }
        board();
    }
    else if (c % 2 != 0)
    {
        printf("Player 2 turn: ");
        scanf("%d %d", &a, &b);
        if (game[a][b] == 'o' || game[a][b] == 'x')
        {
            printf("Invalid location selected.\n Try again!\n");
            process();
        }
        else
        {
            game[a][b] = player2;
            board();
        }
    }
    if (c >= 4)
    {
        winner();
    }
    c++;
    process();
}
void winner()
{
    for (int z = 0; z < 3; z++)
    {
        if ((game[0][z] == game[1][z] && game[1][z] == game[2][z] && game[2][z] == player1) || (game[z][0] == game[z][1] && game[z][1] == game[z][2] && game[z][2] == player1) ||
            (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[2][2] == player1) || (game[2][0] == game[1][1] && game[1][1] == game[0][2] && game[0][2] == player1))
        {
            printf("Player 1 Wins!\n");
            exit(0);
        }
        else if ((game[0][z] == game[1][z] && game[1][z] == game[2][z] && game[2][z] == player2) || (game[z][0] == game[z][1] && game[z][1] == game[z][2] && game[z][2] == player2) ||
                 (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[2][2] == player2) || (game[2][0] == game[1][1] && game[1][1] == game[0][2] && game[0][2] == player2))
        {
            printf("Player 2 Wins!\n");
            exit(0);
        }
    }
    if (c >= 8)
    {
        printf("Draw!\n");
        exit(0);
    }
    else
        c++;
    process();
}