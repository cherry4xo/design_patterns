#include <iostream>
#include <string>

class Component
{
public:
    virtual ~Component() {}

    virtual void operation() = 0;
};

class ConcreteComponent : public Component
{
public:
    ~ConcreteComponent() {}

    void operation() override
    {
        std::cout << "Concrete component operation\n";
    }
};

class Decorator : public Component
{
public:
    ~Decorator() {}

    Decorator(Component* c) : component_(c) {}

    virtual void operation() override
    {
        component_->operation();
    }

private:
    Component* component_;
};

class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA(Component* c) : Decorator(c) {}

    void operation() override 
    {
        Decorator::operation();
        std::cout << "Added behavior for ConcreteDecoratorA\n";
    }
};

class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(Component* c) : Decorator(c) {} 

    void operation() override
    {
        Decorator::operation();
        std::cout << "Added behavior for ConcreteDecoratorB\n";
    }
};

int main(int argc, char** argv)
{
    Component* cc = new ConcreteComponent();
    ConcreteDecoratorA* cda = new ConcreteDecoratorA(cc);
    ConcreteDecoratorB* cdb = new ConcreteDecoratorB(cc);

    cda->operation();
    cdb->operation();

    return 0;
}