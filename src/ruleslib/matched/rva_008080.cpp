
class MyClass {
public:
    unsigned char pad[0x88];          // padding to reach offset 0x88
    unsigned char counters[10];       // byte array indexed by the argument
    void incrementCounter(unsigned char idx);
};

void MyClass::incrementCounter(unsigned char idx) {
    if (idx < sizeof(counters))      // guard against out‑of‑range index
        ++counters[idx];            // equivalent to the assembly add/lea sequence
}

