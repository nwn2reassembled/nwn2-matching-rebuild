struct LegacyFuncHolder {
    int legacyMethod(const void *arg) const;
};

int LegacyFuncHolder::legacyMethod(const void *arg) const {
    // The assembly loads the first argument from the stack, then reads an int
    // at offset 0x1a4 of that argument and returns it.
    return *reinterpret_cast<const int*>(reinterpret_cast<const char*>(arg)+0x1a4);
}
