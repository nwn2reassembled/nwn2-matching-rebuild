class C {
public:
    unsigned char padding0[0x70];
    unsigned int field70;
    unsigned char padding1[0x1c];
    unsigned int field90;
    void clear(int unused);
};

void C::clear(int unused)
{
    field90 = 0;
    field70 = 0;
}
