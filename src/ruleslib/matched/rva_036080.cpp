struct Legacy { bool compare(int, unsigned char); };
bool Legacy::compare(int, unsigned char value) { return value <= 0x28; }
