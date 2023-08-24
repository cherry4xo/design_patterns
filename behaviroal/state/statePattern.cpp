#include <iostream>

class State
{
public:
    virtual ~State() {}

    virtual void handle() = 0;
};

class ConcreteStateA : public State
{
    ~ConcreteStateA() {}

    void handle() override 
    {
        std::cout << "State A handled\n";
    }
};

class ConcreteStateB : public State
{
public:
    ~ConcreteStateB() {}

    void handle() override 
    {
        std::cout << "State B handled\n";
    }
};

class Context
{
public:
    Context() : state() {}
    ~Context()
    {
        if(state)
            delete state;
    }

    void setState(State* const s)
    {
        if(state)
            delete state;
        state = s;
    }

    void request()
    {
        state->handle();
    }

private:
    State* state;
};

int main(int argc, char** argv)
{
    Context* context = new Context();

    context->setState(new ConcreteStateA());
    context->request();

    context->setState(new ConcreteStateB());
    context->request();

    return 0;
}