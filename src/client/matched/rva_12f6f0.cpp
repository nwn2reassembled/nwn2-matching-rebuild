struct TextBuffer {
    char data[0x100];
    int length; // offset 0x100
};

int TextBuffer_AppendChar(TextBuffer* buf, unsigned int ch)
{
    int len = buf->length;
    if (len < 0xfe)
    {
        unsigned int idx = ch - 1;
        if (idx <= 0xfd)
        {
            buf->data[len] = (char)ch;
            ++buf->length;
            return 1;
        }
    }
    return 0;
}
