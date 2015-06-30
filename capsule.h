//capsule.h header file--designed for Code Blocks mingw gcc compiler
//place it in the same directory as your c++ code
//type #include"capsule.h" to include this file
#ifndef CAPSULE_H
#define CAPSULE_H
#include<windows.h>
HANDLE H;
COORD C={0,0};

void setop()//Initializes HANDLE
{
    H=GetStdHandle(STD_OUTPUT_HANDLE);
}
void setcolor(int VALUE=7)//Sets output text color--Call setop() first
{
    SetConsoleTextAttribute(H,VALUE);
}
void visit(int X_COORDINATE=0,int Y_COORDINATE=0)//Visits the requested location--Call setop() first
{
    C.X=X_COORDINATE;
    C.Y=Y_COORDINATE;
    SetConsoleCursorPosition(H,C);
}
void clear()//Clears the screen and visits (0,0)
{
    system("cls");
}
template<class STR>
void sort(STR* POINTER,int SIZE)//Sorts a 1-D array
{
    int INDEX_1,INDEX_2;
    STR TEMP;
    for(INDEX_1=0;INDEX_1!=(SIZE-1);INDEX_1++)
    for(INDEX_2=INDEX_1+1;INDEX_2!=SIZE;INDEX_2++)
    if(POINTER[INDEX_1]>POINTER[INDEX_2])
    {
        TEMP=POINTER[INDEX_1];
        POINTER[INDEX_1]=POINTER[INDEX_2];
        POINTER[INDEX_2]=TEMP;
    }
}
template<class STR>
int search(STR* POINTER,int SIZE,STR VALUE)//Searches for an element in a 1-D array--returns its index+1 as position
{
    int INDEX,FLAG;
    for(INDEX=0;INDEX!=SIZE;INDEX++)
    if(POINTER[INDEX]==VALUE){FLAG=1;break;}
    if(FLAG==1){return INDEX+1;}
    else {return -1;}
}

#endif // CAPSULE_H
