struct LegacyObject {
    unsigned char getByteAt1C() const;
};

unsigned char LegacyObject::getByteAt1C() const {
    return *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(this) + 0x1c);
}
