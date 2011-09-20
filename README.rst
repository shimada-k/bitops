bitops -C言語用ビット操作ライブラリ-
=================================

ある変数のアドレスを受け取って指定された桁数のビットを操作するライブラリです。

今何ビット幅の処理をやっているか、ということを意識できるように変数のビット幅
ごとに関数を分けています。

ビット幅としては8bit、32bit、64bitの3種類のAPIセットを実装してあります。

依存するパッケージはありません。bitops.hをインクルードして、bitops.oをリンク
するだけです。

::
    gcc -c YourProgramName.c
    gcc -c bitops.c
    gcc -o YourProgramName YourProgramName.o bitops.o

bitops.cでは以下のAPIを提供しています。

8bit変数操作API
-----------------

unsigned int pick_nbit8(unsigned char num, unsigned int n);

void set_nbit8(unsigned char *num, unsigned int n);

void clr_nbit8(unsigned char *num, unsigned int n);

void rotate_nbit8(unsigned char *num, unsigned int n);

unsigned int find_first_setbit8(unsigned char num);

unsigned int find_next_setbit8(unsigned char num, unsigned int n);

void print_binary8(unsigned char num);

32bit変数操作API
-----------------

unsigned int pick_nbit32(unsigned int num, unsigned int n);

void set_nbit32(unsigned int *num, unsigned int n);

void clr_nbit32(unsigned int *num, unsigned int n);

void rotate_nbit32(unsigned int *num, unsigned int n);

unsigned int find_first_setbit32(unsigned int num);

unsigned int find_next_setbit32(unsigned int num, unsigned int n);

void print_binary32(unsigned int num);

64bit変数操作API
-----------------

unsigned int pick_nbit64(unsigned long long num, unsigned int n);

void set_nbit64(unsigned long long *num, unsigned int n);

void clr_nbit64(unsigned long long *num, unsigned int n);

void rotate_nbit64(unsigned long long *num, unsigned int n);

unsigned int find_first_setbit64(unsigned long long num);

unsigned int find_next_setbit64(unsigned long long num, unsigned int n);

void print_binary64(unsigned long long num);

