// Returns the maximum number of classes a character may take.
int MaxCharacterClasses()
{
    const int MAX_CLASSES_EPIC   = 581;
    const int MAX_CLASSES_LEGACY = 0;

    int limit;
    if (MAX_CLASSES_EPIC > MAX_CLASSES_LEGACY)
        limit = MAX_CLASSES_EPIC;
    else
        limit = MAX_CLASSES_LEGACY;

    return limit;
}
