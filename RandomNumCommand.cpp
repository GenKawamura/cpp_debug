/*
 * C++ Sample code: Using OOP Command pattern
 * Author: Gen Kawamura
 * 2020
 *
 */

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "RandomNumCommand.h"

// STL vector
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Receiver
 * Knows how to perform the operations associated
 * with carrying out a request
 * Implemented a simple random number generator
 */
bool mysort (int i,int j) { return (i<j); };

void RandomNumReceiver::action(){


    cout << "Starting RandomNumGenerator" << endl;
    int random[10];
    srand(time(NULL));

    // Generating random numbers
    for(int i=0; i<100; i++) {
      random[i] = rand();
      cout << i << " = " << random[i] << endl;
    }
    cout << "----------------------" << endl;

    // Using vector. Int array is coverted 
    int n = sizeof(random) / sizeof(random[0]);
    vector<int> myrand(random, random+n);

    // Homework. Use sorting with STL and mysort function above defined
    // Hint: check 'std::sort'


    // Display the sorted result of myrand using vector iterator
    
}

/*
 * Concrete Command
 * Executing by invoking the operation(s) on Receiver
 */
ConcreteCommand::ConcreteCommand( RandomNumReceiver *r ) : receiver( r ) {}
ConcreteCommand::  ~ConcreteCommand() {
  if ( receiver ) {
    delete receiver;
  }
}
  
void ConcreteCommand::execute() {
  receiver->action();
}


/*
 * Invoker
 * asks the command to carry out the request
 */
void Invoker::set( Command *c ){
  command = c;
}

void Invoker::confirm(){
  if ( command ) {
    command->execute();  
  }
}
