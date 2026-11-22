class MyClass {
public:
    unsigned int getValue(unsigned int idx) const;
private:
    char padding[0xc54];
    struct Elem { unsigned int value; char pad[12]; };
    Elem arr[1];
};

unsigned int MyClass::getValue(unsigned int idx) const
{
    return this->arr[idx].value;
}

