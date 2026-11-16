struct Legacy {
    static int __stdcall getValue(void*);
};

int __stdcall Legacy::getValue(void* ptr) {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr)+0x71c);
}

