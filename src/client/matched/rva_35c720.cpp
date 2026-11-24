struct LegacyObject {
    char padding[0x164];
    short value;
    short getValue() const;
};

short LegacyObject::getValue() const { return value; }
