# <center>c++学习笔记</centert>

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
- vector<T>(向量容器)是一个长度可变的序列，用来存放 T 类型的对象。必要时，可以自动增加容量，但只能在序列的末尾高效地增加或删除元素。
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
- vector删除元素(需要引入头文件#include <algorithm>)
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

