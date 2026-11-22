struct LegacyClass {
    char pad[0x715];
    unsigned char flag;
    void setFlag();
};

void LegacyClass::setFlag() {
    this->flag = 1;
}

