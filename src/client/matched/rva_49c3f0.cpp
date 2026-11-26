class Handler {
public:
    char pad_[0x0A];
    unsigned short state_;
    int __thiscall IsMatching(const struct Msg* msg);
};

struct Msg {
    char pad_[4];
    unsigned long type_;
};

int Handler::IsMatching(const Msg* msg)
{
    int result = 0;
    if (this->state_ == 3 && msg != 0 && msg->type_ == 0x3d)
        result = 1;
    return result;
}
