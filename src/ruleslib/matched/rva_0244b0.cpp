struct Data {
    int a, b, c;
    unsigned char lower : 2;
    unsigned char flag : 1;
    unsigned char upper : 5;
};

class MyClass {
public:
    static void __stdcall method(Data* data, void* flagArg);
};

void __stdcall MyClass::method(Data* data, void* flagArg) {
    data->flag = flagArg != 0;
}
