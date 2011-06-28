/*
	bitops.c:ビット演算用ライブラリ
	written by shimada-k
	last modify 2011.6.9
*/

#include <stdio.h>
#include <stdlib.h>
#include "bitops.h"

/*
*
*	32bit operation APIs
*
*/

/*
* Description:numのnビット目をbool型で返す関数
* @num:nビット目を調べる数
 *@n:ビットの桁数（0...31）
*/
u32 pick_nbit32(u32 num, u32 n)
{
	invalid_order(n, 32, __func__);

	num = num >> n;
	num = num & 0x01;
	return num;
}

/*
* Description:ビットをセットする関数
* @num:ビットをセットする変数のアドレス
* @n:セットするビットの桁数（0...31）
*/
void set_nbit32(u32 *num, u32 n)
{
	invalid_order(n, 32, __func__);

	u32 val = 0x01;

	val = val << n;	/* if n==3; val = 0000 1000 */
	*num = *num | val;
}

/*
* Description:ビットをクリアする関数
* @num:ビットをクリアされる変数のアドレス
* @n:クリアするビットの桁数（0...31）
*/
void clr_nbit32(u32 *num, u32 n)
{
	invalid_order(n, 32, __func__);

	u32 val = 0x00;

	set_nbit32(&val, n);
	val = ~val;
	*num = *num & val;
}

/*
* Description:ビットを反転させる関数
* @num:ビットを反転される変数のアドレス
* @n:反転するビットの桁数（0...31）
*/
void rotate_nbit32(u32 *num, u32 n)
{
	invalid_order(n, 32, __func__);

	if(pick_nbit32(*num, n))
		clr_nbit32(num, n);
	else
		set_nbit32(num, n);
}

/*
* Description:最初にセットされているビットの位置を返す関数
* @num:ビットを走査する変数のアドレス
*/
u32 find_first_setbit32(u32 num)
{
	u32	i;

	for(i = 0; i < 32; i++){
		if(pick_nbit32(num, i))
			return i;
	}
	return 32;
}

/*
* Description:セットされているビットのnビット目の位置を返す関数
* @num:起点のビットの桁数（0...31）
*/
u32 find_next_setbit32(u32 num, u32 n)
{
	invalid_order(n, 32, __func__);

	u32 i;

	for(i = n; i < 32; i++){
		if(pick_nbit32(num, i))
			return i;
	}
	return 32;
}

/*
* Description:numを2進数で標準出力に右から左へ表示
* @num:表示する変数の値
*/
void print_binary32(u32 num)
{
	u32 i = 31;

	while(1){

		if(pick_nbit32(num, i))
			printf("1");
		else
			printf("0");

		if(i != 0 && i % 4 == 0)	/* ４桁ずつスペースを入れる */
			putchar(' ');

		if(i == 0)
			break;
		else
			i--;
	}
	putchar('\n');
}


/*
*
*	64bit operation APIs
*
*/


/*
* Description:numのnビット目をbool型で返す関数
* @num:nビット目を調べる数
 *@n:ビットの桁数（0...63）
*/
u32 pick_nbit64(u64 num, u32 n)
{
	invalid_order(n, 64, __func__);

	num = num >> n;
	num = num & 0x01;
	return num;
}

/*
* Description:ビットをセットする関数
* @num:ビットをセットする変数のアドレス
* @n:セットするビットの桁数（0...63）
*/
void set_nbit64(u64 *num, u32 n)
{
	invalid_order(n, 64, __func__);

	u64 val = 0x01;

	val = val << n;	/* if n==3; val = 0000 1000 */
	*num = *num | val;
}

/*
* Description:ビットをクリアする関数
* @num:ビットをクリアされる変数のアドレス
* @n:クリアするビットの桁数（0...63）
*/
void clr_nbit64(u64 *num, u32 n)
{
	invalid_order(n, 64, __func__);

	u64 val = 0x00;

	set_nbit64(&val, n);
	val = ~val;
	*num = *num & val;
}

/*
* Description:ビットを反転させる関数
* @num:ビットを反転される変数のアドレス
* @n:反転するビットの桁数（0...63）
*/
void rotate_nbit64(u64 *num, u32 n)
{
	invalid_order(n, 64, __func__);

	if(pick_nbit64(*num, n))
		clr_nbit64(num, n);
	else
		set_nbit64(num, n);
}

/*
* Description:最初にセットされているビットの位置を返す関数
* @num:ビットを走査する変数のアドレス
*/
u32 find_first_setbit64(u64 num)
{
	u32	i;

	for(i = 0; i < 32; i++){
		if(pick_nbit64(num, i))
			return i;
	}
	return 32;
}

/*
* Description:セットされているビットのnビット目の位置を返す関数
* @num:起点のビットの桁数（0...63）
*/
u32 find_next_setbit64(u64 num, u32 n)
{
	invalid_order(n, 64, __func__);

	u32 i;

	for(i = n; i < 64; i++){
		if(pick_nbit64(num, i))
			return i;
	}
	return 64;
}

/*
* Description:numを2進数で標準出力に右から左へ表示
* @num:表示する変数の値
*/
void print_binary64(u64 num)
{
	u32 i = 63;

	while(1){

		if(pick_nbit64(num, i))
			printf("1");
		else
			printf("0");

		if(i != 0 && i % 4 == 0)	/* ４桁ずつスペースを入れる */
			putchar(' ');

		if(i == 0)
			break;
		else
			i--;
	}
	putchar('\n');
}

