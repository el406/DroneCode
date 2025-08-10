#include <cctype>
#include <cstdint>
#include <stdint.h>

enum States {
   GROUNDED,
   RISING,
   REST,
   STRAFING,
   TURNING
};

typedef struct OdometryPacket {
    States state;    
    float motorPowers[4];
    float time;
} OdometryPacket; 

typedef struct ControlPacket { 
    float stick[2];
    bool buttons[4];
} ControlPacket;



