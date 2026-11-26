struct Server {
    unsigned char pad[0x7AB78];
    unsigned int maxLevel;

    void SetMaxLevel(unsigned int level);
};

void Server::SetMaxLevel(unsigned int level)
{
    if (level >= 0x60)
        level = 0x60;
    this->maxLevel = level;
}
