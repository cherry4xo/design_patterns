#include <iostream>
#include <string>

class Target
{
public:
    Target() { std::cout << "Target\n"; }
    virtual ~Target() {}

    virtual void request() = 0;
};

class Adaptee
{
public:
    Adaptee() { std::cout << "Adaptee\n"; }
    virtual ~Adaptee() {}

    void specificRequest() 
    {
        std::cout << "This is a specific request\n";
    }
};

class Adapter : public Target
{
public:
    Adapter()
    {
        adaptee = new Adaptee();
        std::cout << "Adapter\n"; 
    }
    ~Adapter()
    {
        delete adaptee;
    }

    void request()
    {
        adaptee->specificRequest();
        std::cout << "This is a request\n";
    }

private:
    Adaptee* adaptee = nullptr; 
};

int main(int argc, char** argv)
{
    Target* t = new Adapter();
    t->request();

    return 0;
}