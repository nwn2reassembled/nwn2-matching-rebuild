class Legacy {
public:
    int Init();
private:
    volatile char pad0[12];          // offset 0x00-0x0B
    volatile short fieldC;           // offset 0x0C-0x0D
    volatile char pad1[2];           // offset 0x0E-0x0F
    volatile int   field10;          // offset 0x10-0x13
    volatile int   field14;          // offset 0x14-0x17
    volatile int   field18;          // offset 0x18-0x1B
    volatile int   field1C;          // offset 0x1C-0x1F
    volatile int   field20;          // offset 0x20-0x23
    volatile int   field24;          // offset 0x24-0x27
    volatile int   field28;          // offset 0x28-0x2B
    volatile char  pad2[4];          // padding to shift offsets
    volatile int   field30;          // offset 0x30-0x33
    volatile int   field34;          // offset 0x34-0x37
};

int Legacy::Init() {
    this->field14 = 0;
    this->field18 = 0;
    this->fieldC  = 0;   // short zero, generates WORD store
    this->field10 = 0;
    this->field1C = 0;
    this->field20 = 0;
    this->field24 = 0;
    this->field28 = 0;
    this->field30 = 0;
    this->field34 = 0;
    return 1;
}

