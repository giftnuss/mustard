
#ifndef _WISPER_BITS_BITMAP_H_
# define _WISPER_BITS_BITMAP_H_

#include <wisper/bool.h>

typedef unsigned int bitmap_bits;

enum BitValue {
  bit_off,
  bit_on,
};

struct Bitmap {
  bitmap_bits* bits;
  int x;
  int y;
  int cols;
};

typedef enum BitValue bit_value_type;
typedef struct Bitmap bitmap_type;
typedef struct Bitmap*  bitmap_t;

bitmap_t new_bitmap(int, int);

bool is_bitmap_bit_on(bitmap_t, int, int);
void set_bitmap_bit(bitmap_t, int, int, bit_value_type);
void bitmap_bit_on(bitmap_t, int, int);
void bitmap_bit_off(bitmap_t, int, int);

void delete_bitmap(bitmap_t);

#endif

