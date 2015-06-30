//horizon one -a caps corp initiative
#include<iostream>
#include<windows.h>
#include<stdio.h>//ed
#include<time.h>
#include<conio.h>
#include"capsule.h"
using namespace std;
struct rocketsm{int y;};
struct rock{int x;int y;int face;};
int main()
{
    system("title horizon one");//ed
    rocketsm A;
    rock B[200];
    setop();
    srand(time(NULL));
    int m,count,flag;
    clock_t now;
    string L("--------------------------------------------------------------------------------");//ed

    do{
    initializations:
    {
    A.y=10;
    count=flag=0;
    }
    do
    {
        system("cls");//single call faster
        //Move and Display Rock
        for(m=0;m!=count;m++)
        {
            B[m].x--;
            if(B[m].x<=5){B[m].x=5;B[m].face=0;}
            else if(B[m].x>5){visit(B[m].x,B[m].y);setcolor(B[m].face);printf("%c",219);}//ed fast
            if((B[m].x==30)&&(B[m].y==A.y)){flag=50;}//ed
        }
        //Generate Rock
        if(flag==0)
        {
            B[count].x=rand()%40+40;
            B[count].y=rand()%20;
            B[count].face=11;//ed
            visit(B[count].x,B[count].y);
            setcolor(B[m].face);
            printf("%c",219);//ed
            count++;
            flag=5;
            if(count==200){flag=0;}
        }
        //Display Rocket
        visit(30,A.y);
        setcolor(12);//ed
        printf("%c",16);//ed
        //Display teleporter
        setcolor(11);//ed
        visit(0,20);
        cout<<L;//ed
        //Display progress
        setcolor(14);//ed
        visit(70,21);
        printf("%d/100",count/2);//ed
        //Winning and Losing Conditions
        if(flag<0)
        {visit(2,22);setcolor(10);printf("\a\aYOU WIN!");break;}//ed
        else if(flag==50)//ed fast
        {visit(30,A.y);setcolor(12);printf("%c",219);visit(2,22);printf("\a\aYOU LOSE!");break;}//ed
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
        else if(GetAsyncKeyState(VK_DOWN)){A.y++;}//ed fast
        //Ceiling and Teleport Control
        if(A.y==-1){A.y=0;}
        else if(A.y==20){A.y=0;}//ed fast

    }while(!0);
    //Restart the game
    printf("\tPress enter to retry ");//ed
    cin.get();
    }while(!0);

    return 0;
}
