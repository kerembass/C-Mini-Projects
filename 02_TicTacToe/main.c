#include <stdio.h>
#include <stdlib.h>
char board[3][3] = {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};

void printBoard()
{
    printf("\n\t\t\t--- Tic-Tac-Toe ---\n\n");
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t_____|_____|_____\n");
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("\t\t\t     |     |     \n\n");
}
int checkWin()
{
    //horizontal rows
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2]) return 1;
    if(board[1][0] == board[1][1] && board[1][1] == board[1][2]) return 1;
    if(board[2][0] == board[2][1] && board[2][1] == board[2][2]) return 1;

    //vertical rows
    if(board[0][0] == board[1][0] && board[1][0] == board[2][0]) return 1;
    if(board[0][1] == board[1][1] && board[1][1] == board[2][1]) return 1;
    if(board[0][2] == board[1][2] && board[1][2] == board[2][2]) return 1;

    //staggered rows
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;

    if(board[0][0] != '1' && board[0][1] != '2' && board[0][2] != '3' &&
       board[1][0] != '4' && board[1][1] != '5' && board[1][2] != '6' &&
       board[2][0] != '7' && board[2][1] != '8' && board[2][2] != '9' ){
        return 0; //draw
       }
    return -1; //The game continues
    // If it returns 1,someone has won
}
int main()
{
    int choice;
    char mark;
    int player = 1;
    int status = -1;

    while(status == -1){
        printBoard();
        if (player % 2 != 0){
        mark = 'X';
        printf("Player 1 (X), please choose a box (1-9): ");
        }
        else{
            mark = 'O';
            printf("Player 2 (O), please choose a box (1-9): ");
        }

        scanf("%d",&choice);

        switch(choice){
            case 1: if(board[0][0] == '1') board[0][0] = mark; else{printf("Box filled!\n"); player--;}break;
            case 2: if(board[0][1] == '2') board[0][1] = mark; else{printf("Box filled!\n"); player--;}break;
            case 3: if(board[0][2] == '3') board[0][2] = mark; else{printf("Box filled!\n"); player--;}break;
            case 4: if(board[1][0] == '4') board[1][0] = mark; else{printf("Box filled!\n"); player--;}break;
            case 5: if(board[1][1] == '5') board[1][1] = mark; else{printf("Box filled!\n"); player--;}break;
            case 6: if(board[1][2] == '6') board[1][2] = mark; else{printf("Box filled!\n"); player--;}break;
            case 7: if(board[2][0] == '7') board[2][0] = mark; else{printf("Box filled!\n"); player--;}break;
            case 8: if(board[2][1] == '8') board[2][1] = mark; else{printf("Box filled!\n"); player--;}break;
            case 9: if(board[2][2] == '9') board[2][2] = mark; else{printf("Box filled!\n"); player--;}break;
            default:
                printf("Invalid selection! Please try again.\n");
                continue;
        }
        status = checkWin();
        player++;
    }

    printBoard();

    if(status == 1){
        player--;
        if(player % 2 != 0){
            printf("==> \aPlayer 1 (X) WINS!\n\n");
        }
        else{
            printf(("==> \aPlayer 2 (O) WINS!\n\n"));
        }
    }
    else{
        printf("==> \aGame Draw!\n\n");
    }
    return 0;
}
