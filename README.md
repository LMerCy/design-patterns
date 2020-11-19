# design-patterns
design patterns with c++

c++ version of head first design patterns

thanks to https://refactoringguru.cn/design-patterns

## 策略模式

策略模式是在算法库中很常见的一种模式，主要是通过定义一簇算法，让他们之间可以互相替换，而且不会影响到客户使用，同时用户可以在使用过程中动态地去改变所使用的具体算法。所以在书中提供的Duck类中，真正体现策略模式的是Quack和Fly两个接口类,Duck可以通过setFly和setQuack方法动态的去改变具体是哪种飞行和叫的方式。同时Duck是通过一个具体的函数来调用各类算法的调用，当然前提就是这类算法的调用都继承了同一个方法（本质上是一种多态）。


## 工厂方法模式

网上有很多介绍工厂方法模式的文章，大部分都是和各种生成实践联系在一起，但是个人看完之后大多似懂非懂，直到看到winter在知乎的回答才比较清楚：[工厂模式（factory  Method）的本质是什么？为什么引入工厂模式？](https://www.zhihu.com/question/42975862/answer/1244807350)

一句话概括的话就是，外面想要新建一个对象，但是不知道对象的具体类型，同时由于多态的存在，我们可以是用这些对象的共同的父类的某些方法。

问题是我们为什么不能直接调用具体对象的构造函数，同时复用这些对象的某些方法呢？如：./Creational/why_need_factory.cpp

update