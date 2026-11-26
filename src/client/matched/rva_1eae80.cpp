struct NwGame {
    unsigned char pad0[0x130];
    unsigned int m_value;      /* +0x130 */
    unsigned int m_flag;       /* +0x134 */
};

/* stack-passed this; __stdcall with two stack params (this + value) */
void __stdcall NwGame_SetDefaultValue(NwGame* self, unsigned int value)
{
    if (self->m_flag == 0)
    {
        self->m_value = value;
    }
}
