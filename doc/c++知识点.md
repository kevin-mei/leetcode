1. 虚函数的实现方式?
   通过虚函数表和虚函数表指针实现， 虚函数表一般放在程序的只读段，windows放在常量区，linux放在只读数据段中(rodata)； 虚函数本身位于代码段（.text）; 虚函数表指针是带有虚函数的类实例化（执行构造函数时）时，会初始化虚函数表指针，虚函数表指针和类的实例对象相关；

   **基类的析构函数**一般要写成虚函数，当声明的是父类对象，但是new的是子类对象，这时候delete是，就会指向子类的析构函数，而子类的析构函数有自动调用基类的析构函数，这样整个子类对象就会完全被释放；

   如果析构函数没声明成虚函数，那这个对象delete时，就会造成内存泄露；

   构造函数不能定义为虚函数； 再构造函数中可以调用虚函数，不过此时正在调用的正在构造的类中的虚函数，而子类的虚函数还没有构造好；

   构造时：先父类，在子类
   删除时：先子类，再父类；

2. 类对象的存储空间：是非静态成员的数据类型大小之和，编译器加入的额外成员变量（如指向虚函数表的指针）。

3. 内联函数和宏定义的区别
   内联函数和普通函数相比，可以加快程序的运行速度，因为不需要中断调用（不用创建新的函数堆栈，减少保存期存器，返回时恢复，拷贝实参等）
   lambda表达式，可以看做未命名的内联函数，[]可以捕获局部变量列表，为空表示不需要使用所在函数的局部变量
   `auto compare=[](pair<int, int> &a, pair<int, int> &b){ return a.first < b.first; };`
    - 内联函数在编译时展开，宏在预编译时展开
    - 内联函数直接嵌入到目标代码中，宏是简单的做文本替换
    - 内联函数有类型检测、语法判断等功能，而宏没有
    - 内联函数是函数，宏不是
    - 宏定义时要注意书写（参数要括起来）否则容易出现歧义，内联函数不会产生歧义
    - 内联函数代码是被放到符号表中，使用时像宏一样展开，没有调用的开销，效率很高；
4. 如何用代码判断大小端存储
   可以使用强制类型转换，
   ```c
   int a = 0x1234; char c = (char)(a);
   if(c == 0x12) // 说明低地址存放的高地址的数据  大端存储
   else 
    //小端存储
   ```
5. c++的struct和class的区别
   两个都可以拥有成员函数，公有和私有部分
   任何可以用class完成的共奏，同样可以用struct完成

struct 的默认成员函数是公有的；class的默认成员函数是私有的；

c++和c struct的区别
c语言中：struct是用户自定义数据类型(UDT)；c++中struct是抽象数据类型(ADT)，
支持成员函数的定义，c++中的struct能继承，能实现多态；

c中的struct是没有权限设置的，且struct中只能是一些遍历的集合体，可以封装数据却不可以隐藏数据，
而且成员不可以是函数；

c中的struct声明后，使用的时候，需要在结构标记前加上struct，才能做结构类型明(除：typedef struct class{})；

柔性数组  是否可以考虑用protobuf替换
```c++
// 定长缓冲区
struct max_buffer
{
   int len;
   char data[MAX_LENGTH];
};
```
sizeof(max_buffer) > sizeof(int) + sizeof(char) *MAX_LENGTH;
为了防止数据溢出的情况，data的长度一般会设置得足够大，但也正因为这样，才导致数组的冗余；

避免数据的浪费：
```c++
struct point_buffer
{
    int   len;
    char  *data;
};
// 数据
// 内存申请：
if ((p_buffer = (struct point_buffer *)malloc(sizeof(struct point_buffer))) != NULL)
{
    p_buffer->len = CUR_LENGTH;
    if ((p_buffer->data = (char *)malloc(sizeof(char) * CUR_LENGTH)) != NULL)
    {
        memcpy(p_buffer->data, "point_buffer test", CUR_LENGTH);
        printf("%d, %s\n", p_buffer->len, p_buffer->data);
    }
}
// 内存释放
free(p_buffer->data);
free(p_buffer);
p_buffer = NULL;
```
虽然这样能够节约内存，但是两次分配的内存是不连续的，需要分别对其进行管理

柔性数组，柔性数组成员(flexible array member)也叫伸缩性数组成员，它必须是数组的最后一个成员；

```c++
struct test
{
   short len;// 必须至少有一个其它成员
   char arr[];// 柔性数组必须是结构体的最后一个成员(也可以是其它类型，int,double)
};
```
