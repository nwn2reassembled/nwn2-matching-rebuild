class Legacy {
public:
    virtual ~Legacy() {}
    unsigned char getByte() const;
private:
    unsigned char* ptr;
};

unsigned char Legacy::getByte() const {
    return *(ptr + 0x1018c);
}

