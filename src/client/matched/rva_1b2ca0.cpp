class Legacy {
public:
    unsigned short getField() const;
private:
    char padding[0x4ba];
    unsigned short field_;
};

unsigned short Legacy::getField() const {
    return field_;
}

