void ApplyResourceDelta(int* total, const unsigned char* res, int count)
{
    *total += (int)((*(const unsigned int*)(res + 0x112) * (unsigned int)count)
                    / (*(const unsigned int*)(res + 0x116)));
}
