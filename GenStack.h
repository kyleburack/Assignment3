/*
Kyle Burack
2288845
burack@chapman.edu
CPSC350-1
Assignment3 - Syntax Checker
*/

#include <iostream>
#ifndef GENSTACK_H
#define GENSTACK_H

using namespace std;

template <class T>
//template will have the .h and .cpp of the given GenStack in lecture combined into 1 class
class GenStack{
private:
  // s = size
  // t = top
  int s;
  int t;
  T *arr;
public:
  GenStack(){ //default constructor
    s = 0;
    t = -1;
  };
  GenStack(int maximumSize){ //constructor that allows for imput of the size of the array based stack
      s = maximumSize;
      t = -1;
//dynamic memory allocation, needs to be deleted in the destructor
//Setting the 'T *arr' to arr with the maximumSize instead of an empty array
      arr = new T[s];
    };

  ~GenStack(){
    delete []arr;
    cout << "Stack deleted" << endl;
  };
/* List of necessary functions to properly use a stack,

s == size
t == top

pop() - returns and removes the top of the stack
isFull() - returns true if s - 1 == t
isEmpty() - returns true if t == -1
look() - looks at the top of the stack but does not return / eliminate the top of the stack like pop does.
moveTop() - moves a specific position from a certain place in the stack to the top to be the nexted to be popped/looked at.
*/

T pop(){
  if(isEmpty() == true){
    cout << "Stack is empty" << endl;
    return arr[0];
  }
  return arr[t--];
};

bool isFull(){
  //return true if the top is equal to size -1 as the size starts at 0 in the default constructor as the top starts at -1. (size can never be negative)
  return (s - 1 == t);
};

bool isEmpty(){
  //return true if top is at 1 which is what t was intilized as, if t is any other number, will return false
  return (t == -1);
};

T look(){
    if(isEmpty() == true){
      cout << "Stack is empty" << endl;
      return arr[0];
    }
    return arr[t];
};

void push(T x){
  //need to move the place of the stack where 'x' is to be at the new top, (++t) as t==-1
  if(isEmpty() == true){
    cout << "Stack is empty" << endl;
  }
  else{
    //use ++t so that the 'x' is the new top which allows the rest to shift down as t is updated in the stack
    arr[++t] == x;
  }
};
};

#endif
