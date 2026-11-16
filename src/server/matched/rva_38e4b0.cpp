struct MyClass {
    int m_value;
    int foo(int);
};

int MyClass::foo(int arg) { return m_value + arg * 4; }
