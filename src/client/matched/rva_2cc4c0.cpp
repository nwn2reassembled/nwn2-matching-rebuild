struct B;

struct A {
    B* p;
    virtual void dummy() {}   // forces a vptr at offset 0
    int member();
};

int A::member() { return *(int*)((char*)p + 0x368); }

