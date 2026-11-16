
class Legacy {
public:
    unsigned int getValue(void* ptr) const;
};

unsigned int Legacy::getValue(void* ptr) const
{
    return *reinterpret_cast<unsigned int*>(reinterpret_cast<char*>(ptr)+0x12c);
}

