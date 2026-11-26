struct Legacy {
    int dummy;
    int CheckAllZero() const;
};

int Legacy::CheckAllZero() const
{
    const unsigned char* base = reinterpret_cast<const unsigned char*>(this);
    int sum = *reinterpret_cast<const int*>(base + 0x1160);
    sum += *reinterpret_cast<const int*>(base + 0x1154);
    sum += *reinterpret_cast<const int*>(base + 0x1148);
    sum += *reinterpret_cast<const int*>(base + 0x113c);
    sum += *reinterpret_cast<const int*>(base + 0x1130);
    sum += *reinterpret_cast<const int*>(base + 0x1124);
    sum += *reinterpret_cast<const int*>(base + 0x1118);
    sum += *reinterpret_cast<const int*>(base + 0x110c);
    sum += *reinterpret_cast<const int*>(base + 0x1100);
    sum += *reinterpret_cast<const int*>(base + 0x10f4);
    sum += *reinterpret_cast<const int*>(base + 0x10e8);
    sum += *reinterpret_cast<const int*>(base + 0x10dc);
    sum += *reinterpret_cast<const int*>(base + 0x10d0);
    sum += *reinterpret_cast<const int*>(base + 0x10c4);
    sum += *reinterpret_cast<const int*>(base + 0x10b8);
    sum += *reinterpret_cast<const int*>(base + 0x10ac);
    sum += *reinterpret_cast<const int*>(base + 0x10a0);
    sum += *reinterpret_cast<const int*>(base + 0x1094);
    sum += *reinterpret_cast<const int*>(base + 0x1088);
    sum += *reinterpret_cast<const int*>(base + 0x1004);
    return (sum == 0) ? 0 : 1;
}

