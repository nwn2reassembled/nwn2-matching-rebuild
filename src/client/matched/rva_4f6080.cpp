class Legacy {
public:
    void setFlag();
};

void Legacy::setFlag() {
    *reinterpret_cast<unsigned char*>(reinterpret_cast<char*>(this) + 0x714) = 1;
}
