struct Widget {
    unsigned char pad0x00[0x58];
    unsigned long state;

    int IsActive();
};

int Widget::IsActive() {
    unsigned long v = this->state;
    if (v == 1 || v == 3 || v == 0x0a || v == 7 || v == 5)
        return 1;
    return 0;
}
