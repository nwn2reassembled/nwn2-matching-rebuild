struct ServerObject {
    unsigned char pad[0xA8];
    int valueAtA8;
};

void __cdecl SetServerValue(ServerObject* obj, int value)
{
    if (obj == 0) {
        (*(ServerObject**)0x83ee84)->valueAtA8 = value;
    } else {
        obj->valueAtA8 = value;
    }
}
