struct LegacyClass {
    unsigned int readOffset3C(void* ptr);
};

unsigned int LegacyClass::readOffset3C(void* ptr) {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(ptr) + 0x3c);
}

