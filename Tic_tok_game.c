// Tic tak toe game
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> // for bool
#include <time.h>
#include <windows.h>

#define TRUE 1
#define FALSE 0
void PRINTC(int c, char *s)
{
    printf("\033[%dm"
           "%s"
           "\033[34m",
           30 + c, s);
}
// our board
void board(char x, char o, unsigned char *player1, unsigned char *player2, char *a)
{
    int i;
    system("cls"); //  to clear 
    PRINTC(3, "\t************___ Tic-Tac-Toe____************\n\n");

    printf("Player "
           "\x1b[35m"
           " %s "
           "\x1b[34m"
           " has taken  %c ",
           player1, x);
    printf("\nPlayer "
           "\x1b[35m"
           " %s "
           "\x1b[34m"
           " has taken  %c \n",
           player2, o);
    printf("\n\t");
    for (int i = 0; i < 9; i++)
    {
        if (a[i] == 'X' || a[i] == 'x')
            printf("\x1b[37m"
                   " %2c "
                   "\x1b[0m"
                   "\x1b[34m",
                   a[i]);
        else if (a[i] == '0' || a[i] == 'o' || a[i] == 'O')
            printf("\x1b[33m"
                   " %2c "
                   "\x1b[34m",
                   a[i]);
        else
            printf("\x1b[32m"
                   " %2c "
                   "\x1b[34m",
                   a[i]);
        if (i == 2 || i == 5 || i == 8)
        {
            printf("\n\t  ---------------");
            printf("\n\t");
        }
        else
            printf(" | ");
    }
}

// check for winning condition
int checkforwin(char *a)
{
    if (a[0] == a[1] && a[1] == a[2])
        return 1;
    else if (a[3] == a[4] && a[4] == a[5])
        return 1;
    else if (a[6] == a[7] && a[7] == a[8])
        return 1;
    else if (a[0] == a[3] && a[3] == a[6])
        return 1;
    else if (a[1] == a[4] && a[4] == a[7])
        return 1;
    else if (a[2] == a[5] && a[5] == a[8])
        return 1;
    else if (a[0] == a[4] && a[4] == a[8])
        return 1;
    else if (a[2] == a[4] && a[4] == a[6])
        return 1;
    else if (a[0] != '1' && a[1] != '2' && a[2] != '3' && a[3] != '4' && a[4] != '5' && a[5] != '6' && a[6] != '7' && a[7] != '8' && a[8] != '9')
        return 0;
    else
        return -1;
}

void rules()
{
    char link;
    PRINTC(3, "\n\t************___ Tic-Tac-Toe____************\n\n");

    printf("Rules:-\n");
    printf("\n\t1:Each player will be entering the number to put respective X or O in the desired position.");
    printf("\n\t2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner");
    printf("\n\nEnjoy the game! \n\n");
    printf("For more clarifications press Y else type any other character:- ");
    scanf("%c", &link);
    if (link == 'y' || link == 'Y')
    {

        system("start http://www.wikihow.com/Play-Tic-Tac-Toe");
    }
}

bool decision(char *x, char *o, unsigned char *player1)
{
    char dec;
    printf("\n\n");
    do
    {
        printf("Player %s \n Select  X or 0 : ", player1);
        dec = getchar(); // uses ?
        scanf("%c", &dec);
    } while (dec != 'X' && dec != 'x' && dec != '0');
    if (dec == 'X' || dec == 'x')
    {
        *x = 'X';
        *o = '0';
    }
    else
    {
        *x = '0';
        *o = 'X';
    }
    return 1;
}

void animation()
{

    char win[] = "HURRAYhurray";
    int l = strlen(win);
    int k = 50;
    for (int i = 0; i < l && k; i++)
    {
        Sleep(90);
        printf("\033[%dm", 30 + i % 7);
        printf("%c ", win[i]);
        printf("\033[0m");
        if (i == 5)
        {
            printf("\r ");
        }
        if (i == l - 1)
        {
            printf("\r ");
            i = -1;
        }
        k--;
    }
}

