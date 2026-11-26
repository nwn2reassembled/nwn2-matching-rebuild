struct Item {
    char reserved0[0x70];
    int value;
    char reserved1[0x1c];
    int initialized;

    void Initialize(int newValue);
};

void Item::Initialize(int newValue) {
    if (initialized == 0) {
        value = newValue;
        initialized = 1;
    }
}
