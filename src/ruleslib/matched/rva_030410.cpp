struct Legacy {
    char pad[0xA8];
    int field;
    static void __stdcall setField(Legacy* thisPtr, int value);
};

void Legacy::setField(Legacy* thisPtr, int value) {
    thisPtr->field = value;
}

