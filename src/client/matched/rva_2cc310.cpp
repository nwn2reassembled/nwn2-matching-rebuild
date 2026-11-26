struct Target {
    char unused[0x398];
    int value;
};

struct Owner {
    int unused;
    Target* target;
    void SetValue(int value);
};

void Owner::SetValue(int value) {
    target->value = value;
}
