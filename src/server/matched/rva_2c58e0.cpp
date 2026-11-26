class ScriptManager
{
public:
    unsigned int field0_;
    unsigned int pad_[(0x360 - 4) / 4];
    unsigned int *ids_;
    int field364_;
    int count_;
    int HasScriptArg(unsigned int id) const;
};

int ScriptManager::HasScriptArg(unsigned int id) const
{
    int count = count_;
    for (int i = 0; i < count; ++i)
    {
        if (ids_[i] == id)
            return 1;
    }
    return 0;
}
