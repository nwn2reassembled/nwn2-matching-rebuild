struct LegacyClass {
    void setValue(unsigned int);
};

void LegacyClass::setValue(unsigned int v) {
    *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(this)+0x7ac48) = v;
}
