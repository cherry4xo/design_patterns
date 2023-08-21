#include <iostream>

class AbstractProductA
{
public:
    AbstractProductA() { std::cout << "AbstractProductA\n"; }
    virtual ~AbstractProductA() {}
    virtual void checkProduct() = 0;
};

class AbstractProductB
{
public:
    AbstractProductB() { std::cout << "AbstractProductB\n"; }
    virtual ~AbstractProductB() {}
    virtual void checkProduct() = 0;
};

class ProductA1 : public AbstractProductA
{
public:
    ProductA1() { std::cout << "ProductA1\n"; }
    ~ProductA1() override {}
    void checkProduct() override { std::cout << "ProductA1 has been created\n"; }
};

class ProductA2 : public AbstractProductA
{
public:
    ProductA2() { std::cout << "ProductA2\n"; }
    ~ProductA2() override {}
    void checkProduct() override { std::cout << "ProductA2 has been created\n"; }
};

class ProductB1 : public AbstractProductB
{
public:
    ProductB1() { std::cout << "ProductB1\n"; }
    ~ProductB1() override {}
    void checkProduct() override { std::cout << "ProductB1 has been created\n"; }
};

class ProductB2 : public AbstractProductB
{
public:
    ProductB2() { std::cout << "ProductB2\n"; }
    ~ProductB2() override {}
    void checkProduct() override { std::cout << "ProductB2 has been created\n"; }
};

class AbstractFactory
{
public:
    AbstractFactory() { std::cout << "AbstractFactory\n"; }
    virtual ~AbstractFactory() {}
    virtual AbstractProductA* createProductA() = 0;
    virtual AbstractProductB* createProductB() = 0;
};

class ConcreateFactory1 : public AbstractFactory
{
public:
    ConcreateFactory1() { std::cout << "ConcreateFactory1\n"; }
    ~ConcreateFactory1() override {}
    AbstractProductA* createProductA() override { return new ProductA1; }
    AbstractProductB* createProductB() override { return new ProductB1; }
};

class ConcreateFactory2 : public AbstractFactory
{
public:
    ConcreateFactory2() { std::cout << "ConcreateFactory2\n"; }
    ~ConcreateFactory2() override {}
    AbstractProductA* createProductA() override { return new ProductA2; }
    AbstractProductB* createProductB() override { return new ProductB2; }
};


int main(int argc, char** argv)
{
    AbstractFactory* cf1 = new ConcreateFactory1();
    AbstractProductA* productA1 = cf1->createProductA();
    productA1->checkProduct();
    AbstractProductB* productB1 = cf1->createProductB();
    productB1->checkProduct();

    AbstractFactory* cf2 = new ConcreateFactory2();
    AbstractProductA* productA2 = cf2->createProductA();
    productA2->checkProduct();
    AbstractProductB* productB2 = cf2->createProductB();
    productB2->checkProduct();

    return 0;
}
