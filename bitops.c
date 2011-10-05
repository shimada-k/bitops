/*
	bitops.c:ビット演算用ライブラリ
	written by shimada-k
	last modify 2011.9.18
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include "bitops.h"

/*
*
* BITOPS APIs
*
*/


/*
*
*	8bit operation APIs
*
*/

/*
* Description:numのnビット目をbool型で返す関数
* @num:nビット目を調べる数
 *@n:ビットの桁数（0...7）
*/
unsigned int pick_nbit8(unsigned char num, unsigned int n)
{
	invalid_order(n, 8, __func__);

	num = num >> n;
	num = num & 0x01;
	return num;
}

/*
* Description:ビットをセットする関数
* @num:ビットをセットする変数のアドレス
* @n:セットするビットの桁数（0...7）
*/
void set_nbit8(unsigned char *num, unsigned int n)
{
	invalid_order(n, 8, __func__);

	unsigned char val = 0x01;

	val = val << n;	/* if n==3; val = 0000 1000 */
	*num = *num | val;
}

/*
* Description:ビットをクリアする関数
* @num:ビットをクリアされる変数のアドレス
* @n:クリアするビットの桁数（0...7）
*/
void clr_nbit8(unsigned char *num, unsigned int n)
{
	invalid_order(n, 8, __func__);

	unsigned char val = 0x00;

	set_nbit8(&val, n);
	val = ~val;
	*num = *num & val;
}

/*
* Description:ビットを反転させる関数
* @num:ビットを反転される変数のアドレス
* @n:反転するビットの桁数（0...7）
*/
void rotate_nbit8(unsigned char *num, unsigned int n)
{
	invalid_order(n, 8, __func__);

	if(pick_nbit8(*num, n))
		clr_nbit8(num, n);
	else
		set_nbit8(num, n);
}

/*
* Description:最初にセットされているビットの位置を返す関数
* @num:ビットを走査する変数のアドレス
*/
unsigned int find_first_setbit8(unsigned char num)
{
	unsigned char	i;

	for(i = 0; i < 8; i++){
		if(pick_nbit8(num, i))
			return i;
	}
	return 8;
}

/*
* Description:セットされているビットのnビット目の位置を返す関数
* @num:起点のビットの桁数（0...7）
*/
unsigned int find_next_setbit8(unsigned char num, unsigned int n)
{
	invalid_order(n, 8, __func__);

	unsigned char i;

	for(i = n; i < 8; i++){
		if(pick_nbit8(num, i))
			return i;
	}
	return 8;
}

