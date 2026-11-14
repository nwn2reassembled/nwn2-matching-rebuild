struct Target {
    char pad[12];
    unsigned char flagByte : 1;
    unsigned char otherBits : 7;
    static void __stdcall setFlag(Target* other, int flag);
};

void __stdcall Target::setFlag(Target* other, int flag) {
    other->flagByte = flag != 0;
}
