#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define num_rows 19
#define num_cols 19
#define zero_flag 0
int is_black = 1;
int is_over = 0;
int is_won = 0;

char board[num_rows * num_cols];
char delim[] = " ";

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
        char col_id = 'a';
        for (y = 0; y < num_cols; y++){
            if (x == num_rows){
                char col_id_str[3] = {col_id++,' ', '\0'};
                strcat(row,col_id_str);

            } else {
                int position = x * (num_cols-1) + y;
                char stone = board[position];
                if (stone != '0'){
                    char stone_str[3] = {stone,' ','\0'};
                    strcat(row,stone_str);
                } else {
                strcat(row,"+ ");
                }

            }
            if (y == (num_cols-1)){
                strcat(row, "\n");
            }

        }
        strcat(visual,row);
        memset(row, '\0', sizeof(row));
    }
    printf("%s",visual);
};
int is_valid_move(int x, int y){};
int is_on_edge(int x, int y){
    if(x == 0 || y == 0 || x == (num_rows - 1) || y == (num_cols -1)){
        return 1;
    }
    return 0;
}
int is_on_corner(int x, int y){
    if ((x == 0 && y == 0) || (x == 0 && y == num_cols - 1) || (x == num_rows - 1 && y == 0) || (x == num_rows - 1 && y == num_cols - 1)){
        return 1;
    }
        return 0;
}
int make_move(int x, int y)
{
    int position = x * num_cols + y;
    if (board[position] != '0'){
        printf("invalid move, stone alread exist\n");
        return 0;
    } else {
        board[position] = (is_black) ? 'x' : 'o';
        return 1;
    }
}
void main(void)
{
    while (! is_over){
        memset(board, '0', sizeof(board));
        printf("Wecome to C Go, a place where you can play a game of go with your friend in the terminal.\n");
        printf("Hints: Moves should be entered as 'uppercase letter space lowercase number', i.e 'A a' 'B c'\n" );
        printf("Hints: When playing enter 'stop' as move to stop the game\n" );        
        while (! is_won){
            draw_board(board);
            printf("current turn: %s\n", (is_black) ? "x" : "o");
            char move[10];

            printf("Enter a move: ");
            fgets(move, sizeof(move),stdin);

            int check_over = strcmp(move,"stop\n") == 0;
            if(check_over){
                is_over = 1;
                break;
            }
            char move_x = move[0];
            char move_y = move[2];
            if(!isalpha(move_x) || !isalpha(move_y)){
                puts("Invalid move, must enter letters.");
            }
            int x;
            int y;
            x = toupper(move_x) - 65;
            y = toupper(move_y) - 65;
            printf("place stone at: %i, %i \n", x  , y );
            if (make_move(x,y)){
                is_black = (is_black) ? 0 : 1;
            }
            // end turn clean up
        }

        // for loop to update game states

            // get user input and valid user input
            
        // make move
            // check move
        // print board     
        
    }
   
}