struct LegacyClass {
    char pad[0xA20];
    int field;
    void setZero();
};

void LegacyClass::setZero() {
    field = 0;
}

