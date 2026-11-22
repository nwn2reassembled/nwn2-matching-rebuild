struct B {
    char padding[0x44];
    unsigned short* array;
};

class A {
public:
    unsigned short get(B* p, int idx);
};

unsigned short A::get(B* p, int idx) {
    return *(p->array + idx);
}
