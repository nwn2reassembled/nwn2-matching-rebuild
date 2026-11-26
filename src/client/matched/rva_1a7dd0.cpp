struct SomeClass {
    void* field0;
    void* field4;
    int   field8;
    int   fieldC;
    int   field10;
    SomeClass(void* a, void* b);
};

SomeClass::SomeClass(void* a, void* b) {
    field8  = 0;
    fieldC  = 0;
    field10 = 0;
    field0  = a;
    field4  = b;
}
