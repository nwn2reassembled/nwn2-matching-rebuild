struct Outer {
    unsigned int dummy;
    void* ptr;
    unsigned int func();
};

unsigned int Outer::func() {
    return *reinterpret_cast<unsigned int*>( reinterpret_cast<char*>(ptr) + 0x390 );
}

