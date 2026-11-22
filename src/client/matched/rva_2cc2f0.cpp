struct B {
    char pad[0x340];
    unsigned int val;
};

struct Outer {
    int dummy;      // offset 0, ensures pB starts at offset 4
    B* pB;          // pointer stored at [ecx+0x4]
    unsigned int getVal() const;
};

unsigned int Outer::getVal() const { return pB->val; }

