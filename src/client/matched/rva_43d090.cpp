class Legacy {
public:
    void setValue(int val);
private:
    char padding[0x44];
    int field;
};

void Legacy::setValue(int val) {
    field = val;
}

