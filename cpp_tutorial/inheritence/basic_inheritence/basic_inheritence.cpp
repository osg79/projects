#include <iostream>

class Base
{
public:
    Base() { std::cout << "Base Constructor called" << std::endl; }
    ~Base() { std::cout << "Base Destructor called" << std::endl; }
    void setter(int val1, float val2, char val3)
    {
        m_var1 = val1;
        m_var2 = val2;
        m_var3_ = val3;
        print();
    }
    int m_var1{};

protected:
    float m_var2{};
    void print() const
    {
        std::cout << "Class members:" << std::endl;
        std::cout << "Public member: " << m_var1 << std::endl;
        std::cout << "Protected member: " << m_var2 << std::endl;
        std::cout << "Private member: " << m_var3_ << std::endl;
    }

private:
    char m_var3_{};
};

class DerivedPublic : public Base
{
public:
    DerivedPublic()
    {
        std::cout << "DerivedPublic Constructor called" << std::endl;
    }
    ~DerivedPublic()
    {
        std::cout << "DerivedPublic Destructor called" << std::endl;
    }
    void print_accessible() const
    {
        std::cout << "Accessible members:" << std::endl;
        std::cout << "Public member: " << m_var1 << std::endl;
        std::cout << "Protected member: " << m_var2 << std::endl;
        std::cout << "Cannot access Private member m_var3_" << std::endl;
    }
};

class DerivedProtected : protected Base
{
public:
    DerivedProtected()
    {
        std::cout << "DerivedProtected Constructor called" << std::endl;
        setter(3, 7.5f, 'C');
    }
    ~DerivedProtected()
    {
        std::cout << "DerivedProtected Destructor called" << std::endl;
    }
    void print_accessible() const
    {
        std::cout << "Accessible members:" << std::endl;
        std::cout << "Public member: " << m_var1 << std::endl;
        std::cout << "Protected member: " << m_var2 << std::endl;
        std::cout << "Cannot access Private member m_var3_" << std::endl;
    }
};

class DerivedPrivate : private Base
{
public:
    DerivedPrivate()
    {
        std::cout << "DerivedPrivate Constructor called" << std::endl;
        setter(4, 10.0f, 'D');
    }
    ~DerivedPrivate()
    {
        std::cout << "DerivedPrivate Destructor called" << std::endl;
    }
    void print_accessible() const
    {
        std::cout << "Accessible members:" << std::endl;
        std::cout << "Public member: " << m_var1 << std::endl;
        std::cout << "Protected member: " << m_var2 << std::endl;
        std::cout << "Cannot access Private member m_var3_" << std::endl;
    }
};

int main()
{
    Base *base = new Base;
    base->setter(1, 2.5f, 'A');
    // Cannot access protected members of a class from outside the class
    // base->print(); NOT ALLOWED!

    DerivedPublic *derived_public = new DerivedPublic;
    derived_public->setter(2, 5.0f, 'B');
    derived_public->print_accessible();

    DerivedProtected *derived_protected = new DerivedProtected;
    // Not allowed because setter() is now a protected member of DerivedProtected
    // derived_protected->setter(3, 7.5f, 'C');
    derived_protected->print_accessible();

    DerivedPrivate *derived_private = new DerivedPrivate;
    // Not allowed because setter() is now a private member of DerivedPrivate
    // derived_protected->setter(3, 7.5f, 'C');
    derived_private->print_accessible();

    delete base;
    delete derived_public;
    delete derived_protected;
    delete derived_private;
    return 0;
}