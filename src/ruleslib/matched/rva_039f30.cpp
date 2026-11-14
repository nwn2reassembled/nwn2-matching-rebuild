class Legacy {
public:
    void reset();
};

void Legacy::reset() { *reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x164) = 0; }
