struct ServerObject {
    char pad0[0x23];
    unsigned char flagAt23;
    char pad24[0x0e];
    signed char curValue;
};

void __cdecl SetServerObjectValue(ServerObject* obj, int value) {
    if (value == obj->curValue) {
        return;
    }
    if (value == 1) {
        if (obj->flagAt23 == 1) {
            obj->curValue = 1;
        }
    } else if (value == 0) {
        if (obj->flagAt23 == 1) {
            obj->curValue = 0;
        }
    }
}
