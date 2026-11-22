struct MyClass {
    struct Elem {
        char pad1[0x38];
        int value;
        char pad2[0x14]; // pads total size to 0x50 (80 bytes)
    };
    virtual void dummy();
    Elem* elems; // stored at offset +4 because of vptr
    void setValue(int index, int val);
};

inline void MyClass::dummy() {}

void MyClass::setValue(int index, int val) {
    elems[index].value = val;
}

