struct ObjectWithFields
{
    unsigned char before0[0x2eb0];
    int valueAt2eb0;
    unsigned char between[0x8];
    int valueAt2ebc;

    int ResetTwoFields();
};

int ObjectWithFields::ResetTwoFields()
{
    valueAt2eb0 = 0;
    valueAt2ebc = 0;
    return 0;
}
