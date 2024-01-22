# Time log

- 12:05:45 连接两命令的 pipe 实现
- 12:27:38 `pipe -> stdin -> execvp -> stdout -> pipe` 失败，文件描述符指向内容泄露(详细原因需要学习操作系统后了解)
- 12:39:06 How to redirect `STDOUT->pipe`?
- 15:35:48 Pipe 和局部变量地址空间区别搞清楚了
- 16:15:07 成功实现多级 pipe!
- 20:49:06 网络编程复习，小的互相发送程序实现
- 21:35:52 Client和Server封装成类，准备实现多线程
- 22:26:12 多线程好像搞不了？不理解，可能有些地方弄错了，明天先用单进程+fork()试试，然后再用多线程

# Minor-tasks

- [x] 实现一个两个命令的 pipe
- [x] 测试 pipe -> stdin -> execvp -> stdout -> pipe 过程
- [x] 将两个命令的 pipe 泛化，实现一个多段 command 的 pipe
- [x] 完善 CIT5950 HW4
- [x] 网络编程部分复习
- [x] 写个小的互相发送 Socket 程序练手

# Summary

- 原来 Pipe 和局部变量不一样，它不会随着循环作用域的退出而消失。局部变量位于进程虚拟地址空间里，位于栈上。但是 Pipe 位于 kernel 的虚拟地址空间里。因此当循环退出的时候，局部变量会消失，但是 Pipe 不会。因此如果下一次要用 Pipe，需要把 pipe 读/写端的 fd 号保存一下。
- 要变得比那个学长厉害得多！要做自己的小英雄！
- 效率不算高，明天继续加油！