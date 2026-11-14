class Legacy {
public:
    int compute(unsigned char val);
private:
    unsigned char _pad1[0x159];
    unsigned char threshold;
    unsigned char _pad2[14];
    int baseValue;
};

int Legacy::compute(unsigned char val) {
    if (val < this->threshold)
        return ((int)val * 0x630) + this->baseValue;
    else
        return 0;
}

