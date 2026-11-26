typedef unsigned __int64 u64;

struct StreamSizer {
    u64 pad[5];
    u64 base;
    u64 stored;

    int __fastcall Trim(u64 requested);
};

int StreamSizer::Trim(u64 requested)
{
    if (requested - this->base > this->stored) {
        this->stored = 0;
        this->base = requested;
        return 1;
    }

    this->stored = this->stored - requested + this->base;
    this->base = requested;
    return 0;
}
