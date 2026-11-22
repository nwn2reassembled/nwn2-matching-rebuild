struct Inner { /* unknown layout */ };

struct MyClass {
    void* _vptr;           // vtable pointer at offset 0
    Inner* inner;          // at offset 4
    int func() const;
};

int MyClass::func() const {
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(inner) + 0x64);
}

