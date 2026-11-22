struct Legacy {
    char pad[0x214];
    unsigned int field_214;
    unsigned int field_218;
    unsigned int field_21c;
    unsigned int field_220;
    unsigned int field_224;
    unsigned int field_228;
    unsigned int field_22c;
    unsigned int field_230;
    unsigned int field_234;
    unsigned int field_238;
    unsigned int field_23c;

    void reset();
};

void Legacy::reset()
{
    field_218 = 0;
    field_21c = 0;
    field_220 = 0;
    field_224 = 0;
    field_228 = 0;
    field_22c = 0;
    field_230 = 0;
    field_234 = 0;
    field_238 = 0;
    field_23c = 0;
    field_214 = 1;
}

