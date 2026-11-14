struct Legacy {
    static int __stdcall getField(void*);
};

int Legacy::getField(void* param) {
    return static_cast<int>(*reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(param) + 0x14));
}
