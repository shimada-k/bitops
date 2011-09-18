
/* 桁数をチェックし不正ならコンソールに表示するマクロ */
#define invalid_order(n, order, __func__)	if(n > order - 1){			\
							printf(__func__);		\
							puts(":out of order");	\
						}

/* 8bit operation APIs */
unsigned int pick_nbit8(unsigned char num, unsigned int n);
void set_nbit8(unsigned char *num, unsigned int n);
void clr_nbit8(unsigned char *num, unsigned int n);
void rotate_nbit8(unsigned char *num, unsigned int n);
unsigned int find_first_setbit8(unsigned char num);
unsigned int find_next_setbit8(unsigned char num, unsigned int n);
void print_binary8(unsigned char num);

/* 32bit operation APIs */
unsigned int pick_nbit32(unsigned int num, unsigned int n);
void set_nbit32(unsigned int *num, unsigned int n);
void clr_nbit32(unsigned int *num, unsigned int n);
void rotate_nbit32(unsigned int *num, unsigned int n);
unsigned int find_first_setbit32(unsigned int num);
unsigned int find_next_setbit32(unsigned int num, unsigned int n);
void print_binary32(unsigned int num);

/* 64bit operation APIs */
unsigned int pick_nbit64(unsigned long long num, unsigned int n);
void set_nbit64(unsigned long long *num, unsigned int n);
void clr_nbit64(unsigned long long *num, unsigned int n);
void rotate_nbit64(unsigned long long *num, unsigned int n);
unsigned int find_first_setbit64(unsigned long long num);
unsigned int find_next_setbit64(unsigned long long num, unsigned int n);
void print_binary64(unsigned long long num);
