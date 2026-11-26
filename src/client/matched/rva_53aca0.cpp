void AdjustValue(unsigned int* out, const unsigned char* stats, unsigned int amount) {
    unsigned int scaled = *(const unsigned int*)(stats + 0x112) * amount;
    *out -= scaled / *(const unsigned int*)(stats + 0x116);
}
