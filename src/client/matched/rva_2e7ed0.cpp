class ClientObject {
    char pad[0x398];
    int flagValue;
public:
    int ClearOrCheckFlag();
};

int ClientObject::ClearOrCheckFlag()
{
    if (flagValue == 0)
        return 0;
    flagValue = 0;
    return 1;
}
