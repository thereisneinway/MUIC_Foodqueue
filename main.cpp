#include <iostream>
#include <string.h>
#include "Queue.h"
void pay(int);
int main(int argc , char **argv) {
  Queue Q;
  Q.headPtr = NULL;
  Q.tailPtr = NULL;
  Q.size=0;
  int i = 1;
  int indexB = 1, indexS = 1;
  cout<<"====================="<<endl;
  while(i < argc){
    if(argv[i][0] == 'x'){
      if(indexB>indexS) cout<<"Customer number: "<<indexS<<endl;
      int price = dequeue_struct(Q);
      if(indexB>indexS) {
        cout<<" | Total price: "<< price <<endl;
        pay(price);
        cout<<"THANK YOU!"<<endl;
      }
      indexS++;
    }else if(0<atoi(argv[i])&&atoi(argv[i])<5){
      cout<<"Customer number: "<< indexB <<endl;
      enqueue_struct(Q,atoi(argv[i])-1,atoi(argv[i+1]));
      i++;
      indexB++;
    }else{
      cout<<"Invalid argument";
      return 0;
    }
    cout<<"====================="<<endl;
    i++;
  }
  
        
  return 0;
}

void pay(int price){
  int input,change,done = 0;
  cout<<"Enter your money you want to pay: ";
  cin>>input;
  change = input-price;
  do{
    if(change >=0) {
      cout<<"Change: "<<change<<endl;
      done = 1;
    }
    else{
      cout<<"NOT ENOUGH!\nEnter more money: ";
      cin>>input;
      change += input;
    }
  }while(done == 0);
}
