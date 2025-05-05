#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

 char board[3][3];
    const char PLAYER = 'X';
    const char COMPUTER = 'O';
    const char PLAYER2 = '0';


    void reset();
    void print();
    int checkforspace();
    void playermove();
    void computermove();
    char checkwinner();
    void printwinner(char);

int main()
{
    char winner = ' ';
    char response;
    char yn = 'y';

    printf("\nWelcome to Tic-Tac-Toe!!\n");
    printf("In order to play, input the corresponding number:\n");
    printf(" 1 | 2 | 3     1 : 1, 2, 3\n");
    printf("---|---|---\n");
    printf(" 4 | 5 | 6     2: 1, 2, 3\n");
    printf("---|---|---\n");
    printf(" 7 | 8 | 9     3: 1, 2, 3\n");
    printf("\n(Row, Column) Ex: 1,1\n");
    sleep(1);

do{
    winner = ' ';
    printf("\n \nC = Computer, P = Player\n");
    printf("Play with computer or vs player?: ");
    scanf(" %c", &response);

    if(response == 'C' || response == 'c'){
    reset();
        while(winner == ' ' && checkforspace != 0){
            print();
            playermove();
            winner = checkwinner();
            if(winner != ' ' || checkforspace() == 0){
                break;
            }

            computermove();
            winner = checkwinner();
            if(winner != ' ' || checkforspace() == 0){
                break;
            }
        }
    print();
    printwinner(winner);
    sleep(1);
    printf("\ndo you want to play again? y/n: ");
    scanf(" %c", &yn);
    }
    else if (response == 'p' || response == 'P') {
        reset();
        while(winner == ' ' && checkforspace != 0){
            print();
            playermove();
            winner = checkwinner();
            if(winner != ' ' || checkforspace() == 0){
                break;
            }

            player2move();
            winner = checkwinner();
            if(winner != ' ' || checkforspace() == 0){
                break;
            }
        }
        print();
    printwinner(winner);
    sleep(1);
    printf("\nDo you want to play again? y/n: ");
    scanf(" %c", &yn);
    } else {
        printf("INVALID!");
    }
} while(yn == 'y' || yn =='Y');

    return 0;
}

    void reset(){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                board[i][j] = ' ';
            }
        }
    }

    void print(){
        printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
        printf("\n---|---|---\n");
        printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
        printf("\n---|---|---\n");
        printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
        printf("\n");
    }

    int checkforspace(){
        int space = 9;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] != ' '){
                    space--;
                }
            }
        }
        return space;
    }

    void playermove(){

        int x;
        int y;

        do{
        printf("Enter Row Number 1-3: ");
        scanf("%d", &x);
        x--;
        printf("Enter Column Number 1-3: ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' '){
            printf("Invalid Move!");
        } else {
            board[x][y] = PLAYER;
            break;}
            }
        while(board[x][y] != ' ');

    }

    void player2move(){

        int x;
        int y;

        do{
        printf("\nEnter Row Number for Player2 1-3: ");
        scanf("%d", &x);
        x--;
        printf("Enter Column Number for Player2 1-3: ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' '){
            printf("Invalid Move!");
        } else {
            board[x][y] = PLAYER2;
            break;}
            }
        while(board[x][y] != ' ');

    }



    void computermove(){
        srand(time(0));
        int x;
        int y;

        if(checkforspace() > 0){
            do{
                x = rand() % 3;
                y = rand() % 3;
            } while(board[x][y] != ' ');
            board[x][y] = COMPUTER;
        } else {
            printwinner(' ');
        }
    }

    char checkwinner(){
        //check rows
        for(int i = 0; i < 3; i++){
            if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
                return board[i][0];
            }
        }
        // check columns
        for(int i = 0; i < 3; i++){
            if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
                return board[0][i];
            }
        }
        // check diagonals
        for(int i = 0; i < 3; i++){
            if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
                return board[0][0];
            }
        }
        for(int i = 0; i < 3; i++){
            if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
                return board[0][2];
            }
        }
            return ' ';
    }


    void printwinner(char winner)
    {
        if(winner == PLAYER){
            printf("Player1 wins!!");
        } else if(winner == COMPUTER){
            printf("Computer wins!");
        } else if (winner == PLAYER2){
            printf("Player2 wins!!");
        } else {
            printf("TIE!!");
        }
    }


