class Legacy {
public:
    unsigned int getField(void* p);
};

unsigned int Legacy::getField(void* p) {
    return *reinterpret_cast<unsigned int*>(static_cast<char*>(p)+0x28);
}

