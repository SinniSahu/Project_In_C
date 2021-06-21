#include<iostream>
using namespace std;

char sq[10] = {'0','1','2','3','4','5','6','7','8','9'};

/***********************************
 return ->
 -1  win
  0  finish and no result (draw)
  1 game in progress
************************************/

int checkwin(){

    if(    (sq[1] == sq[2] && sq[2] == sq[3])
        || (sq[4] == sq[5] && sq[5] == sq[6])
        || (sq[7] == sq[8] && sq[8] == sq[9])

        || (sq[1] == sq[4] && sq[4] == sq[7])
        || (sq[2] == sq[5] && sq[5] == sq[8])
        || (sq[3] == sq[6] && sq[6] == sq[9])

        || (sq[3] == sq[5] && sq[5] == sq[7])
        || (sq[1] == sq[5] && sq[5] == sq[9]) )
    {
        return -1;
    }

    else if(   sq[1] != '1'
            && sq[2] != '2'
            && sq[3] != '3'
            && sq[4] != '4'
            && sq[5] != '5'
            && sq[6] != '6'
            && sq[7] != '7'
            && sq[8] != '8'
            && sq[9] != '9'
        )
    {
        return 0;
    }

    else 
        return 1;
}

void board(){
    system("cls");

    cout <<"\n TIC TAC TOE \n\n" ;
    cout <<"Player 1 (X) | Player 2 (O)"<<endl;
    cout <<endl;


    cout<<"     |     |     "<<endl;
    cout<<"  "<<sq[7]<<"  |  "<<sq[8]<<"  |  "<<sq[9]<<" "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<sq[4]<<"  |  "<<sq[5]<<"  |  "<<sq[6]<<" "<<endl;
    cout<<"_____|_____|_____"<<endl;
    cout<<"     |     |     "<<endl;
    cout<<"  "<<sq[1]<<"  |  "<<sq[2]<<"  |  "<<sq[3]<<" "<<endl;
    cout<<"     |     |     "<<endl;
}


int main()
{
    int player = 1, i = 1, choice;
    char mark;

    do
    {
        board();

        player = (player % 2) ? 1 : 2;

        cout<<"Player "<<player<<" enter number : ";
        cin>>choice;

        mark = (player == 1) ? 'X' : 'O';

        if(choice == 1 && sq[1] == '1')
            sq[1] = mark;
        else if(choice == 2 && sq[2] == '2')
            sq[2] = mark;
        else if(choice == 3 && sq[3] == '3')
            sq[3] = mark;
        else if(choice == 4 && sq[4] == '4')
            sq[4] = mark;
        else if(choice == 5 && sq[5] == '5')
            sq[5] = mark;
        else if(choice == 6 && sq[6] == '6')
            sq[6] = mark;
        else if(choice == 7 && sq[7] == '7')
            sq[7] = mark;
        else if(choice == 8 && sq[8] == '8')
            sq[8] = mark;
        else if(choice == 9 && sq[9] == '9')
            sq[9] = mark;
        else{
            cout<<"Invalid choice"<<endl;
            player --;
            // cin.ignore();
            // cin.get();
        }

        i = checkwin();
        player++;
        
    } while (i==1);

    board();

    if (i==-1)
    {
        cout<<" Player "<<--player<<" win !!!\n";
    }
    else
        cout<<" GAME DRAW ! \n";
    
    
    return 0;
}