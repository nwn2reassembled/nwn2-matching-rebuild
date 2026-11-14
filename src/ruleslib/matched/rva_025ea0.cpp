struct MyStruct {
    char pad[0xD8];          // offset 0xd8
    unsigned int value;      // field accessed by the legacy function
    static unsigned int __stdcall getValue(MyStruct* obj);   // ordinary member, defined out‑of‑line
};

unsigned int MyStruct::getValue(MyStruct* obj) {
    return obj->value;
}

