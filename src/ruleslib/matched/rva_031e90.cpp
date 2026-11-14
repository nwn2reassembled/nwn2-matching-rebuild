struct LegacyStruct {
    unsigned char padding[0x44];
    unsigned char byte_at_0x44;
    static unsigned int __stdcall getByte(const LegacyStruct* p);
};

unsigned int LegacyStruct::getByte(const LegacyStruct* p) {
    return static_cast<unsigned int>(p->byte_at_0x44);
}

