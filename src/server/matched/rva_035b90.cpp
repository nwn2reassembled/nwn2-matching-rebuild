struct CharPtrBox
{
    const char* m_text;
    bool IsEmpty() const;
};

bool CharPtrBox::IsEmpty() const
{
    return m_text == 0 || *m_text == 0;
}
