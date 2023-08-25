#include <iostream>

class Subsystem1
{
public:
    void suboperation() 
    {
        std::cout << "Subsystem1 Operation\n";
    }
};

class Subsystem2
{
public:
    void suboperation()
    {
        std::cout << "Subsystem2 Operation\n";
    }
};

class Facade
{
public:
    Facade() 
    {
        std::cout << "Facade\n";
        subsystem1 = new Subsystem1();
        subsystem2 = new Subsystem2();
    }

    ~Facade()
    {
        if(subsystem1)
            delete subsystem1;
        if(subsystem2)
            delete subsystem2;
    }

    void operationWrapper()
    {
        subsystem1->suboperation();
        subsystem2->suboperation();
    }

private:
    Subsystem1* subsystem1;
    Subsystem2* subsystem2;
};

int main(int argc, char** argv)
{
    Facade facade;
    facade.operationWrapper();

    return 0;
}