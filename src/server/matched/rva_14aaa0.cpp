struct MyClass {
    int dummy;
    unsigned int* ptr;
    void func(unsigned int);
};

void MyClass::func(unsigned int val)
{
    // Store the argument at offset 0x10194 bytes from *ptr.
    *(ptr + 0x4065) = val;   // 0x4065 * sizeof(unsigned int) == 0x10194
}

