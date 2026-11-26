class CZero {
public:
    unsigned int m0;
    unsigned int m1;
    unsigned int m2;
    unsigned int m3;

    CZero* Clear();
};

CZero* CZero::Clear()
{
    m0 = 0;
    m1 = 0;
    m2 = 0;
    m3 = 0;
    return this;
}
