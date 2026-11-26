class Obj {
public:
    char pad1_[10];
    unsigned short kind_;
    char pad2_[4];
    void* handle_;

    int IsSpecial();
};

int Obj::IsSpecial() {
    if (kind_ == 0x10 || kind_ == 0x11)
        return 1;
    return handle_ != 0;
}
