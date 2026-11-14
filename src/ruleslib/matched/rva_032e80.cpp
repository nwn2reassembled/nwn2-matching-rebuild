class Legacy {
public:
    short field0;   // offset 0x00
    short field2;   // offset 0x02, written by setField
    static void __stdcall setField(Legacy* obj, short value);
};

void Legacy::setField(Legacy* obj, short value) {
    obj->field2 = value;
}

