struct SomeStruct {
    char pad[12];
    bool active;
};

SomeStruct* ToggleActive(SomeStruct* p) {
    p->active = !p->active;
    return p;
}
