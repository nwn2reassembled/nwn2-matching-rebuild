struct MyStruct {
    unsigned int GetValue() const;
private:
    unsigned int dummy;          // offset 0
    unsigned int *ptrField;      // offset 4
};

unsigned int MyStruct::GetValue() const {
    return *reinterpret_cast<const unsigned int*>(
        reinterpret_cast<const char*>(ptrField) + 0x100b8);
}

