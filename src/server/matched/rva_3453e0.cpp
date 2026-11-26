struct CState
{
    unsigned int m0;
    unsigned int m1;
    unsigned int m2;
    unsigned int m3;
    unsigned int m4;
    unsigned int m5;
    unsigned int m6;
    unsigned int m7;
    unsigned int m8;
    unsigned int m9;
    unsigned int m10;

    CState* Init();
};

CState* CState::Init()
{
    m1 = 0;
    m2 = 0;
    m3 = 0;
    m4 = 0;
    m5 = 0;
    m6 = 0;
    m7 = 0;
    m8 = 0;
    m9 = 0;
    m10 = 0;
    m0 = 0x80fe84u;
    return this;
}
