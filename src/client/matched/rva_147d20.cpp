struct Chunk
{
    int field_0;
    int field_4;
    int field_8;
    int field_c;
    int field_10;
    int field_14;
    int field_18;
    int field_1c;
};

void Chunk_Clear(Chunk *c)
{
    c->field_18 = 0;
    c->field_14 = 0;
    c->field_1c = 0;
    c->field_c = 0;
    c->field_8 = 0;
    c->field_10 = 0;
}
