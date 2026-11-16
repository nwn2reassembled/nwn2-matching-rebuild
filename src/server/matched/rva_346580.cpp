class Legacy {
public:
    int init();
private:
    char pad[0x38];
    int field1;
    int field2;
    int field3;
};

int Legacy::init() {
    this->field1 = 0;
    this->field2 = 0;
    this->field3 = 0;
    return 1;
}

