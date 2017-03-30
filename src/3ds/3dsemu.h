
#include "3dstypes.h"

// Uncomment this to convert before releasing this to remove
// all the debugging stuff.
//
#define EMU_RELEASE 

// Uncomment this to allow user to break into debug mode (for the 65816 CPU)
//
//#define DEBUG_CPU

// Uncomment this to allow user to break into debug mode (for the SPC700 APU)
//
//#define DEBUG_APU



#define DEBUG_WAIT_L_KEY 	\
    { \
        uint32 prevkey = 0; \
        while (aptMainLoop()) \ 
        {  \
            hidScanInput(); \ 
            uint32 key = hidKeysHeld(); \
            if (key == KEY_L) break; \
            if (key == KEY_R) { emulator.enableDebug = false; break; } \
            if (key == KEY_TOUCH) break; \
            if (prevkey != 0 && key == 0) \
                break;  \
            prevkey = key; \
        } \ 
    }