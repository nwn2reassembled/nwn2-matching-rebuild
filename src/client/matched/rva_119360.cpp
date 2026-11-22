struct Legacy {
    char pad[0x164];
    unsigned int legacyField;
    void setLegacy();
};

void Legacy::setLegacy() {
    legacyField = 1;
}

