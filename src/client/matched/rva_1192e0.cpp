struct LegacyClass {
    char padding[0x108];
    int value;
    int getValue();
};

int LegacyClass::getValue() { return value; }
