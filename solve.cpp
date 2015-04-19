#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include"Sudoku.h"
using namespace std;


int main(){
Sudoku out;
out.ReadIn();
out.Solve();
return 0;
}


int Sudoku::ReadIn(){
    num_of_ans[0] = 0;
    int i,j;
    for(i=0;i<12;i++){
        for(j=0;j<12;j++){
        ques[i][j] = 0;
        ans[i][j] = 0;
        }
    }
    cout<<"solve the sudoku : "<<endl;
    for(i=0;i<12;i++){
        for(j=0;j<12;j++)
        cin>>ques[i][j];}
    
}

int Sudoku::row_check(int row,int r){
    int j;
    for(j=0;j<12;j++){
        if(ques[r][j] == row)
        return 0;
    }
    return 1;
}

int Sudoku::column_check(int column,int c){
    int i;
    for(i=0;i<12;i++){
        if(ques[i][c] == column)
        return 0;
    }
    return 1;
}

int Sudoku::cube_check(int cube,int s,int ss){
    int x=s-(s%3),y=ss-(ss%3);
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            if(ques[x+i][y+j] == cube)
            return 0;
    }
    return 1;
}

void Sudoku::SolveSudoku(){
    int i,j;
    int number = 0;
    for(i=0;i<12;i++){
        for(j=0;j<12;j++){
            if (ques[i][j] != 0)
                number++;
        }
    }
    if(number == 144){
        num_of_ans[0]++;
        if(num_of_ans[0] == 2){
        printf("2\n");
            return;
        }
        for(i=0;i<12;i++){
            for(j=0;j<12;j++)
            ans[i][j]=ques[i][j];
        }
            return;
    }

    int input;

    for(i=11;i>=0;i--){
        for(j=11;j>=0;j--){

            if(ques[i][j] == 0){
                for(input=1;input<=9;input++){
                      if(row_check(input,i) == 1 && column_check(input,j) == 1 && cube_check(input,i,j) == 1){
                            ques[i][j]=input;
                            SolveSudoku();
                            ques[i][j] = 0;
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
        cout<<ans[i][j]<<" ";
        printf("\n");
    }
}

void Sudoku::Solve(){
SolveSudoku();
if(num_of_ans[0] == 0)
    cout<<"0"<<endl;
else if(num_of_ans[0] == 1){
    cout<<"1"<<endl;
    print_answer();
}
}
