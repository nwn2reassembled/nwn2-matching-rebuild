class Dummy {
public:
    void setField(Dummy* pObj, unsigned char value);
};

void Dummy::setField(Dummy* pObj, unsigned char value) {
    char* base = reinterpret_cast<char*>(pObj);
    base[0xAC] = static_cast<char>(value);
}
