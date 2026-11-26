struct Widget {
    char pad_00[0x1c];
    unsigned int base;
    char pad_20[0x0c];
    unsigned int extra;
};

unsigned int __stdcall GetTotal(Widget *self, int flag)
{
    if (flag != 0)
        return self->extra + self->base;
    return self->base;
}
