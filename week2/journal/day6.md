# Time log

- 08:18:49 起床，换衣服，洗脸刷牙
- 08:35:02 手机充了会儿电，现在出发去买早餐
- 10:20:04 买了早饭，吃完了早饭，听了会儿音乐，洗了筷子，电脑卡死了
- 10:28:08 电脑卡死修复
- 11:11:23 修改了一下构造函数的参数，将其改为`std::initializer_list<T>`
- 12:27:53 吃了午饭，洗了碗，解决了`main cannot find reference to ipb::named_vector<int>::named_vector(xxx)和ipb::named_vector<int>::empty()`的问题，是函数模板相关的原因，原因将在后面学习 C++ 模板后进行总结；项目构建成功，开始实现函数本身。
- 12:35:43 实现了除`reserve()`和`resize()`外的其他函数
- 13:01:09 将`vector`的`data`域从`std::initialize_list<T>`改为`T* data`，因为`std::initialize_list<T>`是用来初始化的，不是用来存数据的。
- 13:25:52 实现了除`reserve()`和`resize()`外的其他函数
- 14:09:21 实现了包括`reserve()和resize()`在内的所有函数，`hw4 task1`完成
- 14:19:28 安装`Catch2`，一个`C++`单元测试框架(暂停)
- 15:16:27 去穿条毛裤，太冷了
- 15:32:42 实现了`accumulate(),count(),all_even(),clamp()`，有点困了，要去躺一会儿
- 17:27:26 没睡好，头有点疼
- 17:55:30 实现了除`rotate()`外所有函数
- 18:05:03 安装`Catch2`，修改了一下`CMakeLists.txt`，显示缺少`boost`库
- 18:16:14 使用`sudo apt search boost`，搜索到了很多`boost`相关库，安装`libboost-all-dev`
- 18:22:34 `Test`中给的测试是基于`Catch2`了，而现在`Catch`已经更新到了`v3`，因此需要根据[Catch 文档](https://github.com/catchorg/Catch2/blob/devel/docs/migrate-v2-to-v3.md#top)做一些调整
- 18:37:57 下载了`catch_amalgamated.hpp`和`catch_amalgamated.cpp`，并将所有的`catch/catch2.hpp`替换成了`catch_amalgamated.hpp`，开始编译测试
- 18:49:29 所有算法实现完成，`vscode ssh`又连不上了，呜呜呜
- 19:08:56 `hw4`完成，作业的测试基本上就是希望你在自己的实现里面套个`std::vector`，就不管他了，后期看《STL 源码剖析》，学一下标准的`std::vector`实现
- 21:27:15 用`pandas`弄完了时间统计
- 22:05:38 学不动了，准备洗个澡

# Minor-tasks

- [x] 帮我爸把表格的事情完成

# Summary

今天效率不错，还可以再高点！
