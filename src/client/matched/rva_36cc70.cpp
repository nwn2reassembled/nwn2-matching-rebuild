struct Obj {
    unsigned int v00;
    unsigned int v04;
    unsigned int v08;
    unsigned int v0c;
    unsigned int v10;
    unsigned int v14;
    unsigned int v18;
    unsigned int v1c;
    unsigned int v20;
    unsigned int v24;
    unsigned int v28;
    unsigned int v2c;
    unsigned int v30;
    unsigned int v34;
    unsigned int v38;
    unsigned int v3c;
    unsigned int v40;
    unsigned int v44;
    unsigned int v48;
    unsigned int v4c;
    unsigned int v50;
    unsigned int v54;
    unsigned char b58;
    unsigned int v5c;

    Obj* Clear();
};

Obj* Obj::Clear()
{
    v00 = 0;
    v04 = 0;
    v08 = 0;
    v0c = 0;
    v10 = 0;
    v14 = 0;
    v18 = 0;
    v1c = 0;
    v20 = 0;
    v24 = 0;
    v28 = 0;
    v2c = 0;
    v30 = 0;
    v34 = 0;
    v38 = 0;
    v3c = 0;
    v40 = 0;
    v44 = 0;
    v48 = 0;
    v4c = 0;
    v50 = 0;
    v54 = 0;
    b58 = 0;
    v5c = 0;
    return this;
}
