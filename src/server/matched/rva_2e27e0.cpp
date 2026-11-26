void CopyVectors(const unsigned int *src1, const unsigned int *src2)
{
    *(unsigned int *)0x0086FA20 = src1[0];
    *(unsigned int *)0x0086FA24 = src1[1];
    *(unsigned int *)0x0086FA28 = src1[2];

    *(unsigned int *)0x0084117C = src2[0];
    *(unsigned int *)0x00841180 = src2[1];
    *(unsigned int *)0x00841184 = src2[2];
}
