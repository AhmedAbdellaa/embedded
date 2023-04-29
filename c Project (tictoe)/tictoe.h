#include "STD_TYPES_H.h"
#ifndef tictoe
#define tictoe

#define boardSize 3
#define matBoard  mat[boardSize][boardSize]

/// @brief clear screen before prsint16 each move on board
void clrscr();

/// @brief check if there a winner player or no win or there is still room to play
/// @param matBoard tictoe board with last update
/// @return 1 if x win , -1 if o win or 2 no one win
sint8 check_winer(sint8 matBoard);
 
sint16 min(sint16 num1,sint16 num2);

sint16 max(sint16 num1,sint16 num2);

/// @brief recursive method to build a tree of each possible solution for the board
/// @param matBoard tictoe board with last update
/// @param depth indection of current debth of the solution tree
/// @param maxmize maxmize or minimize that player 
/// @return sum score of recurcive result
sint16 minmax(sint8 matBoard, sint16 depth, sint16 maxmize);

/// @brief prsint16 game last status
/// @param matBoard tictoe board with last update
/// @param player1 numper of wins for player one
/// @param player2 numper of wins for player two
void printxo(sint8 matBoard,sint16 player1,sint16 player2);

/// @brief algorithm use best pos to play in using minmax and one_move_win
/// @param matBoard tictoe board with last update
/// @return 1 if pc played sucssufully 0 if pc didn't play
sint8 computer_turn(sint8 matBoard);


/// @brief take row and col postion from user
/// @param matBoard tictoe board with last update
/// @param input 'x' or 'o'
/// @param player '1' for player 1 '2' for second player
/// @return 1 if given succfully row and col pos else repet it recursively
sint8 player_input(sint8 matBoard, sint8 input,sint8 player);

/// @brief take from user dession to play with friend or with computer
/// @return mode 1 play with friend of 2 play with computer else return 'n'
sint8 start_menu();

/// @brief 
/// @param matBoard tictoe board with last update
/// @param mode mode 1 play with friend of 2 play with computer
/// @param player1 numper of wins for player one to read and store
/// @param player2 numper of wins for player one to read and store
/// @return 0 if 
sint8 playgame(sint8 matBoard, sint8 mode,sint16* player1,sint16* player2);

/// @brief clearn tictoe board for next round
/// @param matBoard tictoe board with last update
void clear_mat(sint8 matBoard);

#endif
