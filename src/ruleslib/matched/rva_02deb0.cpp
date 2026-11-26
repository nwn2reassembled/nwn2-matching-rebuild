namespace NWN2RulesLib {

class RulesSystem {
public:
    static unsigned long GetVersionConstant();
};

unsigned long RulesSystem::GetVersionConstant()
{
    return 0x70fu;
}

}
