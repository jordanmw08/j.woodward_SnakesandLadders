#include <iostream>
#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
using namespace std;
class Board
{

    public:
    int board[10][10];
    Board();// constructor
    virtual  int nextPosition(int, int);
    virtual  void display();
    private:
};
Board::Board()
{
    int k=1;
    for (int i = 0; i< 10; i++){
        for (int j= 0; j<10; j++ ){
            board[i][j] = k++;
        }
    }
}
int Board::nextPosition(int a, int b)
{
    switch(a+b)
    {
            //ladders
        case 8:
            cout << "You Got a Ladder!"<< endl;
            return 31;
            break;
        case 15:
            return 97;
            break;
        case 42:
            return 81;
            break;
        case 66:
            return 87;
            break;
        case 24:
            cout<< "You got a snake!";
            return 1;
            break;
        case 55:
            return 13;
            break;
        case 71:
            return 29;
            break;
        case 88:
            return 6;
            break;
        default:
            return(a+b);
            break;
            
    }
}

void
Board::display()
{
for(int i=9; i>=0; i--)
{
    cout << endl;
    if (i%2 != 0)
    {
        for (int j=9; j>=0; j--)
        {
            if (board[i][j] ==1 || board[i][j]==24)
                cout << board[i][j] << "S1\t";
            else if(board[i][j] ==13 || board [i][j] == 55)
                cout<< board[i][j] << "S2\t";
            else if(board[i][j] ==29| board [i][j] == 71)
                cout<< board[i][j] << "S3t";
            else if(board[i][j] ==54| board [i][j] == 88)
                cout<< board[i][j] << "S4\t";
            else if(board[i][j] ==6 || board [i][j] == 99)
                cout<< board[i][j] << "S5\t";
            else if(board[i][j] ==8 || board [i][j] == 31)
                cout<< board[i][j] << "L4\t";
                else {
                    cout<< board[i][j] << "\t";
                }
            
    }
}
}
}
class Player
{
    public:
    char name[50];
    Player();

    int currentPosition;
    int previousPosition;

    int Rollingdie();

};

Player::Player()
{
currentPosition=1;
previousPosition=1;

}
int 
Player::Rollingdie()
{
    return (rand() % 6) + 1 ;
}

int main ()
{
Player player1, player2;
    Board b;
    srand(time(0));

    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<< endl;
    cout << " Snakes and Ladder Board" << endl;
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"<< endl;
    
    cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
    

    cout<< "Player one Name" << endl;
    cin >> player1.name;
    cout << "Player two name" << endl;
    cin >> player2.name;
    cout << endl;
    b.display();

    
    int score;
    while(true){
        player1.previousPosition = player1.currentPosition;
        
        if(player1.currentPosition < 100){
            player1.currentPosition = player1.previousPosition;
            score = player1.Rollingdie();
        player1.currentPosition = b.nextPosition(score, player1.previousPosition);
            sleep(1);
        b.display();
        cout << player1.name << "\t" << player1.currentPosition << "\t" << score << endl;
        }
        if (player1.currentPosition >= 100){
            cout << player1.name << "  won!" << endl;
            break;
        }
        player2.previousPosition = player2.currentPosition;
        
        if(player2.currentPosition < 100){
            player2.currentPosition = player2.previousPosition;
            score = player2.Rollingdie();
        player2.currentPosition = b.nextPosition(score, player2.previousPosition);
            sleep(1);
            b.display();
        cout << player2.name << "\t" << player2.currentPosition << "\t" << score << endl;
        }
        if (player2.currentPosition >= 100){
            cout << player2.name << "  won!" << endl;
            break;
        }
    }
sleep(10);
    return 1;
}
