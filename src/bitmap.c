
#include <assert.h>
#include <stdlib.h>

#include <wisper/bits/bitmap.h>
#include <wisper/exception/memoryerror.h>

static bitmap_t _alloc_self()
{
  bitmap_t self = (bitmap_t) malloc(sizeof(bitmap_type));
  if(NULL != self) {
	self->bits = NULL;
	self->x = self->y = self->cols = 0;
	return self;
  }
  memoryerror_exception();
  return (bitmap_t) NULL;
}

static void _alloc_bitmap(bitmap_t self, int x, int y)
{
  int c = (x + (x % 8 > 0 ? 8 - x % 8 : 0)) / 8;
  c = c + (c % sizeof(bitmap_bits) > 0 ? 
	    sizeof(bitmap_bits) - c % sizeof(bitmap_bits) : 0);
  {
    bitmap_bits* bits = (bitmap_bits*) calloc(c,y);
    if(NULL != bits) {
	  self->bits = bits;
	  self->x = x;
	  self->y = y;
	  self->cols = c / sizeof(bitmap_bits);
	  return;
	}
	memoryerror_exception();
  }
}

bitmap_t new_bitmap(int x, int y)
{
  assert(x > 0 && y > 0);

  bitmap_t self = _alloc_self();
  _alloc_bitmap(self,x,y);
  return self;
}

static bitmap_bits* get_bitmap_bits_pointer(bitmap_t self, int x, int y)
{
  assert(x >= 0 && x < self->x && y >= 0 && y < self->y);
  {
    int c = x / 8 / sizeof(bitmap_bits);
  
    bitmap_bits* bits = self->bits + self->cols * y + c;
    return bits;
  }
}

bool is_bitmap_bit_on(bitmap_t self, int x, int y)
{
  bitmap_bits* bits = get_bitmap_bits_pointer(self, x, y);
  int bit = x % (8 * sizeof(bitmap_bits));
  bitmap_bits pattern = 1 << bit;
  
  return (*bits & pattern) == 0 ? false : true; 
}

void bitmap_bit_on(bitmap_t self, int x, int y)
{
  set_bitmap_bit(self, x, y, bit_on);
}

void bitmap_bit_off(bitmap_t self, int x, int y)
{
  set_bitmap_bit(self, x, y, bit_off);
}

void set_bitmap_bit(bitmap_t self, int x, int y, bit_value_type val)
{  
  bitmap_bits* bits = get_bitmap_bits_pointer(self, x, y);	
  int bit = x % (8 * sizeof(bitmap_bits));
  bitmap_bits pattern = 1 << bit;
  
  if(val == bit_on) {
	  *bits = *bits | pattern;
  }
  else {
	  *bits = *bits & (~(bitmap_bits)0 ^ pattern);
  }
}

bit_value_type toggle_bitmap_bit(bitmap_t self, int x, int y)
{
  bit_value_type toggled = is_bitmap_bit_on(self,x,y) ? bit_off : bit_on;
  set_bitmap_bit(self,x,y,toggled);
  return toggled;
}
