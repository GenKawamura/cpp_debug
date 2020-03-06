#include "RandomNumCommand.h"

int main() {
  ConcreteCommand command( new RandomNumReceiver() );
  
  Invoker invoker;
  invoker.set( &command );
  invoker.confirm();
  
  return 0;
}

