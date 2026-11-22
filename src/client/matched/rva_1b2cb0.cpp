struct Legacy {
    void setField(unsigned short);
private:
    char pad[0x4BA];
    unsigned short field;
};

void Legacy::setField(unsigned short val) { field = val; }
