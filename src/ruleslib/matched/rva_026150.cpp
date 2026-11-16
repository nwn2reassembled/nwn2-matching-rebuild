class Legacy {
public:
    int getFieldFromParam(const void* ptr) const;
};

int Legacy::getFieldFromParam(const void* ptr) const {
    return *reinterpret_cast<const int*>(reinterpret_cast<const char*>(ptr)+0x160);
}

