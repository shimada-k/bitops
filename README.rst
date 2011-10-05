bitops -C言語用ビット操作ライブラリ-
====================================

ビット演算を行うときのライブラリです。bitosは以下の２種類のAPIが存在します。

* bitos-APIs
* BSTREAM-Framework

種類別のドキュメントになっています。

bitops-APIs
-------------

bitops-APIsは、ある変数のアドレスを受け取って指定された桁数のビットを操作するライブラリです。

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

.. list-table:: API一覧
   :header-rows: 1
   :stub-columns: 1

   * - ビット幅
     - 8ビット
     - 32ビット
     - 64ビット
   * - 指定された桁のビットの値（0 or 1）を調べる関数
     - pick_nbit8
     - pick_nbit32
     - pick_nbit64
   * - 指定された桁のビットを1にする関数
     - set_nbit8
     - set_nbit32
     - set_nbit64
   * - 指定された桁のビットを0にする関数
     - clr_nbit8
     - clr_nbit32
     - clr_nbit64
   * - 指定された桁のビットを反転する関数
     - rotate_nbit8
     - rotate_nbit32
     - rotate_nbit64
   * - 最初に1になっているビットの桁数を返す関数
     - find_first_setbit8
     - find_first_setbit32
     - find_first_setbit64
   * - 指定された桁の次に1になっているビットの桁数を返す関数
     - clr_nbit8
     - clr_nbit32
     - clr_nbit64
   * - 2進数で標準出力に値を出力する関数
     - print_binary8
     - print_binary32
     - print_binary64

プロトタイプ
-------------

8bit変数操作API
^^^^^^^^^^^^^^^

unsigned int pick_nbit8(unsigned char num, unsigned int n);

void set_nbit8(unsigned char *num, unsigned int n);

void clr_nbit8(unsigned char *num, unsigned int n);

void rotate_nbit8(unsigned char *num, unsigned int n);

unsigned int find_first_setbit8(unsigned char num);

unsigned int find_next_setbit8(unsigned char num, unsigned int n);

void print_binary8(unsigned char num);

32bit変数操作API
^^^^^^^^^^^^^^^^

unsigned int pick_nbit32(unsigned int num, unsigned int n);

void set_nbit32(unsigned int *num, unsigned int n);

void clr_nbit32(unsigned int *num, unsigned int n);

void rotate_nbit32(unsigned int *num, unsigned int n);

unsigned int find_first_setbit32(unsigned int num);

unsigned int find_next_setbit32(unsigned int num, unsigned int n);

void print_binary32(unsigned int num);

64bit変数操作API
^^^^^^^^^^^^^^^^

unsigned int pick_nbit64(unsigned long long num, unsigned int n);

void set_nbit64(unsigned long long *num, unsigned int n);

void clr_nbit64(unsigned long long *num, unsigned int n);

void rotate_nbit64(unsigned long long *num, unsigned int n);

unsigned int find_first_setbit64(unsigned long long num);

unsigned int find_next_setbit64(unsigned long long num, unsigned int n);

void print_binary64(unsigned long long num);


BSTREAM-Framework
--------------------

BSTREAM-Frameworkは、ビットストリームを扱う時の関数群です。内部でbitops-APIsをコールしています。

ビットストリームとは、固定長のあるバイト列において、ビットの内容を低位ビットから順番に返していくというデータ構造です。

返す値は0or1でunsigned intの値になっています。

