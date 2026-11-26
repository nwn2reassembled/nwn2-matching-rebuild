struct Widget {
    unsigned char flags;
    unsigned char pad0[51];
    unsigned int activeValue;
    unsigned char pad1[51];
    unsigned int idleValue;
};

unsigned int __fastcall Widget_getValue(Widget *ecxThis) {
    if (ecxThis->flags != 0)
        return ecxThis->activeValue;
    return ecxThis->idleValue;
}
