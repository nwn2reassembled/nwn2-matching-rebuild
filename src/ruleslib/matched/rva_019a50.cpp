class MyClass {
public:
    unsigned int computeLog2(unsigned int value);
};

unsigned int MyClass::computeLog2(unsigned int value)
{
    unsigned int count = 0;
    // Shift the input once; if it becomes zero, exit immediately.
    while ((value >>= 1)) {
        ++count;
    }
    return count;
}

