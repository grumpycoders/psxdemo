#include <stdint.h>

#include "common/hardware/gpu.h"

__attribute__((noreturn)) void _binary_core_bin_start();
extern uint32_t _binary_texture_tex_start[];
extern uint32_t _binary_texture_tex_end[];

union GPUPoint {
    uint32_t packed;
    struct {
        int16_t x, y;
    };
};

int main() {
    GPU_STATUS = 0x00000000;  // reset GPU
    struct FastFill ff = {
        .c = {0},
        .x = 0,
        .y = 0,
        .w = 1024,
        .h = 512,
    };
    fastFill(&ff);
    waitGPU();
    sendGPUData(0xa0000000);
    union GPUPoint p;
    p.x = 960;
    p.y = 256;
    GPU_DATA = p.packed;
    p.x = 64;
    p.y = 34;
    GPU_DATA = p.packed;
    for (uint32_t * ptr = _binary_texture_tex_start; ptr < _binary_texture_tex_end; ptr++) {
        GPU_DATA = *ptr;
    }
    _binary_core_bin_start();
}
