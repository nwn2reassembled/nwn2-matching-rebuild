struct Cursor {
    int head;
    int tail;
    int count;
    int flags;
    int limit;
    int spare;
    Cursor(int headValue, int tailValue);
};

Cursor::Cursor(int headValue, int tailValue)
{
    head = headValue;
    tail = tailValue;
    count = 0;
    flags = 0;
    limit = 0;
    spare = 0;
}
