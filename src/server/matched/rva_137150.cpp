typedef unsigned char Byte;

int ResetFlags17(void* gate, void* obj)
{
    if (*(unsigned*)((Byte*)gate + 0xAC8) != 0)
    {
        Byte* base = (Byte*)obj;
        *(unsigned*)(base + 0x68) = 0;
        *(unsigned*)(base + 0x6C) = 0;
        *(unsigned*)(base + 0x70) = 0;
        *(unsigned*)(base + 0x74) = 0;
        *(unsigned*)(base + 0x78) = 0;
        *(unsigned*)(base + 0x7C) = 0;
        *(unsigned*)(base + 0x80) = 0;
        *(unsigned*)(base + 0x84) = 0;
        *(unsigned*)(base + 0x88) = 0;
        *(unsigned*)(base + 0x8C) = 0;
        *(unsigned*)(base + 0x90) = 0;
        *(unsigned*)(base + 0x94) = 0;
        *(unsigned*)(base + 0x98) = 0;
        *(unsigned*)(base + 0x9C) = 0;
        *(unsigned*)(base + 0xA0) = 0;
        *(unsigned*)(base + 0xA4) = 0;
        *(unsigned*)(base + 0xA8) = 0;
        *(unsigned*)(base + 0xAC) = 0;
    }
    return 1;
}
