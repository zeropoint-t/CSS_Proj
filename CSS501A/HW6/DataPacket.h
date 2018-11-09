
#ifndef DataPacket_h
#define DataPacket_h

#include <ctime>

    template<typename T>
    struct DataPacket{
        time_t utc_timestamp;
        T open;
        T high;
        T low;
        T close;
        int32_t volume;
    };

#endif