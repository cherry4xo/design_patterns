#include <iostream>

class Reciever
{
public:
    void action()
    {
        std::cout << "Reciever: execute action\n";
    }
};

class Command
{
public:
    virtual ~Command() {}

    virtual void execute() = 0;
};

class ConcreteCommand : public Command
{
public:
    ConcreteCommand(Reciever* r): reciever_(r) {}
    ~ConcreteCommand () override 
    {
        if(!reciever_)
            delete reciever_;
    }

    void execute() override 
    {
        reciever_->action();
    }
private:
    Reciever* reciever_;
};

class Invoker
{
public:
    void setCommand(Command* c) { command_ = c; }

    void executeCommand()
    {
        if(command_) command_->execute();
    }

private:
    Command* command_;
};

int main(int argc, char** argv)
{
    Reciever* reciever = new Reciever();
    Command* command = new ConcreteCommand(reciever);

    Invoker invoker;
    invoker.setCommand(command);
    invoker.executeCommand();

    return 0;
}