class MyClass
{
public:
    int dummy;
    struct Nested *ptr;
    unsigned int getValue() const;
};

struct Nested { /* contents irrelevant */ };

unsigned int MyClass::getValue() const
{
    return *reinterpret_cast<const unsigned int*>(
        reinterpret_cast<const char*>(ptr) + 0x90);
}

