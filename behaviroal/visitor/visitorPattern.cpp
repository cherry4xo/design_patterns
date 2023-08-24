#include <iostream>

class Element;
class ConcreteElementA;
class ConcreteElementB;

class Visitor
{
public:
    virtual ~Visitor() {}

    virtual void visitorElementA(ConcreteElementA* const element) = 0;
    virtual void visitorElementB(ConcreteElementB* const element) = 0;
};

class ConcreteVisitorA : public Visitor
{
public:
    ~ConcreteVisitorA() {}

    void visitorElementA(ConcreteElementA* const element) override;
    void visitorElementB(ConcreteElementB* const element) override;
};

class ConcreteVisitorB : public Visitor
{
public:
    ~ConcreteVisitorB() {}

    void visitorElementA(ConcreteElementA* const element) override;
    void visitorElementB(ConcreteElementB* const element) override;
};

class Element
{
public:
    virtual ~Element() {}

    virtual void accept(Visitor& v) = 0;
};

class ConcreteElementA : public Element
{
public:
    ConcreteElementA(const std::string& data)
        : data_(data) {}
    ~ConcreteElementA() {}

    void accept(Visitor& v) override
    {
        v.visitorElementA(this);
    }

    std::string getData()
    {
        return data_;
    }

private:
    std::string data_;
};

class ConcreteElementB : public Element {
public:
    ConcreteElementB(const std::string& data)
    : data_(data) {}
    ~ConcreteElementB() {}

    void accept(Visitor& v) {
        v.visitorElementB(this);
    }

    std::string getData() {
        return data_;
    }
private:
    std::string data_;
};

void ConcreteVisitorA::visitorElementA(ConcreteElementA* const element)
{
    std::cout << "Concrete visitor A: Element A visited\n";
    std::cout << "Element A data: " << element->getData() << std::endl;
}

void ConcreteVisitorA::visitorElementB(ConcreteElementB* const element)
{
    std::cout << "Concrete visitor A: Element B visited\n";
    std::cout << "Element B data: " << element->getData() << std::endl;
}

void ConcreteVisitorB::visitorElementA(ConcreteElementA* const element)
{
    std::cout << "Concrete visitor B: Element A visited\n";
    std::cout << "Element A data: " << element->getData() << std::endl;
}

void ConcreteVisitorB::visitorElementB(ConcreteElementB* const element)
{
    std::cout << "Concrete visitor B: Element B visited\n";
    std::cout << "Element B data: " << element->getData() << std::endl;
}

int main(int argc, char** argv)
{
    ConcreteElementA elementA("Hello");
    ConcreteElementB elementB("World");

    ConcreteVisitorA visitorA;
    ConcreteVisitorB visitorB;

    elementA.accept(visitorA);
    elementA.accept(visitorB);

    elementB.accept(visitorA);
    elementB.accept(visitorA);

    return 0;
}