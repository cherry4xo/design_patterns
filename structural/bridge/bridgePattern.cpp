#include <iostream>
#include <string>

class Implementor
{
public:
    Implementor() { std::cout << "Implementor\n"; }
    virtual ~Implementor() {}

    virtual void operationImp() = 0;
};

class ConcreteImplementorA : public Implementor
{
public:
    ConcreteImplementorA() { std::cout << "ConcreteImplementorA\n"; }
    ~ConcreteImplementorA() {}

    void operationImp() override
    {
        std::cout << "This is operationImp from ConcreteImplementorA\n";
    }
};

class ConcreteImplementorB : public Implementor
{
public:
    ConcreteImplementorB() { std::cout << "ConcreteImplementorB\n"; }
    ~ConcreteImplementorB() {}

    void operationImp() override
    {
        std::cout << "This is operationImp from ConcreteImplementorB\n";
    }
};

class Abstraction
{
public:
    Abstraction() { std::cout << "Abstraction\n"; }
    virtual ~Abstraction() {}

    virtual void operation() = 0;
};

class RefinedAbstraction : public Abstraction
{
public:
    ~RefinedAbstraction() {}
    RefinedAbstraction(Implementor* ip)
        : implementor(ip) 
    {
        std::cout << "RefinedAbstraction\n";
    }

    void operation() 
    {
        implementor->operationImp();
    }

private:
    Implementor* implementor;
};

int main(int argc, char** argv)
{
    Implementor* imp1 = new ConcreteImplementorA();
    Abstraction* abs1 = new RefinedAbstraction(imp1);
    abs1->operation();

    Implementor* imp2 = new ConcreteImplementorB();
    Abstraction* abs2 = new RefinedAbstraction(imp2);
    abs2->operation();

    return 0;
}