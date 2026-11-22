struct LegacyClass {
    char padding[0xa8];
    int value;
    void setValue(int);
};

void LegacyClass::setValue(int v) {
    this->value = v;
}

