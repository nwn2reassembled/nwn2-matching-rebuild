class MyStruct {
public:
    // Returns the address of a member located at offset 0x310 from this.
    const void* getField() const;
};

const void* MyStruct::getField() const {
    return reinterpret_cast<const void*>(reinterpret_cast<const char*>(this) + 0x310);
}

