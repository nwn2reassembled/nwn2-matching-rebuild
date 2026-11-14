class Dummy {
public:
    char padding[0x78];
    int field;
    static int __stdcall GetField(Dummy* p);
};

int Dummy::GetField(Dummy* p) { return p->field; }
