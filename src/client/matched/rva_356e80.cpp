struct MyClass {
    char pad[160];          // 0xA0 bytes of padding to reach offset 0xa0
    int value;              // stored at [ecx+0xa0]
    void setValue(int);     // declared here, defined out‑of‑line below
};

void MyClass::setValue(int v) {
    value = v;
}
