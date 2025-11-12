#ifndef TTIO_H
#define TTIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <nds/arm9/dldi.h>

bool TTIO_Startup(void);
bool TTIO_IsInserted(void);
bool TTIO_ReadSectors(uint32_t sector, uint32_t num_sectors, void* buffer);
bool TTIO_WriteSectors(uint32_t sector, uint32_t num_sectors, const void* buffer);
bool TTIO_ClearStatus(void);
bool TTIO_Shutdown(void);

const DISC_INTERFACE io_ttio = {
    0x5454494F, // "TTIO"
    (FEATURE_MEDIUM_CANREAD | FEATURE_MEDIUM_CANWRITE | FEATURE_SLOT_NDS),
    (FN_MEDIUM_STARTUP)&TTIO_Startup,
    (FN_MEDIUM_ISINSERTED)&TTIO_IsInserted,
    (FN_MEDIUM_READSECTORS)&TTIO_ReadSectors,
    (FN_MEDIUM_WRITESECTORS)&TTIO_WriteSectors,
    (FN_MEDIUM_CLEARSTATUS)&TTIO_ClearStatus,
    (FN_MEDIUM_SHUTDOWN)&TTIO_Shutdown
};

#ifdef __cplusplus
}
#endif

#endif // TTIO_H

