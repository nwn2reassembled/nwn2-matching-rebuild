class Dummy {
public:
    void zeroField(Dummy* p);
};

void Dummy::zeroField(Dummy* p)
{
    *(int*)((char*)p + 0x4c) = 0;
}

