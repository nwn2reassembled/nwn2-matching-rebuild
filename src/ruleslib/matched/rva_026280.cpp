struct MyStruct {
    char pad[0x1e8];
    int value;
    static int __stdcall getValue(const MyStruct*);
};

int MyStruct::getValue(const MyStruct* obj) { return obj->value; }
