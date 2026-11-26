struct RenderState
{
    unsigned long m_refCount;
    void *m_parent;
    void *m_firstChild;
    void *m_nextSibling;
    unsigned long m_flags;
    unsigned long m_lastTick;
    unsigned long m_userData;
    unsigned char m_visible;
    unsigned char m_dirty;
    unsigned long m_reserved;

    RenderState();
};

RenderState::RenderState()
{
    m_refCount = 0;
    m_parent = 0;
    m_firstChild = 0;
    m_nextSibling = 0;
    m_flags = 0;
    m_lastTick = 0;
    m_userData = 0;
    m_visible = 0;
    m_dirty = 0;
    m_reserved = 0;
}
