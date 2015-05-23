#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include"Sudoku.h"
using namespace std;
main()
{
	Sudoku ss;
	ss.ReadIn();
	ss.Solve();
	return 0;
}
