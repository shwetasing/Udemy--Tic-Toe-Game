#include<iostream>
#include<conio.h>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char turn = 'X';
int row, col;

void display_board()
{
    system("cls");
    cout << "\t\t\t T I C K C R O S S G A M E\n";
    cout << "\t Player1[X]:\n\t Player2[O]:\n";
    cout << "\t\t\t     |     |     \n";
    cout << "\t\t\t  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"   \n";
    cout << "\t\t\t_____|_____|_____\n";
    cout << "\t\t\t     |     |     \n";
    cout << "\t\t\t  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"   \n";
    cout << "\t\t\t_____|_____|_____\n";
    cout << "\t\t\t     |     |     \n";
    cout << "\t\t\t  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"   \n";
    cout << "\t\t\t     |     |     \n";
}

void player_turn()
{
    if(turn == 'X')
    {
        cout << "Player1[X] turn: ";
    }
    else
    {
        cout << "Player2[O] turn: ";
    }
    int choice;
    cin >> choice;
    switch(choice)
        {
            case 1: row = 0; col = 0; break;
            case 2: row = 0; col = 1; break;
            case 3: row = 0; col = 2; break;
            case 4: row = 1; col = 0; break;
            case 5: row = 1; col = 1; break;
            case 6: row = 1; col = 2; break;
            case 7: row = 2; col = 0; break;
            case 8: row = 2; col = 1; break;
            case 9: row = 2; col = 2; break;
            default: cout << "Invalid Choice\n"; break;
        }
    if(turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = 'X';
        turn = 'O';
    }
    else if(turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O')
    {
        board[row][col] = 'O';
        turn = 'X';
    }
    else
    {
    	cout << "\nBox already filled\nPlease try again\n\n";
    	player_turn();
	}
	display_board();
}

bool gameover()
{
    for(int i = 0; i < 3; ++i)
    {
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

        else if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
            return false;
    }

    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return true;
        }

        turn = 'D';
        return 0;
}

int main(){
    while(gameover()){
        display_board();
        player_turn();
        gameover();
    }

    if(turn == 'X')
        cout << "Player2[O] wins!!\nCongratulations!!\n";

    if(turn == 'O')
        cout << "Player1[X] wins!!\nCongratulations!!\n";

    if(turn == 'D')
        cout << "Game Draw. :(\n";
	
	int i = 100000;
	while(i > 0){
		--i;
	}

	getch();
    return 0;
}
