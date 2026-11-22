struct MyClass {
    char pad[132];
    int value;
};

class Wrapper {
public:
    MyClass* ptr;
    int getAndClear();
};

int Wrapper::getAndClear()
{
    MyClass* real = this->ptr;      // loads [ecx]
    int tmp = real->value;          // reads from [ecx+0x84]
    real->value = 0;
    return tmp;
}
