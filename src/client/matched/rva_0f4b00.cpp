int __stdcall GetBlendMode(bool enable, bool flag)
{
    if (enable)
        return flag ? 3 : 1;
    else
        return flag ? 2 : 0;
}
