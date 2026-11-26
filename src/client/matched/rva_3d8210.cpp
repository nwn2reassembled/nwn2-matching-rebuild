class Thing {
public:
    int hasSomething();
    int  pad0;
    int* field04;
    char pad[48];
    int  field38;
};

int Thing::hasSomething() {
    if (field04 == 0)
        return 0;
    if (field38 == 0)
        field38 = 1;
    return 1;
}
