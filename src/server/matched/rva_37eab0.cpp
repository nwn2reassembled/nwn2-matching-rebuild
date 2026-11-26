struct S {
    void* p;
    void set();
};

void S::set() {
    p = reinterpret_cast<void*>(0x8127dcu);
}
