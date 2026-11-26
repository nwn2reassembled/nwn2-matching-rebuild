class Legacy {
public:
    int getValue();
};

int Legacy::getValue() {
    int* p = *reinterpret_cast<int**>(reinterpret_cast<char*>(this)+4);
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(p)+0x100c0);
}
