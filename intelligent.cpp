//The Intelligent Experiment
#include<iostream>
#include<windows.h>
#include<time.h>
#include<conio.h>
#include"capsule.h"
using namespace std;
struct rocketsm{int y;int behav;};
struct comet{int x;int y;int face;int behav;};
int main()
{
    system("title The Intelligent Experiment");
    rocketsm A;
    comet B[400];
    setop();
    srand(time(NULL));
    int m,n,count,flag;
    int p,q1,q2,r1,r2,s;
    clock_t now;

    do{
    initializations:
    {
    A.y=10;
    count=flag=0;
    A.behav=0;
    }
    do
    {
        clear();
        //Move AI
        if(A.behav==1){A.y--;}
        if(A.behav==2){A.y++;}
        if(A.y==20){A.y=0;}
        if(A.y==-1){A.y=1;A.behav=2;}
        if(A.y==0){A.behav=2;}
        if(A.y==10){A.behav=0;}
        //Move Comet
        for(m=0;m!=count;m++)
        {
            B[m].x--;
            if(B[m].behav==1){B[m].y--;}
            if(B[m].behav==2){B[m].y++;}
            if(B[m].y==20){B[m].y=0;}
            if(B[m].y==-1){B[m].y=1;B[m].behav=2;}
        }
        //Display Comet
        for(m=0;m!=count;m++)
        {
            for(n=0;n!=count;n++){if(m==n){continue;}if((B[m].x==B[n].x)&&(B[m].y==B[n].y)){B[m].x=5;B[m].behav=0;break;}}
            if(B[m].x<=5){B[m].x=5;B[m].face=0;}
            if(B[m].x>5){visit(B[m].x,B[m].y);setcolor(B[m].face);cout<<char(4);}
            if((B[m].x==35)&&(B[m].y==A.y)){flag=50;}
        }
        //AI's MIND:
        p=q1=q2=r1=r2=4;
        s=0;
        for(n=0;n!=count;n++)
        {
            if((p==4)&&(B[n].x==36)&&(B[n].y==A.y)){p=B[n].behav;s++;}
            if((q1==4)&&(B[n].x==36)&&((B[n].behav==0)||(B[n].behav==2))&&(B[n].y==(A.y)-1)){q1=B[n].behav;s++;}
            if((q2==4)&&(B[n].x==36)&&((B[n].behav==0)||(B[n].behav==1))&&(B[n].y==(A.y)+1)){q2=B[n].behav;s++;}
            if((r1==4)&&(B[n].x==36)&&(B[n].behav==2)&&(B[n].y==(A.y)-2)){r1=B[n].behav;s++;}
            if((r2==4)&&(B[n].x==36)&&(B[n].behav==1)&&(B[n].y==(A.y)+2)){r2=B[n].behav;s++;}
            if(s==5){break;}
        }
        if(s==1)
        {
            if(A.behav==0){if(p==0){A.behav=2;}else if(q1==2){A.behav=2;}else if(q2==1){A.behav=2;}}
            else if(A.behav==1){if(p==1){A.behav=0;}else if(q1==0){A.behav=0;}else if(r1==2){A.behav=0;}}
            else if(A.behav==2){if(p==2){A.behav=0;}else if(q2==0){A.behav=0;}else if(r2==1){A.behav=0;}}
        }
        if(s>1)
        {
            if((p==0)&&(q1==0)){A.behav=2;}//ok 36.1=2
            else if((p==0)&&(q2==0)){A.behav=1;}//ok 36.3=1
            else if((p==0)&&(r1==2)){A.behav=2;}//ok 36.5=2
            else if((p==0)&&(r2==1)){A.behav=1;}//ok 36.6=1
            else if((p==1)&&(q1==2)){A.behav=2;}//ok 36.8=2
            else if((p==1)&&(q2==0)){A.behav=0;}//ok 36.9=0
            else if((p==1)&&(q2==1)){A.behav=2;}//ok 36.10=2
            else if((p==1)&&(r2==1)){A.behav=0;}//ok 36.12=0
            else if((p==2)&&(q1==0)){A.behav=0;}//ok 36.13=0
            else if((p==2)&&(q1==2)){A.behav=1;}//ok 36.14=1
            else if((p==2)&&(q2==1)){A.behav=1;}//ok 36.16=1
            else if((p==2)&&(r1==2)){A.behav=0;}//ok 36.17=0
            else if((q1==0)&&(q2==0)){A.behav=0;}//ok 36.19=0
            else if((q1==0)&&(q2==1)){A.behav=2;}//ok 36.20=2
            else if((q1==0)&&(r2==1)){A.behav=0;}//ok 36.22=0
            else if((q1==2)&&(q2==0)){A.behav=1;}//ok 36.23=1
            else if((q1==2)&&(r1==2)){A.behav=2;}//ok 36.25=2
            else if((q1==2)&&(r2==1)){A.behav=1;}//ok 36.26=1
            else if((q2==0)&&(r1==2)){A.behav=0;}//ok 36.27=0
            else if((q2==1)&&(r1==2)){A.behav=2;}//ok 36.29=2
            else if((q2==1)&&(r2==1)){A.behav=1;}//ok 36.30=1
            else if((r1==2)&&(r2==1)){A.behav=0;}//ok 36.31=0
            else if((p==0)&&(q1==2)){A.behav=2;}//rep 36.2=2
            else if((p==0)&&(q2==1)){A.behav=2;}//rep 36.4=2
            else if((p==1)&&(q1==0)){A.behav=0;}//rep 36.7=0
            else if((p==1)&&(r1==2)){A.behav=0;}//rep 36.11=0
            else if((p==2)&&(q2==0)){A.behav=0;}//rep 36.15=0
            else if((p==2)&&(r2==1)){A.behav=0;}//rep 36.18=0
            else if((q1==0)&&(r1==2)){A.behav=0;}//rep 36.21=0
            else if((q1==2)&&(q2==1)){A.behav=2;}//rep 36.24=2
            else if((q2==0)&&(r2==1)){A.behav=0;}//rep 36.28=0
        }
        //Generate Comet
        if(flag==0)
        {
            for(n=0;n!=2;n++)
            {
            B[count].x=rand()%43+37;
            B[count].y=rand()%20;
            B[count].face=4;
            B[count].behav=rand()%3;
            visit(B[count].x,B[count].y);
            setcolor(B[m].face);
            cout<<char(4);
            count++;
            }
            flag=3;
            if(count==400){flag=0;}
        }
        //Display Rocket
        visit(35,A.y);
        setcolor(1);
        cout<<char(16);
        //Display teleporter
        setcolor(3);
        visit(0,20);
        cout<<"--------------------------------------------------------------------------------";
        //Display progress
        setcolor(6);
        visit(70,21);
        cout<<count/4<<"%";
        //Display message
        setcolor();
        visit(2,24);
        cout<<"JUST WATCH!";
        //Winning and Losing Conditions
        if(flag<0){visit(2,22);setcolor(2);cout<<"\a\aAI WINS!";break;}
        if(flag==50){visit(35,A.y);setcolor(4);cout<<char(219);visit(2,22);cout<<"\a\aAI LOSES!";break;}
        //Game progress controlled by flag
        flag--;
        //Transient Input
        Sleep(25);
        now=clock()+1;
        while(now<=clock());
    }while(!0);
    //Restart the game
    cout<<"\tPress enter to retest ";
    cin.get();
    }while(!0);

    return 0;
}
