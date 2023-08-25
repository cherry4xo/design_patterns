#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>

class Component
{
public:
    Component() { std::cout << "Component\n"; }
    virtual ~Component() {}

    virtual void operation() = 0;

    virtual void add(Component*) {};
    virtual void remove(Component*) {};
    virtual Component* getChild(u_int16_t) { return nullptr; }
};

class Leaf : public Component
{
public:
    Leaf(int id) : id_(id) { std::cout << "Leaf\n"; }
    ~Leaf() {}

    void operation() override { std::cout << "This is operation from Leaf: " << id_ << std::endl; }

private:
    int id_;
};

class Composite : public Component
{
public:
    Composite() { std::cout << "Composite\n"; }
    ~Composite() 
    {
        for(u_int16_t i = 0; i < children_.size(); ++i)
        {
            delete children_[i];
        }
    }

    void operation() override 
    {
        std::cout << "Size of children = " << children_.size() << std::endl;
        for(u_int16_t i = 0; i < children_.size(); ++i)
        {
            children_[i]->operation();
        }
    }

    void add(Component* c) override
    {
        children_.push_back(c);
    }

    void remove(Component* c) override
    {
        for(auto iter = children_.begin(); iter != children_.end(); ++iter)
        {
            if(*iter == c)
                children_.erase(iter);
        }
    }

    Component* getChild(u_int16_t idx) override
    {
        return idx < children_.size() ? children_[idx] : nullptr;
    }

private:
    std::vector<Component*> children_;
};

int main(int argc, char** argv)
{
    Composite composite;
    for(u_int16_t i = 0; i < 3; ++i)
    {
        composite.add(new Leaf(i));
    }

    composite.add(new Composite);

    composite.remove(0);
    composite.operation();

    Component* component1 = composite.getChild(0);
    component1->operation();

    Component* component2 = composite.getChild(3);
    component2->operation();

    return 0;
}