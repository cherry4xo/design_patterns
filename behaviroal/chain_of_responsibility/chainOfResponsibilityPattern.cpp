#include <iostream>
#include <string>

class Handler
{
public:
    virtual ~Handler() {}

    void setSuccessor(Handler* s)
    {
        successor_ = s;
    }

    Handler* getSuccessor()
    {
        return successor_;
    }

    virtual void handleRequest() = 0;

private:
    Handler* successor_;
};

class ConcreateHandler1 : public Handler
{
public:
    ~ConcreateHandler1() {}

    void handleRequest() override
    {
        if (!this->getSuccessor())
            std::cout << "This is handled by ConcreateHandler1\n";
        else
        {
            std::cout << "This will be handled by the successor\n";
            this->getSuccessor()->handleRequest();
        }
    }
};

class ConcreateHandler2 : public Handler
{
public:
    ~ConcreateHandler2() {}

    void handleRequest() override
    {
        if (!this->getSuccessor())
            std::cout << "This is handled by ConcreateHandler2\n";
        else
        {
            std::cout << "This will by handled by the successor\n";
            this->getSuccessor()->handleRequest();
        }
    }
};

int main(int argc, char** argv)
{
    Handler* h1 = new ConcreateHandler1();
    Handler* h2 = new ConcreateHandler2();

    h1->getSuccessor();
    h1->handleRequest();
    h2->handleRequest();

    return 0;
}