/*
* Description:numを2進数で標準出力に右から左へ表示
* @num:表示する変数の値
*/
void print_binary8(unsigned char num)
{
	unsigned int i = 7;

	while(1){

		if(pick_nbit8(num, i))
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
*	32bit operation APIs
*
*/

/*
* Description:numのnビット目をbool型で返す関数
* @num:nビット目を調べる数
 *@n:ビットの桁数（0...31）
*/
unsigned int pick_nbit32(unsigned int num, unsigned int n)
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
void set_nbit32(unsigned int *num, unsigned int n)
{
	invalid_order(n, 32, __func__);

	unsigned int val = 0x01;

	val = val << n;	/* if n==3; val = 0000 1000 */
	*num = *num | val;
}

/*
* Description:ビットをクリアする関数
* @num:ビットをクリアされる変数のアドレス
* @n:クリアするビットの桁数（0...31）
*/
void clr_nbit32(unsigned int *num, unsigned int n)
{
	invalid_order(n, 32, __func__);

	unsigned int val = 0x00;

	set_nbit32(&val, n);
	val = ~val;
	*num = *num & val;
}

/*
* Description:ビットを反転させる関数
* @num:ビットを反転される変数のアドレス
* @n:反転するビットの桁数（0...31）
*/
void rotate_nbit32(unsigned int *num, unsigned int n)
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
unsigned int find_first_setbit32(unsigned int num)
{
	unsigned int	i;

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
unsigned int find_next_setbit32(unsigned int num, unsigned int n)
{
	invalid_order(n, 32, __func__);

	unsigned int i;

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
void print_binary32(unsigned int num)
{
	unsigned int i = 31;

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
unsigned int pick_nbit64(unsigned long long num, unsigned int n)
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
void set_nbit64(unsigned long long *num, unsigned int n)
{
	invalid_order(n, 64, __func__);

	unsigned long long val = 0x01;

	val = val << n;	/* if n==3; val = 0000 1000 */
	*num = *num | val;
}

/*
* Description:ビットをクリアする関数
* @num:ビットをクリアされる変数のアドレス
* @n:クリアするビットの桁数（0...63）
*/
void clr_nbit64(unsigned long long *num, unsigned int n)
{
	invalid_order(n, 64, __func__);

	unsigned long long val = 0x00;

	set_nbit64(&val, n);
	val = ~val;
	*num = *num & val;
}

/*
* Description:ビットを反転させる関数
* @num:ビットを反転される変数のアドレス
* @n:反転するビットの桁数（0...63）
*/
void rotate_nbit64(unsigned long long *num, unsigned int n)
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
unsigned int find_first_setbit64(unsigned long long num)
{
	unsigned int	i;

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
unsigned int find_next_setbit64(unsigned long long num, unsigned int n)
{
	invalid_order(n, 64, __func__);

	unsigned int i;

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
void print_binary64(unsigned long long num)
{
	unsigned int i = 63;

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


/*
*
* BITSTREAM APIs
*
*/

/*
	データをストリーム化する関数
	@raw 呼出側が指定するビットストリーム化したいデータ
	@count rawのサイズ
	return 成功:BSTREAMのアドレス 失敗:NULL
*/
BSTREAM *openBitStream(const void *raw, size_t count, const char *mode)
{
	BSTREAM *bs = NULL;

	bs = malloc(sizeof(BSTREAM));

	bs->raw_data = malloc(count);

	memset(bs->raw_data, 0, count);

	if(strcmp(mode, "r") == 0 && raw){	/* 読み込みモードでもopenだったら */
		memcpy(bs->raw_data, raw, count);	/* 呼出側のデータをコピー */
	}

	bs->raw_data_length = count;
	bs->focus = bs->raw_data;
	bs->bit_pos = 0;

	return bs;
}

/*
	データを読み出す関数
	return ビットの内容(1 or 0) データが終了したら-1を返す
*/
int readBitStream(BSTREAM *stream)
{
	unsigned int bit;
	static int current_idx;

	if(stream->bit_pos > 7){
		if(current_idx < stream->raw_data_length - 1){
			stream->focus++;
			stream->bit_pos = 0;
			current_idx++;
		}
		else{
			return -1;
		}
	}

	bit = pick_nbit8(*((unsigned char *)stream->focus), stream->bit_pos);

	stream->bit_pos++;

	return bit;

}

/*
	データを書き込む関数
	@stream ビットストリームのアドレス
	@bit ビットの内容（0 or 1）
	return 成功:0 データの書き込みが終了したら-1を返す
*/
int writeBitStream(BSTREAM *stream, int bit)
{
	static int current_idx = 0;

	if(stream->bit_pos > 7){
		if(current_idx < stream->raw_data_length - 1){
#ifdef DEBUG
			char c;
			memcpy((void *)&c, stream->focus, 1);
			putchar(c);
			putchar('\n');
#endif
			stream->focus++;
			stream->bit_pos = 0;
			current_idx++;
		}
		else{
#ifdef DEBUG
			printf("current_idx=%d\n", current_idx);
#endif
			return -1;
		}
	}

	if(bit == 0){
		clr_nbit8((unsigned char *)stream->focus, stream->bit_pos);
	}
	else if(bit == 1){
		set_nbit8((unsigned char *)stream->focus, stream->bit_pos);
	}

	stream->bit_pos++;

	return 0;
}

/* 
	ストリームを解放する関数
*/
void closeBitStream(BSTREAM *stream)
{
	free(stream->raw_data);
	free(stream);
}

