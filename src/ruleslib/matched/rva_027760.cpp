class Legacy {
public:
    int getValue(int* ptr);
};

int Legacy::getValue(int* ptr) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr)+0x330);
}
