class Legacy {
    // Padding to align the target byte at offset 0x218
    char _pad[0x218];
public:
    unsigned char field;          // The byte at [ecx+0x218]
    void update(unsigned char a, unsigned char b);
};

void Legacy::update(unsigned char a, unsigned char b) {
    unsigned char temp = ((b & 1u) << 1) | (a & 1u); // LSB of args combined
    unsigned char cur = this->field;                 // Load existing byte
    temp <<= 2;                                      // Multiply by 4
    cur &= 0xF3u;                                     // Mask bits 1 and 2
    temp |= cur;                                     // Combine results
    this->field = temp;                              // Store back to [ecx+0x218]
}

