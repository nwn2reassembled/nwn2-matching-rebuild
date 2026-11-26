class ServerInfoBlock
{
public:
    ServerInfoBlock();

    float value[80];
    int countA;
    int countB;
    int countC;
};

ServerInfoBlock::ServerInfoBlock()
{
    value[79] = value[78] = value[77] = value[76] = value[75] =
    value[74] = value[73] = value[72] = value[71] = value[70] =
    value[69] = value[68] = value[67] = value[66] = value[65] =
    value[64] = value[63] = value[62] = value[61] = value[60] =
    value[59] = value[58] = value[57] = value[56] = value[55] =
    value[54] = value[53] = value[52] = value[51] = value[50] =
    value[49] = value[48] = value[47] = value[46] = value[45] =
    value[44] = value[43] = value[42] = value[41] = value[40] =
    value[39] = value[38] = value[37] = value[36] = value[35] =
    value[34] = value[33] = value[32] = value[31] = value[30] =
    value[29] = value[28] = value[27] = value[26] = value[25] =
    value[24] = value[23] = value[22] = value[21] = value[20] =
    value[19] = value[18] = value[17] = value[16] = value[15] =
    value[14] = value[13] = value[12] = value[11] = value[10] =
    value[9] = value[8] = value[7] = value[6] = value[5] =
    value[4] = value[3] = value[2] = value[1] = value[0] = 0.0f;

    countA = countB = countC = 0;
}
