# design-patterns
design patterns with c++

c++ version of head first design patterns

thanks to https://refactoringguru.cn/design-patterns

## 工厂方法模式

网上有很多介绍工厂方法模式的文章，大部分都是和各种生成实践联系在一起，但是个人看完之后大多似懂非懂，直到看到winter在知乎的回答才比较清楚：[工厂模式（factory  Method）的本质是什么？为什么引入工厂模式？](https://www.zhihu.com/question/42975862/answer/1244807350)

一句话概括的话就是，外面想要新建一个对象，但是不知道对象的具体类型，同时由于多态的存在，我们可以是用这些对象的共同的父类的某些方法。

问题是我们为什么不能直接调用具体对象的构造函数，同时复用这些对象的某些方法呢？如：./Creational/why_need_factory.cpp
