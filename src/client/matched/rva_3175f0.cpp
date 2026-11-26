class CStringTable {
public:
    unsigned short length;
    unsigned char pad[14];
    unsigned char* data;

    unsigned char Get(unsigned short index);
};

unsigned char CStringTable::Get(unsigned short index) {
    if (index >= length) {
        return 0;
    }
    return data[index];
}
