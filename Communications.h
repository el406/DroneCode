#include <sys/types.h>

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
} t_OdometryPacket; 

typedef struct ControlPacket { 
    float stick[2];
    u_int8_t buttons[4];
} t_ControlPacket;




