#include <iostream>

class Subject
{
public:
    virtual ~Subject() {}

    virtual void request() = 0;
};

class RealSubject : public Subject
{
public:
    void request() override
    {
        std::cout << "RealSubject request\n";
    }
};

class Proxy : public Subject
{
public:
    Proxy() { subject = new RealSubject(); }
    ~Proxy() { delete subject; }

    void request() override
    {
        subject->request();
    }

private:
    RealSubject* subject;
};

int main(int argc, char** argv)
{
    Proxy* proxy = new Proxy();
    proxy->request();

    delete proxy;

    return 0;
}