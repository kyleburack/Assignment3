/*
Kyle Burack
2288845
burack@chapman.edu
CPSC350-1
Assignment3 - Syntax Checker
*/

#include <iostream>
#include "SyntaxChecker.h"
#include "GenStack.h"

using namespace std;

int main(int argc, char *argv[]){

  if(argc > 1){

    string file;
    SyntaxChecker syntax;
    cout << "Please enter the file name to analyze." << endl;
    getline(cin, file);
    syntax.delimiter(file.c_str());

  }
  else{
    cout << "Error, no arguments." << endl;
  }

  return 0;
}
