struct SomeClass {
    char pad[0x48];
    unsigned int state; // offset 0x48
};

int __fastcall SomeClass_probe(struct SomeClass* thisPtr) {
    unsigned int state = thisPtr->state;
    if (state == 3 || state == 4 || state == 5 || state == 9 || state == 6 || state == 2)
        return 1;
    return 0;
}
