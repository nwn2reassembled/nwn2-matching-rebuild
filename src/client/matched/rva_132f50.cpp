struct Widget {
    unsigned int pad0;
    unsigned int pad1;
    unsigned int pad2;
    unsigned int pad3;
    unsigned int field10;
};

void SetField10(Widget* w, unsigned int value) {
    unsigned int tmp = value;
    w->field10 = tmp;
}
