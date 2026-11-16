class Legacy {
public:
    unsigned int getField(void* obj);
};

unsigned int Legacy::getField(void* obj) {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(obj)+0x1d0);
}

