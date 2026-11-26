struct NwnObject {
    unsigned char pad[0x30];

    NwnObject* baseOf();
};

NwnObject* NwnObject::baseOf() {
    return reinterpret_cast<NwnObject*>(reinterpret_cast<char*>(this) - 0x30);
}
