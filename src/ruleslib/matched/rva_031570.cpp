class LegacyObject {
public:
    unsigned char pad[0x5FC];
    unsigned int value;
};

class LegacyClass {
public:
    unsigned int getField(const void* p) const;
};

unsigned int LegacyClass::getField(const void* p) const {
    return ((const LegacyObject*)p)->value;
}

