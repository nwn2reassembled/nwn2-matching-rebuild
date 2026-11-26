struct BlockCoord {
    unsigned a0;   // +0x00
    unsigned a1;   // +0x04
    unsigned a2;   // +0x08
    unsigned a3;   // +0x0C
    unsigned a4;   // +0x10
    unsigned id;   // +0x14
};

unsigned __fastcall pack_coord(int /*unused ecx arg*/, const BlockCoord *bc)
{
    unsigned c = bc->id;
    if (c > 0x7bcu)
        c -= 0x7bcu;
    else if (c > 0x50u)
        c -= 0x50u;

    unsigned ax = ((bc->a2 << 6) + bc->a1) << 5;
    ax += bc->a0 >> 1;

    unsigned cx = ((c << 4) + bc->a4 + 1) << 5;
    cx += bc->a3;

    return (cx << 16) | ax;
}
