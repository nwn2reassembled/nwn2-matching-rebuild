class Rules {
public:
    unsigned* __stdcall GetEntry(int index);

private:
    unsigned char pad[0x294];
    int count;       // +0x294
    unsigned* entries; // +0x298
};

unsigned* __stdcall Rules::GetEntry(int index) {
    if (index >= 0 && index < count)
        return entries + index * 5;
    return 0;
}
