struct DataHeader {
    unsigned char pad_00[0x0c];
    unsigned int dataCount;      // +0x0c
    unsigned char pad_10[0x04];
    unsigned int nameCount;      // +0x14
    unsigned char pad_18[0x04];
    unsigned int recordCount;    // +0x1c (array of 16-byte records)
    unsigned char pad_20[0x04];
    unsigned int extraCount;     // +0x24
    unsigned char pad_28[0x04];
    unsigned int miscCount;      // +0x2c
    unsigned char pad_30[0x04];
    unsigned int tailCount;      // +0x34
};

class Object {
public:
    unsigned int ComputeSize();

private:
    unsigned char pad_00[0x50];
    DataHeader* header;          // +0x50
};

unsigned int Object::ComputeSize() {
    if (header == 0) {
        return 0;
    }
    unsigned int size = (header->dataCount + header->nameCount) * 3 * 4;
    size += header->recordCount * 16;
    size += header->tailCount;
    size += header->extraCount;
    size += header->miscCount;
    return size + 0x38;
}
