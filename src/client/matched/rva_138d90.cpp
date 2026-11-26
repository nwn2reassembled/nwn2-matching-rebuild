struct ResetJob
{
    unsigned char pad[0x80];
    unsigned char big[3][0x101];
    unsigned int first[3];
    unsigned int mid[3];
    unsigned char chans[3][0x200];
    unsigned int last[3];
    unsigned int total;
    unsigned char totalFlag;
    unsigned char pad2[0x101];
    unsigned int flag;
};

int ResetData(ResetJob *job)
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (job->flag != 0 && i == 0)
        {
        }
        else
        {
            job->big[i][0] = 0;
            job->chans[i][0] = 0;
            job->first[i] = 0;
            job->mid[i] = 0;
            job->last[i] = 0;
        }
    }
    job->total = 0;
    job->totalFlag = 0;
    return 1;
}
