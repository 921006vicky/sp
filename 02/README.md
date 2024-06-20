int doBegin = nextLabel();
宣告並初始化 doBegin 變數，並使用 nextLabel() 函數獲取下一個標籤的索引。這將用於表示 do-while 循環的起始位置。

int doEnd = nextLabel();
宣告並初始化 doEnd 變數，並使用 nextLabel() 函數獲取另一個標籤的索引。這將用於表示 do-while 循環的結束位置。

emit("(L%d)\n", doBegin);
發出一個標籤 L，對應於 doBegin，表示 do-while 循環的起始位置。這會在生成的代碼中插入一行，如 (L0)。

skip("do");
跳過並檢查當前的 token 是否為 "do"。如果是，則消耗它並移到下一個 token；如果不是，則報錯並終止程序。

STMT();
解析並生成 do-while 循環中的語句。STMT 函數將處理 do 循環內部的單個語句或語句塊。

skip("while");
跳過並檢查當前的 token 是否為 "while"。如果是，則消耗它並移到下一個 token；如果不是，則報錯並終止程序。

skip("(");
跳過並檢查當前的 token 是否為 "("。如果是，則消耗它並移到下一個 token；如果不是，則報錯並終止程序。

int e = E();
解析 while 條件中的表達式，並返回臨時變數的索引（表示條件表達式的值）。E 函數處理這個表達式的解析和生成。

emit("if t%d goto L%d\n", e, doBegin);
發出一個條件跳轉指令。這行生成的代碼檢查條件變數 t 的值，如果條件為真（即 t[e] 為非零），則跳轉到 do-while 循環的起始位置 L[doBegin]，從而實現循環。

skip(")");
跳過並檢查當前的 token 是否為 ")"。如果是，則消耗它並移到下一個 token；如果不是，則報錯並終止程序。

skip(";");
跳過並檢查當前的 token 是否為 ";"。如果是，則消耗它並移到下一個 token；如果不是，則報錯並終止程序。

emit("(L%d)\n", doEnd);
發出一個標籤 L，對應於 doEnd，表示 do-while 循環的結束位置。這會在生成的代碼中插入一行，如 (L1)。這行標籤在跳出循環後使用。


執行
vicky@LAPTOP-9KHSH2NS:/mnt/c/systemdesign/sp/02$ make clean
rm -f *.o *.exe
vicky@LAPTOP-9KHSH2NS:/mnt/c/systemdesign/sp/02$ rm -f *.o *.exe
vicky@LAPTOP-9KHSH2NS:/mnt/c/systemdesign/sp/02$ make
gcc -std=c99 -O0 lexer.c compiler.c main.c -o compiler
vicky@LAPTOP-9KHSH2NS:/mnt/c/systemdesign/sp/02$ gcc -std=c99 -O0 lexer.c compiler.c main.c -o compiler
vicky@LAPTOP-9KHSH2NS:/mnt/c/systemdesign/sp/02$ ./compiler test/while.c
i = 1;
while (i<10) i = i + 1;

========== lex ==============
token=i
token==
token=1
token=;
token=while
token=(
token=i
token=<
token=10
token=)
token=i
token==
token=i
token=+
token=1
token=;
========== dump ==============
0:i
1:=
2:1
3:;
4:while
5:(
6:i
7:<
8:10
9:)
10:i
11:=
12:i
13:+
14:1
15:;
============ parse =============
t0 = 1
i = t0
(L0)
t1 = i
t2 = 10
t3 = t1 < t2
if not T3 goto L1
t4 = i
t5 = 1
t6 = t4 + t5
i = t6
goto L0
(L1)