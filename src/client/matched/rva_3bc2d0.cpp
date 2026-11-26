class CTarget {
public:
    unsigned char pad0x00[0x9c];
    unsigned long field_9c;

    void SetTargetId(unsigned long id, unsigned long unusedParam);
};

void CTarget::SetTargetId(unsigned long id, unsigned long unusedParam)
{
    if (id != this->field_9c)
        this->field_9c = id;
}
