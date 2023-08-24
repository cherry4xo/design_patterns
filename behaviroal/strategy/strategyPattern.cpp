#include <iostream>

class Strategy
{
public:
    virtual ~Strategy() {}
    virtual void algorithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy
{
public:
    ~ConcreteStrategyA() {}

    void algorithmInterface() override
    {
        std::cout << "ConcreteStrategyA\n";
    }
};

class ConcreteStrategyB : public Strategy
{
public:
    ~ConcreteStrategyB() {}

    void algorithmInterface() override
    {
        std::cout << "ConcreteStrategyB\n";
    }
};

class ConcreteStrategyC : public Strategy
{
public:
    ~ConcreteStrategyC() {}

    void algorithmInterface() override
    {
        std::cout << "ConcreteStrategyC\n";
    }
};

class Context
{
public:
    Context(Strategy* s) : strategy(s) {}
    ~Context() 
    {
        delete strategy;
    }

    void setStrategy(Strategy* s)
    {
        if(strategy)
            delete strategy;
        strategy = s;
    }

    void contextInterface()
    {
        strategy->algorithmInterface();
    }

private:
    Strategy* strategy;
};

int main(int argc, char** argv)
{
    Context context(new ConcreteStrategyA());
    context.contextInterface();
    context.setStrategy(new ConcreteStrategyB());
    context.contextInterface();
}