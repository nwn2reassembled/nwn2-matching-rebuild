class Legacy {
public:
    unsigned long getValue();
private:
    char padding[0x204];
    unsigned long value;
};

unsigned long Legacy::getValue() { return value; }
