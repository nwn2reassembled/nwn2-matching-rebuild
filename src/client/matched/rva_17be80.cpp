struct Widget {
    char pad[0x80];
    int field80;   // offset 0x80
    int field84;   // offset 0x84

    int GetActiveValue();
};

int Widget::GetActiveValue() {
    if (field84 != 0)
        return 0;
    return field80;
}
