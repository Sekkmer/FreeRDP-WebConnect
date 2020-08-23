#ifndef LIBWSGATE_FREERDP_HELPER_HPP
#define LIBWSGATE_FREERDP_HELPER_HPP

uint32_t freerdp_color_convert_var(uint32_t color, int srcBpp, int dstBpp);

unsigned char* freerdp_image_flip(unsigned char* src, unsigned char* dst, int width, int height, int bpp);

void freerdp_bitmap_flip(unsigned char * src, unsigned char * dst, int scanLineSz, int height);

#endif // LIBWSGATE_FREERDP_HELPER_HPP