#include <stdio.h>
#include "tictoe.h"
int main()
{
    sint8 matrix[3][3] = {{'_','_','_'},
                        {'_','_','_'},
                        {'_','_','_'}};
    sint16 player1 = 0;
    sint16 player2 = 0;
    sint8 exit;
    sint8 mode ;
    sint8 pr;
    mode = start_menu();
    if(mode == 'n')
        return 0;
    while(1){
        
        pr = playgame(matrix,mode,&player1,&player2);
        if (!pr)
            return 0 ;
        clear_mat(matrix);
        printf("\nfor exit press x\nfor continue press any key else : ");
        scanf(" %c",&exit);
        if(exit == 'x')
        break;
    }

    return 0;
}