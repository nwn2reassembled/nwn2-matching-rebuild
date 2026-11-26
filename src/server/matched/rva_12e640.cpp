struct ServerObject {
    /* 0x00 .. 0x13 */ int data[5];
    char flags; /* 0x14 */
};

bool __cdecl ServerObject_HasFlagSet(ServerObject *pObj)
{
    char c = pObj->flags;
    c &= 1;
    return c == 1;
}
