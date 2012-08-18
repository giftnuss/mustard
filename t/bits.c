
#include <stdlib.h>
#include <tap.h>

#include <wisper/foundation.h>
#include <wisper/bits/bitlist64.h>

static void check_empty()
{  
  bitlist64 check = 0x0000000000000000;
  char* show = bitlist64_hex_format(check);
  diag(show);
  free(show);
  ok(bitlist64_value(check,0) == -1,"empty bitlist has no value	at all");
}

static void check_one(bitlist64 check)
{
  char* show = bitlist64_hex_format(check);
  diag(show);
  free(show);
  ok(bitlist64_value(check,0) == 0,"bitlist(1) - [0] = 0");
  ok(bitlist64_value(check,1) == -1,"bitlist(1) - [1] = -1");
}

static void check_multi1(bitlist64 check)
{              
  // 0001_1010_0100_1000
  char* show = bitlist64_hex_format(check);
  diag(show);
  free(show);
  ok(bitlist64_value(check,0) == 3,"bitlist(1A48) - [0] = 3");
  ok(bitlist64_value(check,1) == 2,"bitlist(1A48) - [1] = 2");
  ok(bitlist64_value(check,2) == 2,"bitlist(1A48) - [2] = 2");
  ok(bitlist64_value(check,3) == 1,"bitlist(1A48) - [3] = 1");
  ok(bitlist64_value(check,4) == 0,"bitlist(1A48) - [4] = 0");
  ok(bitlist64_value(check,5) == -1,"bitlist(1A48) - [5] = -1");
}

static bitlist64 dynamic_one()
{
  bitlist64 one = 0;
  ok(bitlist64_add_value(&one,0),"add 0");
  return one;
}

static bitlist64 dynamic_multi1()
{
  bitlist64 m = 0;
  ok(bitlist64_add_value(&m,3),"add 3");
  ok(bitlist64_add_value(&m,2),"add 2");
  ok(bitlist64_add_value(&m,2),"add 2");
  ok(bitlist64_add_value(&m,1),"add 1");
  ok(bitlist64_add_value(&m,0),"add 0");
  return m;
}

static void check_overflow(bitlist64 check)
{  
  char* show = bitlist64_hex_format(check);
  diag(show);
  free(show);
  ok(bitlist64_value(check,0) == 63,"[0] = 63");
}

static bitlist64 bit_overflow()
{
  bitlist64 m = 0;
  ok(bitlist64_add_value(&m,63),"add 63");
  ok(!bitlist64_add_value(&m,0),"add 0 returns false");
  return m;	
}

int main(int argv, char** argc)
{	
  ok(sizeof(bitlist64) == 8,"sizof bitlist64 is 8");
  check_empty();
  check_one(0x0000000000000001);
  check_one(dynamic_one());
  check_multi1(0x0000000000001A48);
  check_multi1(dynamic_multi1());
  check_overflow(0x8000000000000000);
  check_overflow(bit_overflow());
  return 0;
}
