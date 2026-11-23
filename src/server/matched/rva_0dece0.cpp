struct LegacyObject {
    char pad[12];
    int value;
    int getValue();
};

int LegacyObject::getValue() { return value; }
