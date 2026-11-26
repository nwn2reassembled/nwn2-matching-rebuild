struct MyStruct
{
    char pad[4];
    unsigned int *ptr;
    unsigned short GetWord();
};

unsigned short MyStruct::GetWord()
{
    return *(unsigned short*)((char*)ptr + 0x10018);
}

