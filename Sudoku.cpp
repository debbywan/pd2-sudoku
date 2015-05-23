#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include"Sudoku.h"
using namespace std;


int Sudoku::ReadIn(){
    anses[0] = 0;
    int i,j;
    for(i=0;i<12;i++){
        for(j=0;j<12;j++){
        a[i][j] = 0;
        aa[i][j] = 0;
        }
    }
    cout<<"Enter a sudoku : "<<endl;
    for(i=0;i<12;i++){
        for(j=0;j<12;j++)
        cin>>a[i][j];
    }
}

int Sudoku::row_check(int row,int r){
    int j;
    for(j=0;j<12;j++){
        if(a[r][j] == row)
        return 0;
    }
    return 1;
}

int Sudoku::column_check(int column,int c){
    int i;
    for(i=0;i<12;i++){
        if(a[i][c] == column)
        return 0;
    }
    return 1;
}

void Sudoku::SolveSudoku(){
    int i,j;
    int number = 0;
    for(i=0;i<12;i++){
        for(j=0;j<12;j++){
            if (a[i][j] != 0)
                number++;
        }
    }
    if(number == 144){
        anses[0]++;
        if(anses[0] == 2){
        printf("2\n");
            return;
        }
        for(i=0;i<12;i++){
            for(j=0;j<12;j++)
            aa[i][j]=a[i][j];
        }
            return;
    }

    int input;

    for(i=11;i>=0;i--){
        for(j=11;j>=0;j--){

            if(a[i][j] == 0){
                for(input=1;input<=9;input++){
                      if(row_check(input,i) == 1 && column_check(input,j) == 1 && square_check(input,i,j) == 1){
                            a[i][j]=input;
                            SolveSudoku();
                            a[i][j] = 0;
                      }
                }
                return;
            }
        }
    }
}

void Sudoku::print_answer(){
    int i,j;
    for(i=0;i<12;i++){
        for(j=0;j<12;j++)
        cout<<aa[i][j]<<" ";
        printf("\n");
    }
}

void Sudoku::Solve(){
SolveSudoku();
if(anses[0] == 0)
    cout<<"0"<<endl;
else if(anses[0] == 1){
    cout<<"1"<<endl;
    print_answer();
}
}

int Sudoku::square_check(int square,int s,int ss){
    int x=s-(s%3),y=ss-(ss%3);
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            if(a[x+i][y+j] == square)
            return 0;
    }
    return 1;
}

void Sudoku::GiveQuestion(){
int number_of_question = 4;
srand(time(NULL));
int n;
n = rand()%number_of_question;
switch(n){
case 1:
printf("4 2 0 8 7 3 9 5 1 -1 -1 -1\n\
0 0 3 9 5 0 6 0 4 -1 -1 -1\n\
9 0 1 6 0 4 8 0 0 -1 -1 -1\n\
-1 -1 -1 1 3 2 0 8 7 0 5 6\n\
-1 -1 -1 0 8 0 1 9 0 4 0 0\n\
-1 -1 -1 4 9 6 2 3 0 0 7 1\n\
1 0 0 0 4 0 -1 -1 -1 6 0 0\n\
0 0 4 0 6 0 -1 -1 -1 0 3 0\n\
6 9 5 0 1 7 -1 -1 -1 0 0 4\n\
3 1 2 -1 -1 -1 7 4 0 0 0 9\n\
7 4 8 -1 -1 -1 0 6 9 0 1 0\n\
0 6 0 -1 -1 -1 3 1 0 7 0 0\n");
break;           //change from the teacher's ppt code

case 2 :
printf("0 6 0 -1 -1 -1 3 1 0 7 0 0\n\
7 4 8 -1 -1 -1 0 6 9 0 1 0\n\
3 1 2 -1 -1 -1 7 4 0 0 0 9\n\
6 9 5 0 1 7 -1 -1 -1 0 0 4\n\
0 0 4 0 6 0 -1 -1 -1 0 3 0\n\
1 0 0 0 4 0 -1 -1 -1 6 0 0\n\
-1 -1 -1 4 9 6 2 3 0 0 7 1\n\
-1 -1 -1 0 8 0 1 9 0 4 0 0\n\
-1 -1 -1 1 3 2 0 8 7 0 5 6\n\
9 0 1 6 0 4 8 0 0 -1 -1 -1\n\
0 0 3 9 5 0 6 0 4 -1 -1 -1\n\
4 2 0 8 7 3 9 5 1 -1 -1 -1\n");  //鏡射from case1
break;
case 3 :
printf("3 1 2 -1 -1 -1 7 4 0 0 0 9\n\
7 4 8 -1 -1 -1 0 6 9 0 1 0\n\
0 6 0 -1 -1 -1 3 1 0 7 0 0\n\
-1 -1 -1 1 3 2 0 8 7 0 5 6\n\
-1 -1 -1 0 8 0 1 9 0 4 0 0\n\
-1 -1 -1 4 9 6 2 3 0 0 7 1\n\
1 0 0 0 4 0 -1 -1 -1 6 0 0\n\
0 0 4 0 6 0 -1 -1 -1 0 3 0\n\
6 9 5 0 1 7 -1 -1 -1 0 0 4\n\
4 2 0 8 7 3 9 5 1 -1 -1 -1\n\
0 0 3 9 5 0 6 0 4 -1 -1 -1\n\
9 0 1 6 0 4 8 0 0 -1 -1 -1\n");//上下大列對調
break;
case 4:
printf("0 7 3 6 0 -1 -1 -1 -1 9 0 4\n\
6 4 1 9 0 0 -1 -1 -1 0 0 2\n\
0 8 2 5 4 0 -1 -1 -1 1 3 0\n\
-1 -1 -1 0 0 0 4 0 1 6 9 8\n\
-1 -1 -1 1 6 4 9 8 3 0 5 7\n\
-1 -1 -1 7 0 0 6 0 2 4 0 3\n\
3 0 7 -1 -1 -1 2 1 0 8 6 9\n\
1 6 4 -1 -1 -1 3 9 8 0 0 5\n\
0 9 0 -1 -1 -1 0 0 7 0 4 1\n\
7 0 0 0 0 6 0 4 0 -1 -1 -1\n\
0 1 0 0 3 0 7 0 5 -1 -1 -1\n\
0 0 9 4 0 0 1 0 6 -1 -1 -1\n");
break; //旋轉原矩陣
 }
}


