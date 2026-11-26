class CThing {
public:
    void SetByteAt(int index, unsigned char value);
private:
    unsigned char data[0xe7];
};

void CThing::SetByteAt(int index, unsigned char value) {
    if ((unsigned int)index <= 6) {
        data[0xe3 + index] = value;
    }
}
