/*
 * C++ Sample code: Using OOP Command pattern
 * Author: Gen Kawamura
 * 2020
 *
 */

/*
 * Receiver
 */
class Receiver {
public:
  virtual void action() = 0;
};

class RandomNumReceiver : public Receiver {
 public:
  void action();
};

/*
 * Command
 */
class Command {
public:
  virtual ~Command() {}
  virtual void execute() = 0;

protected:
  Command() {}
};

/*
 * Concrete Command
 */
class ConcreteCommand : public Command {
public:
  ConcreteCommand( RandomNumReceiver *r );
  ~ConcreteCommand();
  void execute();
private:
  RandomNumReceiver *receiver;
};


/*
 * Invoker
 */
class Invoker {
public:
  void set( Command *c );
  void confirm();

private:
  Command *command;
};
