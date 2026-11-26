void __fastcall ClearFields(void *self) {
    unsigned long *p = reinterpret_cast<unsigned long *>(self);
    p[0x0E] = 0;
    p[0x0C] = 0;
    p[0x0B] = 0;
    p[0x0F] = 0;
    p[0x03] = 0;
    p[0x04] = 0;
    p[0x06] = 0;
    p[0x07] = 0;
    p[0x08] = 0;
    p[0x09] = 0;
    p[0x05] = 0;
    p[0x0D] = 0;
    p[0x0A] = 0;
    p[0x12] = 0;
}
