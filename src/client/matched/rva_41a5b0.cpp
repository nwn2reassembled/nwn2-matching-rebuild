struct Legacy {
    void legacyFunction();
};

void Legacy::legacyFunction() {
    *reinterpret_cast<int*>((char*)this + 0xEC) = 0;
}

