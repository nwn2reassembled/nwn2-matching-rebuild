class ContainedObject;

class SomeClass {
public:
    ContainedObject* GetContained();
    ContainedObject* GetSubObject();
};

ContainedObject* SomeClass::GetSubObject()
{
    ContainedObject* obj = *(ContainedObject**)this;
    if (obj != 0)
        return *(ContainedObject**)((char*)obj + 0x7ac04);
    return 0;
}
