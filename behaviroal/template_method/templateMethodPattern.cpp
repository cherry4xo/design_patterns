#include <iostream>

class AbstractClass
{
public:
    virtual ~AbstractClass() {}

    void templateMethod()
    {
        primitiveOperation1();
        primitiveOperation2();
    }

    virtual void primitiveOperation1() = 0;
    virtual void primitiveOperation2() = 0;
};

class ConcreteClass1 : public AbstractClass
{
public:
    ~ConcreteClass1() {}

    void primitiveOperation1() override
    {
        std::cout << "Primitive operation 1\n";
    }

    void primitiveOperation2() override
    {
        std::cout << "Primitive operation 2\n";
    }
};

class ConcreteClass2 : public AbstractClass
{
public:
    ~ConcreteClass2() {}

    void primitiveOperation1() override
    {
        std::cout << "Another primitive operation 1\n";
    }

    void primitiveOperation2() override
    {
        std::cout << "Another primitive operation 2\n";
    }
};

class Director
{
public:
    Director(AbstractClass* t) : template_(t) {}
    ~Director()
    {
        if (template_)
            delete template_;
    }

    void setTemplate(AbstractClass* t)
    {
        if (template_)
            delete template_;
        template_ = t;
    }

    void method()
    {
        template_->templateMethod();
    }
private:
    AbstractClass* template_;
};

int main(int argc, char** agrv)
{
    AbstractClass* templateClass = new ConcreteClass1();
    templateClass->templateMethod();

    Director* director = new Director(new ConcreteClass1());
    director->method();
    director->setTemplate(new ConcreteClass2());
    director->method();

    return 0;
}