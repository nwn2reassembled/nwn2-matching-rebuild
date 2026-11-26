struct ZeroedBlock
{
    int first;
    int second;
    int third;
    int fourth;
    int fifth;

    ZeroedBlock* Clear();
};

ZeroedBlock* ZeroedBlock::Clear()
{
    ZeroedBlock* self = this;

    self->first = 0;
    self->second = 0;
    self->third = 0;
    self->fourth = 0;
    self->fifth = 0;

    return self;
}
