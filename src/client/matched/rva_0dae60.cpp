struct PairRecord {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;

    bool IsMatch() const;
};

bool PairRecord::IsMatch() const
{
    return a == c && b == d;
}
