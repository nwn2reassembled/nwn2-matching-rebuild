struct Block {
    char bytes[32];
};

class Holder {
public:
    char before[0x38d];
    Block block;
    void* CopyTo(void* destination) const;
};

void* Holder::CopyTo(void* destination) const {
    *static_cast<Block*>(destination) = block;
    return destination;
}
