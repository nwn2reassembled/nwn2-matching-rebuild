class Legacy {
public:
    unsigned int GetField(unsigned int* p);
};

unsigned int Legacy::GetField(unsigned int* p)
{
    return p[145];
}
