#include <stdio.h>
#include <stdint.h>

static inline void Store128(void *dst, const void *src) {
	const uint8_t *s = (const uint8_t*)src;
	uint8_t *d = (uint8_t*)dst;
	*(uint32_t*)(d + 0) = *(const uint32_t*)(s + 0);
	*(uint32_t*)(d + 4) = *(const uint32_t*)(s + 4);
	*(uint32_t*)(d + 8) = *(const uint32_t*)(s + 8);
	*(uint32_t*)(d + 12) = *(const uint32_t*)(s + 12);
}

int main(void)
{
	float A[4] = {1, 2, 3, 4};
	float B[4] = {5, 6, 7, 8};

	Store128(B, A);

	for (int i = 0; i < 4; i++) 
		printf("%f\n", B[i]);

	return 0;
}
