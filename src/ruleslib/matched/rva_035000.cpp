class Legacy {
public:
    static void __stdcall setByte(Legacy* obj, unsigned char val);
private:
    char pad[0x51];
    unsigned char byteAtOffset;
};

void Legacy::setByte(Legacy* obj, unsigned char val) { obj->byteAtOffset = val; }

