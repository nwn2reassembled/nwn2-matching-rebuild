class ServerObject
{
public:
    ServerObject* GetSelf();

private:
    /* other members omitted */
};

ServerObject* ServerObject::GetSelf()
{
    return this;
}
