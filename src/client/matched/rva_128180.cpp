class Legacy {
public:
    unsigned int ptr;
    short getWord() const;
};

short Legacy::getWord() const {
    return *(short*)((char*)ptr + 0x80);
}

