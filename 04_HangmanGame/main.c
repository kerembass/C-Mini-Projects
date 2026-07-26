#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    char secretWord[50];
    int lives = 6;
    int length;
    char guessWord[50];


    printf("\n=======HANGMAN GAME=======\n\n");
    printf("Player one, please enter a word(in capital letters): ");
    scanf("%s",secretWord);

    system("cls");

    length = strlen(secretWord);


    for(int i=0;i<length;i++){
        guessWord[i] = '_';
    }

    guessWord[length] = '\0';

    while(lives > 0){
        printf("============================\n");
        printf("Player 2's remaining lives:%d\n\n",lives);
        for(int i=0;i<length;i++){
            printf("%c ",guessWord[i]);
        }
        char guess;

        printf("\n\nPlease enter a prediction(in capital letters): ");
        scanf(" %c",&guess);

        int found = 0;

        for(int i=0;i<length;i++){
            if(secretWord[i]==guess){
                guessWord[i] = guess;
                found = 1;
            }
        }
        if(found == 0){
            printf("\nIncorrect guess!\n\n");
            lives--;
        }
        else{
            printf("\nGreat, you found the right letter!\n\n");
        }

        if(strchr(guessWord,'_')== NULL){
            printf("\n====================================\n");
            printf("Congratulations, you found the word: %s\n",secretWord);
            break;
        }
    }
    if(lives == 0){
        printf("\n====================================\n");
        printf("GAME OVER!\n");
        printf("The secret word was: %s\n", secretWord);
    }
    return 0;
}
