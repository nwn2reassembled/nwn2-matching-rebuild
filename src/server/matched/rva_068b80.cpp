class Legacy {
public:
    void* get_ptr(int idx);
};

void* Legacy::get_ptr(int idx) {
    return reinterpret_cast<char*>(this) + 0x188 + idx * 12;
}
