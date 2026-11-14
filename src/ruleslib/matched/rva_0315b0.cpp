struct Legacy {
    char pad[0x5b4];
    int field;
    static void __stdcall setField(Legacy* obj, int value);
};

void Legacy::setField(Legacy* obj, int value) {
    obj->field = value;
}

