struct Child {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct Owner {
    unsigned char pad[0x22C];
    Child* child;
};

void __cdecl ClearChildField(Owner* self)
{
    Child* child = self->child;
    if (child != 0) {
        child->field_C = 0;
    }
}