int main()
{
    char x, o, symbol, re, start, dec;
    char player1[50], player2[50];
    int player = 1, choice, score = -1, s;

    rules();

    FILE *p;
    p = fopen("score.txt", "r");
    if (!p)
    {
        p = fopen("score.txt", "w");
        fprintf(p, "\t%s", "Player 1");
        fprintf(p, "\t\t%s", "Player 2");
        fprintf(p, "\t  %s", "Winner");
        fprintf(p, "\n%s", "---------------------------------------------------------------");
    }
    fclose(p);

    printf("\x1b[33m"
           "\n\nPress 1 to start the game : "
           "\x1b[0m");
    printf("\x1b[33m"
           "\nPress 2 to view leader board: \t"
           "\x1b[0m");
    scanf("%d", &s);
    switch (s)
    {
    case 1:
        do
        {
            p = fopen("score.txt", "a+");

            printf("\x1b[35m"
                   "\nEnter name of player 1 : "
                   "\x1b[0m");
            scanf("%s", player1);
            fprintf(p, "\n%10s", player1);

            printf("\x1b[35m"
                   "Enter name of player 2 : "
                   "\x1b[0m");
            scanf("%s", player2);
            fprintf(p, "\t\t%10s", player2);

            fclose(p);

            !strcmp(player1, player2) ? printf("\x1b[31m"
                                               "The Name should be different !! \n\n"
                                               "\x1b[0m")
                                      : 0;

        } while (!strcmp(player1, player2));
        char option = 'n';
        do
        {
            char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

            decision(&x, &o, player1);

            board(x, o, player1, player2, a);

            do
            {
                int flag = 0;
                player = ((player % 2) ? 1 : 2);
                if (player == 1)
                    printf("\x1b[30m"
                           "Press any digit from 1-9 to fill your response \n"
                           "\x1b[0m"
                           "\x1b[37m"
                           " %s's  turn : "
                           "\x1b[0m",
                           player1);
                else
                    printf("\x1b[30m"
                           "Press any digit from 1-9 to fill your response \n"
                           "\x1b[0m"
                           "\x1b[37m"
                           " %s's  turn : "
                           "\x1b[0m",
                           player2);

                scanf("%d", &choice);

                symbol = ((player == 1) ? x : o);

                if (choice == 1 && a[0] == '1')
                    a[0] = symbol;
                else if (choice == 2 && a[1] == '2')
                    a[1] = symbol;
                else if (choice == 3 && a[2] == '3')
                    a[2] = symbol;
                else if (choice == 4 && a[3] == '4')
                    a[3] = symbol;
                else if (choice == 5 && a[4] == '5')
                    a[4] = symbol;
                else if (choice == 6 && a[5] == '6')
                    a[5] = symbol;
                else if (choice == 7 && a[6] == '7')
                    a[6] = symbol;
                else if (choice == 8 && a[7] == '8')
                    a[7] = symbol;
                else if (choice == 9 && a[8] == '9')
                    a[8] = symbol;
                else
                {
                    printf("\n\n \t\t Wrong Selection\n");
                    // player--;
                    flag = 1;
                }
                if (!flag)
                {

                    score = checkforwin(a);

                    player++;

                    board(x, o, player1, player2, a);
                }
            } while (score == -1);

            p = fopen("score.txt", "a+");
            if (score == 1)
            {

                if (player == 2)
                {
                    printf("\x1b[33m"
                           "\n\nPlayer %s Wins!! \n\n"
                           "\x1b[0m",
                           player1); // do some animation
                    animation();
                    fprintf(p, "\t\t%7s", player1);
                }
                else
                {
                    printf("\x1b[33m"
                           "\n\nPlayer %s Wins!!\n\n"
                           "\x1b[0m",
                           player2);
                    animation();
                    fprintf(p, "\t\t%7s", player2);
                }
            }
            else
            {
                printf("\n\n Game Draws !\n\n");
                fprintf(p, "\t\t%7s", "DRAW");
            }
            fclose(p);
            getchar();
            printf("\nDo you want to play more (y/n) : ");
            scanf("%c", &option);
        } while (option == 'y' || option == 'Y');
        break;

    case 2:

    {

        system("cls");
        printf("\n\n");
        printf("\t*************  LEADERBOARD  ****************\n\n");
        char c;
        p = fopen("score.txt", "r");
        while ((c = getc(p)) != EOF)
        {
            printf("%c", c);
        }
        fclose(p);
        getchar();
        break;
    default:
        printf("\n\nShould have typed 1 to play the game !\nHope to see you back soon!\n\n");
        getchar();
        break;
    }
    }
    getchar();
}
