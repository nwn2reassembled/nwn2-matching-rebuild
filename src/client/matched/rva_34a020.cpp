struct Legacy {
    char padding[0x8e8];
    int field;
    void setField();
};

void Legacy::setField() { this->field = 0x200; }
