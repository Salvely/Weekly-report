/*
 * lc4libc.h
 */

typedef int lc4_int; 
typedef unsigned int lc4_uint;
typedef char lc4_char;

lc4_int lc4_getc();
lc4_int lc4_getc_echo();

void lc4_puts(lc4_uint *str);
void lc4_draw_square(lc4_int x, lc4_int y, lc4_int width, lc4_uint color);
void lc4_draw_sprite(lc4_int x, lc4_int y, lc4_uint color, lc4_uint *sprite);

void lc4_halt();
void lc4_reset_vmem();
void lc4_blt_vmem();

// Added to support pseudo-RNG
lc4_int lc4_get_seed_status();
lc4_uint lc4_get_seed();
