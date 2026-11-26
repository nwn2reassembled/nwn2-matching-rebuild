struct RuleCharCell { char value; };

void __stdcall SetRuleCharValue(RuleCharCell* cell, char c)
{
    if (cell != 0)
        cell->value = c;
}
