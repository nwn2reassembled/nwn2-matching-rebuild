class Legacy {
public:
    void setField(unsigned short val);
private:
    char pad[0x3d0];
    unsigned short field;
};

void Legacy::setField(unsigned short val) {
    field = val;
}

