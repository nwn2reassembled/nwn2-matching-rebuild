class Legacy {
public:
    void setField(void* ptr, unsigned short val);
};

void Legacy::setField(void* ptr, unsigned short val)
{
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(ptr) + 0x66) = val;
}

