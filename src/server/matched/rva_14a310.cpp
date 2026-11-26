class MyClass {
public:
    int getValue();
};

int MyClass::getValue()
{
    // Load pointer from offset 4 of this object.
    void *ptr = *(void**)((char*)this + 4);
    // Return the integer located at ptr + 0x10090.
    return *(int*)((char*)ptr + 0x10090);
}

