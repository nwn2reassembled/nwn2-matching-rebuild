class Legacy {
public:
    int readValue(int* ptr);
};

int Legacy::readValue(int* ptr)
{
    return *reinterpret_cast<int*>(reinterpret_cast<char*>(ptr) + 0x1f8);
}

