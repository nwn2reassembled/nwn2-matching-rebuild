struct Outer {
    unsigned int dummy;
    unsigned int* ptr;

    unsigned int getValue() const;
};

unsigned int Outer::getValue() const
{
    return *(unsigned int*)((char*)ptr + 0x160);
}

