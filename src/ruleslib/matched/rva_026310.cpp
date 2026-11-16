class Legacy {
public:
    int placeholder;
    static unsigned int __stdcall getValue(void* obj);
};

unsigned int Legacy::getValue(void* obj) {
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(obj)+0x194);
}

