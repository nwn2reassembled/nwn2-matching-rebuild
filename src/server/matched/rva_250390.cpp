struct MyClass {
    int test(unsigned int);
};

int MyClass::test(unsigned int arg)
{
    return (arg <= 1u) ? 1 : 0;
}

