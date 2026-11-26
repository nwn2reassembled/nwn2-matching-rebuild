struct ServerSettings {
    unsigned char pad00[0x50];
    unsigned char field50;
    unsigned char field51;
    unsigned char field52;
    unsigned char field53;
    unsigned char field54;
    unsigned char field55;
    unsigned char field56;
    unsigned char field57;
    unsigned char field58;
    unsigned char pad59[0x2CB];
    unsigned short field324;

    int AllLimitsBelowTen();
};

int ServerSettings::AllLimitsBelowTen() {
    if (this->field58 >= 10)
        return 1;
    if (this->field324 != 0)
        return 0;
    if (this->field50 < 10)
        return 1;
    if (this->field51 < 10)
        return 1;
    if (this->field52 < 10)
        return 1;
    if (this->field53 < 10)
        return 1;
    if (this->field54 < 10)
        return 1;
    if (this->field55 < 10)
        return 1;
    if (this->field56 < 10)
        return 1;
    return this->field57 < 10;
}
