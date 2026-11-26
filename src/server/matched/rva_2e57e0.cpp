typedef unsigned int uint;

class ServerStateBlock
{
public:
    void ClearCounters();

private:
    char pad00[8];
    uint w08[2];
    char pad10[4];
    uint w14[9];
    char pad38[12];
    uint w44[2];
    char pad4c[4];
    uint w50[9];
    char pad74[20];
    uint w88[11];
    char pab4[16];
    uint wc4[3];
    uint wd0[8];
    char paf0[4];
    uint wf4[2];
    char pafc[8];
    uint w104[2];
    char pad10c[8];
    uint w114[2];
    char pad11c[252];
};

void ServerStateBlock::ClearCounters()
{
    w114[0] = 0;
    w114[1] = 0;
    w104[0] = 0;
    w104[1] = 0;
    wf4[0] = 0;
    wf4[1] = 0;
    wc4[0] = 0;
    wc4[1] = 0;
    wc4[2] = 0;
    wd0[2] = 0;
    wd0[3] = 0;
    wd0[4] = 0;
    wd0[5] = 0;
    wd0[0] = 0;
    wd0[1] = 0;
    wd0[6] = 0;
    wd0[7] = 0;
    w88[0] = 0;
    w88[1] = 0;
    w88[2] = 0;
    w88[5] = 0;
    w88[6] = 0;
    w88[7] = 0;
    w88[8] = 0;
    w88[3] = 0;
    w88[4] = 0;
    w88[9] = 0;
    w88[10] = 0;
    w50[0] = 0;
    w50[1] = 0;
    w50[2] = 0;
    w50[3] = 0;
    w50[4] = 0;
    w50[5] = 0;
    w50[6] = 0;
    w50[7] = 0;
    w50[8] = 0;
    w44[0] = 0;
    w44[1] = 0;
    w14[0] = 0;
    w14[1] = 0;
    w14[2] = 0;
    w14[3] = 0;
    w14[4] = 0;
    w14[5] = 0;
    w14[6] = 0;
    w14[7] = 0;
    w14[8] = 0;
    w08[0] = 0;
    w08[1] = 0;
}
