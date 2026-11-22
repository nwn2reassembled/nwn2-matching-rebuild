struct LegacyObject {
    unsigned int dummy;
    void* ptr;
    unsigned int getValue();
};

unsigned int LegacyObject::getValue()
{
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(ptr) + 0x98);
}

