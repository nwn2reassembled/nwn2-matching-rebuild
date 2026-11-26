struct LegacyObject {
    char padding[0x78];
    unsigned int data[10];
    unsigned int getArrayElement(int idx) const;
};

unsigned int LegacyObject::getArrayElement(int idx) const { return data[idx]; }

