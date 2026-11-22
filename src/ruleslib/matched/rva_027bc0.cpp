struct Bar {
    static int __stdcall getField(void* p);
};

int Bar::getField(void* p) {
    return *reinterpret_cast<int*>( reinterpret_cast<char*>(p) + 0x2fc );
}
