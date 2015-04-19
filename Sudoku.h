#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
using namespace std;

class Sudoku{
public:
    int ReadIn();
    int row_check(int ,int );
    int column_check(int ,int );
    int cube_check(int ,int ,int );
    void SolveSudoku();
    void print_answer();
    void Solve();
    void GiveQuestion();
private:
    int num_of_ans[1];
    int ques[12][12];
    int ans[12][12];
};

