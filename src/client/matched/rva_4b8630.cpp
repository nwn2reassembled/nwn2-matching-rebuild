struct MyStruct {
    int a;
    int b;
    unsigned int low;   // offset 8
    unsigned int high;  // offset 12

    unsigned __int64 getValue();
};

unsigned __int64 MyStruct::getValue() {
    return *reinterpret_cast<unsigned __int64*>( reinterpret_cast<char*>(this) + 8 );
}

