unsigned long __stdcall CheckServerInfoFlag(void* info, unsigned long flagMask) {
    if (flagMask == 0)
        return 1;
    return *(unsigned long*)((char*)info + 0x314) & flagMask;
}
