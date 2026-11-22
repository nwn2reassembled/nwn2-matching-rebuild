class Legacy {
public:
    int getOffsetValue(void* data);
};

int Legacy::getOffsetValue(void* data) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(data)+0x200);
}

