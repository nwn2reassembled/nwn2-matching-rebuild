class C{
public:
    unsigned char f(const void* base,unsigned char off);
};
unsigned char C::f(const void* base,unsigned char off){
    return *reinterpret_cast<const unsigned char*>(
        reinterpret_cast<unsigned int>(base)+0x23b+off );
}

