/*
Kyle Burack
2288845
burack@chapman.edu
CPSC350-1
Assignment3 - Syntax Checker
*/

#include <iostream>
#include "GenStack.h"

using namespace std;

class SyntaxChecker{
public:
  //allows for each delimiter to be counted in the delimiter function to see if they are correctly even
  int leftPar;
  int rightPar;
  int leftBrack;
  int rightBrack;
  int leftCurl;
  int rightCurl;

  bool parEqual;
  bool brackEqual;
  bool curlEqual;

  GenStack<char>* parStack;
  GenStack<char>* brackStack;
  GenStack<char>* curlStack;

  //goes throught file / code adds each delimiter indivdualy, returns true if ( == ), { == }, [ == ].
  void delimiter(string fileName);
  void incoPar(string filename);
  void incoBrack(string filename);
  void incoCurl(string filename);
  void delimiterEqual();
};
