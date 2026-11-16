struct LegacyStruct {
    char pad[0x178];
    unsigned long value;
    static unsigned long __stdcall getLegacyValue(LegacyStruct* p);
};

unsigned long LegacyStruct::getLegacyValue(LegacyStruct* p) {
    return p->value;
}

