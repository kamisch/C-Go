#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define num_rows 19
#define num_cols 19
#define zero_flag 0
int is_black = 1;
char board[num_rows * num_cols];

void draw_board(){
    int x, y;
    char visual[1500];
    memset(visual, '\0', sizeof(visual));
    char row[60];
    memset(row, '\0', sizeof(row));
    char row_id = 'A';
    for (x = 0; x < num_rows + 1; x++){
        char row_id_str[4] = {row_id++,':',' ', '\0'};
        (x == num_rows) ? strcat(row,"   ") : strcat(row,row_id_str);
        char col_id = '0';
        for (y = 0; y < num_cols + 1; y++){
            if (x == num_rows){
                char col_id_str[3] = {col_id++,' ', '\0'};
                strcat(row,col_id_str);

            } else {
                int position = x * (num_cols-1) + y-1;
                char stone = board[position];
                if (stone != '0'){
                    char stone_str[3] = {stone,' ','\0'};
                    strcat(row,stone_str);
                } else {
                strcat(row,"+ ");
                }

            }
            if (y == (num_cols)){
                strcat(row, "\n");
            }

        }
        strcat(visual,row);
        memset(row, '\0', sizeof(row));
    }
    printf("%s",visual);
};
int is_valid_move(int x, int y){};
int make_move(int x, int y)
{

}
void main(void)
{
    memset(board, '0', sizeof(board));
    board[0] = 'x';
    draw_board(board);

}