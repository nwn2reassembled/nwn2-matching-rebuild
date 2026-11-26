class TextBase {
public:
    unsigned long flags;
    unsigned long unk1;
    unsigned long unk2;
    unsigned long unk3;
};

class TextBuffer : public TextBase {
public:
    char* GetBuffer();

private:
    char storage[16];
    unsigned long pad;
    unsigned long size;
};

char* TextBuffer::GetBuffer() {
    if (size >= 0x10) {
        return *(char**)storage;
    }
    return (char*)storage;
}
