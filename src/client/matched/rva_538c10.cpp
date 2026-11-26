struct Widget {
    char pad0[0x10];
};

Widget* ResetWidget(Widget* w)
{
    *(char*)((char*)w + 0x10) = 0;
    *(unsigned int*)((char*)w + 0x11) = 0;
    *(unsigned int*)((char*)w + 0x31) = 0;
    *(unsigned int*)((char*)w + 0x35) = 0;
    *(unsigned int*)((char*)w + 0x2d) = 0;
    return 0;
}
