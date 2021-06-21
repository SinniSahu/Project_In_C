#include<iostream>
#include<conio.h>
// #include<time.h>
#include<Windows.h>  
// for Sleep(), to reduce speed;

// #define width 20
// #define height 20

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x,y, targetX, targetY, score;

int tailX[100] = {0}, tailY[100] = {0};
int ntail = 0;

enum class eDirection { STOP=0, LEFT, RIGHT, UP, DOWN };
eDirection dir;

void Setup() {
    gameOver = false;
    dir = eDirection::STOP;
    x = width / 2;
    y = height / 2;
    targetX = rand() % width;
    targetY = rand() % height;
    score = 0;
}

void Board()
{
    system("cls");

    for(int i=0; i<width+2; i++)  // upper wall
        cout<<"#";
    cout<<endl;

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){

            if(j==0)        // left wall
            cout<<"#";

            if(i==y && j==x)
                cout<<"O";      // snake head

            else if(j==targetX && i==targetY)
                cout<<"@";      // food

            else{
                bool p = false;
                for(int k=0; k<ntail; k++){
                    if(tailX[k] == j && tailY[k] == i)
                    {
                        cout<<"o";
                        p = true;
                    }
                }
                if(!p)
                    cout<<" ";  // height*width empty space
            }

            if(j==width-1)        // right wall  index=21;
            cout<<"#";
        }
        cout<<endl;
    }

    for(int i=0; i<width+2; i++)  // down wall 
        cout<<"#";

    cout<<endl;
    cout<<"Score : "<<score<<endl;
}

void Input() {
    if(_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = eDirection::LEFT;
            break;
        case 'd':
            dir = eDirection::RIGHT;
            break;
        case 'w':
            dir = eDirection::UP;
            break;
        case 's':
            dir = eDirection::DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        default:
            // dir = eDirection::STOP;
            break;
        }
    }
}

void Logic(){

    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    

    for (int i = 1; i < ntail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case eDirection::LEFT :
        x--;
        break;
    case eDirection::RIGHT :
        x++;
        break;
    case eDirection::UP :
        y--;
        break;
    case eDirection::DOWN :
        y++;
        break;
    default:
        break;
    }

    // hit the wall
    // if(x>width || x<0 || y>height || y<0)
    //     gameOver = true;

// pass the wall and move out from other side
    if (x >= width) x = 0;
    else if (x < 0) x = width - 1;

    if (y >= height) y = 0;
    else if (y < 0) y = height - 1;

// if snake hit its tail
    // for (int i = 0; i < ntail; i++)
    // {
    //     if (tailX[i] == x && tailY[i] == y)
    //         gameOver = true;
    // }

    if(x==targetX && y==targetY){
        score += 10;
        // srand(time(0)); 
        targetX = rand() % width;
        targetY = rand() % height;
        ntail++;
    }
}

int main()
{
    Setup();
    while (!gameOver)
    {
        Board();
        Input();
        Logic();
        Sleep(50);
    }
    
    
    
    return 0;
}