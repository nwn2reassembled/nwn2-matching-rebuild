struct SoundChannelRecord {
    int id;
    char name[136];
    float gain;
    float pitch;
    int flags;
};

enum { kMaxSoundChannelsPerZone = 8 };

int GetMaxSoundChannelsPerZone() { return sizeof(SoundChannelRecord) * kMaxSoundChannelsPerZone; }
