struct MyClass {
    virtual void dummy() {}
    int* ptr;
    int getValue();
};

int MyClass::getValue()
{
    return *reinterpret_cast<int*>( reinterpret_cast<char*>(ptr) + 0x240 );
}

