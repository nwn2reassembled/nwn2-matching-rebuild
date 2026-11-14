struct MyStruct {
    char pad[0x3C];
    unsigned short field;
};

class Utils {
public:
    static void __stdcall setField(MyStruct* obj, unsigned short val);
};

void Utils::setField(MyStruct* obj, unsigned short val)
{
    // Store the 16‑bit value at offset 0x3C of the object.
    *(unsigned short*)((char*)obj + 0x3C) = val;
}

// Ensure the function is emitted and not inlined or discarded.
static void (__stdcall *ptr)(MyStruct*, unsigned short) = Utils::setField;
