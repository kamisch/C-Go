#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define num_rows 19
#define num_cols 19
#define zero_flag 0
int is_over = 0;
int is_won = 0;
char player = 'x';
char board[num_rows * num_cols];
char delim[] = " ";
char result;
void draw_board()
{
    int x, y;
    char visual[1500];
    memset(visual, '\0', sizeof(visual));
    char row[60];
    memset(row, '\0', sizeof(row));
    char row_id = 'A';
    for (x = 0; x < num_rows + 1; x++)
    {
        char row_id_str[4] = {row_id++, ':', ' ', '\0'};
        (x == num_rows) ? strcat(row, "   ") : strcat(row, row_id_str);
        char col_id = 'a';
        for (y = 0; y < num_cols; y++)
        {
            if (x == num_rows)
            {
                char col_id_str[3] = {col_id++, ' ', '\0'};
                strcat(row, col_id_str);
            }
            else
            {
                int position = x * num_cols + y;
                char stone = board[position];
                if (stone != '0')
                {
                    char stone_str[3] = {stone, ' ', '\0'};
                    strcat(row, stone_str);
                }
                else
                {
                    strcat(row, "+ ");
                }
            }
            if (y == (num_cols - 1))
            {
                strcat(row, "\n");
            }
        }
        strcat(visual, row);
        memset(row, '\0', sizeof(row));
    }
    printf("%s", visual);
};
int is_valid_move(int x, int y)
{
    int position = x * num_cols + y;
    if (board[position] != '0')
    {
        printf("invalid move, stone alread exist\n");
        return 0;
    }
    return 1;
}
char is_winning(void)
{
    // horizontal check
    for (int x = 0; x < num_cols - 4; x++)
    {
        for (int y = 0; y < num_cols; y++)
        {
            if (board[x * num_cols + y] == 'x' && board[(x + 1) * num_cols + y] == 'x' && board[(x + 2) * num_cols + y] == 'x' && board[(x + 3) * num_cols + y] == 'x' && board[(x + 4) * num_cols + y] == 'x')
            {
                return 'x';
            }
            if (board[x * num_cols + y] == 'o' && board[(x + 1) * num_cols + y] == 'o' && board[(x + 2) * num_cols + y] == 'o' && board[(x + 3) * num_cols + y] == 'o' && board[(x + 4) * num_cols + y] == 'o')
            {
                return 'o';
            }
        }
    }
    // vertical check
    for (int x = 0; x < num_cols; x++)
    {
        for (int y = 0; y < num_cols - 4; y++)
        {
            if (board[x * num_cols + y] == 'x' && board[x * num_cols + y + 1] == 'x' && board[x * num_cols + y + 2] == 'x' && board[x * num_cols + y + 3] == 'x' && board[x * num_cols + y + 4] == 'x')
            {
                return 'x';
            }
            if (board[x * num_cols + y] == 'o' && board[x * num_cols + y + 1] == 'o' && board[x * num_cols + y + 2] == 'o' && board[x * num_cols + y + 3] == 'o' && board[x * num_cols + y + 4] == 'o')
            {
                return 'o';
            }
        }
    }
    // diagonal check
    for (int x = 4; x < num_cols - 4; x++)
    {
        for (int y = 4; y < num_cols - 4; y++)
        {
            if (board[x * num_cols + y] == 'x' && board[(x + 1) * num_cols + y + 1] == 'x' && board[(x + 2) * num_cols + y + 2] == 'x' && board[(x + 3) * num_cols + y + 3] == 'x' && board[(x + 4) * num_cols + y + 4] == 'x')
            {
                return 'x';
            }
            if (board[x * num_cols + y] == 'o' && board[(x + 1) * num_cols + y + 1] == 'o' && board[(x + 2) * num_cols + y + 2] == 'o' && board[(x + 3) * num_cols + y + 3] == 'o' && board[(x + 4) * num_cols + y + 4] == 'o')
            {
                return 'o';
            }
            if (board[(x + 4) * num_cols + y] == 'x' && board[(x + 3) * num_cols + y + 1] == 'x' && board[(x + 2) * num_cols + y + 2] == 'x' && board[(x + 1) * num_cols + y + 3] == 'x' && board[x * num_cols + y + 4] == 'x')
            {
                return 'x';
            }
            if (board[(x + 4) * num_cols + y] == 'o' && board[(x + 3) * num_cols + y + 1] == 'o' && board[(x + 2) * num_cols + y + 2] == 'o' && board[(x + 1) * num_cols + y + 3] == 'o' && board[x * num_cols + y + 4] == 'o')
            {
                return 'o';
            }
        }
    }
    // tie check
    for (int x = 4; x < num_cols - 4; x++)
    {
        for (int y = 4; y < num_cols - 4; y++)
        {
            if (board[x * num_cols + y] == '0')
            {
                return '0';
            }
        }
    }
    // if returned one game is tied
    return '1';
}
int make_move(int x, int y)
{
    int position = x * num_cols + y;
    if (is_valid_move(x, y))
    {
        board[position] = player;
        return 1;
    }
    return 0;
}

void main(void)
{
    while (!is_over)
    {
        memset(board, '0', sizeof(board));
        printf("Wecome to C Gomoku, a place where you can play a game of gomoku with your friend in the terminal.\n");
        printf("Hints: Moves should be entered as 'letter leteer', i.e 'A a' or 'a c'\n");
        printf("Hints: When playing enter 'stop' as move to stop the game\n");
        is_won = 0;
        player = 'x';
        while (!is_won)
        {
            draw_board(board);
            printf("current turn: %c\n", player);
            char move[10];

            printf("Enter a move: ");
            fgets(move, sizeof(move), stdin);

            int check_over = strcmp(move, "stop\n") == 0;
            if (check_over)
            {
                is_over = 1;
                break;
            }
            char move_x = move[0];
            char move_y = move[2];
            if (!isalpha(move_x) || !isalpha(move_y))
            {
                puts("Invalid move, must enter letters.");
            }
            int x;
            int y;
            x = toupper(move_x) - 65;
            y = toupper(move_y) - 65;
            printf("place stone at: %i, %i \n", x, y);
            if (make_move(x, y))
            {
                result = is_winning();
                if (result != '0')
                {
                    is_won = 1;
                }
                else
                {
                    player = (player == 'x') ? 'o' : 'x';
                }
            }
            // end turn clean up
        }
        if (!is_over)
        {
            (result == '1') ? printf("Game tied, starting a new game...\n") : ((result == 'x') ? printf("x won the game, starting a new game...\n") : printf("o won the game, starting a new game...\n"));
        }
    }
}