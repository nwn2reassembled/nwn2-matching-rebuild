void InitOnce(void)
{
    unsigned char one = 1;
    unsigned int zero = 0;

    if (*(unsigned char *)0x00874423 != one)
    {
        *(unsigned int *)0x00874414 = zero;
        *(unsigned int *)0x00874418 = 0x0085F168u;
        *(unsigned int *)0x0087441C = 0x00015180u;
        *(unsigned char *)0x00874420 = (unsigned char)zero;
        *(unsigned char *)0x00874423 = one;
    }
}
