class Data {
public:
    unsigned int pad1;
    unsigned int pad2;
    unsigned int low1;
    unsigned int high1;
    unsigned int low2;
    unsigned int high2;

    unsigned __int64 subtract() const;
};

unsigned __int64 Data::subtract() const {
    return *reinterpret_cast<const unsigned __int64*>((const char*)this + 8) -
           *reinterpret_cast<const unsigned __int64*>((const char*)this + 16);
}

