struct Legacy {
    // 0x190 (400) bytes of padding before the counter
    char pad[0x190];
    int count;            // offset 0x190
    int array[128];       // starts at offset 0x194

    int add(int value);
};

int Legacy::add(int value)
{
    int idx = count;
    array[idx] = value;
    ++count;
    return count < 0x80 ? 1 : 0;   // returns 1 if still less than 128 after increment, else 0
}

