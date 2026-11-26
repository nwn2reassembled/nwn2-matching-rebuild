class Legacy {
public:
    char* offset();
};

char* Legacy::offset() {
    return (char*)this - 0x730;
}
