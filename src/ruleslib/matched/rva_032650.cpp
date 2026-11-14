class MyClass {
public:
    void setElement(int* base, int index, int value);
};

void MyClass::setElement(int* base, int index, int value)
{
    *reinterpret_cast<int*>(reinterpret_cast<char*>(base) + 0x30 + index * 4) = value;
}

