class Legacy {
public:
    int getValue();
};

int Legacy::getValue() {
    int* ptr = *reinterpret_cast<int**>(reinterpret_cast<char*>(this) + 4);
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0x100bc);
}

