#include <iostream>
#include <string.h>
#include "Queue.h"

int main(int argc , char **argv) {
  Queue Q;
  Q.headPtr = NULL;
  Q.tailPtr = NULL;
  Q.size=0;
  int i = 1;
  while(i < argc){
    if(argv[i][0] == 'x'){
      int price = dequeue_struct(Q);
      cout<<" | Total price: "<< price <<endl;
    }else if(0<atoi(argv[i])&&atoi(argv[i])<5){
      enqueue_struct(Q,atoi(argv[i])-1,atoi(argv[i+1]));
      i++;
    }else{
      cout<<"Invalid argument";
      return 0;
    }
    i++;
  }
  
        
  return 0;
}