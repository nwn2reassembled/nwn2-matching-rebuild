struct Legacy {
    char pad[0x164];
    int flag;
    void setFlag();
};

void Legacy::setFlag() { flag = 1; }

