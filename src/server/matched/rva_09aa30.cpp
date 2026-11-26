class Thing {
public:
    unsigned char m_active;      /* offset 0x00 */
    unsigned char m_pad1[11];    /* offsets 0x01-0x0B */
    unsigned long m_valueA;      /* offset 0x0C */
    unsigned char m_pad2[68];    /* offsets 0x10-0x53 */
    unsigned long m_valueB;      /* offset 0x54 */

    unsigned long __fastcall GetResolvedValue();
};

unsigned long __fastcall Thing::GetResolvedValue()
{
    if (m_active != 0)
        return m_valueA;
    return m_valueB;
}
