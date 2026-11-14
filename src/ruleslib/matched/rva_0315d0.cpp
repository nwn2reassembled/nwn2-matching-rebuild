struct MyStruct {
    char padding[0x5b4];
    int value;
};

class Helper {
public:
    static int __stdcall getValue(MyStruct* ptr);
};

int Helper::getValue(MyStruct* ptr) { return ptr->value; }

