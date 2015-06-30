//The Freeflow Experiment
#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include"capsule.h"
using namespace std;
struct rocketsm{int y;};
struct rock{int x;int y;int face;};
int main()
{
    system("title The Freeflow Experiment");
    rocketsm A;
    rock B[200];
    setop();
    srand(time(NULL));
    int m,count,flag;
    clock_t now;

    do{
    initializations:
    {
    A.y=10;
    count=flag=0;
    }
    do
    {
        clear();
        //Move and Display Rock
        for(m=0;m!=count;m++)
        {
            B[m].x--;
            if(B[m].x<=5){B[m].x=5;B[m].face=0;}
            if(B[m].x>5){visit(B[m].x,B[m].y);setcolor(B[m].face);cout<<char(219);}
            if((B[m].x==30)&&(B[m].y==A.y)){flag=50;}
        }
        //Generate Rock
        if(flag==0)
        {
            B[count].x=rand()%40+40;
            B[count].y=rand()%20;
            B[count].face=3;
            visit(B[count].x,B[count].y);
            setcolor(B[m].face);
            cout<<char(219);
            count++;
            flag=5;
            if(count==200){flag=0;}
        }
        //Display Rocket
        visit(30,A.y);
        setcolor(4);
        cout<<char(16);
        //Display teleporter
        setcolor(3);
        visit(0,20);
        cout<<"--------------------------------------------------------------------------------";
        //Display progress
        setcolor(6);
        visit(70,21);
        cout<<count/2<<"%";
        //Winning and Losing Conditions
        if(flag<0){visit(2,22);setcolor(2);cout<<"\a\aYOU WIN!";break;}
        if(flag==50){visit(30,A.y);setcolor(4);cout<<char(219);visit(2,22);cout<<"\a\aYOU LOSE!";break;}
        //Game progress controlled by flag
        flag--;
        //Transient Input
        Sleep(25);
        now=clock()+1;
        while(now<=clock())
        {
            getch();
            getch();
        }
        //Key pressed checks
        if(GetAsyncKeyState(VK_UP)){A.y--;}
        if(GetAsyncKeyState(VK_DOWN)){A.y++;}
        //Ceiling and Teleport Control
        if(A.y==-1){A.y=0;}
        if(A.y==20){A.y=0;}

    }while(!0);
    //Restart the game
    cout<<"\tPress enter to retry ";
    cin.get();
    }while(!0);

    return 0;
}
