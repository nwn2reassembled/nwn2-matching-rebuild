struct TimerPair
{
    unsigned int pad[2];
    unsigned __int64 start;
    unsigned __int64 end;
    unsigned __int64 Diff();
};

unsigned __int64 TimerPair::Diff()
{
    return start - end;
}
