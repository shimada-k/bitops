#include <stdio.h>
#include <stdlib.h>	/* atoi(3) */
#include "bitops.h"

/*
	test.c:bitops.cのテストプログラム
	written by shimada-k
	last modify 2011.6.17
*/

void rotate_test32(void)
{
	int i;
	u32 hoge = 0;

	puts("rotate_test");

	print_binary32(hoge);	/* 表示テスト */

	putchar('\n');

	for(i = 0; i < 32; i += 2){
		set_nbit32(&hoge, i);	/* 0から1個飛ばしにビットをセット */
	}

	print_binary32(hoge);	/* 表示 */
	putchar('\n');

	for(i = 1; i < 32; i += 2){
		set_nbit32(&hoge, i);	/* 1から1個飛ばしにビットをセット */
	}

	print_binary32(hoge);	/* 表示 */
	putchar('\n');

	for(i = 0; i < 32; i += 2){		/* 0から1個飛ばしにビットを反転 */
		rotate_nbit32(&hoge, i);
	}

	print_binary32(hoge);	/* 表示 */
	putchar('\n');

	for(i = 1; i < 32; i += 2){		/* 1から1個飛ばしにビットを反転 */
		rotate_nbit32(&hoge, i);
	}

	print_binary32(hoge);	/* 表示 */
	putchar('\n');
}

void rotate_test64(void)
{
	int i;
	u64 hoge = 0;

	puts("rotate_test");

	print_binary64(hoge);	/* 表示テスト */

	putchar('\n');

	for(i = 0; i < 64; i += 2){
		set_nbit64(&hoge, i);	/* 0から1個飛ばしにビットをセット */
	}

	print_binary64(hoge);	/* 表示 */
	putchar('\n');

	for(i = 1; i < 64; i += 2){
		set_nbit64(&hoge, i);	/* 1から1個飛ばしにビットをセット */
	}

	print_binary64(hoge);	/* 表示 */
	putchar('\n');

	for(i = 0; i < 64; i += 2){		/* 0から1個飛ばしにビットを反転 */
		rotate_nbit64(&hoge, i);
	}

	print_binary64(hoge);	/* 表示 */
	putchar('\n');

	for(i = 1; i < 64; i += 2){		/* 1から1個飛ばしにビットを反転 */
		rotate_nbit64(&hoge, i);
	}

	print_binary64(hoge);	/* 表示 */
	putchar('\n');
}

void bitpos_test32(void)
{
	int i;
	u32 hoge = 0;

	puts("bitpos_test");

	for(i = 0; i < 32; i += 2){		/* 0から1個飛ばしにビットをセット */
		set_nbit32(&hoge, i);
	}

	print_binary32(hoge);	/* 表示 */
	putchar('\n');

	for(i = 0; i < 32; i = find_next_setbit32(hoge, i)){
		clr_nbit32(&hoge, i);
	}

	print_binary32(hoge);	/* 表示 */
	putchar('\n');

	for(i = 1; i < 32; i *= 2){		/* 1からiの2倍の間隔を空けながらビットをセット */
		set_nbit32(&hoge, i);
	}

	print_binary32(hoge);	/* 表示 */
	putchar('\n');

	for(i = 0; i < 32; i = find_next_setbit32(hoge, i)){
		clr_nbit32(&hoge, i);
	}

	print_binary32(hoge);	/* 表示 */
	putchar('\n');
}

void bitpos_test64(void)
{
	int i;
	u64 hoge = 0;

	puts("bitpos_test");

	for(i = 0; i < 64; i += 2){		/* 0から1個飛ばしにビットをセット */
		set_nbit64(&hoge, i);
	}

	print_binary64(hoge);	/* 表示 */
	putchar('\n');

	for(i = 0; i < 64; i = find_next_setbit64(hoge, i)){
		clr_nbit64(&hoge, i);
	}

	print_binary64(hoge);	/* 表示 */
	putchar('\n');

	for(i = 1; i < 64; i *= 2){		/* 1からiの2倍の間隔を空けながらビットをセット */
		set_nbit64(&hoge, i);
	}

	print_binary64(hoge);	/* 表示 */
	putchar('\n');

	for(i = 0; i < 64; i = find_next_setbit64(hoge, i)){
		clr_nbit64(&hoge, i);
	}

	print_binary64(hoge);	/* 表示 */
	putchar('\n');
}

int main(int argc, char *argv[])
{
	int bit_width = 32;	/* デフォルトは32ビットテスト */

	if(argc == 2){	/* 引数があるなら受ける取る */
		bit_width = atoi(argv[1]);
	}

	if(bit_width == 32){
		puts("----32 bit operation----");
		rotate_test32();
		bitpos_test32();
	}
	else if(bit_width == 64){
		puts("----64 bit operation----");
		rotate_test64();
		bitpos_test64();
	}

	return 0;
}

