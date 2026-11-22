class C {
public:
    int x;
    short getValue(void* p);
};

short C::getValue(void* p) {
    return *reinterpret_cast<short*>( reinterpret_cast<char*>(p) + 0x64 );
}
