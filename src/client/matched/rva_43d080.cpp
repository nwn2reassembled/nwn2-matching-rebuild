class Legacy {
public:
    void setField(int value);
private:
    char padding[0x9c];
    int field;
};

void Legacy::setField(int value) { field = value; }
