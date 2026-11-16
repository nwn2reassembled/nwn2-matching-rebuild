
class Legacy {
public:
    unsigned char readByte(void* ptr);
};

unsigned char Legacy::readByte(void* ptr) {
    unsigned char* p = reinterpret_cast<unsigned char*>(ptr);
    return p[14];
}
