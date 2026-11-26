struct ParticleSystemDesc {
    int field_00;
    int field_04;
    int field_08;
    int pad_0c[2];
    int field_14;
    int field_18;
    int pad_1c[1];
    int field_20;
};

ParticleSystemDesc *InitParticleSystemDesc(ParticleSystemDesc *desc, int a2, int a3)
{
    desc->field_00 = a2;
    desc->field_04 = a3;
    desc->field_08 = 0;
    desc->field_20 = 0;
    desc->field_14 = 0;
    desc->field_18 = 0;
    return desc;
}
