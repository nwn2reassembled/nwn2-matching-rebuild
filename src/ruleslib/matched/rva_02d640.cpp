class RulesEngine
{
public:
    unsigned int GetMaxEffectLayers() const;
    char m_pad[0x688];
};

unsigned int RulesEngine::GetMaxEffectLayers() const
{
    return 0x688u;
}
