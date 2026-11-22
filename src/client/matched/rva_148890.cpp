struct MyStruct {
    char dummy;
    void* ptr;
    int getValue();
};

int MyStruct::getValue()
{
    return *reinterpret_cast<int*>( reinterpret_cast<char*>(ptr) + 0x10014 );
}

