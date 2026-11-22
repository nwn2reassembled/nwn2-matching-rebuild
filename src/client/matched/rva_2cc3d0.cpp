class A {
public:
    int foo() const;
};

int A::foo() const {
    // Load a 32‑bit pointer from *this + 0x04.
    const void* ptr = *(void**)((const char*)this + 4);
    // Return the 32‑bit value located at offset 0x2f0 of that pointed object.
    return *reinterpret_cast<const int*>((const char*)ptr + 0x2f0);
}

