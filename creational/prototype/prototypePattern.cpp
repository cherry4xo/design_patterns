#include <iostream>
#include <string>

class Prototype
{
public:
    Prototype() { std::cout << "Prototype\n"; }
    virtual ~Prototype() {}
    virtual Prototype* clone() = 0;
    virtual void checkPrototype() = 0;
};

class ConcreatePrototype1 : public Prototype
{
public:
    ConcreatePrototype1() { std::cout << "ConcreatePrototype1\n"; }
    ~ConcreatePrototype1() override {}

    Prototype* clone() override 
    {
        return new ConcreatePrototype1;
    }   
    void checkPrototype() override
    {
        std::cout << "Prototype1 has been created\n";
    }
};

class ConcreatePrototype2 : public Prototype
{
public:
    ConcreatePrototype2() { std::cout << "ConcreatePrototype2\n"; }
    ~ConcreatePrototype2() override {}

    Prototype* clone() override
    {
        return new ConcreatePrototype2;
    }
    void checkPrototype() override
    {
        std::cout << "Prototype2 has been created\n";
    }
};

class Client
{
public:
    Client() { std::cout << "Client\n"; }
    ~Client()
    {
        if(prototype)
            delete prototype;
    }
    void setPrototype(Prototype* p)
    {
        if(prototype)
            delete prototype;
        prototype = p;
    }
    Prototype* clone()
    {
        if(!prototype)
            return nullptr;
        return prototype->clone();
    }
private:
    Prototype* prototype = nullptr;
};


int main(int argc, char** argv)
{
    Client client;
    client.setPrototype(new ConcreatePrototype1);
    Prototype* p1 = client.clone();
    p1->checkPrototype();

    client.setPrototype(new ConcreatePrototype2);
    Prototype* p2 = client.clone();
    p2->checkPrototype();

    return 0;
}