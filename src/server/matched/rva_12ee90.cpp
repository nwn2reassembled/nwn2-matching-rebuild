struct Session
{
    unsigned char pad[0x14];
    unsigned char state;
};

unsigned char GetState(Session* session)
{
    return session->state;
}
