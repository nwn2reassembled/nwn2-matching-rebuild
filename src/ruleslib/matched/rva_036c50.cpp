class Legacy {
public:
    static void __stdcall setValue(unsigned int* ptr, unsigned short value);
};

void Legacy::setValue(unsigned int* ptr, unsigned short value) {
    *reinterpret_cast<unsigned short*>(reinterpret_cast<char*>(ptr)+12) = value;
}

