struct Legacy {
    char pad[0x294];
    unsigned int value;

    static unsigned int __stdcall getValue(Legacy* obj);
};

unsigned int Legacy::getValue(Legacy* obj) {
    return obj->value;
}

