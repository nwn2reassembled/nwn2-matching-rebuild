struct MyStruct {
    char pad[0x608];
    unsigned int field;
};

struct Helper {
    static void __stdcall setField(MyStruct* obj, unsigned int val);
};

void Helper::setField(MyStruct* obj, unsigned int val) {
    obj->field = val;
}

