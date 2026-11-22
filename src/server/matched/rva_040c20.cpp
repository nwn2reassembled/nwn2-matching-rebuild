struct MyClass {
    void* getField58() const;
};

void* MyClass::getField58() const {
    return const_cast<char*>(reinterpret_cast<const char*>(this) + 0x58);
}

