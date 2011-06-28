
/* 桁数をチェックし不正ならコンソールに表示するマクロ */
#define invalid_order(n, order, __func__)	if(n > order - 1){			\
							printf(__func__);		\
							puts(":out of order");	\
						}

typedef unsigned long u32;

u32 pick_nbit32(u32 num, u32 n);
void set_nbit32(u32 *num, u32 n);
void clr_nbit32(u32 *num, u32 n);
void rotate_nbit32(u32 *num, u32 n);
u32 find_first_setbit32(u32 num);
u32 find_next_setbit32(u32 num, u32 n);
void print_binary32(u32 num);

typedef unsigned long long u64;

u32 pick_nbit64(u64 num, u32 n);
void set_nbit64(u64 *num, u32 n);
void clr_nbit64(u64 *num, u32 n);
void rotate_nbit64(u64 *num, u32 n);
u32 find_first_setbit64(u64 num);
u32 find_next_setbit64(u64 num, u32 n);
void print_binary64(u64 num);
