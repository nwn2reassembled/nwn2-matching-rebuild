struct Triple24 { unsigned int first, second, third; };
struct Table24 {
    unsigned char reserved[0x24];
    Triple24* data;
    unsigned int getAt(unsigned int index);
};
unsigned int Table24::getAt(unsigned int index) { return data[index].first; }
