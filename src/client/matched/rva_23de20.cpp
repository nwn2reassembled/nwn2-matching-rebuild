struct Obj {
    char pad[0x108];
    void* field_108;
};

struct Inner {
    char pad[0xd4];
    void* field_d4;
};

void* __fastcall Obj_GetFieldD4(Obj* this_)
{
    Inner* p = static_cast<Inner*>(this_->field_108);
    if (p)
        return p->field_d4;
    return 0;
}
