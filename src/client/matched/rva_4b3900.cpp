struct Entity {
    unsigned char unknown_000[0x8c];
    int state;
    int IsSpecial();
};

int Entity::IsSpecial() {
    int value = state;
    if (value == 8 || value == 14)
        return 1;
    return 0;
}
