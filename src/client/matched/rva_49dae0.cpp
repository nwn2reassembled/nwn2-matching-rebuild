class GlyphTable {
public:
    unsigned short GetGlyph(unsigned short index);

    unsigned int field_00;
    unsigned int field_04;
    unsigned int field_08;
    unsigned int field_0c;
    unsigned int field_10;
    unsigned int field_14;
    unsigned int field_18;
    unsigned int field_1c;
    unsigned int field_20;
    unsigned int field_24;
    unsigned int field_28; // unsigned short* table
    int field_2c;          // count
};

unsigned short GlyphTable::GetGlyph(unsigned short index)
{
    if ((int)index >= this->field_2c)
        return 0xFFFF;
    unsigned short* table = (unsigned short*)this->field_28;
    return table[index];
}
