struct Legacy {
    char pad[0x6c];
    unsigned long value;
    void setValue(unsigned long);
};

void Legacy::setValue(unsigned long param) { value = param; }
