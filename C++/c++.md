# <center>c++学习笔记</centert>
[TOC]
### c++格式化输出：

- [参考网站](http://c.biancheng.net/view/275.html)
### c++参数传递
-  引用的规则： 
    - （1）引用被创建的同时必须被初始化（指针则可以在任何时候被初始化）。 
    - （2）不能有NULL引用，引用必须与合法的存储单元关联（指针则可以是NULL）。 
    - （3）一旦引用被初始化，就不能改变引用的关系（指针则可以随时改变所指的对象）。 

- 指针传递的实质：
指针传递参数本质上是值传递的方式，它所传递的是一个地址值。值传递过程中，被调函数的形式参数作为被调函数的局部变量处理，即在栈中开辟了内存空间以存放由主调函数放进来的实参的值，从而成为了实参的一个副本。值传递的特点是被调函数对形式参数的任何操作都是作为局部变量进行，不会影响主调函数的实参变量的值。（这里是在说实参指针本身的地址值不会变）如果理解不了大可跳过这段
- 指针传递和引用传递一般适用于：
函数内部修改参数并且希望改动影响调用者。对比指针/引用传递可以将改变由形参“传给”实参（实际上就是直接在实参的内存上修改，不像值传递将实参的值拷贝到另外的内存地址中才修改）。
另外一种用法是：当一个函数实际需要返回多个值，而只能显式返回一个值时，可以将另外需返回的变量以指针/引用传递给函数，这样在函数内部修改并且返回后，调用者可以拿到被修改过后的变量，也相当于一个隐式的返回值传递吧。

### String类：
* assign()函数
    * 使用 assign() 函数可以直接给字符串赋值。该函数既可以将整个字符串赋值给新串，也可以将字符串的子串赋值给新串。其在 basic_string 中的原型为：

    ```c++
    basic_string& assign (const E*s); //直接使用字符串赋值
    basic_string& assign (const E*s, size_type n);
    basic_string& assign (const basic_string & str, size_type pos, size_type n);
    //将str的子串赋值给调用串
    basic_string& assign (const basic_string& str);    //使用字符串的“引用”賦值
    basic_string& assign (size_type n, E c) ; //使用 n个重复字符賦值
    basic_string& assign (const_iterator first, const_iterator last);    //使用迭代器赋值
    ```c++
- insert()函数
    - insert () 函数的原型为：
    ```c++
    basic_string& insert (size_type p0 , const E * s); //插人 1 个字符至字符串 s 前面
    basic_string& insert (size_type p0 , const E * s, size_type n); // 将 s 的前 3 个字符插入p0 位置
    basic_string& insert (size_type p0, const basic_string& str);
    basic_string& insert (size_type p0, const basic_string& str,size_type pos, size_type n); //选取 str 的子串
    basic_string& insert (size_type p0, size_type n, E c); //在下标 p0 位置插入  n 个字符 c
    iterator insert (iterator it, E c); //在 it 位置插入字符 c
    void insert (iterator it, const_iterator first, const_iterator last); //在字符串前插入字符
    void insert (iterator it, size_type n, E c) ; //在 it 位置重复插入 n 个字符 c
    ```
- append 函数
    - append() 函数的原型为：
    ```c++
    basic_string& append (const E * s); //在原始字符串后面追加字符串s
    basic_string& append (const E * s, size_type n);//在原始字符串后面追加字符串 s 的前 n 个字符
    basic_string& append (const basic_string& str, size_type pos,size_type n);//在原始字符串后面追加字符串 s 的子串 s [ pos,…,pos +n -1]
    basic_string& append (const basic_string& str);
    basic_string& append (size_type n, E c); //追加 n 个重复字符
    basic_string& append (const_iterator first, const_iterator last); //使用迭代器追加
    ```
- find()函数和 rfind()
    -find() 函数的原型主要有以下 4 种：
    ```c++
    size_type find (value_type _Chr, size_type _Off = 0) const;
    //find()函数的第1个参数是被搜索的字符、第2个参数是在源串中开始搜索的下标位置
    size_type find (const value_type* _Ptr , size_type _Off = 0) const;
    //find()函数的第1个参数是被搜索的字符串，第2个参数是在源串中开始搜索的下标位置
    size_type find (const value_type* _Ptr, size_type _Off = 0, size_type _Count) const;
    //第1个参数是被搜索的字符串，第2个参数是源串中开始搜索的下标，第3个参数是关于第1个参数的字符个数，可能是 _Ptr 的所有字符数，也可能是 _Ptr 的子串宇符个数
    size_type find (const basic_string& _Str, size_type _Off = 0) const;
    //第1个参数是被搜索的字符串，第2参数是在源串中开始搜索的下标位置
    ```
    rfind() 函数的原型和find()函数的原型类似，参数情况也类似。只不过 rfind() 函数适用于实现逆向查找。


### STL序列式容器：
序列容器以线性序列的方式存储元素。它没有对元素进行排序，元素的顺序和存储它们的顺序相同。以下有5种标准的序列容器，每种容器都具有不同的特性：
- array<T,N>(数组容器)是一个长度固定的序列，有 N 个 T 类型的对象，不能增加或删除元素。
- vector<T>(向量容器)是一个长度可变的序列，用来存放 T 类型的对象。必要时，可以自动增加容量，但只能在序列的  末尾高效地增加或删除元素。
- deque<T>(双向队列容器)是一个长度可变的、可以自动增长的序列，在序列的两端都不能高效地增加或删除元素。
- list<T>(链表容器)是一个长度可变的、由 T 类型对象组成的序列，它以双向链表的形式组织元素，在这个序列的任何地方都可以高效地增加或删除元素。访问容器中任意元素的速度要比前三种容器慢，这是因为 list<T> 必须从第一个元素或最后一个元素开始访问，需要沿着链表移动，直到到达想要的元素。
- forward list<T>(正向链表容器)是一个长度可变的、由 T 类型对象组成的序列，它以单链表的形式组织元素，是一类比链表容器快、更节省内存的容器，但是它内部的元素只能从第一个元素开始访问。

- ![pic](http://c.biancheng.net/uploads/allimg/180911/2-1P911110REB.jpg)

#### (STL array)的用法
    模板实例的元素被内部存储在标准数组中。和标准数组相比，array 容器的额外幵销很小，但提供了两个优点：如果使用 at()，当用一个非法的索引访问数组元素时，能够被检测到，因为容器知道它有多少个元素，这也就意味着数组容器可以作为参数传给函数，而不再需要单独去指定数组元素的个数。

使用 array 容器类型时，需要在源文件中包含头文件 array。数组容器非常好用，这里有一个示例，展示了如何创建具有 100 个 double 型元素的 array<>:
```c++
std::array<double,100> data;
```
通过调用数组对象的成员函数 fill()，可以将所有元素设成给定值。
```c++
values.fill(3.1415926)
```
- c++ array元素的比较
    -可以用任何比较运算符比较两个数组容器，只要它们有相同的大小，保存的是相同类型的元素，而且这种类型的元素还要支持比较运算符。示例如下：
    ```c++
    std::array<double,4> these {1.0, 2.0, 3.0, 4.0};
    std::array<double,4> those {1.0, 2.0, 3.0, 4.0};
    std::array<double,4> them {1.0, 3.0, 3.0, 2.0};

    if (these == those) std::cout << "these and those are equal." << std::endl;
    if (those != them) std::cout << "those and them are not equal."<< std::endl;
    if (those < them) std::cout << "those are less than them."<< std::endl;
    if (them > those) std::cout << "them are greater than those." << std::endl;
    ```
    容器被逐元素地比较。对 ==,如果两个数组对应的元素都相等，会返回 true。对于 !=，两个数组中只要有一个元素不相等，就会返回 true。这也是字典中单词排序的根本方式，两个单词中相关联字母的不同决定了单词的顺序。这个代码片段中所有的比较运算都是 true。所以当它们执行时，会输出 4 条消息。

#### C++ vector的使用
    vector<T> 容器是包含 T 类型元素的序列容器，和 array<T，N> 容器相似，不同的是 vector<T> 容器的大小可以自动增长，从而可以包含任意数量的元素；因此类型参数 T 不再需要模板参数 N。只要元素个数超出 vector 当前容量，就会自动分配更多的空间。只能在容器尾部高效地删除或添加元素。
- 初始化：
    ```c++
    std::vector<double> values(20);
    ```
    x.size（）方法返回vector的大小。
- 遍历：
    ```c++
    for(auto& prime : primes)
        prime *= 2;
    ```
    - 通过调用reserve()方法来增加容器的容量。
    
    - 通过调用成员函数 resize() 可以改变容器大小，这也可能导致容量的增加。下面是 resize() 的几种用法：
    ```c++
    std::vector<int> values {1,2,3};
    values.resize (5);
    values.resize (7, 99);
    values.resize (6);
    ```
    第一个 resize() 调用会把元素的个数变为参数指定的值，所以会增加两个用默认值初始化的元素。如果添加了一个元素，导致超过当前容器的容景，容量会自动增加。

    第二个 resize() 调用将元素增加到第一个参数指定的个数，并用第二个参数初始化增加的新元素。第三个 resize() 凋用将容器大小设为 6，小于当前元素的个数。当需要减小容器的大小时，会移除多余的元素，这就好像重复调用了几次 pop_back() 函数。在本章的后面，会对此做一些解释。减少容器的大小不会影响容器的容量。

    vector 的成员函数 front() 和 back() 分別返回序列中第一个和最后一个元素的引用。
- vector添加（增加）元素

    - 可以通过使用容器对象的 push_back() 函数，在序列的末尾添加一个元素。
    ```c++
    std::vector<double> values;
    values.push_back(3.1415926);
    ```
    通过使用成员函数 emplace()，可以在 vector 序列中插入新的元素。对象会在容器中直接生成，而不是先单独生成对象，然后再把它作为参数传入。

    emplace() 的第一个参数是一个迭代器，它确定了对象生成的位置。对象会被插入到迭代器所指定元素的后面。第一个参数后的参数，都作为插入元素的构造函数的参数传入。
    ```c++
    std::vector<std::string> words {"first", "second"};
    // Inserts string(5,'A') as 2nd element
    auto iter = words.emplace(++std::begin(words),5,'A');
    //Inserts string ("$$$$") as 3rd element
    words.emplace(++iter, "$$$$");\
    ```
    这段代码执行后，vector 中的字符串对象如下:
    "first" "AAAAA" "$$$$" "second"
- vector删除元素(需要引入头文件algorithm)
    - 可以通过使用 vector 的成员函数 clear() 来删除所有的元素。
    ```c++
    //#include <algorithm>
    std::vector<int> data(100, 99);// Contains 100 elements initialized to 99
    data.clear(); // Remove all elements
    ```
    - 可以使用 vector 的成员函数 pop_back() 来删除容器尾部的元素
    ```c++
    std::vector<int> data(100, 99); // Contains 100 elements initialized to 99
    data.pop_back(); // Remove the last element
    ```
    可以使用成员函数 erase() 来删除容器中的一个或多个元素。如果只删除单个元素，那么只需要提供一个参数，
    ```c++
    auto iter = data.erase(std::begin(data)+1); //Delete the second element
    ```
    删除一个元素后，vector 的大小减 1；但容量不变。会返回一个迭代器，它指向被删除元素后的一个元素。这里的返回值和表达式 std::begin(data)+1 相关；如果移除了最后一个元素，会返回 std::end(data)。
- c++中sort的使用
    sort使用需要引入算法库（<algorithm>，如果要指定元素通过降序排列需要引入#include<functional>）
    - functional中指定greater<type>()和less<type>()来进行升序与降序的指定。
    ```c++
    sort(test.begin(),test.end(),greater<>());//对vector进行升序排序
    sort(test.begin(),test.end(),less<>());//对vector进行降序排序
    ```
#### C++ deque使用、创建及初始化详解

```
deque<T>，一个定义在 deque 头文件中的容器模板，可以生成包含 T 类型元素的容器，它以双端队列的形式组织元素。可以在容器的头部和尾部高效地添加或删除对象，这是它相对于 vector 容器的优势。当需要这种功能时，可以选择这种类型的容器。(队列)
```
- 生成 deque 容器
    ```c++
    std::deque<int> a_deque;
    std::deque<int> my_deque(10);  //指定大小
    ```
    ![pic](http://c.biancheng.net/uploads/allimg/180912/2-1P912112354246.jpg)
    deque 容器也有拷贝构造函数，可以生成现有容器的副本
    ```c++
    std::deque<std::string> words_copy { words };// Makes a copy of the words container
    ```
    可以用下标运算符来访问元素，但是索引并没有进行边界检查。为了用进行边界检查的索引来访问元素，可以选择使用成员函数 at(),如果数据超出索引会抛出outofrange（）异常。
- deque添加和删除元素

    + deque 也有成员函数 push_front() 和 pop_front()，可以在序列头部执行相似的操作。

- deque修改（替换、更改）元素
    - deque 的成员函数 assign() 可以替换现有的所有元素。它有三个重版版本；替换的新内容可以是由初始化列表指定的元素，也可以是由迭代器指定的一段元素，或是一个特定对象的多个副本。

    assign() 函数只需要输入迭代器，因此可以使用任何类别的迭代器。
    ```c++
    std::deque<std::string> words {"one", "two", "three", "four"};
    auto init_list = {std::string{"seven"}, std::string{ "eight"}, std::string{"nine"}};
    words.assign(init_list);
    //或者
    words.assign({"seven”，"eight","nine"});
    words.assign(8,"eight"); //Assign eight instances of string("eight")将eight替换8次
    ```
    下面是一个使用 deque 容器的完整示例：
    ```c++
    // Using a deque container
    #include <iostream> // For standard streams
    #include <algorithm> // For copy()
    #include <deque> // For deque container
    #include <string> // For string classes
    #include <iterator> // For front_insert_iterator & stream iterators

    using std::string;

    int main()
    {
        std::deque<string> names;
        std::cout << "Enter first names separated by spaces. Enter Ctrl+Z on a new line to end:\n";
        std::copy(std::istream_iterator < string > {std::cin}, std::istream_iterator < string > {}, std::front_inserter(names));
        std::cout << "\nIn reverse order, the names you entered are:\n";
        std::copy(std::begin(names), std::end(names), std::ostream_iterator < string > {std::cout, "  "});
        std::cout << std::endl;
    }
    /*
    该程序读入几个任意长度的字符串，然后把它们存储在 names 容器中。copy() 算法将从 istream_iterator<string> 获取到的序列，输入到 names 容器的 front_insert_itemtor 中，这个迭代器是由函数 front_inserter() 返回的。

    copy() 的第一个参数是用来输入的开始迭代器，第二个参数是对应的结束迭代器。当使用键盘输入 Ctrl+Z 时，输入迭代器会对应为结束迭代器；如果是从文件流中读取数据，当读到 EOF 时，也会产生一个结束迭代器。因为 deque 容器有成员函数 push_front()，可以用来在序列的头部添加元素，所以我们这里可以使用 front_insert_iterator； front_insert_iterator 通过调用 push_front()在容器中添加元素，因此它适用于有成员函数 push_front() 的任何容器。

    输出也是由 copy() 算法生成的。前两个参数是用来指定元素范围的迭代器，这些元素被复制到第三个参数所指定的位置。因为前两个参数正好是 deque 容器的开始和结束迭代器，因此会复制 deque 容器的全部元素。目的地是一个接收字符串对象的 ostream_iterator，它会将这些字符串对象写入标准输出流。*/
    ```
#### list(STL list)使用、创建和初始化

- list 容器具有一些 vector 和 deque 容器所不具备的优势，它可以在常规时间内，在序列已知的任何位置插入或删除元素。这是我们使用 list，而不使用 vector 或 deque 容器的主要原因。list 的缺点是无法通过位置来直接访问序列中的元素，也就是说，不能索引元素。为了访问 list 内部的一个元素，必须一个一个地遍历元素，通常从第一个元素或最后一个元素开始遍历。
![pic](http://c.biancheng.net/uploads/allimg/180912/2-1P912134314345.jpg)
- list 容器的使用、创建和初始化
    ```c++
    std::list<std::string> words;//未指定大小与初始值
    std::list<std::string> sayings {20}; // A list of 20 empty strings
    std::list<double> values(50, 3.14159265);//初始化一定数量的相同元素
    ```
    list容器可以使用拷贝构造函数来初始化。
    ```c++
    std::list<double> save_values {values}; // Duplicate of values
    ```
- list（STL list）增加和插入元素
    - 可以使用 list 容器的成员函数 push_front() 在它的头部添加一个元素。调用 push_back() 可以在 list 容器的末尾添加一个元素。
    
        成员函数 emplace_front() 和 emplace_back() 可以做得更好，他们将它们消除了 pushJfront() 和 push_back() 不得不执行的右值移动运算。（creat ！= add）
    ```c++
    std::list<std::string> names { "Jane", "Jim", "Jules", "Janet"};
    names.push_front("Ian"); // Add string ("Ian") to the front of the list
    names.push_back("Kitty"); // Append string ("Kitty") to the end of the list
    
    names.emplace_front("Ian");//Create string ("Ian") in place at the front of the list
    names.emplace_back("Kitty");// Create string ("Kitty") in place at the end of the list
    ```
    1) 可以在迭代器指定的位置插入一个新的元素：
    ```c++
    std::list<int> data(10, 55); // List of 10 elements with value 55
    data.insert(++begin(data), 66); // Insert 66 as the second element
    ```
    insert() 的第一个参数是一个指定插入点的迭代器，第二个参数是被插入的元素。begin() 返回的双向迭代器自增后，指向第二个元素。上面的语句执行完毕后，list 容器的内容如下：
    55 66 55 55 55 55 55 55 55 55 55

        list 容器现在包含 11 个元素。插入元素不必移动现有的元素。生成新元素后，这个过程需要将 4 个指针重新设为适当的值。第一个元素的 next 指针指向新的元素，原来的第二个元素的 pre 指针也指向新的元素。新元素的 pre 指针指向第一个元素，next 指针指向序列之前的第二个元素。和 vector、deque 容器的插入过程相比，这个要快很多，并且无论在哪里插入元素，花费的时间都相同。

    2) 可以在给定位置插入几个相同元素的副本：
    ```c++
    auto iter = begin(data);
    std::advance(iter, 9); // Increase iter by 9
    data.insert(iter, 3, 88);// Insert 3 copies of 88 starting at the 10th
    ```
    iter 是 list<int>::iterator 类型。insert() 函数的第一个参数是用来指定插入位置的迭代器，第二个参数是被插入元素的个数，第三个参数是被重复插入的元素。为了得到第 10 个元素，可以使用定义在 iterator 头文件中的全局函数 advance()，将迭代器增加 9。只能增加或减小双向迭代器。因为迭代器不能直接加 9，所以 advance() 会在循环中自增迭代器。

    执行完上面的代码后，list 容器的内容如下：
    55 66 55 55 55 55 55 55 55 88 88 88 55 55

    3) 有三个函数可以在 list 容器中直接构造元素：
    
        emplace() 在迭代器指定的位置构造一个元素；emplace_front() 在 list 的第一个元素之前构造元素；emplace_back() 在 list 的尾部元素之后构造元素。
        ```c++
        std::list<std:: string> names {"Jane", "Jim", "Jules", "Janet"};
        names.emplace_back("Ann");
        std:: string name ("Alan");
        names.emplace_back(std::move(name));
        names.emplace_front("Hugo");
        names.emplace(++begin(names), "Hannah");
        ```
        第 4 行代码用 std::move() 函数将 name 的右值引用传入 emplace_back() 函数。这个操作执行后，names 变为空，因为它的内容已经被移到 list 中。执行完这些语句后，names 中的内容如下：


        "Hugo” "Hannah" "Jane" "Jim" "Jules" "Janet" "Ann" "Alan"
- list(STL list)删除元素
    - list 容器的成员函数 remove() 则移除和参数匹配的元素。
    ```c++
    std::list<int> numbers { 2, 5, 2, 3, 6, 7, 8, 2, 9};
    numbers.remove(2); // List is now 5 3 6 7 8 9
    //移除所有2.
    ```
    -  remove_if() 期望传入一个一元断言作为参数。一元断言接受一个和元素同类型的参数或引用，返回一个布尔值。断言返回 true 的所有元素都会被移除。例如：
    ```c++
    numbers.remove_if([](int n){return n%2 == 0;});// Remove even numbers. Result 5 3 7 9 "此处使用lambda表达式"
    ```
    - 成员函数 unique() 非常有意思，它可以移除连续的重复元素，只留下其中的第一个。
    ```c++
    std::list<std::string> words { "one", "two", "two", "two","three", "four", "four"};
    words.unique () ; // Now contains "one" "two" "three" "four"
    ```
- List排序
    - ist 模板定义了自己的 sort() 函数。sort() 有两个版本：无参 sort() 函数将所有元素升序排列。第二个版本的 sort() 接受一个函数对象或 lambda 表达式作为参数，这两种参数都定义一个断言用来比较两个元素。

        假设我们想对 names 中的元素进行排序，但是不想使用字符串对象标准的 std::greater<> 来比较，而是想将相同初始字符的字符串按长度排序。可以如下所示定义一个类：
        ```c++
            // Order strings by length when the initial letters are the same
        class my_greater
        {
            public:
            bool operator () (const std::strings s1, const std::strings s2)
            {
                if (s1[0] == s2 [0])
                    return si.length() > s2.length();
                else
                    return s1 > s2;
            }
        };
        names.sort(my_greater()); // Sort using my_greater
        ```
        lambda表达式
        ```c++
        names.sort([](const std::strings s1, const std::strings s2)
        {
            if (s1[0] == s2[0])
                return s1.length() > s2.length();
            else
                return s1 > s2;
        });
        ```
- 元素合并
    list 的成员函数 merge() 以另一个具有相同类型元素的 list 容器作为参数。两个容器中的元素都必须是升序。参数 list 容器中的元素会被合并到当前的 list 容器中。例如：
    ```c++
    std::list<int> my_values {2, 4, 6, 14};
    std::list<int> your_values{ -2, 1, 7, 10};
    my_values.merge (your_values);//my_values contains: -2 1 2 4 6 7 10 14
    your_values.empty(); // Returns true
    ```
    元素从 your_values 转移到 my_values，因此，在执行完这个操作后，your_values 中就没有元素了。改变每个 list 节点的指针，在适当的位置将它们和当前容器的元素链接起来，这样就实现了元素的转移。list 节点在内存中的位置不会改变；只有链接它们的指针变了。在合并的过程中，两个容器中的元素使用 operator()() 进行比较。

#### forward_list用法详解


forward_list 的单向链接性也意味着它会有一些其他的特性：
无法使用反向迭代器。只能从它得到const或non-const前向迭代器，这些迭代器都不能解引用，只能自增；
没有可以返回最后一个元素引用的成员函数back();只有成员函数front();
因为只能通过自增前面元素的迭代器来到达序列的终点，所以push_back()、pop_back()、emplace_back()也无法使用。
- 单链表的size
    forward_list 容器的构造函数的使用方式和 list 容器相同。forward_list 的迭代器都是前向迭代器。它没有成员函数 size()，因此不能用一个前向迭代器减去另一个前向迭代器，但是可以通过使用定义在头文件 iterator 中的 distance() 函数来得到元素的个数。
    ```c++
    std::forward_list<std::string> my_words {"three", "six", "eight"};
    auto count = std::distance(std::begin(my_words),std::end(my_words));
    // Result is 3
    ```
#### stack(STL stack)用法详解
stack<T>容器适配器中的数据是以 LIFO 的方式组织的，这和自助餐馆中堆叠的盘子、箱子中的一堆书类似。图 1 展示了一个理论上的 stack 容器及其一些基本操作。只能访问 stack 顶部的元素；只有在移除 stack 顶部的元素后，才能访问下方的元素。

- stack的创建
    ```c++
    std::stack<std::string> words;
    ```
    stack 容器适配器的模板有两个参数。第一个参数是存储对象的类型，第二个参数是底层容器的类型。stack<T> 的底层容器默认是 deque<T> 容器，因此模板类型其实是 stack<typename T, typename Container=deque<T>>。通过指定第二个模板类型参数，可以使用任意类型的底层容器，只要它们支持 back()、push_back()、pop_back()、empty()、size() 这些操作。
    ```c++
    std::stack<std::string,std::list<std::string>> fruit;//使用list容器来进行栈的构建
    ```
- stack的初始化
    ```c++
    std::stack<double,std::list<double>> my_stack (values);
    ```

- 堆栈操作
    - top()：返回一个栈顶元素的引用，类型为 T&。如果栈为空，返回值未定义。
    - push(const T& obj)：可以将对象副本压入栈顶。这是通过调用底层容器的 push_back() 函数完成的。
    - push(T&& obj)：以移动对象的方式将对象压入栈顶。这是通过调用底层容器的有右值引用参数的 push_back() 函数完成的。
    - pop()：弹出栈顶元素。
    - size()：返回栈中元素的个数。
    - empty()：在栈中没有元素的情况下返回 true。
    - emplace()：用传入的参数调用构造函数，在栈顶生成对象。
    - swap(stack<T> & other_stack)：将当前栈中的元素和参数中的元素交换。参数所包含元素的类型必须和当前栈的相同。对于 stack 对象有一个特例化的全局函数 swap() 可以使用。
#### queue(STL queue)用法
许多程序都使用了 queue 容器。queue 容器可以用来表示超市的结账队列或服务器上等待执行的数据库事务队列。对于任何需要用 FIFO 准则处理的序列来说，使用 queue 容器适配器都是好的选择
- 创建及初始化
```c++
std::queue<std::string> words;
std::queue<std::string, std::list<std::string>>words;//使用其他模型初始化队列
//底层容器必须提供这些操作：front()、back()、push_back()、pop_front()、empty() 和 size()。
```
- queue的操作

- front()：返回 queue 中第一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
- back()：返回 queue 中最后一个元素的引用。如果 queue 是常量，就返回一个常引用；如果 queue 为空，返回值是未定义的。
- push(const T& obj)：在 queue 的尾部添加一个元素的副本。这是通过调用底层容器的成员函数 push_back() 来完成的。
- push(T&& obj)：以移动的方式在 queue 的尾部添加元素。这是通过调用底层容器的具有右值引用参数的成员函数 push_back() 来完成的。
- pop()：删除 queue 中的第一个元素。
- size()：返回 queue 中元素的个数。
- empty()：如果 queue 中没有元素的话，返回 true。
- emplace()：用传给 emplace() 的参数调用 T 的构造函数，在 queue 的尾部生成对象。
- swap(queue<T> &other_q)：将当前 queue 中的元素和参数 queue 中的元素交换。它们需要包含相同类型的元素。也可以调用全局函数模板 swap() 来完成同样的操作。
#### priority_queue(STL priority_queue)(优先队列)用法
priority_queue 容器适配器定义了一个元素有序排列的队列。默认队列头部的元素优先级最高。因为它是一个队列，所以只能访问第一个元素，这也意味着优先级最高的元素总是第一个被处理。但是如何定义“优先级”完全取决于我们自己。如果一个优先级队列记录的是医院里等待接受急救的病人，那么病人病情的严重性就是优先级。如果队列元素是银行的借贷业务，那么借记可能会优先于信贷。
- priority_queue 模板有 3 个参数，其中两个有默认的参数；第一个参数是存储对象的类型，第二个参数是存储元素的底层容器，第三个参数是函数对象，它定义了一个用来决定元素顺序的断言。因此模板类型是：
```c++
template <typename T, typename Container=std::vector<T>, typename Compare=std::less<T>> class priority_queue
```
![pic](http://c.biancheng.net/uploads/allimg/180913/2-1P913134031947.jpg)
- 创建 priority_queue
```c++
std::priority_queue<std::string> words; 
std::string wrds[] { "one", "two", "three", "four"};
std::priority_queue<std::string> words { std::begin(wrds),std:: end(wrds)}; // "two" "three" "one" "four" 
```
优先级队列可以使用任何容器来保存元素，只要容器有成员函数 front()、push_back()、pop_back()、size()、empty()。
- priority_queue 操作
    - push(const T& obj)：将obj的副本放到容器的适当位置，这通常会包含一个排序操作。
    - push(T&& obj)：将obj放到容器的适当位置，这通常会包含一个排序操作。
    - emplace(T constructor a rgs...)：通过调用传入参数的构造函数，在序列的适当位置构造一个T对象。为了维持优先顺序，通常需要一个排序操作。
    - top()：返回优先级队列中第一个元素的引用。
    - pop()：移除第一个元素。
    - size()：返回队列中元素的个数。
    - empty()：如果队列为空的话，返回true。
    - swap(priority_queue<T>& other)：和参数的元素进行交换，所包含对象的类型必须相同。
### map容器（STL map容器）
- map<K，T>容器，保存的是 pair<const K，T> 类型的元素。pair<const K,T> 封装了一对键对象，键的类型是 K，对象的类型是 T。每个键都是唯一的，所以不允许有重复的键；但可以保存重复的对象，只要它们的键不同。map 容器中的元素都是有序的，元素在容器内的顺序是通过比较键确定的。默认使用 less<K> 对象比较。
- multimap<K，T> 容器和 map<K，T> 容器类似，也会对元素排序。它的键必须是可比较的，元素的顺序是通过比较键确定的。和 map<K，T> 不同的是，multimap<K，T> 允许使用重复的键。因此，一个 multimap 容器可以保存多个具有相同键值的 <const K,T> 元素。
- unordered_map<K，T> 中 pair< const K，T>元素的顺序并不是直接由键值确定的，而是由键值的哈希值决定的。哈希值是由一个叫作哈希的过程生成的整数，本章后面会解释这一点。unordered_map<K，T>不允许有重复的键。
- unordered_multimap<K,T> 也可以通过键值生成的哈希值来确定对象的位置，但它允许有重复的键。
#### map
map 类模板有 4 个类型参数，但一般只需要指定前两个模板参数的值。第 1 个是键的类型，第 2 个是所保存对象的类型，第 3 个和第 4 个模板参数分别定义了用来比较键的函数对象的类型以及为 map 分配内存的对象的类型。最后两个参数有默认值。例如我们可以这样定义：
```c++
std::map<std::string, size_t> people;//string 为键，size_t为值
std::map<std::string, size_t> people{{"Ann", 25}, {"Bill", 46},{"Jack", 32},{"Jill", 32}};
```
- map插入数据
插入单个数据：
```c++
std::map<std:: string,size_t> people {std::make_pair ("Ann",25),std::make_pair("Bill",46) , std::make_pair ("Jack",32), std::make_pair("Jill",32)};
auto pr = std::make_pair("Fred",22); //Create a pair element and insert it
auto ret_pr = people.insert(pr);
std::cout << ret_pr.first->first << " "<< ret_pr.first->second<< "" << std:: boolalpha <<ret_pr.second << "\n"; // Fred 22 true
```
可通过make_pair方法来创建key-value对象。通过insert()方法将数据插入到map容器中。
当需要遍历容器中的元素时需要使用map中的迭代器生成迭代器对象
```c++
map<T,P>::iterator it;
```
- map获取（访问）元素
at() 返回的是参数键对应的对象。如果这个键不存在，就会拋出 out_of_range 异常。
```c++
Name key;
try
{
    key = Name {"Dan”, ”Druff"};
    auto value = people.at(key);
    std:: cout << key << "is aged " << value << std:: endl;
    key = Name {"Don", "Druff"};
    value = people.at(key);
    std::cout << key << " is aged " << value << std::endl;
}
catch(const std::out_of_range& e)
{
    std::cerr << e.what() << '\n'<< key << " was not found." <<std::endl;
}
```
- map删除元素
map 的成员函数 erase() 可以移除键和参数匹配的元素，然后返回所移除元素的个数
```c++
std::map<std::string, size_t> people {{ "Fred", 45}, {"Joan", 33},{"Jill", 22}};
std::string name{"Joan"};
if(people.erase(name))
    std::cout << name << " was removed." << std::endl;
else
    std::cout << name << " was not found" << std::endl;
/*或者可以使用这种方式
std::map<std::string, size_t> people{ { "Fred", 45}, {"Joan", 33},{"Jill", 22} };
	//std::string name{ "Joan" };
	if (people.erase("Jill"))
		std::cout << " was removed." << std::endl;
	else
		std::cout << " was not found" << std::endl;
*/
```
#### C++ hash(STL hash)及其函数模板用法
如果在容器中保存对象及其关联的键，并且不用键来决定 键/对象 对的顺序，那就必须对键值釆用其他方式来确定元素在内存中的位置。如果使用像 string 这样的对象作为键，就会遇到一些问题，可能的变量的数目是巨大的。具有 10 个字符的字母字符串可能的个数是 2610。这个索引范围没有多大用处。我们需要一种机制来将它变为可接受的范围；而且理想情况下，这个机制可以为每个键生成唯一的值。这也是哈希需要做的事情之一。

哈希是用给定范围的基本类型的数据项，或者用像 string 这样的对象，生成整数值的过程。哈希产生的值叫作哈希值或哈希码，它们通常被用在容器中，用来确定表中对象的位置。像前面所说的那样，理想情况下，每个对象应该产生唯一的哈希值，但这一般是不可能的。当不同键值的个数大于可能的哈希值个数时，显然就会出现上面所说的这种情况，我们早晚会得到重复的哈希值。重复的哈希值也叫作碰撞。

哈希不仅可以在容器中保存对象，它也被应用到很多其他地方，例如密码和加密数据的安全系统中，密码识别有时也包含哈希。在系统中保存明文密码是有很大风险的。保存密码的哈希值要比保存明文密码更安全，更能防范黑客。得到哈希值的黑客需要将哈希值转换为对他们有用的原始密码，而这是一个不可能完成的任务。因此STL提供的对不同类型数据哈希的能力不仅可以用在关联容器上，也可以被用在更加广阔的场景中。

虽然理解容器的哈希机制没在必要，但是这能让我们对它们能做些什么有一个基本的了解。哈希算法有很多，但却没有可以通用的。为某个场景确定合适的哈希算法并不总是简单。通常都需要对数据分割后再计算。这可能是最简单的处理键的算法了，不管什么类型的键，都会作为数值处理。所以哈希值可能是表达式k%m产生的。
- 生成哈希值的函数
functional 头文件中定义了无序关联容器使用的特例化 hash<K> 模板。hash<K> 模板定义了可以从 K 类型的对象生成哈希值的函数对象的类型。hash<K> 实例的成员函数  operator()() 接受 K 类型的单个参数，然后返回 size_t 类型的哈希值。对于基本类型和指针类型，也定义了特例化的 hash<K> 模板。
hash函数必须满足一些具体的要求：
    - 不能拋出异常
    - 对于相等的键必须产生相等的哈希值
    - 对于不相等的键产生碰撞的可能性必须最小接近 size_t 最大值的倒数
- 生成哈希值的实例
```c++
std::hash<int> hash_int;// Function object to hash int
std::vector<int> n{-5, -2, 2, 5, 10};
std::transform(std::begin(n), std::end(n),std::ostream_iterator<size_t> (std:: cout," "),hash_int);
```
参考地址: [http://c.biancheng.net/view/526.html](http://c.biancheng.net/view/526.html)


## c++常见算法及使用
- find的使用
```c++
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	std::vector<int> numbers{ 5, 46, -5, -6, 23, 17, 5, 9, 6, 5 };
	int value{ 23 };
	auto iter = std::find(std::begin(numbers), std::end(numbers), value);
	if (iter != std::end(numbers))
		std::cout << value << " was found. \n";
}
```
- binary_search()算法(二分查找)
```c++
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	std::vector<int> numbers{ 5, 46, -5, -6, 23, 17, 5, 9, 6, 5 };
	sort(numbers.begin(), numbers.end());
	int x= binary_search(numbers.begin(), numbers.end(), 200);
	cout << x;

}
```
- string中的字符串查找
```c++
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	char *i = "you are so beautiful!";
	char  *find = "ok";
	if (strstr(i, find))
	{
		cout << "1"<<endl;
	}
	else
	{
		cout << "0" << endl;
	}

}
```
### C++格式化输出
在输出数据时，为简便起见，往往不指定输出的格式，由系统根据数据的类型采取默认的格式，但有时希望数据按指定的格式输出，如要求以十六进制或八进制形式 输出一个 整数，对输出的小数只保留两位小数等。有两种方法可以达到此目的。
- 1）使用控制符的方法；
- 2）使用流对象的有关成员函数。分别叙述如下。
```c++
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
 
int main()
{
	int a;
	cout << "input a:";
	cin >> a;
	cout << "dec:" << dec << a << endl; //以十进制形式输出整数
	cout << "hex:" << hex << a << endl; //以十六进制形式输出整数a
	cout << "oct:" << setbase(8) << a << endl; //以八进制形式输出整数a
	char *pt = "China"; //pt指向字符串"China"
	cout << setw(10) << pt << endl; //指定域宽为,输出字符串
	cout << setfill('*') << setw(10) << pt << endl; //指定域宽,输出字符串,空白处以'*'填充
	double pi = 22.0 / 7.0; //计算pi值
	//按指数形式输出,8位小数
	cout << setiosflags(ios::scientific) << setprecision(8);
	cout << "pi=" << pi << endl; //输出pi值
	cout << "pi=" << setprecision(4) << pi << endl; //改为位小数
	cout << "pi=" << setiosflags(ios::fixed) << pi << endl; //改为小数形式输出
	system("pause");
	return 0;
}
```
 cout << fixed << setprecision(4) << value << endl; // 加了fixed意味着是固定点方式显示，所以这里的精度指的是小数位，输出为12.3457
![pic](https://img-blog.csdn.net/20150707141709578)


| 格式标志 | 作用 |
| ---------- | :----------- |
| ios::left | 输出数据在本域宽范围内向左对齐 |  
| ios::right | 输出数据在本域宽范围内向右对齐 |  
| ios::internal| 数值的符号位在域宽内左对齐，数值右对齐，中间由填充字符填充 |  
| ios::dec | 设置整数的基数为10 |  
| ios::oct | 设置整数的基数为8 |  
| ios::hex | 设置整数的基数为16 |  
| ios::showbase | 强制输出整数的基数(八进制数以0打头，十六进制数以0x打头) |  
| ios::showpoint | 强制输出浮点数的小点和尾数0 |  
| ios::uppercase | 在以科学记数法格式E和以十六进制输出字母时以大写表示 |  
| ios::showpos | 对正数显示“+”号 |  
| ios::scientific | 浮点数以科学记数法格式输出 |  
| ios::fixed  | 浮点数以定点格式(小数形式)输出 |  
| ios::unitbuf | 每次输出之后刷新所有的流 |  
| ios::stdio  | 每次输出之后清除stdout, stderr |  