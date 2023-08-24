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

class Adapter : public Target, public Adaptee
{
public:
    Adapter() { std::cout << "Adapter\n"; }
    ~Adapter() {}

    void request()
    {
        specificRequest();
        std::cout << "This is a request\n";
    }
};

int main(int argc, char** argv)
{
    Target* t = new Adapter();
    t->request();
}