class Legacy {
public:
    unsigned int getField() const;
private:
    char pad[0x310];
    unsigned int fieldAtOffset;
};

unsigned int Legacy::getField() const {
    return fieldAtOffset;
}
