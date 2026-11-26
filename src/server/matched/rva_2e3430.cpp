class ServerEntry {
public:
    unsigned int GetNextOffset();
private:
    unsigned int pad[3];
    unsigned int nextOffset;
};

unsigned int ServerEntry::GetNextOffset()
{
    return nextOffset + 4;
}
