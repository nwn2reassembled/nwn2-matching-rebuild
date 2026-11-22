class Legacy {
public:
    short getValue(void* p);
};

short Legacy::getValue(void* p) {
    return *reinterpret_cast<short*>(reinterpret_cast<char*>(p)+0x66);
}
