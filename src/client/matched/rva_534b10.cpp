unsigned __int64 ReverseBytes64(const unsigned char *src)
{
    unsigned char tmp[8];
    tmp[0] = src[7];
    tmp[1] = src[6];
    tmp[2] = src[5];
    tmp[3] = src[4];
    tmp[4] = src[3];
    tmp[5] = src[2];
    tmp[6] = src[1];
    tmp[7] = src[0];
    return *reinterpret_cast<const unsigned __int64 *>(tmp);
}
