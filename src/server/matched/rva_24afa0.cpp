class Session {
public:
    unsigned int GetFlags();

private:
    unsigned char pad_[0x4B4];
    unsigned int flags_;
};

unsigned int Session::GetFlags() {
    return flags_;
}
