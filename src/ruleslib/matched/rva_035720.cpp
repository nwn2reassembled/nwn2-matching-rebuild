struct Dummy {
    static void __stdcall setVal(Dummy* p, unsigned int val);
};

void Dummy::setVal(Dummy* p, unsigned int val) {
    *(unsigned int*)((char*)p + 0x160) = val;
}

