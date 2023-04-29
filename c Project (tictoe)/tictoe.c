#include <stdio.h>
#include <stdlib.h>
#include "tictoe.h"
void clrscr()
{
    system("@cls||clear");
}

sint8 check_winer(sint8 matBoard)
{
    // check cols
    sint16 i, j;
    sint8 flag = 0;
    for (i = 0; i < 3; i++)
    {
        if (mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2])
        {
            if (mat[i][0] == 'x')
            {
                return 1;
            }
            else if (mat[i][0] == 'o')
                return -1;
        }
    }
    // check rows
    for (i = 0; i < 3; i++)
    {
        if (mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i])
        {
            if (mat[0][i] == 'x')
            {
                return 1;
            }
            else if (mat[0][i] == 'o')
                return -1;
        }
    }
    // check diagnoal
    if ((mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2]) || (mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0]))
    {
        if (mat[1][1] == 'x')
        {
            return 1;
        }
        else if (mat[1][1] == 'o')
            return -1;
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (mat[i][j] == '_')
            {
                flag = 1;
            }
        }
    }
    // no one win
    if (flag == 0)
    {
        return 2;
    }
    return 0;
}
sint16 min(sint16 num1,sint16 num2){
    if(num1< num2)
        return num1;
    else 
        return num2;
}
sint16 max(sint16 num1,sint16 num2){
    if(num1> num2)
        return num1;
    else 
        return num2;
}
sint16 minmax(sint8 matBoard, sint16 depth, sint16 maxmize)
{

    sint16 result = check_winer(mat);
    sint16 i, j;
    // base case
    if (result != 0)
    {
        if (result == 2)
            return 0;
        else
            return result;
    }

    //    sint16 score;

    if (maxmize == 1)
    {
        sint16 score = -999;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (mat[i][j] == '_')
                {
                    mat[i][j] = 'x';
                    score = max(score,minmax(mat, depth + 1, 0));
                    mat[i][j] = '_';
                }
            }
        }
        return score;
    }
    else
    {
        sint16 score = 999;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (mat[i][j] == '_')
                {
                    mat[i][j] = 'o';
                    score = min(score,minmax(mat, depth + 1, 1));
                    mat[i][j] = '_';
                }
            }
        }
        return score;
    }
}

void printxo(sint8 matBoard, sint16 player1, sint16 player2)
{
    clrscr();
    sint16 k, m;
    printf("\t\t\tplayer1: %d \t\t\t\t\t\tplayer2: %d\n\n\n", player1, player2);
    for (k = 0; k < 3; k++)
    {
        printf("\t\t\t\t\t\t|");
        for (m = 0; m < 3; m++)
        {
            printf(" %c |", mat[k][m]);
        }

        printf("\n");
        printf("\t\t\t\t\t\t|---|---|---|\n");
    }
}

sint8 computer_turn(sint8 matBoard)
{
    sint16 best = -999;
    sint16 posi = -1;
    sint16 posj = -1;
    sint16 i, j;
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (mat[i][j] == '_')
                {
                    mat[i][j] = 'x';
                    sint16 currentscore = minmax(mat, 0, 0);
                    mat[i][j] = '_';

                    if (currentscore > best)
                    {
                        best = currentscore;
                        posi = i;
                        posj = j;
                    }
                }
            }
        }
    if (posi != -1 && posj != -1)
    {
        mat[posi][posj] = 'x';
        return 1;
    }
    return 0;
}

sint8 player_input(sint8 matBoard, sint8 input, sint8 player)
{
    printf("\n\nplayer %c turn:\n");
    printf("enter pos from numpad 1-9 : \nfor exit press any button else : \n");
    uint16 row, col;
    sint32 pos;
    scanf(" %d", &pos);
    if (pos > 0 && pos < 4)
    {
        row = (pos + 5) / 3;
        col = (pos + 5) % 3;
    }
    else if (pos > 3 && pos < 7)
    {
        row = (pos - 1) / 3;
        col = (pos - 1) % 3;
    }
    else if (pos > 6 && pos < 10)
    {
        row = (pos - 7) / 3;
        col = (pos - 7) % 3;
    }
    else
    {
        // send exit message
        return 0;
    }

    if (mat[row][col] == '_')
    {
        mat[row][col] = input;
        return 1;
    }
    else
        printf("\nposation ocuapied\n");
    return player_input(mat, input, player);
}

sint8 start_menu()
{
    clrscr();
    sint8 mode;
    printf("for multiplayer press : 1\n");
    printf("for play with compuer press : 2\n");
    printf("for exit press any button else :\n");
    scanf(" %c", &mode);
    if (mode == '1' || mode == '2')
    {
        return mode;
    }
    // printf("enter valid choise");
    return 'n';
    // mode = start_menu()
}

sint8 playgame(sint8 matBoard, sint8 mode, sint16 *player1, sint16 *player2)
{

    sint16 i;
    sint8 pn;
    // printf("player 1 turn will play with o \n");
    // printf("enter row and col postion \n");
    printxo(mat, *player1, *player2);
    for (i = 1; i < 10; i++)
    {
        if (i % 2 == 1)
            pn = player_input(mat, 'o', '1');
            
        else
        {
            if (mode == '1')
                pn = player_input(mat, 'x', '2');
            else
                computer_turn(mat);
        }
        if(!pn)
            return 0;
        sint16 result = check_winer(mat);
        if (result == 1)
        {
            // player1 win
            printxo(mat, *player1, *player2);
            printf("\nplayer 1 win");
            *player1 = *player1 + 1;
            return 1;
        }
        else if (result == -1)
        {
            // player2win
            printxo(mat, *player1, *player2);
            printf("\nplayer 2 win");
            *player2 = *player2 + 1;
            return 1;
        }
        else if (result == 2)
        {
            // tie!!
            printxo(mat, *player1, *player2);
            printf("\nTie!!");
            return 1;
        }
        else
            printxo(mat, *player1, *player2);
    }
}
void clear_mat(sint8 matBoard)
{
    sint16 k, m;
    for (k = 0; k < 3; k++)
    {
        for (m = 0; m < 3; m++)
        {
            mat[k][m] = '_';
        }
    }
}
