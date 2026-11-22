class Legacy {
public:
    int getValue(int idx);
};

int Legacy::getValue(int idx) {
    return *reinterpret_cast<int*>( reinterpret_cast<char*>(this)+0xa04 + idx*sizeof(int));
}

