struct Widget {
    unsigned char pad0[0x1c];
    void* items;      /* +0x1c */
    unsigned char pad1[4];
    int count;        /* +0x24 */
};

void* __stdcall Widget_GetItem(Widget* self, int index)
{
    if (index < self->count)
        return &((char*)self->items)[index * 20];
    return 0;
}
