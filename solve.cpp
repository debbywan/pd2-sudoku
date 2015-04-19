#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include"Sudoku.h"
using namespace std;


int main(){
freopen("input.txt","rt",stdin);

Sudoku ans;
ans.ReadIn();
ans.Solve();
return 0;
}


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
        scanf("%d",&a[i][j]);
          
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

int Sudoku::square_check(int square,int s,int ss){
    int x=s-(s%3),y=ss-(ss%3);
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            if(a[x+i][y+j] == square)
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
