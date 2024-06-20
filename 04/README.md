參考同學和使用chatgpt
# race.c

因為沒有對 money 變數進行任何同步控制（如 mutex），所以多個執行緒同時存取 money 可能會交叉進行，導致計算結果不正確。這樣的不同步存取可能導致 money 的最終值與預期不符。

# norace.c

使用了 pthread_mutex_t mutex 來確保在每次對 money 進行修改時，只有一個執行緒可以進行操作，從而避免了競爭條件。

# 執行結果
```
vicky@LAPTOP-9KHSH2NS:/mnt/c/systemdesign/sp/04$ gcc -o race race.c -pthread
vicky@LAPTOP-9KHSH2NS:/mnt/c/systemdesign/sp/04$ ./race
money=-16928004

vicky@LAPTOP-9KHSH2NS:/mnt/c/systemdesign/sp/04$ gcc -o norace norace.c -pthread
vicky@LAPTOP-9KHSH2NS:/mnt/c/systemdesign/sp/04$ ./norace
money=1000
```