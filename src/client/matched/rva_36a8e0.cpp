struct WordTable
{
    int unknown0;
    int unknown4;
    unsigned short* words;
    int count;
};

class WordOwner
{
    char reserved[0x138];
    WordTable* table;
public:
    int GetWord(int index) const;
};

int WordOwner::GetWord(int index) const
{
    WordTable* t = table;
    if (index < 0 || index >= t->count)
        return 0xffff;
    return t->words[index];
}
