class Legacy {
public:
    int pad0[90];
    int field1;
    int pad1;
    int field2;

    int sum();
};

int Legacy::sum() {
    return field1 + field2;
}

