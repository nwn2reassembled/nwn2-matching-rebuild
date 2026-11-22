struct MyClass{
    int dummy;            // offset +0
    int* ptr;             // offset +4
    void setValue(int value); // member function
};

void MyClass::setValue(int value){
    *reinterpret_cast<int*>((char*)ptr + 0x10100) = value;
}

