class Legacy {
public:
    void setField(unsigned int value);
private:
    char padding[24];
    unsigned int field;
};

void Legacy::setField(unsigned int value) { this->field = value; }
