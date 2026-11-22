struct LegacyObject {
    char pad[0xE38];
    unsigned int field;
    void resetField();
};

void LegacyObject::resetField() {
    field = 0u;
}

