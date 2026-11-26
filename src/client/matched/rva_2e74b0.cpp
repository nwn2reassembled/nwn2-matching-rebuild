struct Target
{
    unsigned char pad[0x20];
    unsigned char flag;
};

class Container
{
public:
    unsigned char pad0[0x424];
    Target* target1;
    Target* target2;

    void ClearFlags();
};

void Container::ClearFlags()
{
    if (target1 != 0)
        target1->flag = 0;
    if (target2 != 0)
        target2->flag = 0;
}
