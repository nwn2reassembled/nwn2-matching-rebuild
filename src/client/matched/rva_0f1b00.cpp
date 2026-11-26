struct Object {
    unsigned int pad[153]; // 0x0..0x263
    unsigned int flags;    // offset 0x264
};

bool __fastcall CheckObjectState(const Object *obj)
{
    unsigned int v = obj->flags;
    if ((v & 0x1c00) == 0x800) {
        if ((v & 0x3e0) == 0x20)
            return true;
    }
    return false;
}
