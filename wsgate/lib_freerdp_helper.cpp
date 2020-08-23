#include <cstring>

#include <freerdp2/freerdp/codec/color.h>

#include "lib_freerdp_helper.hpp"


uint32_t freerdp_color_convert_var(uint32_t color, int srcBpp, int dstBpp){
    unsigned char r, g, b, a;
    if (srcBpp == 16 && dstBpp == 32) {
        SplitColor(color, PIXEL_FORMAT_RGB16, &r, &g, &b, &a, nullptr);
        return FreeRDPGetColor(PIXEL_FORMAT_RGBA32, r, g, b, a);
    }
    return color;
}

unsigned char* freerdp_image_flip(unsigned char* src, unsigned char* dst, int width, int height, int bpp) {
    int scanline = width * ((bpp + 7) / 8);
    freerdp_bitmap_flip(src, dst, scanline, height);
    return dst;
}

void freerdp_bitmap_flip(unsigned char * src, unsigned char * dst, int scanLineSz, int height)
{
	int i;

	unsigned char * bottomLine = dst + (scanLineSz * (height - 1));
	unsigned char * topLine = src;

	/* Special processing if called for flip-in-place. */
	if (src == dst)
	{
		/* Allocate a scanline buffer.
		 * (FIXME: malloc / xfree below should be replaced by "get/put
		 * scanline buffer from a pool/Q of fixed buffers" to reuse
		 * fixed size buffers (of max scanline size (or adaptative?) )
		 * -- would be much faster).
		 */
		unsigned char* tmpBfr = reinterpret_cast<unsigned char*>(aligned_alloc(scanLineSz, 16));
		int half = height / 2;
		/* Flip buffer in place by line permutations through the temp
		 * scan line buffer.
		 * Note that if height has an odd number of line, we don't need
		 * to move the center scanline anyway.
		 * Also note that in place flipping takes three memcpy() calls
		 * to process two scanlines while src to distinct dest would
		 * only requires two memcpy() calls for two scanlines.
		 */
		height--;
		for (i = 0; i < half ; i++)
		{
			std::memcpy(tmpBfr, topLine, scanLineSz);
			std::memcpy(topLine, bottomLine, scanLineSz);
			std::memcpy(bottomLine, tmpBfr, scanLineSz);
			topLine += scanLineSz;
			bottomLine -= scanLineSz;
			height--;
		}
		free(tmpBfr);
	}
}