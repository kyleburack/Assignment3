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
#include <fstream>

using namespace std;

void SyntaxChecker::delimiter(string fileName){
  string local;
  string temp;
  temp = fileName;
  int lines = 0;
  ifstream myfile (temp.c_str());
  if(myfile.is_open()){
    while(getline(myfile, local)){
      lines++;
      for(int i = 0; i < local.length(); i++){
        if(local[i] == '('){
          ++leftPar;
        }
        else if(local[i] == ')'){
          ++rightPar;
        }
        else if(local[i] == '['){
          ++leftBrack;
        }
        else if(local[i] == ']'){
          ++rightBrack;
        }
        else if(local[i] == '{'){
          ++leftCurl;
        }
        else if(local[i] == '}'){
          ++rightCurl;
        }
      }
    }
    if(leftPar == rightPar){
      parEqual = true;
    }
    else{
      parEqual = false;
    }
    if(leftBrack == rightBrack){
      brackEqual = true;
    }
    else{
      brackEqual = false;
    }
    if(leftCurl == rightCurl){
      curlEqual = true;
    }
    else{
      curlEqual = false;
    }

    if(parEqual == true && brackEqual == true && curlEqual == true){
      delimiterEqual();
    }
    else if(parEqual == false && brackEqual == true && curlEqual == true){
      incoPar(temp);
    }
    else if(parEqual == true && brackEqual == false && curlEqual == true){
      incoBrack(temp);
    }
    else if(parEqual == true && brackEqual == true && curlEqual == false){
      incoCurl(temp);
    }
    else if(parEqual == true && brackEqual == false && curlEqual == false){
      incoBrack(temp);
      incoCurl(temp);
    }
    else if(parEqual == false && brackEqual == false && curlEqual == true){
      incoPar(temp);
      incoBrack(temp);
    }
    else if(parEqual == false && brackEqual == true && curlEqual == false){
      incoPar(temp);
      incoCurl(temp);
    }
    else if(parEqual == false && brackEqual == false && curlEqual == false){
      incoPar(temp);
      incoBrack(temp);
      incoCurl(temp);
    }
  }
  else{
    cout << "File not able to be opened" << endl;
  }
}

void SyntaxChecker::delimiterEqual(){
  string analyze;
  string fileN;
  cout << "Your file has correct delimiter syntax. Would you like to analyze another file? (Enter 'y' for yes, anything else for no.)" << endl;
  getline(cin, analyze);
  if(analyze == "Y" || analyze == "y"){
    cout << "Please enter your next fileName. (Case sensitive.)" << endl;
    getline(cin, fileN);
    delimiter(fileN);
  }
  else{
    cout << "Thanks for checking your syntax. Goodbye" << endl;
  }
}

void SyntaxChecker::incoPar(string filename){
  parStack = new GenStack<char>(leftPar * 2);
  int line = 0;
  string local;
  ifstream myFile (filename.c_str());

  while(getline(myFile,local)){
    line++;
    for(int i = 0; i < local.length(); i++){
      if(local[i] == '(' || local[i] == '[' || local[i] == '{'){
        parStack->push(local[i]);
      }
      if(local[i] == ')' || local[i] == ']' || local[i] == '}'){
        if('(' != parStack->look()){
          cout << "Delimiter does not match at line " << line << " expected was ')'.";
        }
        else{
          parStack->pop();
        }
      }
    }
  }
  if(!parStack->isEmpty()){
    cout << "Reached end of file. Missing delimiter ')'.";
  }
}

void SyntaxChecker::incoBrack(string filename){
  brackStack = new GenStack<char>(leftBrack * 2);
  int line = 0;
  string local;
  ifstream myFile (filename.c_str());

  while(getline(myFile,local)){
    line++;
    for(int i = 0; i < local.length(); i++){
      if(local[i] == '(' || local[i] == '[' || local[i] == '{'){
        parStack->push(local[i]);
      }
      if(local[i] == ')' || local[i] == ']' || local[i] == '}'){
        if('[' != parStack->look()){
          cout << "Delimiter does not match at line " << line << " expected was ']'.";
        }
        else{
          parStack->pop();
        }
      }
    }
  }
  if(!parStack->isEmpty()){
    cout << "Reached end of file. Missing delimiter ']'.";
  }
}

void SyntaxChecker::incoCurl(string filename){
  curlStack = new GenStack<char>(leftCurl * 2);
  int line = 0;
  string local;
  ifstream myFile (filename.c_str());

  while(getline(myFile,local)){
    line++;
    for(int i = 0; i < local.length(); i++){
      if(local[i] == '(' || local[i] == '[' || local[i] == '{'){
        parStack->push(local[i]);
      }
      if(local[i] == ')' || local[i] == ']' || local[i] == '}'){
        if('{' != parStack->look()){
          cout << "Delimiter does not match at line " << line << " expected was '}'.";
        }
        else{
          parStack->pop();
        }
      }
    }
  }
  if(!parStack->isEmpty()){
    cout << "Reached end of file. Missing delimiter '}'.";
  }
}
