struct Legacy {
    int field0;
    int field4;
    unsigned char byte8;
    // implicit padding to align next int
    int fieldc;
    char pad1[52];
    int field44;
    void init();
};

void Legacy::init() {
    this->field0 = -1;
    this->field4 = -1;
    this->byte8 = 0xff;
    this->fieldc = -1;
    this->field44 = 0;
}

