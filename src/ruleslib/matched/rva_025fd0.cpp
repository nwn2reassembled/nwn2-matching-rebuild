class Dummy {
public:
    unsigned int method(void* ptr) const;
};

unsigned int Dummy::method(void* ptr) const {
    return *reinterpret_cast<unsigned int*>(static_cast<char*>(ptr)+0x138);
}

