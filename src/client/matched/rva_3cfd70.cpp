struct Legacy {
    char _pad[0x7b0];
    unsigned int field;
    void setField(unsigned int);
};

void Legacy::setField(unsigned int value) {
    this->field = value;
}

