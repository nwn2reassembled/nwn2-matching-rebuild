class MyClass {
public:
    int foo(int first, unsigned char second);
};

int MyClass::foo(int /*first*/, unsigned char second) {
    return (second <= 9);
}

