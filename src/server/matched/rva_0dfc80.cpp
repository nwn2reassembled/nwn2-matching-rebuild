struct ServerObject
{
    unsigned long typeInfo;
    unsigned long refCount;
    unsigned long link;
    unsigned long state;

    ServerObject();
};

ServerObject::ServerObject()
    : typeInfo(0x7F4928UL),
      refCount(0),
      link(0),
      state(0)
{
}
