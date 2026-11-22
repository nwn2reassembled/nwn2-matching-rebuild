struct Legacy {
    int getField();
};

int Legacy::getField() { return *reinterpret_cast<int*>(reinterpret_cast<char*>(this)+0x4BC); }
