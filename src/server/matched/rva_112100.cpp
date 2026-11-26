struct Legacy {
    char pad[0x164];
    unsigned long flag;
    void setFlag();
};

void Legacy::setFlag() {
    this->flag = 1;
}

