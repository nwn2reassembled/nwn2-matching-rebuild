struct Buffer10 {
    char reserved[0x88];
    unsigned char values[10];

    unsigned char* Decrement(unsigned char index);
};

unsigned char* Buffer10::Decrement(unsigned char index)
{
    if (index < 10) {
        --values[index];
        return &values[index];
    }
}
