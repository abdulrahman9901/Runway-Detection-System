
#pragma once

#include <stdint.h>
#include <stdbool.h>

#define MAX_BRIGHTNESS 255

typedef struct {
    uint8_t magic[2];
} bmpfile_magic_t;

typedef struct {
    uint32_t filesz;
    uint16_t creator1;
    uint16_t creator2;
    uint32_t bmp_offset;
} bmpfile_header_t;

typedef struct {
    uint32_t header_sz;
    int32_t  width;
    int32_t  height;
    uint16_t nplanes;
    uint16_t bitspp;
    uint32_t compress_type;
    uint32_t bmp_bytesz;
    int32_t  hres;
    int32_t  vres;
    uint32_t ncolors;
    uint32_t nimpcolors;
} bitmap_info_header_t;

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t nothing;
} rgb_t;


#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

typedef short int pixel_t;

pixel_t* load_bmp(const char* filename, bitmap_info_header_t* bitmapInfoHeader);
bool save_bmp(const char* filename, const bitmap_info_header_t* bmp_ih, const pixel_t* data);
void convolution(const pixel_t* in, pixel_t* out, const float* kernel, const int nx, const int ny, const int kn, const bool normalize);
void gaussian_filter(const pixel_t* in, pixel_t* out, const int nx, const int ny, const float sigma);
pixel_t* canny_edge_detection(const pixel_t* in, const bitmap_info_header_t* bmp_ih, const int tmin, const int tmax, const float sigma);


