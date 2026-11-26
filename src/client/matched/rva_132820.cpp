struct Handle { int field_00; int field_04; int field_08; };

int GetHandleId(Handle* handle)
{
    return handle->field_08;
}
