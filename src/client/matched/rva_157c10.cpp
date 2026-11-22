class Legacy {
public:
    int setByte(int value);
private:
    char pad[0xA80];
    unsigned char byteField;
};

int Legacy::setByte(int value) {
    this->byteField = static_cast<unsigned char>(value);
    return 1;
}

