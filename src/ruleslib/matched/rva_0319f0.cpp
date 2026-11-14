struct SomeStruct;

class Legacy {
public:
    char readByte(SomeStruct* p);
};

char Legacy::readByte(SomeStruct* p) {
    return *reinterpret_cast<const unsigned char*>(reinterpret_cast<char*>(p)+0x62b);
}

