class Legacy {
public:
    void setZero();
private:
    char padding[0x164];
    int value;
};

void Legacy::setZero() { value = 0; }

