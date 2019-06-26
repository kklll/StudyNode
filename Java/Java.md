# <center>Java学习笔记</center>

# javastudy
## &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Java学习笔记

#### 注意
>【1】使用时应该注意文件名要与class名一样。（当类被public修饰时）  
>【2】main方法只能用public和static来修饰.  
>【3】面向对象的三个特征：继承、多态、封装。  
>【4】数据类型：基本类型和引用类型 基本类型：布尔类型、数值类型。引用类型：类、接口、数组。
对象：实例和数组  
>【5】\b退格符，\r回车符  
>【6】byte：1字节（内存八位），short：2，int：4，long：8，char：2，float：4，double：8  
#### 面向对象：  




>[1]static修饰的类方法属于类，不属于实例。  
>[2]方法可以作为返回值（this的使用）  
>[3]可变参数定义的方法：  
>``public static void main（int a，String[] ... books``)  
>或者：  
>``public static void main(int a, String[] books)``  
>下面这种方法在调用时为:  
>``main(5,new String []{"疯狂java讲义","小王子","谁的青春不迷茫"})``  
><font color=#ff0000 >推荐使用第一种。 </font>   
>类变量在建立类的
>
>
>
>
>
>
>
>
>时候就会初始化，与实例变量不同，实例变量实在创建实例的时候才分配内存，且实例变量随新建变量会在堆区储存，而类变量不会随对象的新建而变化。
>- 创建处于其包下的实例，在调用构造器的时候要指定包名，或者直接使用import语句  
 


## import
### java常用包:
* java.lang:Java的核心库文件String，Math，System，Thread。无需导入
* java.util：Java工具和接口框架等，Arrays，List，Set等。
* java.net：java网络编程的类和接口。
* java.io：输入输出。
* java.text：java格式化的类
* java.sql:包含了java进行JBDC编程的类
* java.awt：抽象窗口工具集（GUI）
* java.swing：swing图形用户界面编程的相关类。  
  
## extends  
### 继承
* 关键字：extends（扩展)
* java的子类不能得到父类的构造器
* super父类    


### 转型
* 父类变量可以引用任何一个子类对象,而子类变量不能引用父类对象 
* 向上转型可能会丢失子类中多余的方法，特征（向上转型为子类对象赋值给父类引用变量）
* 向下转型（将父类实例转换为子类类型），那么这个对象的实际类型必须是子类类型。  


### instanceof运算符  

* 前面的类与后面的类相同或者有继承关系  
* Object类是所有类的父类。
---
### 类的复用
1. 可以使用类的继承，子类继承父类的特性形成复用。
2. 将原来的父类组合到原来的子类，作为子类的一个组成部分  
```java    
public class test1 {
    static class Animal {
        private void beat() {
            System.out.println("心脏在跳动");
        }

        public void breath() {
            beat();
            System.out.println("正在呼吸");
        }
    }

    class Bird {
        private Animal a;

        public Bird(Animal a) {
            this.a = a;
        }

        public void breath() {
            a.breath();
        }

        public void fly() {
            System.out.println("我在天空飞!");
        }
    }

    public static void main(String[] args) {
        Animal a1=new Animal();
        a1.breath();
    }
}
```

### 包装类
----
-  功能：  

    	将基本变量类型转换为对象类型（装箱）
		将对象类型转换为基本变量类型（拆箱） 

- 进行两个封装类的实例比较比较复杂，因为类实例实际是引用类型，两个包装类指向同一个对象才会TRUE。
- int类型中系统向-128——127的数字计入缓存，不会出现上述现象。
- compare方法（所有包装类都具有的类），参数为两个比较值。以此来比较基本数据类型是否相同

### ==和equal方法


-  ==如果为基本类型变量则比较数值，引用类型的话比较地址
-  equal判断两个引用变量的值是否相等（所有引用变量都可以调用）。

- <font color=#8470FF >推荐使用第一种。 </font>

### final修饰符
-  final修饰符修饰的成员变量必须显式的初始值，初始化后其值不能改变。
-  java不允许直接访问final访问的成员变量，需要使用方法来访问。

### 抽象类
- 抽象类和抽象方法的不同点
   - 抽象类和方法用abstract修饰，抽象类不能被实例化，只能通过被其他子类继承来定义方法。
   - private和abstract不能同时使用。

## 接口
- 接口的定义使用关键字interface 接口名 extends 父接口1，父接口2···
- 接口内不能含有构造器和初始化定义模块。（允许抽象方法，类方法和默认方法，私有方法。）
* 接口描述类具有什么功能,而不给出每个功能的具体实现.
* 一个类可以实现多个接口
- 接口中定义默认方法需要用default来修饰
- 接口的功能可以用来定义常量，被其它类实现。
- 接口的实现使用implement关键字，格式为
   ```java
    [修饰符] class 类名 extends 父类 implement 接口1，2···
    {

    }
    ```
```JAVA
package dataandvar.test;
   public interface output{
       int max=50;
       void out();
       void getdata();
       default void print(String []msgs)
       {
           for (String msg:msgs) {
               System.out.println(msg);
           }
       }
       default void test(){
           System.out.println("默认的test方法");
       }
       static String staticTest(){
           return ("接口类的test方法");
       }
   }
```
```JAVA
package dataandvar;

import dataandvar.test.output;

public class DataType {
    public static void main(String[] args) {
        System.out.println(output.max);
        System.out.println(output.staticTest());
    }
}
```







### 接口与内部类
## 接口

* 接口描述类具有什么功能,而不给出每个功能的具体实现.
* 一个类可以实现多个接口

#### Comparable接口的实例

我们希望对Employee数组进行排序,调用`Arrays.sort()`方法

如果没有实现`Comparable`接口的话,sort会抛出一个异常:

```java
Employee employee = new Employee("Rick", 1, 7000);
Employee employee2 = new Employee("Rick", 1, 8000);
Employee[] employeeList = {employee2, employee};
Arrays.sort(employeeList);
System.out.println(Arrays.toString(employeeList));
```

```java
//异常信息:
Exception in thread "main" java.lang.ClassCastException: week01.extend.Employee cannot be cast to java.lang.Comparable
	at java.util.ComparableTimSort.countRunAndMakeAscending(ComparableTimSort.java:320)
	at java.util.ComparableTimSort.sort(ComparableTimSort.java:188)
	at java.util.Arrays.sort(Arrays.java:1246)
	at Main.main(Main.java:14)
```

所以我们需要实现`Comparable`接口,才能使用`sort`方法对数组排序.Comparable接口可以添加一个泛型参数

```java

public class Employee extends Person implements Comparable<Employee>{
    private int salary;

    public Employee() {
    }

    public Employee(String name, int sex, int salary) {
        super(name, sex);
        this.salary = salary;
    }

    @Override
    public String getDescription() {
        return super.getName() + " " + super.getSex() + " " + getSalary();
    }

    public int getSalary() {
        return salary;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "name='" + super.getName() + '\'' +
                ", sex=" + super.getSex() +
                ", salary=" + salary +
                '}' + '\n';
    }



    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true; //如果引用相同
        if (obj == null) return false; //如果比较的对象为null,一定不相等
        if (getClass()  != obj.getClass()) return false; //getClass获取对象的类.如果两个对象类都不相同,那么这两个对象肯定不相同
        //排除了前面的条件后,就可以开始判断这两个类的信息是否相同
        Employee other = (Employee) obj;
        return this.getName() == other.getName()
                && this.getSalary() == other.getSalary()
                && this.getSex() == other.getSex();
    }


    @Override
    public int compareTo(Employee o) {
        return Integer.compare(getSalary(), o.getSalary());
    }
}

```

Employee作为父类实现了Comparable接口之后,Manager作为子类,就可以重写父类的`compareTo()`方法,编写针对Manager的比较方式

#### 接口的特性

* 接口不是类,不能创建一个接口的**实例** ,比如 不允许`new Comparable<>();`
* 接口中的所有方法默认`public`
* 可以声明一个接口的 **变量**,这个变量必须 **引用实现了接口的类对象**.这是一种向上转型.
  * 比如`Comparable comparable = new Employee();`
* 接口也可以被扩展.一个接口可以继承另一个接口
* 接口中 **不能包含实例域或静态方法**,但是接口可以包含**常量** 
* 一个类只能拥有一个父类,但是可以实现多个接口

### 接口与内部类实战

我们首先创建一个`JDBCObject`类,这个类用于和数据库进行交互,实现`save` `update` `delete` `query`等方法

继承了`JDBCObject`的类,都可以调用save等方法和数据库交互,在数据库中存储信息.

```java

public class JDBCObject {
    public void save() {
        //假设save方法是异步进行网络请求
        Response response = JDBCHelper.getInstance().save(this); //保存对象,获取Response响应
        //响应不为空 并且响应码为201 (201在HTTP协议中表示请求成功并且服务器创建了新的资源)
        if (null != response && response.code() == 201) {
            if (response.code() == 201) {
                try {
                    //获取服务器的响应的内容(json是一种数据对象的字符串映射)
                    String json = response.body().string(); 
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

        } else {
            //save方法请求失败
        }
    }
}
```

```java
//Person继承JDBCObject
public abstract class Person extends JDBCObject{
    ...
}
```

我们希望在存储成功时获取服务器的响应信息,而在存储失败时获取异常信息,这时候就需要**利用接口实现回调**

#### 回调

例子:    你到一个商店买东西，刚好你要的东西没有货，于是你在店员那里留下了你的电话,我们继续去做自己的事情.过了几天店里有货了，店员就打了你的电话，然后你接到电话后就知道店里有了货.

在我们这里就是: 我们希望在服务器的数据库中存储一个对象, 在服务器的数据库中存储需要网络通信,会有一定的延迟,所以我们留下一个SaveListener接口(在子线程中执行存储过程). 当与服务器交互存储完毕后,子线程会通知主线程:我已经得到了服务器响应信息,你现在可以对这些信息进行处理了.

#### 创建接口

```java
public class JDBCDao {
    public interface SaveListener{
        void onSucceed(String response);

        void onFail(Exception e);
    }
}
```

#### 利用接口通知save方法调用成功或失败信息

* 添加接口参数
* 利用接口通知信息

```java
public class JDBCObject {
    public void save(JDBCDao.SaveListener listener) {
        Response response = JDBCHelper.getInstance().save(this); //获取Response响应
        //响应不为空 并且响应码为201 (201在HTTP协议中表示请求成功并且服务器创建了新的资源)
        if (null != response && response.code() == 201) {
            if (response.code() == 201) {
                try {
                    String json = response.body().string(); //数据对象的字符串映射
                    listener.onSucceed(json);
                } catch (IOException e) {
                    e.printStackTrace();
                    listener.onFail(e);
                }
            }
        } else {
            //save方法请求失败
            Exception e = new Exception("save failed!");
            listener.onFail(e);
        }
    }
}
```

#### 调用save方法

* 现在我们可以看到,save方法要求传入一个实现了`SaveListener`的类对象.我们有许多种方法可以实现

- 方法1: 每次调用save,创建一个类实现SaveListener方法,对响应信息进行处理.

* 特别麻烦

- 方法2: 内部类(定义在一个类中的类)

我们可以在Main中定义一个静态的`ResponseHandler`,实现SaveListener接口.

```java
public class Main {
    //内部类,声明为静态是因为在
    static class ResponseHandler implements JDBCDao.SaveListener {
        @Override
        public void onSucceed(String response) {
            System.out.println(response);
            System.out.println(response.toUpperCase());
        }

        @Override
        public void onFail(Exception e) {

        }
    }

    public static void main(String[] args) {
        Employee employee2 = new Employee("Rick2", 1, 8000);
        Manager manager = new Manager("SuperRick", 1, 7000, 5000);
        ResponseHandler responseHandler = new ResponseHandler();
        manager.save(responseHandler);

    }
}
```

内部类存在的问题:

* 创建的内部类只使用了很少次,用处不大

* 如果我们想在每次调用save方法对response做不同的处理的话,要在Main类中创建许多个不同的内部类

##### 这时可以使用方法内部类 (定义在方法中的类)

```java
public static void main(String[] args) {
        class ResponseHandler implements JDBCDao.SaveListener {
            @Override
            public void onSucceed(String response) {
                System.out.println(response);
                System.out.println(response.toUpperCase());
            }

            @Override
            public void onFail(Exception e) {

            }
        }

        Employee employee2 = new Employee("Rick2", 1, 8000);
        Manager manager = new Manager("SuperRick", 1, 7000, 5000);
        ResponseHandler responseHandler = new ResponseHandler();
        manager.save(responseHandler);
}
```

* 目前仍然存在的问题是,这个类的作用仅仅是用于实现SaveListener接口,它的作用仅仅用于在save方法中传递信息

  因此完全可以使用匿名内部类: **在创建对象的同时,定义类**

  * 匿名内部类没有类名,只有类的信息

```java
public static void main(String[] args) {
        Employee employee2 = new Employee("Rick2", 1, 8000);
        Manager manager = new Manager("SuperRick", 1, 7000, 5000);

        JDBCDao.SaveListener listener = new JDBCDao.SaveListener() {
            //private int x = 0; //也可以在匿名内部类中定义成员变量

            @Override
            public void onSucceed(String response) {
                System.out.println(response);
            }

            @Override
            public void onFail(Exception e) {

            }
        };

        manager.save(listener);
    }
```

##### 最简洁的方式:  用匿名内部类对象作为参数

```java
public static void main(String[] args) {
        Employee employee2 = new Employee("Rick2", 1, 8000);
        Manager manager = new Manager("SuperRick", 1, 7000, 5000);
        manager.save(new JDBCDao.SaveListener() {
            @Override
            public void onSucceed(String response) {
                System.out.println(response);
            }

            @Override
            public void onFail(Exception e) {

            }
        });
    }
```
#### this关键词的使用
* 当定义类中功能时，该函数内部要用到该函数的对象时使用this来表示这个对象。
* this语句用于构造函数之间互相调用。
* this语句只能在构造函数的第一行。
```java
package object.test1;

class Test {
    private String name;
    private int age;

    Test(String name) {
        this.name = name;
    }

    Test(String name, int age) {
        this(name);
        this.age=age;
    }
```

#### Java泛型
- 你可以写一个泛型方法，该方法在调用时可以接收不同类型的参数。根据传递给泛型方法的参数类型，编译器适当地处理每一个方法调用。

- 下面是定义泛型方法的规则：

+ 所有泛型方法声明都有一个类型参数声明部分（由尖括号分隔），该类型参数声明部分在方法返回类型之前（在下面例子中的<E>）。
+ 每一个类型参数声明部分包含一个或多个类型参数，参数间用逗号隔开。一个泛型参数，也被称为一个类型变量，是用于指定一个泛型类型名称的标识符。
+ 类型参数能被用来声明返回值类型，并且能作为泛型方法得到的实际参数类型的占位符。
+ 泛型方法体的声明和其他方法一样。注意类型参数只能代表引用型类型，不能是原始类型（像int,double,char的等）。

### JAVA多线程

使用多线程时的同步函数如果是静态的，那么其使用的锁为该类的字节码文件，如Person类则为：Person.class

```java
//单例设计模式
package Test;
//懒汉式，延迟加载
class Single {
    private static Single s = null;

    private Single() {
    }

    public static Single getInstance() {
        if (s == null) {
            synchronized (Single.class) {
                if (s == null)
                    s = new Single();
            }
        }
        return s;
    }
}
//饿汉式，此方法可以解决在多线程中出现的安全问题
class Single {
    private static final Single s = new Single();

    private Single() {
    }

    public static Single getInstance() {
        return s;
    }
}
```
多线程的实现方式：
- 1.`继承Thread类，复写run方法后start方法`
```java
public class test1 {

    public static void main(String[] args) {
        Test1 test1 = new Test1();
        Test1 test2 = new Test1();
        Thread thread = new Thread(test1);
        Thread thread2 = new Thread(test2);
        thread.start();
        thread2.run();
    }
}

class Test1 extends Thread {
    @Override
    public void run() {
        for (int i=0;i<=100;i++)
            System.out.println("x"+i);
    }
}

```
- 2.`实现Runnable接口来实现`
```java

public class test1 {

    public static void main(String[] args) {
        Test1 test1 = new Test1();
        Test1 test2 = new Test1();
        Thread thread = new Thread(test1);
        Thread thread2 = new Thread(test2);
        thread.start();
        thread2.run();
    }
}

class Test1 implements Runnable {

    @Override
    public void run() {
        for (int i = 0; i < 100; i++) {
            System.out.println(Thread.currentThread().getName()+"--"+"hehe");
        }
    }
}
```
- 生产者消费者问题（单个锁对象，没有用到新特性）
```java
//生产者消费者问题

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Resource { //商品
    private String name;
    private int count = 0;
    private boolean flag = false;
    private Lock lock = new ReentrantLock();  //先建立一个锁

    private Condition condition = lock.newCondition(); //建立锁对象

    public void set(String name) {
        lock.lock();
        try {
            while (flag)
                condition.await();
            this.name = name + "--" + count++;

            System.out.println(Thread.currentThread().getName() + "生产者" + this.name);
            flag = true;
            condition.signalAll();//唤醒所有线程
        } catch (Exception e) {
        } finally {
            lock.unlock();
        }
    }

    public void out() {//消费者
        lock.lock();
        try {
            while (!flag)
                condition.await();
            System.out.println(Thread.currentThread().getName() + "消费者" + this.name);
            flag = false;
            condition.signal();//
        } catch (Exception e) {
        } finally {
            lock.unlock();
        }
    }

}

class Producer implements Runnable {
    @Override
    public void run() {
        while (true) {
            res.set("+商品+");
        }
    }

    private Resource res;

    Producer(Resource res) {
        this.res = res;
    }
}

class Consumer implements Runnable {

    @Override
    public void run() {

        while (true) {
            res.out();
        }
    }

    private Resource res;

    Consumer(Resource res) {
        this.res = res;
    }
}

class Demo {
    public static void main(String[] args) {
        Resource r = new Resource();
        Producer pro = new Producer(r);
        Consumer con = new Consumer(r);
        Thread t1 = new Thread(pro);
        Thread t2 = new Thread(pro);
        Thread t4 = new Thread(con);
        Thread t5 = new Thread(con);
        t1.start();
        t2.start();
        t4.start();
        t5.start();
    }
}
```
- 生产者消费者问题（多个锁对象，用到新特性）
```java
//生产者消费者问题

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class Resource { //商品
    private String name;
    private int count = 0;
    private boolean flag = false;
    private Lock lock = new ReentrantLock();  //先建立一个锁

    private Condition condition_pro = lock.newCondition(); //建立锁对象
    private Condition condition_con = lock.newCondition(); //建立锁对象

    /*
    生产者的await和signal一个为等待一个为唤醒
    实现了唤醒对方
     */
    public void set(String name) {
        lock.lock();
        try {
            while (flag)
                condition_pro.await();
            this.name = name + "--" + count++;

            System.out.println(Thread.currentThread().getName() + "生产者" + this.name);
            flag = true;
            condition_con.signal();//唤醒所有线程
        } catch (Exception e) {
        } finally {
            lock.unlock();
        }
    }

    public void out() {//消费者
        lock.lock();
        try {
            while (!flag)
                condition_con.await();
            System.out.println(Thread.currentThread().getName() + "消费者" + this.name);
            flag = false;
            condition_pro.signal();//
        } catch (Exception e) {
        } finally {
            lock.unlock();
        }
    }

}

class Producer implements Runnable {
    @Override
    public void run() {
        while (true) {
            res.set("+商品+");
        }
    }

    private Resource res;

    Producer(Resource res) {
        this.res = res;
    }
}

class Consumer implements Runnable {

    @Override
    public void run() {

        while (true) {
            res.out();
        }
    }

    private Resource res;

    Consumer(Resource res) {
        this.res = res;
    }
}

class Demo {
    public static void main(String[] args) {
        Resource r = new Resource();
        Producer pro = new Producer(r);
        Consumer con = new Consumer(r);
        Thread t1 = new Thread(pro);
        Thread t2 = new Thread(pro);
        Thread t4 = new Thread(con);
        Thread t5 = new Thread(con);
        t1.start();
        t2.start();
        t4.start();
        t5.start();
    }
}
```

#### StingBuffer

```java 
class Test
{

    public static void main(String[] args) {
        StringBuffer sb=new StringBuffer("abcdef");
        sb.append(123);
        sb.append(true);
        sb.insert(1,"x");
        System.out.println(sb);

    }
}
```
缓冲区为一个容器，直接对容器进行操作

- 添加
    - append()
    - insert()

- 删除
```java
class Test
{

    public static void main(String[] args) {
        StringBuffer sb=new StringBuffer("abcdef");
        sb.append(123);
        sb.delete(1,3);//删除包含头不包含尾部
        System.out.println(sb);
        sb.deleteCharAt(0);//删除指定位置的字符
        System.out.println(sb);
    }
}
```
StingBuffer和StringBuilder的区别：
- StringBuffer是线层安全的，而StingBuilder是线程不安全的，但是StringBuilder的执行效率更高。
建议使用：StingBuilder

#### 基本数据类型包装类
```Java
public class test1 {
    public static void sop(String str){
        System.out.println(str);
    }
    public static void main(String[] args) {
        sop("int_max:  "+Integer.MAX_VALUE);
        sop("int :"+Integer.toString(34));
        int a=Integer.parseInt("32");
        System.out.println("123"+a);
        sop(Integer.toBinaryString(-6));//转换二进制
        sop(Integer.toHexString(60));//转换16进制
        //十进制转换为其他进制
        Integer.toBinaryString(1);
        Integer.toHexString(1);
        Integer.toOctalString(1);
        //其他进制转换为十进制
        int x=Integer.parseInt("110",8); //8进制的110转换为十进制
        int y=Integer.parseInt("110",10);//同理
        System.out.println(x);
        System.out.println(y);
        System.out.println(Integer.parseInt("3c",16));
    }
}

```
parseInt()//转换为INT
```Java
public class test1 {
    public static void sop(String str){
        System.out.println(str);
    }
    public static void main(String[] args) {
        Integer x=new Integer("123");
        Integer y=new Integer("123");
        sop("x==y:"+(x==y));       //两个对象，所以不同
        sop("x,,y  "+x.equals(y));  //覆写了equals方法，判断值是否相同
        Integer x=4;//也可以这样写，自动装箱
        x=x+2;//自动拆箱后自动装箱
    }
}
```

```Java
public class test1 {
    public static void sop(String str){
        System.out.println(str);
    }
    public static void main(String[] args) {
        Integer x=new Integer("123");
        Integer y=new Integer("123");
        sop("x==y:"+(x==y));       //两个对象，所以不同
        sop("x,,y  "+x.equals(y));  //覆写了equals方法，判断值是否相同
        Integer m=128;
        Integer n=128;
        sop("m==n:"+(m==n));
        //返回false
        Integer a=127;
        Integer b=127;
        sop("a==b:"+(a==b));
        //返回true，因为a和b指向了同一个Integer对象如果值在byte
        // 范围内，如果该值存在那么不开辟新的空间
    }
}
```
### 集合框架

集合用于存储对象，长度可变，可以存储不同类型的数据

#### collecttions Framework接口

方法摘要：

```java
import java.util.*;

public class test1 {

    public static void main(String[] args) {
        method_2();
    }
    public static void base_method() {
        ArrayList al = new ArrayList();
        al.add("java01");
        al.add("java02");
        al.add("java03");
        al.add("java04");
        al.add("java05");
        Object o = new Object();
        al.add(o);
        //获取集合长度
        System.out.println("size:" + al.size());
        //打印集合
        System.out.println(al);
        //删除元素
        al.remove("java02");
        System.out.println("size:" + al.size());
        //判断元素
        System.out.println("java03是否存在：" + al.contains("java03"));
        System.out.println("集合是否为空：" + al.isEmpty());
        System.out.println(al);
        al.clear();//清空集合
        System.out.println("size:" + al.size());
        System.out.println(al);
    }

    public static void method_2() {
        ArrayList al1 = new ArrayList();
        al1.add("java01");
        al1.add("java02");
        al1.add("java03");
        al1.add("java04");
        ArrayList al2 = new ArrayList();
        al2.add("java01");
        al2.add("java02");
        al2.add("java05");
        al2.add("java06");
        al2.retainAll(al1);//取交集，al2中只存在和al1相同的元素
        System.out.println(al2);
        al1.retainAll(al2);
        System.out.println(al1);//删除相同的元素
    }
}

```
- 集合中只存对象的地址值，不储存对象
 

 ### 迭代器
 用于取出元素的方式一个东西。
 - ArrayList：数组结构
 - LinkedLIst：链表结构（增删速度快，索引慢）
 - Vector：数组结构（线程同步，被ArrayList替代了）

```java
import java.util.*;

public class test1 {

    public static void main(String[] args) {
        methon_get();
    }

    public static void methon_get() {
        ArrayList al = new ArrayList();
        al.add("java01");
        al.add("java02");
        al.add("java03");
        al.add("java04");
        al.add("java05");
        Iterator it = al.iterator();//获取迭代器对象
        while (it.hasNext()) {
            System.out.println(it.next());
        }
    }

}
```
#### List（元素是有序的，且可以重复）
```java
import java.io.ObjectStreamException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

class ListDemo {
    public static void main(String[] args) {
        method_2();
    }
    public static void method_2(){
        //list迭代器
        /*
        list特有的迭代器是Iterator的子接口
        在迭代式不可以通过集合对象操作集合类的对象
        在迭代器中只能通过迭代器操作元素，如果进行其他的操作
        需要使用listIterator
         */
        ArrayList a1 = new ArrayList();
        a1.add("java1");
        a1.add("java2");
        a1.add("java3");
        a1.add("java4");
        ListIterator li= a1.listIterator();
        while(li.hasNext())
        {
            Object obj=li.next();
            if (obj.equals("java2"))
            {
                li.set("javasdas123");
            }
        }
        System.out.println("has next:"+li.hasNext());
        System.out.println("has next:"+li.hasPrevious());//可以用于逆向遍历元素
        System.out.println(a1);
//        Iterator it = a1.iterator();
//        //在迭代过程中准备添加或删除元素
//        while(it.hasNext())
//        {
//            Object ob=it.next();
//            if (ob.equals("java2"))
//                it.remove();
//        }
//        System.out.println(a1);
    }
    public static void methed() {
        ArrayList a1 = new ArrayList();
        a1.add("java1");
        a1.add("java2");
        a1.add("java3");
        a1.add("java4");
        System.out.println("原集合是" + a1);
        //指定位置添加元素
        a1.add(1, "javax");
        System.out.println(a1);
        a1.remove(2);
        System.out.println(a1);
        a1.set(2, "java007");
        System.out.println(a1);
        System.out.println(a1.get(1));
        //获取所有元素
        for (int i = 0; i < a1.size(); i++) {
            System.out.println(a1.get(i));
        }
        Iterator it = a1.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }
        System.out.println(a1.indexOf("javax"));
        System.out.println(a1.indexOf("java123"));
        List list = a1.subList(1, 3);
        System.out.println(list);
    }

}
```
#### vector
```java
import java.util.Enumeration;
import java.util.Vector;

/*
枚举是vector特有的取出方式，已经被废弃
 */
class ListDemo {
    public static void main(String[] args) {
        Vector vector = new Vector();
        vector.add(123);
        vector.add(1222);
        vector.add(23245);

        Enumeration en = vector.elements();
        while (en.hasMoreElements()) {
            System.out.println(en.nextElement());
        }
    }
}
```
#### LinkedList
- LinkList模拟队列
```java
import java.util.LinkedList;
/*
LinkList特有方法:
getFirst()
getLast()
removeFirst()
removeLast()
 */
class ListDemo {
    public static void main(String[] args) {
        LinkedList link=new LinkedList();
        link.addFirst("123");
        link.addFirst(123);
        link.addFirst("12333");
        link.addFirst(123123);
        link.peekFirst();//获取但不移除第一个元素
        System.out.println(link.pollFirst());//获取并移除第一个元素
    }
}
```
```java
import java.util.LinkedList;
//Arraylist模拟队列
class ListDemo {
    public static void main(String[] args) {
        Queue my=new Queue();
        my.myAdd(123);
        my.myAdd(1234);
        my.myAdd(12345);
        my.myAdd(123456);
        my.myAdd(12345678);
        while (!my.isnull())
        {
            System.out.println(my.myGet());
        }
    }
}

class Queue {
    private LinkedList link;

    Queue() {
        link = new LinkedList();
    }

    public void myAdd(Object obj) {
        link.addFirst(obj);
    }

    public Object myGet() {
        return link.removeLast();
    }

    public boolean isnull() {
        if (link.isEmpty())
            return true;
        else
            return false;
    }
}
```
- 无重复的ArrayList
- List集合判断元素是否相同，依据是元素的equals方法
```java
import java.util.ArrayList;
import java.util.Iterator;

class ListDemo {
    public static void main(String[] args) {
        ArrayList al=new ArrayList();
        al.add(123);
        al.add(123);
        al.add(1234);
        al.add(1234);
        al.add(12345);
        al.add(12345);
        System.out.println(al);
        al=singleElement(al);
        System.out.println(al);
        Iterator it=al.iterator();
        while (it.hasNext())
        {
            System.out.println(it.next());
        }

    }
    public static ArrayList singleElement(ArrayList al)
    {
        ArrayList newal=new ArrayList();
        Iterator it=al.iterator();
        while(it.hasNext())
        {
            Object obj = it.next();
            if (!newal.contains(obj))
            {
                newal.add(obj);
            }
        }
        return newal;
    }
}
```
- 使用ArrayList储存对象（需要用到多态）
```java
import java.util.ArrayList;
import java.util.Iterator;

class ListDemo {
    public static void main(String[] args) {
        ArrayList al = new ArrayList();
        al.add(new Person("lisi1", 12));
        al.add(new Person("lisi2", 12));
        al.add(new Person("lisi3", 12));
        al.add(new Person("lisi4", 12));
        al.add(new Person("lisi5", 12));
        al.add(new Person("lisi6", 12));
        al.add(new Person("lisi7", 12));
        al.add(new Person("lisi8", 12));
//        System.out.println(al);
        Iterator it = al.iterator();
        while (it.hasNext()) {
            Object obj=new Object();
            Person p= (Person) it.next();
            System.out.println(p.getName()+"...."+p.getAge());
        }
    }
}
class Person {
    private String name;
    private int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }
}

```
#### Set（元素不可以重复）

##### HashSet
- 无序，元素不可以重复（set集合的功能和Collection功能差不多）
    - 常见子类`HashSet` `TreeSet` 
- HashSet无序性验证
```java
import java.util.HashSet;
import java.util.Iterator;
/*
HashSet使用hashcode和equals的方法来来保证元素的唯一性，
如果传入对象的话需要自定义hashcode方法和equals方法
在删除时也会调用对象的hashcode方法和equals方法，
 */
class ListDemo {

    public static void main(String[] args) {
        HashSet hs = new HashSet();
        hs.add(new Person("lisi1", 12));
        hs.add(new Person("lisi2", 12));
        hs.add(new Person("lisi3", 12));
        hs.add(new Person("lisi4", 12));
        hs.add(new Person("lisi4", 12));
        hs.remove(new Person("lisi1",12));
        Iterator it = hs.iterator();

        while (it.hasNext()) {
            Person p = (Person) it.next();
            System.out.println(p.getName() + "----" + p.getAge());
        }
    }
}

class Person {
    private String name;
    private int age;

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    @Override
    public int hashCode() {
        System.out.println(this.name + "---hashcode");
        return name.hashCode() + age;
    }

    @Override
    public boolean equals(Object o) {
        if (!(o instanceof Person))
            return false;
        Person p = (Person) o;
        System.out.println(this.getName() + "--equ--" + p.getAge());
        return this.name.equals(p.name) && this.age == p.age;
    }
}
```
##### TreeSet
可以对set集合内的元素进行排序，可指定顺序（类似二叉排序树）
```java
import java.util.Iterator;
import java.util.TreeSet;
/*
自定义TreeSet需要注意：
           需要具备比较性(实现Compareable接口)
*/
//排序时，如果主要条件相同的话需要判断一下次要条件

class ListDemo {

    public static void main(String[] args) {
        TreeSet ts = new TreeSet();
        ts.add(new Person("lisi02", 10));
        ts.add(new Person("lisi004", 11));
        ts.add(new Person("lisi123", 17));
        ts.add(new Person("lisi123", 17));
        ts.add(new Person("lisi1223", 17));
        Iterator it = ts.iterator();
        while (it.hasNext()) {
            Person p = (Person) it.next();
            System.out.println(p.getName() + "---" + p.getAge());
        }
    }
}

class Person implements Comparable {
    private String name;
    private int age;

    Person(String name, int age) {
        this.age = age;
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    @Override
    public int compareTo(Object o) {
        if (!(o instanceof Person))
            throw new RuntimeException("不是人类对象");
        Person p = (Person) o;
        System.out.println(this.name + "...compareTo..." + p.name);
        if (this.age > p.age)
            return 1;
        if (this.age==p.age)
            return this.name.compareTo(p.name);
        else
            return -1;
    }
}
```
当两种比较器都存在时，优先使用`比较器对象`
你比较可以通过`implement comparetor`接口或者让对象`implement Compareable` 重写`compareTo`方法。
```java
import java.util.*;

/*自定义ThreeSet的第二种排序方式，当自身不具备比较性时，
      或者具备的比较性不是所需要的。
      那么就要让集合具备比较性.定义比较器，
      将比较器对象作为参数传递给ThreeSet集合的构造函数

      当两种比较器都存在时，优先使用比较器对象。
*/
public class ThreeSetDemo {
    public static void main(String[] args) {
        TreeSet ts = new TreeSet(new Mycompare());
        ts.add(new Person("lisi02", 10));
        ts.add(new Person("lisi004", 11));
        ts.add(new Person("lisi123", 15));
        ts.add(new Person("lisi123", 16));
        ts.add(new Person("lisi1223", 18));
        Iterator it = ts.iterator();
        while (it.hasNext()) {
            Person p = (Person) it.next();
            System.out.println(p.getName() + "---" + p.getAge());
        }
    }
}

class Person implements Comparable {
    private String name;
    private int age;

    Person(String name, int age) {
        this.age = age;
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public int getAge() {
        return age;
    }

    @Override
    public int compareTo(Object o) {
        if (!(o instanceof Person))
            throw new RuntimeException("不是人类对象");
        Person p = (Person) o;
//        System.out.println(this.name + "...compareTo..." + p.name);
        if (this.age > p.age)
            return 1;
        if (this.age == p.age)
            return this.name.compareTo(p.name);
        else
            return -1;
    }
}

class Mycompare implements Comparator {

    @Override
    public int compare(Object o1, Object o2) {
        Person p1 = (Person) o1;
        Person p2 = (Person) o2;
        if (p1.getName()==p2.getName())
        return p1.getName().compareTo(p2.getName());
        return new Integer(p1.getAge()).compareTo(new Integer(p2.getAge()));
    }
}
```

#### 泛型


```java
import java.util.*;
/*
泛型，用来解决安全问题，是一个安全机制。

好处：
1：将运行时候的时期，转移到了编译时期，更安全
2：避免了强制类型转换麻烦
*/
class GenericDemo{
    public static void main(String[] args) {
        ArrayList <String> al=new <String> ArrayList();
        al.add("abc");
        al.add("213");
        al.add("avf");
        al.add("nvd");
        Iterator <String>it=al.iterator();
        while (it.hasNext())
        {
            String s=  it.next();
            System.out.println(s+":"+s.length());
        }
    }
} 
```
```java
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Iterator;
import java.util.TreeSet;

class Demo2 {
    public static void main(String[] args) {
        TreeSet<String> ts = new <String>TreeSet(new compare() );
        ts.add("a");
        ts.add("213");
        ts.add("avf");
        ts.add("nvd4");
        Iterator<String> it = ts.iterator();
        while (it.hasNext()) {
            String s = it.next();
            System.out.println(s + ":" + s.length());
        }
    }
}
class compare implements Comparator<String> {

    @Override
    public int compare(String t1, String t2) {
        int num = new Integer(t1.length()).compareTo(new Integer(t2.length()));
        if (num == 0) {
            return t1.compareTo(t2);
        }
        return num;
    }
}
```

###### 泛型类
- 只能定义自定义数据类型，不能定义基本数据类型
```java
class Demo2 {
    public static void main(String[] args) {
        Util<Worker> u=new Util<Worker>();
        u.setObject(new Worker());
        System.out.println(u.getObject());
    }

}
class Util<QQ> {        //泛型类的定义
    private QQ q;

    public void setObject(QQ q) {
        this.q = q;
    }

    public QQ getObject() {
        return q;
    }
}
class Worker {
}
```

```java
//泛型类定义的泛型，在整个类中有效，如果被方法使用
//那么泛型类的对象明确要操作的具体类型后，所有要操作类型就确定了
//为了让不同方法可以操作不同类型而且类型不确定
//那么可以将泛型定义在方法上
//泛型放在返回值之前

//静态方法不能访问类上定义的泛型，如果静态方法操作的应用数据类型不确定，可以将泛型定义在方法上。
class Demo2 {
    public static void main(String[] args) {
        Demo3 stringDemo3=new Demo3();
        stringDemo3.show("haha");
        stringDemo3.print(21);
    }
}

class Demo3 {
    public <T >void show(T t) {
        System.out.println("show：" + t);
    }

    public <T >void print(T t) {
        System.out.println("print:"+t);
    }
}
```


```java
import java.security.PublicKey;
import java.util.ArrayList;
import java.util.Iterator;

class Demo2 {
    public static void main(String[] args) {
        ArrayList<String> al = new ArrayList<String>();
        al.add("abc");
        al.add("bcd");
        al.add("aas");
        ArrayList<Integer> al1 = new ArrayList<Integer>();
        al1.add(123);
        al1.add(32);
        al1.add(1);
        al1.add(345);
        Demo2.Print(al);
        Demo2.Print(al1);
    }

    public static void Print(ArrayList<?> al) { //用？来指定不确定的类型
        Iterator<?> it = al.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }
    }
}
```
泛型限定，限定某个类以及其子类
```java
import java.rmi.StubNotFoundException;
import java.security.Permission;
import java.security.PublicKey;
import java.util.ArrayList;
import java.util.Iterator;
class Demo2 {
    public static void main(String[] args) {
        ArrayList<Person> al = new ArrayList<Person>();
        al.add(new Person("abc"));
        al.add(new Person("bcd"));
        al.add(new Person("aas"));
        ArrayList<Student> al1 = new ArrayList<Student>();
        al1.add(new Student("asdd"));
        al1.add(new Student("as123"));
        al1.add(new Student("123"));
        al1.add(new Student("as324dd"));
        Demo2.Print(al);
        Demo2.Print(al1);
    }

    public static void Print(ArrayList<? extends Person> al) { //用？来指定不确定的类型
        // 用泛型限定来限定指定类 用<? extends xx>
        //<? extends E>:可以接受E类及其子类，上限
        //<? super E>：可以接受E类型或者E类型的父类，下限
        Iterator<? extends Person> it = al.iterator();
        while (it.hasNext()) {
            System.out.println(it.next().getName());
        }
    }
}

class Person {
    private String name;

    Person(String name) {
        this.name = name;

    }

    public String getName() {
        return name;
    }
}

class Student extends Person {
    Student(String name) {
        super(name);
    }
}
```
### Map集合框架
`HashMap` `TreeMap` `HashTable`
    存储键值对，而且要保证键的唯一性
- 功能
    - 添加
    - 删除
    - 判断
    - 获取
#### HashTable(哈希表)
- 底层哈希表，不能存null，该集合线程同步，效率低
#### HashMap
- 底层哈希表，允许null，该集合线程不同步，效率高

```java
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

/*
1:添加
    put();
    putAll();
2:删除
    clean();
    remove();
3:判断
    containValue();
    containKey();
    isEmpty();
4:获取
    get(object k);
    size();
    values();
    entrySet();
 */
class MapTest {
    public static void main(String[] args) {
        Map<String, String> map = new HashMap<>();
        //添加
        System.out.println(map.put("1", "zhansan1"));//储存时返回原有的值，第一次为空
        System.out.println(map.put("1", "zhansan1"));//第二次为值
        map.put("2", "zhansan2");
        map.put("3", "zhansan3");
        System.out.println(map.containsKey("1"));
        //获取
        System.out.println(map.values());
        System.out.println(map.get("33"));
        Collection<String> cl = map.values();
        Iterator it = cl.iterator();
        System.out.println(cl);
        while (it.hasNext()) {
            System.out.println("ok"+it.next());
        }

        //删除
        System.out.println(map.remove("1"));
        System.out.println(map.remove("01"));
        map.put("李四", null);
        System.out.println(map.get("李四"));//可以为空

    }
}
```
Map的取出:
1:keySet：将Map中所有的键存到集合，可以迭代取出
```java
import java.util.*;

class MapTest {
    public static void main(String[] args) {
        Map<String, String> map = new HashMap<>();
        //添加
        map.put("4", "zhansan4");
        map.put("1", "zhansan1");
        map.put("2", "zhansan2");
        map.put("3", "zhansan3");
        //先获取键的方法
        Set<String> set=map.keySet();
        Iterator <String>it= set.iterator();
        while (it.hasNext())
        {
            String key= it.next();
            System.out.println(key);
            System.out.println(map.get(key));
        }
    }
}
```
2:entrySet：
```java
import java.util.*;

/*
Map取出原理，将map转换成set，然后进行取出。
set<Map.entry<k,v>> entrySet:将map集合中的映射关系存入到了set集合之中去，
    这个关系即为:Map.entry
    Map.Entry其实Entry也是一个借口，它是Map接口中的一个内部接口
比如：
interface Map {
    public static interface Entry {
        public abstract Object getkey;
        public abstract Object getValue;
    }
}
class HashMap implements Map.Entry
{

}
 */
class MapTest {
    public static void main(String[] args) {
        Map<String, String> map = new HashMap<>();
        map.put("01", "张三");
        map.put("02", "张三2");
        map.put("03", "张三3");
        map.put("04", "张三4");
        Set<Map.Entry<String, String>> entry = map.entrySet();
        Iterator<Map.Entry<String, String>> it = entry.iterator();
        while (it.hasNext()) {
            Map.Entry<String, String> me = it.next();
            String key = me.getKey();
            String value = me.getValue();
            System.out.println(key + ":" + value);
        }
    }
}
```
```java
import java.util.*;

class Student implements Comparable<Student> {
    private String name;
    private int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String toString() {
        return name + ":" + age;
    }

    @Override
    public int hashCode() {
        return name.hashCode() + age * 34;
    }

    public boolean equals(Object obj) {
        if (!(obj instanceof Student))
            throw new ClassCastException("类型不匹配");
        Student s = (Student) obj;
        return this.name.equals(s.name) && this.age == s.age;
    }

    @Override
    public int compareTo(Student o) {
        int a = new Integer(this.age).compareTo(new Integer(new Integer(o.getAge())));
        if (a == 0)
            return this.name.compareTo(o.name);
        return a;
    }
}

class Demo3 {
    public static void main(String[] args) {
        HashMap<Student, String> map = new HashMap<Student, String>();
        map.put(new Student("张君宝", 22), "中国人");
        map.put(new Student("张君军", 23), "中国人");
        map.put(new Student("张君？", 24), "中国人");
        map.put(new Student("张包宝", 25), "中国人");
        map.put(new Student("张君宝", 22), "中国人");
        //第一种取出方式
        Set<Student> set = map.keySet();
        Iterator<Student> it = set.iterator();
        while (it.hasNext()) {
            Student s=it.next();
            System.out.println(s.getName()+":"+s.getAge());
        }
        //第二种取出方式
        Set<Map.Entry<Student,String>> set1=map.entrySet();
        Iterator <Map.Entry<Student,String>>iterator= set1.iterator();
        while (iterator.hasNext()) {
            Map.Entry<Student,String> me=iterator.next();
            Student st=me.getKey();
            System.out.println(st.getName()+":"+st.getAge());
            System.out.println(me.getValue());
        }
    }
}
```
#### TreeMap
- 二叉树结构，线程不同步，可以用于给map的键进行排序。 HashSet底层为Map
```java
import java.util.*;

//treeMap
class Student implements Comparable<Student> {
    private String name;
    private int age;

    public Student(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String toString() {
        return name + ":" + age;
    }

    @Override
    public int hashCode() {
        return name.hashCode() + age * 34;
    }

    public boolean equals(Object obj) {
        if (!(obj instanceof Student))
            throw new ClassCastException("类型不匹配");
        Student s = (Student) obj;
        return this.name.equals(s.name) && this.age == s.age;
    }

    @Override
    public int compareTo(Student o) {
        int a = new Integer(this.age).compareTo(new Integer(new Integer(o.getAge())));
        if (a == 0)
            return this.name.compareTo(o.name);
        return a;
    }
}

class Demo3 {
    public static void main(String[] args) {
        TreeMap<Student, String> map = new TreeMap<Student, String>(new comp());
        map.put(new Student("张君宝", 22), "中国人");
        map.put(new Student("张君军", 29), "中国人");
        map.put(new Student("张君？", 21), "中国人");
        map.put(new Student("张包宝", 35), "中国人");
        map.put(new Student("张君宝", 32), "中国人");
        Set<Map.Entry<Student, String>> set1 = map.entrySet();
        Iterator<Map.Entry<Student, String>> iterator = set1.iterator();
        while (iterator.hasNext()) {
            Map.Entry<Student, String> me = iterator.next();
            Student st = me.getKey();
            System.out.println(st.getName() + ":" + st.getAge());
            System.out.println(me.getValue());
        }
    }
}

class comp implements Comparator<Student> {

    @Override
    public int compare(Student s1, Student s2) {
        int num = s1.getName().compareTo(s2.getName());
        if (num == 0) {
            return new Integer(s1.getAge()).compareTo(new Integer(s2.getAge()));
        }
        return num;
    }
}
```
- 练习（获取字符串中的字母出现的次数）
```java
import java.util.*;

/*
练习，获取字符串中的字母出现的次数。

 */
class Demo100 {
    public static void main(String[] args) {
        String s = "aaaabbbcsdrd";
        String st = Demo100.charCount(s);
        System.out.println(st);
    }

    public static String charCount(String str) {
        char[] chars = str.toCharArray();
        TreeMap<Character, Integer> tm = new TreeMap<Character, Integer>();
        int count = 0;
        for (int x = 0; x < chars.length; x++) {
            Integer value = tm.get(chars[x]);
            if (value != null)
                count = value;
            count++;
            tm.put(chars[x], count);
            count=0;
        }
        StringBuilder sb = new StringBuilder();
        Set entrySet = tm.entrySet();
        Iterator<Map.Entry<Character, Integer>> it = entrySet.iterator();
        while (it.hasNext()) {
            Map.Entry<Character, Integer> entry = it.next();
            Character key = entry.getKey();
            Integer value2 = entry.getValue();
            sb.append(key + "(" + value2 + ")");
        }
        return sb.toString();
    }
}
```
###### Collections 工具类
- 用于对集合的排序等
 ```java
 import java.util.*;

/*
Collections 工具类的使用
 */
class Demo100 {
    public static void main(String[] args) {
        sortDemo();
    }

    public static void sortDemo() {
        List<String> list = new ArrayList<String>();
        list.add("asd");
        list.add("asd");
        list.add("asdsd");
        list.add("asdqasd");
        list.add("asdqwqqqq");
        System.out.println(list);
        Collections.sort(list,new comp());
        System.out.println(list);
    }
}

class comp implements Comparator<String> {

    @Override
    public int compare(String s, String t1) {
        if (s.length()>t1.length())
            return 1;
        if (s.length()<t1.length())
            return -1;
        return s.compareTo(t1);
    }
}
 ```
 - 输出集合最大值
```java
import java.util.*;

/*
Collections 工具类的使用
 */
class Demo100 {
    public static void main(String[] args) {
        sortDemo();
    }

    public static void sortDemo() {
        List<String> list = new ArrayList<String>();
        list.add("asd");
        list.add("asd");
        list.add("asdsd");
        list.add("asdqasd");
        list.add("asdqwqqqq");
        System.out.println(list);

        Collections.sort(list,new comp());
        System.out.println(Collections.max(list,new comp()));
        System.out.println(list);
    }
}

class comp implements Comparator<String> {

    @Override
    public int compare(String s, String t1) {
        if (s.length()>t1.length())
            return 1;
        if (s.length()<t1.length())
            return -1;
        return s.compareTo(t1);
    }
}
```
- 二分查找

```java
import java.util.*;

/*
Collections 工具类的使用
 */
class Demo100 {
    public static void main(String[] args) {
//        sortDemo();
        binarySearchDemo();
    }

    public static void sortDemo() {
        List<String> list = new ArrayList<String>();
        list.add("asd");
        list.add("asd");
        list.add("asdsd");
        list.add("asdqasd");
        list.add("asdqwqqqq");
        System.out.println(list);
        Collections.sort(list,new comp());
        System.out.println(Collections.max(list,new comp()));
        System.out.println(list);
    }
    public static void binarySearchDemo()
    {
        List<String> list = new ArrayList<String>();
        list.add("asd");
        list.add("asd");
        list.add("asdsd");
        list.add("asdqasd");
        list.add("asdqwqqqq");
        Collections.sort(list,new comp());
        int index=Collections.binarySearch(list,"asd");
        System.out.println(index);
    }
}

class comp implements Comparator<String> {

    @Override
    public int compare(String s, String t1) {
        if (s.length()>t1.length())
            return 1;
        if (s.length()<t1.length())
            return -1;
        return s.compareTo(t1);
    }
}
```
- 替换反转
```java
import java.util.*;

/*
Collections 工具类的使用
 */
class Demo100 {
    public static void main(String[] args) {
        List<String> list = new ArrayList<String>();
        list.add("asd");
        list.add("asd");
        list.add("asdsd");
        list.add("asdqasd");
        list.add("asdqwqqqq");
        System.out.println(list);
        Collections.replaceAll(list,"asd","pp");
        System.out.println(list);
//        Collections.fill(list,"pp");//将集合中的全部元素替换成指定元素
        Collections.reverse(list);
        System.out.println(list);

    }
}
```
```java
Collections.reversOrder()//生成比较顺序相反的比较器
```
```java
Collections.synchronizedList();
Collections.synchronizedSet();
Collections.synchronizedMap();
//用来返回线程安全的集合
Collections.shuffle(list);//生成随机的list集合
```
###### Arrays（用于操作数组的工具类）

```java
import java.util.*;

/*
Arrays 工具类的使用
 */
class Demo100 {
    public static void main(String[] args) {
//        Arrays.binarySearch();//二分查找；
//        Arrays.deepEquals();//深层判断两个数组是否相同（从元素是否相同来看）
//        Arrays.fill();//替换
//        Arrays.sort();//排序
//        int [] arr={200,1,3,4,6};
//        System.out.println(Arrays.toString(arr));
        String [] str={"123","123123","321894"};
        List<String>list=Arrays.asList(str);
        //将数组变成集合，不能使用集合的增删方法，因为数组的长度是一定的
        /*
        如果数组中的元素都是对象那么在存入集合的时候就存入相应的对象
        如果数组中的元素是基本数据类型，那么将会存入这个数组对象
         */
        System.out.println(list);
    }
}
```
```java
import java.util.*;

/*
        集合变数组
*/
class Demo100 {
    public static void main(String[] args) {
        ArrayList<String> list=new ArrayList<String>();
        list.add("123");
        list.add("1231");
        list.add("1231");
        list.add("1232");
        list.add("1233");
        String []arr=list.toArray(new String[20]);
        System.out.println(Arrays.toString(arr));
        //类型制定的长度应该为多长？
        //当指定类型的数组长度小于集合长度，那么数组开辟的空间为size大小。
        //当指定类型的数组长度大于集合长度，就不重新创建数组，而是使用传递进来的数组大小。
        //为什么要将集合变成数组呢？
        //为了限定对元素的操作
    }
}
```
###### 增强for循环

```java
import java.util.*;

/*
        集合变数组
*/
class Demo100 {
    public static void main(String[] args) {
        ArrayList<String> list = new ArrayList<String>();
        list.add("123");
        list.add("1231");
        list.add("1231");
        list.add("1232");
        list.add("1233");
        //增强for循环
//        for(变量类型 变量名 : 被遍历的集合或者数组)
//        {
//        }
//        对集合进行遍历，不能对集合进行操作，只能获取，而迭代器除了遍历，还可以使用remove
//        如果使用ArrayIterator可以对集合进行增删改查的操作
//        高级for局限性:
//          必须要有可遍历对象
        for (String s : list) {
            System.out.println(s);
        }
        HashMap<Integer,String>hm=new HashMap<Integer, String>();
        hm.put(1,"abc");
        hm.put(2,"ab");
        hm.put(3,"bv");
        for(Map.Entry<Integer,String> s:hm.entrySet())
        {
            System.out.println(s.getKey()+"++++"+s.getValue());
        }
    }
}
```
- 可变长度的参数
```java
import java.util.*;

/*
        集合变数组
*/
class Demo100 {
    public static void main(String[] args) {
        fun(123,1223,234234,3445345,34534534);
    }

    public static void fun(int... arr) {
        System.out.println(arr);
        for (int i :arr)
        {
            System.out.println(i);
        }
    }
//    本质上也是数组
//    可变参数使用时必须注意可变参数一定要放在最后面
}
```

###### 静态导入
```java

import java.util.Arrays;

import static java.util.Arrays.*;

/*
        静态导入
*/
//当类名重名时，要指定所属的包名，当方法重名时，指定所属的类或对象。

class Demo100 {
    public static void main(String[] args) {
        int []arr={1,23,4,5};
        binarySearch(arr,1);
        System.out.println(Arrays.toString(arr));
    }
}
```
###### System类
```java
import java.util.Iterator;
import java.util.Properties;

//system类
class Demo100 {
    public static void main(String[] args) {
        //获取系统信息
        Properties ps=System.getProperties();
        for (Object obj:ps.keySet())
        {
            String value = (String) ps.get(obj);
            System.out.println(obj+"::"+value);
        }
    }
}
```
###### Runtime对象
```java


//Runtime类
//本身不具有构造函数，说明其不能通过构造函数来创建对象
//但是发现其方法都是非静态的方法，而且返回值为本类的类名
//则其一定有一个方法能返回实例的对象（单例设计模式）

import java.io.IOException;

class Demo100 {
    public static void main(String[] args) throws InterruptedException, IOException {
        Runtime r = Runtime.getRuntime();
        Process p=r.exec("zeal");
        Thread.sleep(4000);
        p.destroy();
    }
}
``` 

###### Date类
```java
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.*;
//Date类
//可以精确到毫秒
//DateFormat 日期格式化类，但是为抽象类
//使用其子类java.text.SimpleDateFormat
/**
 SimpleDateFormat函数语法：
 G 年代标志符
 y 年
 M 月
 d 日
 h 时 在上午或下午 (1~12)
 H 时 在一天中 (0~23)
 m 分
 s 秒
 S 毫秒
 E 星期
 D 一年中的第几天
 F 一月中第几个星期几
 w 一年中第几个星期
 W 一月中第几个星期
 a 上午 / 下午 标记符
 k 时 在一天中 (1~24)
 K 时 在上午或下午 (0~11)
 z 时区
 */
class Demo100{
    public static void main(String[] args) {
        Date d=new Date();
        System.out.println(d);//打印的时间看不懂，需要格外的格式
        SimpleDateFormat sdf= new SimpleDateFormat("yyyy年MM月dd日 E hh:mm:ss:SS");//指定模式
        String s=sdf.format(d);//使用模式来格式化日期
        System.out.println(s);

        long l=System.currentTimeMillis();
        Date d1=new Date(l);
        System.out.println("d1 :"+d1);
    }
}
```
- Calendar类
```java
package Test;

import java.util.Calendar;
/*
日历方法
 */
class Test{
    public static void main(String[] args) {
        Calendar c=Calendar.getInstance();
        c.set(2012,2,23);//设置时间
        c.add(Calendar.MONTH,-4);//日期的增加或减少
        Demo2(c);
    }
    public static void Demo2(Calendar c){

        String[] month={"一月","二月","三月","四月","五月","六月","七月","八月","九月","十月","十一月","十二月"};
        String[] weeks={"","星期日","星期一","星期二","星期三","星期四","星期五","星期六"};
        System.out.println(c);
        System.out.print(c.get(Calendar.YEAR)+"年");
        System.out.print(month[c.get(Calendar.MONTH)]);
        System.out.println(c.get(Calendar.DAY_OF_MONTH)+"日");
        System.out.println(weeks[c.get(Calendar.DAY_OF_WEEK)]);

        //传统方法
//        Date d= new Date();
//        SimpleDateFormat si=new SimpleDateFormat("yyyy");
//        int year=Integer.parseInt(si.format(d));
//        System.out.println(year);
    }
}
```
###### Math类

```java
package Test;

import java.util.Random;

class Test {
    public static void main(String[] args) {
        double d = Math.ceil(-12.34);//ceil返回大于指定数据的最小整数
        System.out.println(d);
        System.out.println(Math.floor(12.33));//floor返回小于指定数据的最小整数
        System.out.println(Math.round(12.53));//四舍五入
        System.out.println(Math.pow(2,16)); //次幂
        Random r=new Random();
        for (int i = 0; i < 10; i++) {
//            int a=(int)(Math.random()*10+1);
//            System.out.println(a);//伪随机数
            System.out.println(r.nextInt(10)+1);
        }
    }
}
```
#### IO流

IO流体系
![io流体系](https://upload-images.jianshu.io/upload_images/3985563-38c3ea4562d6dbe3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/687/format/webp)

##### 字符流
- FileWriter
    ```java
    import java.io.FileWriter;
    import java.io.IOException;

    /*
    I/O流
    字节流有两个基类:
    InputStream OutPutStream
    */
    public class Test {
        public static void main(String[] args) throws IOException {
            FileWriter fw= new FileWriter("test.txt");
            fw.write("sakjdbasjkdas");
            fw.flush();
            fw.close();
        }
    }
    ```
    - IO异常处理
    ```java
    import java.io.FileWriter;
    import java.io.IOException;

    /*
    I/O流
    I/O异常处理
    */
    public class Test {
        public static void main(String[] args) {
            FileWriter fw = null;
            try {
                fw = new FileWriter("K:\\test.txt");
                fw.write("sakjdbasjkdas");
                fw.flush();
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    if (fw!=null)
                    fw.close();
                    else
                        System.out.println("目录错了！");
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
    ```
    - 追加写
    ```java
    import java.io.FileWriter;
    import java.io.IOException;

    /*
    I/O流
    I/O异常处理
    */
    public class Test {
        public static void main(String[] args) {
            FileWriter fw = null;
            try {
                fw = new FileWriter("test.txt",true);
                fw.write("我哦\n头");
                fw.flush();
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    if (fw!=null)
                    fw.close();
                    else
                        System.out.println("目录错了！");
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
    ```
- FileReader
    ```java
    import java.io.FileNotFoundException;
    import java.io.FileReader;
    import java.io.IOException;

    /*
    */
    public class Test {
        public static void main(String[] args) throws IOException {
            //第一种方法
            FileReader fr = new FileReader("test.txt");
    //        int ch = 0;
    //        while ((ch = fr.read()) != -1) {
    //            System.out.print((char) ch);
    //        }
            //第二种方法
            char[] buff = new char[1024];
            int num = 0;
            while ((num=fr.read(buff))!=-1) {
                System.out.print(new String(buff,0,num));
            }
            fr.close();
        }
    }
    ```
- 字符流的缓冲区 

缓冲区的出现提高了数据的读写效率
对应类

`BufferWriter` 

`BufferReader`
- BufferWriter
```java
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

/*
 */
public class Test {
    public static void main(String[] args) throws IOException {
        FileWriter fw=new FileWriter("test.txt");
        //为了提高写入流的效率加入缓冲技术
        BufferedWriter bufw=new BufferedWriter(fw);
        bufw.write("abcdef");
        bufw.newLine();//换行方法
        bufw.write("abcdef");
        bufw.flush();//必须刷新
        bufw.close();//必须关闭
    }
}
```
- BufferReader
```java
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/*
 */
public class Test {
    public static void main(String[] args) throws IOException {
        FileReader fr=new FileReader("test.txt");
        //为了提高流的效率加入缓冲技术
        BufferedReader bufr=new BufferedReader(fr);
        String x;
        while ((x=bufr.readLine())!=null)
        System.out.println(x);
    }
}
```
###### 装饰设计模式
- 当想要对已有对象进行功能增强时,那么可以定义类，将已有对象传入，基于已有的功能并提供加强功能

- 装饰模式比继承灵活。避免了继承体系的臃肿而且降低了类与类之间的关系

- 装饰类因为增强已有对象，具备的功能和已有功能是相同的，只不过扩展的了其功能
```java
class Person {
    public void chifan() {
        System.out.println("吃饭");
    }
}

class SuperPerson {
    private Person p;

    SuperPerson(Person p) {
        this.p = p;
    }

    public void shuijiao() {
        p.chifan();
        System.out.println("睡觉");
    }
}

class Demo {
    public static void main(String[] args) {
        Person p = new Person();
        p.chifan();
        SuperPerson sp = new SuperPerson(p);
        sp.shuijiao();
    }
}
```
- LineNumberReader
```java
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;

class Demo {
    public static void main(String[] args) throws IOException {
        FileReader fr=new FileReader("test.txt");
        LineNumberReader lr=new LineNumberReader(fr);
        lr.setLineNumber(100);
        String line=null;
        while ((line=lr.readLine())!=null)
            System.out.println(lr.getLineNumber()+":"+line);
        lr.close();
    }
}
```
##### 字节流
`InputStream`  `OutputStream`

FileOutputStream
```java
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

class Demp {
    public static void main(String[] args) throws IOException {
//        write();
//        readFile();
        readFile_2();
        readFile_3();
    }

    public static void write() throws IOException {
        FileOutputStream fos = new FileOutputStream("test.txt");
        fos.write("abcdef".getBytes());
        fos.close();
    }

    public static void readFile() throws IOException {
        FileInputStream fis = new FileInputStream("test.txt");
        int ch = 0;
        while ((ch = fis.read()) != -1) {
            System.out.print((char) ch);
        }
        System.out.println();
        fis.close();
    }

    public static void readFile_3() throws IOException {
        FileInputStream fis = new FileInputStream("test.txt");
        byte[] buf = new byte[1024];//定义一个刚好的缓冲区数组
        int len = 0;
        while ((len = fis.read(buf)) != -1)
            System.out.println(new String(buf, 0, len));
        fis.close();

    }

    public static void readFile_2() throws IOException {
        FileInputStream fis = new FileInputStream("test.txt");
        byte[] buf = new byte[fis.available()];//定义一个刚好的缓冲区数组
        fis.read(buf);//需要注意内存溢出
        System.out.println(new String(buf));
        fis.close();
    }
}
```
练习：图片复制
```java
/*
复制图片
 */

import java.io.*;
class Demo100{
    public static void main(String[] args) {
        FileOutputStream fos=null;
        FileInputStream fis=null;
        try{
            fos=new FileOutputStream("2.jpeg");
            fis=new FileInputStream("C:\\Users\\DeepBlue\\Pictures\\Saved Pictures\\0GBxtiFvzXE.jpg");
            byte []buf=new byte[1024];
            int len=0;
            while ((len=fis.read(buf))!=-1)
                fos.write(buf,0,len);

        }
        catch (IOException e)
        {
            throw new RuntimeException("复制文件失败！");
        }
        finally {
            try {
                fis.close();
                fos.close();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            System.out.println("文件复制成功！");
        }
    }
}
```
通过缓冲区实现对MP3文件的拷贝
```java
/*
通过字节流完成MP3的拷贝

 */

import java.io.*;

class Demo100 {
    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        copy_1();
        long end = System.currentTimeMillis();
        System.out.println(end - start);
    }

    public static void copy_1() throws IOException {
        BufferedInputStream buffis = new BufferedInputStream(new FileInputStream("E:\\CloudMusic\\崔天琪 - 放过.mp3"));
        BufferedOutputStream buffos = new BufferedOutputStream(new FileOutputStream("test.mp3"));
        int by = 0;
        while ((by = buffis.read()) != -1)
            buffos.write(by);
        buffis.close();
        buffos.close();
    }
}
```
自己写的缓冲区
```java
import java.io.*;

class MyBufferedInputStream {
    private InputStream in;
    private byte[] buf = new byte[1024 * 4];
    private int pos = 0, count = 0;

    MyBufferedInputStream(InputStream in) {
        this.in = in;
    }

    //一个字节一个字节读数据
    public int myRead() throws IOException {
        //通过in对象读取数据
        if (count == 0) {
            count = in.read(buf);
            if (count < 0) {
                return -1;
            }
            pos = 0;
            byte b = buf[pos];
            count--;
            pos++;
            return b & 255;
        } else if (count > 0) {
            byte b = buf[pos];
            count--;
            pos++;
            return b & 255;//&255的原因是要int和byte之间的类型提升导致前四字节补1，
            //需要和00000000000000000000000011111111与过后将前三字节的1变成0，
            //使得判断条件-1变化
        }
        return -1;
    }

    public void myclose() throws IOException {
        in.close();
    }

    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        MyBufferedInputStream buffis = new MyBufferedInputStream(new FileInputStream("E:\\CloudMusic\\崔天琪 - 放过.mp3"));
        BufferedOutputStream buffos = new BufferedOutputStream(new FileOutputStream("test.mp3"));
        int by = 0;
        while ((by = buffis.myRead()) != -1)
            buffos.write(by);
        buffis.myclose();
        buffos.close();
        long end = System.currentTimeMillis();
        System.out.println(end - start);
    }
}
```

##### 键盘录入数据

```java
import java.io.*;

/*
System.out:输出
System.in:输入
 */
class ReadIn {
    public static void main(String[] args) throws IOException {
        InputStream in = System.in;//获取键盘输入流对象
        InputStreamReader isr=new InputStreamReader(in);//将字节流对象转换为字符流
        BufferedReader bufr=new BufferedReader(isr);
        String line=null;
        while ((line=bufr.readLine())!=null)
        {
            if (line.equals("over"))
                break;
            System.out.println(line.toUpperCase());
        }
    }
}
//        StringBuilder sb = new StringBuilder();
//        while (true) {
//            int ch = in.read();
//            if (ch == '\r')
//                continue;
//            if (ch == '\n') {
//                String s = sb.toString();
//                if (s.equals("over")) {
//                    break;
//                }
//                System.out.println(s.toUpperCase());
//                sb.delete(0, sb.length());
//            } else
//                sb.append((char) ch);
//        }

```
利用Scanner类进行录入
```java
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        while (sc.hasNext())
        {
            String s=sc.nextLine();
            System.out.println(s);
        }
    }
}
```
转换流对象
```java
import java.io.*;
/*
转换流对象
 */
class Main {
    public static void main(String[] args)throws IOException {
//        InputStream in = System.in;//获取键盘输入流对象
//        InputStreamReader isr=new InputStreamReader(in);//将字节流对象转换为字符流
//        BufferedReader bufr=new BufferedReader(isr);
        BufferedReader bufr=new BufferedReader(new InputStreamReader(System.in));
//        OutputStream out=System.out;
//        OutputStreamWriter osw=new OutputStreamWriter(out);
//        BufferedWriter bufw=new BufferedWriter(osw);
        BufferedWriter bufw=new BufferedWriter(new OutputStreamWriter(System.out));
        String line=null;
        while ((line=bufr.readLine())!=null)
        {
            if (line.equals("over"))
                break;
            bufw.write(line.toUpperCase());
            bufw.newLine();
            bufw.flush();
        }
    }
}
```
- 网络包log4j可以快速完成对日志的建立


- 利用IO流实现日志的打印
```java
import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;

/*
转换流对象
 */
class Main {
    public static void main(String[] args) throws IOException {
        try {
            int arr[] = new int[2];
            System.out.println(arr[3]);
        } catch (Exception e) {
            try {
                PrintStream ps=new PrintStream("Exception.log");
                Date d=new Date();
                SimpleDateFormat sb=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                String time=sb.format(d);
                ps.println(time);
                System.setOut(ps);
            } catch (IOException x) {
                throw new RuntimeException("文件创建失败");
            }
            e.printStackTrace(System.out);
        }
    }
}
```
- 输出设备信息
```java
import java.io.*;
import java.util.Properties;

class Main {
    public static void main(String[] args) throws IOException{
        Properties ps = System.getProperties();
        System.setOut(new PrintStream("SystemInfo.txt"));
        ps.list(System.out);
    }
}
```
###### FIle 类
```java
import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;

/*
构造方法和常用方法
 */
/*
1:创建
    Boolean createNewFile();//指定位置创建文件，如果已经有文件则不创建返回false;
    createTempFile​(String prefix, String suffix);
    createTempFile​(String prefix, String suffix, File directory)
    mkdir();//只能创建一级目录
    mkdirs();//能创建多级目录
2:删除
    boolean delete();
    void deleteOnExit();
3:判断
    boolean canExecute();
    boolean canRead();
    boolean canWrite();
    boolean exists();
4:获取信息
    getName();
    getParent();//返回绝对路径中的父目录，如果为相对路径返回空
	getParentFile();
	getPath();
 */
class Main {
    public static void main(String[] args) throws IOException {
//        listDemo();
        listfileDemo();
    }

    public static void listfileDemo() {//listfile返回的类型是类
        //而list返回String
        File x = new File("c:\\");
        File[] files = x.listFiles();
        for (File f : files) {
            System.out.println(f.getName() + "::" + f.length());
        }
    }

    public static void func() {
        File dir = new File("F:\\javaCode\\javaLearn");
        String[] arr = dir.list(new FilenameFilter() {
            @Override
            public boolean accept(File dir, String name) {
                return name.endsWith(".txt");
            }
        });
        for (String name : arr) {
            System.out.println(name);
        }
    }

    public static void function_1() throws IOException {
        File f = new File("FIle.txt");
        f.deleteOnExit();
//        System.out.println(f.createNewFile());
        System.out.println(f.delete());
    }

    public static void function_2() {
        File f2 = new File("test.txt");
        System.out.println(f2.canExecute());
        System.out.println(f2.canWrite());
        System.out.println(f2.canRead());
    }

    public static void function_3() {
        File f = new File("File.txt");
        //都返回false，因为文件不存在，所以必须判断文件是否存在
        System.out.println(f.isDirectory());
        System.out.println(f.isFile());
    }

    public static void function_4() {
        File f1 = new File("test.txt");
        File f2 = new File("haha.java");
        System.out.println(f1.renameTo(f2));
    }

    public static void function_5() {
        File[] files = File.listRoots();
        for (File f :
                files) {
            System.out.println(f);
        }

    }

    public static void listDemo() {//列出目录下所有文件和文件夹（包含隐藏文件）
        File f = new File("C:\\");//必须封装成目录，该目录必须存在
        String[] names = f.list();
        for (String s :
                names) {
            System.out.println(s);
        }
    }

    public static void gouzaofangfa() {
        File x = new File("a.txt");//当前文件的创建
        File f = new File("F\\IOTest", "test.txt");//父与子
        File f2 = new File("F\\IOTest");
        File f4 = new File(f2, "tets2.txt");
        File f5 = new File("F" + File.separator + "IOTest" + File.separator + "testx.txt");
        System.out.println(x);
        System.out.println(f);
        System.out.println(f2);
        System.out.println(f4);
    }
}
```
- 递归显示文件夹
```java
import java.io.*;

/*
列出指定目录下的文件或文件夹，包含子目录中的内容

 */
class Demox {
    public static void main(String[] args) {
        File dir = new File("E:\\Dell");
        showDir(dir,0);
    }

    public static String getx(int lv) {
        StringBuilder sb = new StringBuilder();
        sb.append("|--");
        for (int x = 0; x < lv; x++) {
            sb.insert(0,"|  ");
        }
        return sb.toString();
    }

    public static void showDir(File dir,int x) {
        System.out.println(getx(x)+dir.getName());
        File[] files = dir.listFiles();
        x++;
        for (int i = 0; i < files.length; i++) {
            if (files[i].isDirectory()) {
                showDir(files[i],x);
            } else {
                System.out.println(getx(x)+files[i]);
            }
        }
    }
}
```
- 递归删除
```java
import java.io.*;


class Demox {
    public static void main(String[] args) {
        File f=new File("D:\\");
        del(f);
    }

    public static void del(File dir) {
        File[] files = dir.listFiles();
        for (int i = 0; i < files.length; i++) {
            if (files[i].isDirectory()) {
                del(files[i]);
            } else {
                System.out.println(files[i].toString() + "::" + files[i].delete());
            }
        }
        dir.delete();
    }
}
```
##### properties（属性）类
```java
import java.io.*;
import java.util.Properties;
import java.util.Set;
/*
properties 类(属性)
 */

class Demox {
    public static void main(String[] args) throws IOException {
//        setAndGet();
        load_data_2();
    }

    public static void setAndGet() {
        Properties prop = new Properties();
        prop.setProperty("张三", "100");
        prop.setProperty("李四", "101");
//        System.out.println(prop);
        prop.setProperty("王五", "1000");
        System.out.println(prop.getProperty("李四"));
        Set<String> names = prop.stringPropertyNames();
        for (String s : names) {
            System.out.println(s + "::" + prop.getProperty(s));
        }
    }

    public static void load_data_2() throws IOException {
        Properties pro = new Properties();
        FileInputStream fis = new FileInputStream("info.txt");
        InputStreamReader ss = new InputStreamReader(fis);
        pro.load(ss);
        pro.setProperty("王五", "20");
        FileOutputStream fos = new FileOutputStream("info.txt");
        OutputStreamWriter ss2=new OutputStreamWriter(fos);
        pro.store(ss2, "haha");//store方法将更改写到文件中去
        System.out.println(pro);
        fos.close();
        fis.close();
    }

    public static void load_data() throws IOException {
        BufferedReader bufr = new BufferedReader(new FileReader("info.txt"));
        String line = null;
        Properties ps = new Properties();
        while ((line = bufr.readLine()) != null) {
            String[] arr = line.split("=");
            System.out.println(arr[0] + "::" + arr[1]);
            ps.setProperty(arr[0], arr[1]);
        }
        bufr.close();
        System.out.println(ps);
    }
}
```

- printStream
```java

import java.io.*;
/*
打印流：
字符打印流：
printWrite
构造函数可以接受的类型：
1：file对象
2：字符串路径
3：字节输出流OutputStream
字节打印流：
printStream
构造函数可以接受的类型：
1：file对象
2：字符串路径
3：字节输出流OutputStream
4：字符输出流Writer
 */
class demox {
    public static void main(String[] args)throws IOException {
        BufferedReader bufr=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr=new PrintWriter(System.out,true);
        String line=null;
        while ((line=bufr.readLine())!=null)
        {
            if("over".equals(line))
                break;
            pr.println(line.toUpperCase());
//            pr.flush();//如果为构造函数中的自动刷新为true可以不刷新
        }
        pr.close();
        bufr.close();
    }
}
```
- 合并流
```java
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.SequenceInputStream;
import java.util.Enumeration;
import java.util.Vector;
/*
合并流，将多个流合并成一个流
 */
class SequenceDemo {
    public static void main(String[] args) throws IOException {
        Vector<FileInputStream> v=new Vector<>();
        v.add(new FileInputStream("haha.java"));
        v.add(new FileInputStream("info.txt"));
        Enumeration<FileInputStream> en=v.elements();
        SequenceInputStream sis = new SequenceInputStream(en);
        FileOutputStream fos=new FileOutputStream("4.txt");
        byte[]buff=new byte[1024];
        int len=0;
        while ((len=sis.read(buff))!=-1)
        {
            fos.write(buff,0,len);

        }
        fos.close();
        sis.close();
    }

}
```
- 文件的合并
```java

import java.util.*;
import java.io.*;

/*
切割流
以及合并流
 */
class splitFile {
    public static void main(String[] args) throws IOException {
//        split();
        hebing();
    }

    public static void hebing() throws IOException {
        ArrayList<FileInputStream> a = new ArrayList<FileInputStream>();
        for (int i = 1; i <= 10; i++) {
            a.add(new FileInputStream("F:\\javaCode\\javaLearn\\splitFiles\\" + i + ".part"));
        }
        Iterator it = a.iterator();
        final Enumeration<FileInputStream> em = new Enumeration<FileInputStream>() {
            @Override
            public boolean hasMoreElements() {
                return it.hasNext();
            }

            @Override
            public FileInputStream nextElement() {
                return (FileInputStream) it.next();
            }
        };
        SequenceInputStream seq = new SequenceInputStream(em);
        FileOutputStream fos = new FileOutputStream("F:\\javaCode\\javaLearn\\splitFiles\\test2.mp3");
        int len = 0;
        byte[] buf = new byte[1024 * 1024];
        while ((len = seq.read(buf)) != -1) {
            fos.write(buf, 0, len);

        }
        fos.close();
        seq.close();
    }

    public static void split() throws IOException {
        FileInputStream fis = new FileInputStream("F:\\javaCode\\javaLearn\\test.mp3");
        FileOutputStream fos = null;
        byte[] buf = new byte[1024 * 1024];
        int len = 0;
        int count = 1;
        while ((len = fis.read(buf)) != -1) {
            fos = new FileOutputStream("F:\\javaCode\\javaLearn\\splitFiles\\" + count++ + ".part");
            fos.write(buf, 0, len);
            fos.close();
        }
        fis.close();
    }
}
```
- ObjectInputStream和ObjectOutputStream
```java
import java.io.*;

class ObjectInputDemo {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        writeObj();
//        load();
    }

    public static void writeObj() throws IOException {
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("obj.txt"));
        Person p = new Person("张三", 2);
        oos.writeObject(p);
        oos.close();
    }

    public static void load() throws IOException, ClassNotFoundException {
        ObjectInputStream in = new ObjectInputStream(new FileInputStream("obj.txt"));
        Person p = (Person) in.readObject();
        System.out.println(p.age);
        in.close();

    }
}

class Person implements Serializable {//必须实现序列化接口
    //静态无法被序列化

    private String name;
    transient int age; //部分成员不想被序列化的话可以加transient

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}
```
- 管道流
```java
import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

/*
管道输入流和管道输出流：

 */
class Demox {
    public static void main(String[] args) throws IOException {
        PipedOutputStream out = new PipedOutputStream();
        PipedInputStream in = new PipedInputStream();
        in.connect(out);
        Read r = new Read(in);
        Write w = new Write(out);
        new Thread(r).start();
        new Thread(w).start();

    }
}

class Read implements Runnable {
    private PipedInputStream in;

    Read(PipedInputStream in) {
        this.in = in;
    }

    public void run() {
        try {
            byte[] buf = new byte[1024];
            System.out.println("读取前准备");
            int len = in.read(buf);
            String s = new String(buf, 0, len);
            System.out.println(s);
            in.close();
        } catch (IOException e) {
            throw new RuntimeException("管道读取失败");
        }
    }
}

class Write implements Runnable {
    private PipedOutputStream out;

    Write(PipedOutputStream out) {
        this.out = out;
    }

    @Override
    public void run() {
        try {
            System.out.println("正在写，等待六秒");
            Thread.sleep(6000);
            out.write("管道".getBytes());
            out.close();
        } catch (Exception e) {
            throw new RuntimeException("管道写入失败");
        }
    }
}
```
- RandomAccessFile（随机访问流）
```java

/*
RandomAccessFile类:
直接继承自Object类，具备读写功能，内部封装数组
通过getFilePointer获取指针位置
seek改变指针位置
只能操作文件
可以实现多线程的下载

 */

import java.io.IOException;
import java.io.RandomAccessFile;

class Demox {
    public static void main(String[] args) throws IOException {
//        writeFile();
//        read();
//        randomWrite();
    }

    public static void writeFile() throws IOException {
        RandomAccessFile raf = new RandomAccessFile("a.txt", "rw");
        raf.write("李四".getBytes());
        raf.writeInt(97);
        raf.write("李二".getBytes());
        raf.writeInt(55);
        raf.close();
    }

    public static void read() throws IOException {
        RandomAccessFile raf = new RandomAccessFile("a.txt", "rw");
        raf.seek(6);//调整指针位置
        raf.skipBytes(12);//跳过的字节数
        byte[] buf = new byte[6];
        raf.read(buf);
        int age = raf.readInt();
        String s = new String(buf);
        System.out.println(s);
        System.out.println(age);
        raf.close();
    }

    public static void randomWrite() throws IOException {
        RandomAccessFile raf = new RandomAccessFile("a.txt", "rw");
        raf.seek(8*3);
        raf.write("周期".getBytes());
        raf.writeInt(103);
        raf.close();
    }
}
```
- DataInputStream和DataOutputStream
```java
import java.io.*;

/*
可以用于操作基本数据类型的流对象。

 */
class DataStreamDemo {
    public static void main(String[] args) throws IOException {
//        write();
//        read();
//        write_utf();
        read_utf();
    }
    public static void read() throws IOException
    {
        DataInputStream fis=new DataInputStream(new FileInputStream("data.txt"));
        int num=fis.readInt();
        boolean n=fis.readBoolean();
        double x=fis.readDouble();
        System.out.println(num);
        System.out.println(n);
        System.out.println(x);
        fis.close();
    }
    public static void write_utf() throws IOException {
        DataOutputStream out=new DataOutputStream(new FileOutputStream("UTF.txt"));
        out.writeUTF("我打算记得那时看见你");
        out.close();
    }
    public static void read_utf() throws IOException {
        DataInputStream in=new DataInputStream(new FileInputStream("UTF.txt"));
        String xx=in.readUTF();
        System.out.println(xx);

    }
        public static void write() throws IOException{
        DataOutputStream out=new DataOutputStream(new FileOutputStream("data.txt"));
        out.writeInt(123);
        out.writeBoolean(true);
        out.writeDouble(123.43);
        out.close();
    }
}
```
![流体系](..\Java\TIM截图20190620201411.jpg)
- 操作字节数组的流（byteArrayInputStream和ByteArrayOutputStream）
```java
import java.io.*;

/*
ByteArrayInputStream:在构造的时候。需要接受数据源，而且数据源是一个字节数组
ByteArrayOutputStream:在构造的时候不用定于数据目的，因为该对象中已经封装了一个可变长度的数组，即为数据目的地
所以不需要关闭。
 */
class Demoxx {
    public static void main(String[] args) {
        //数据源
        ByteArrayInputStream bis = new ByteArrayInputStream("ABHJASBDJAS".getBytes());
        //数据目的
        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        int by = 0;
        while ((by = bis.read()) != -1) {
            bos.write(by);
        }
        bos.writeTo(new FileOutputStream("x.txt"));
        System.out.println(bos.size());//大小
        System.out.println(bos.toString());
    }
}
```
- 编码问题

```java
import java.io.*;

class Demoxx {
    public static void main(String[] args) throws IOException{
//        write();
        read();
    }

    public static void read() throws IOException {
        InputStreamReader isr=new InputStreamReader(new FileInputStream("gbk.txt"),"utf-8");
        char buf[] =new char[10];
        int len=isr.read(buf);
        String str=new String(buf,0,len);
        System.out.println(str);
        isr.close();
    }

    public static void write() throws IOException {
        OutputStreamWriter osw=new OutputStreamWriter(new FileOutputStream("gbk.txt"),"gbk");
        osw.write("你好");
        osw.close();
    }
}
```
#### GUI编程

###### 窗口事件
```java

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

class Demos {
    private Frame f;
    private Button butt;
    Demos()
    {
        init();
    }
    public void init()
    {
        f=new Frame();
        f.setBounds(200,300,500,400);//设置窗体
        f.setLayout(new FlowLayout());
        butt=new Button("my button");//设置按钮
        f.add(butt);
        myEvent();//加载窗体事件
        f.setVisible(true);
    }
    private void myEvent()
    {
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        butt.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("退出，按钮");
                System.exit(0);
            }
        });
    }
    public static void main(String[] args) {
        new Demos();
    }
}
```
###### 鼠标事件
```java

import java.awt.*;
import java.awt.event.*;

class Demos {
    private Frame f;
    private Button butt;
    Demos()
    {
        init();
    }
    public void init()
    {
        f=new Frame();
        f.setBounds(200,300,500,400);//设置窗体
        f.setLayout(new FlowLayout());
        butt=new Button("my button");//设置按钮
        f.add(butt);
        myEvent();//加载窗体事件
        f.setVisible(true);
    }
    private void myEvent()
    {
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        butt.addMouseListener(new MouseAdapter() {
            private int i=0;
            public void mouseClicked(MouseEvent e) {
                if (e.getClickCount()==2)
                    System.out.println("双击事件");
            }
        });
        butt.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("action");
            }
        });
        butt.addMouseListener(new MouseAdapter() {
            private int count=1;
            @Override
            public void mouseEntered(MouseEvent e) {
                System.out.println("鼠标进入"+count++);
            }
        });
    }
    public static void main(String[] args) {
        new Demos();
    }
}
```

###### 键盘事件

```java
import java.awt.*;
import java.awt.event.*;

class Demos {
    private Frame f;
    private Button butt;
    private TextField ts;

    Demos() {
        init();
    }

    public void init() {
        f = new Frame();
        f.setBounds(200, 300, 500, 400);//设置窗体
        f.setLayout(new FlowLayout());
        butt = new Button("my button");//设置按钮
        ts=new TextField(20);
        f.add(ts);
        f.add(butt);
        myEvent();//加载窗体事件
        f.setVisible(true);
    }

    private void myEvent() {
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        butt.addMouseListener(new MouseAdapter() {
            private int i = 0;
            public void mouseClicked(MouseEvent e) {
                if (e.getClickCount() == 2)
                    System.out.println("双击事件");
            }
        });
        ts.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (!(e.getKeyCode()>=KeyEvent.VK_0&&e.getKeyCode()<=KeyEvent.VK_9)) {
                    System.out.println("Wrong input");
                    e.consume();
                }
                else
                    System.out.println(e.getKeyChar()+"..."+e.getKeyCode());
            }
        });
        butt.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ESCAPE)
                    System.exit(0);
                if (e.isControlDown() && e.getKeyCode() == KeyEvent.VK_ENTER)
                    System.out.println("同时被按下");
                System.out.println(KeyEvent.getKeyText(e.getKeyCode()) + "...." + e.getKeyCode());
            }
        });
//        butt.addActionListener(new ActionListener() {
//            @Override
//            public void actionPerformed(ActionEvent e) {
//                System.out.println("action");
//            }
//        });
//        butt.addMouseListener(new MouseAdapter() {
//            private int count = 1;
//
//            @Override
//            public void mouseEntered(MouseEvent e) {
//                System.out.println("鼠标进入" + count++);
//            }
//        });
    }

    public static void main(String[] args) {
        new Demos();
    }
}
```
- 实现输入文件目录后直接输出文件夹中的文件名（GUI）
```java

import java.awt.*;
import java.awt.event.*;
import java.io.File;

class MyWindows extends Frame {
    private Frame f;
    private TextField tf;
    private Button but;
    private TextArea ta;
    private Dialog dialog;
    private Label lable;
    private Button okbu;

    MyWindows() {
        init();
    }

    public void init() {
        f = new Frame("my windows");
        f.setBounds(300, 100, 500, 700);
        f.setLayout(new FlowLayout());
        tf = new TextField(60);
        but = new Button("go to");
        ta = new TextArea(30, 60);
        lable = new Label();
        okbu = new Button("ok");
        dialog = new Dialog(f, "Error", true);
        dialog.setBounds(300, 100, 200, 300);
        dialog.setLayout(new FlowLayout());
        f.add(tf);
        f.add(but);
        f.add(ta);
        dialog.add(lable);
        dialog.add(okbu);
        f.setVisible(true);
        myEvent();
    }

    private void myEvent() {
        dialog.addWindowFocusListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                dialog.setVisible(false);
            }
        });
        okbu.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dialog.setVisible(false);
            }
        });
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        tf.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    function();
                }
            }
        });
        but.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                function();
            }
        });
    }

    private void function() {
        String dir = tf.getText();
        System.out.println(dir);
        File file = new File(dir);
        if (file.exists() && file.isDirectory()) {
            ta.setText("");
            String[] names = file.list();
            for (String name : names) {
                ta.append(name + "\r\n");
            }
        } else {
            String info = "宁输入的路径:" + file.getName() + "请重新输入";
            lable.setText(info);
            dialog.setVisible(true);
        }
        tf.setText("");
    }

    public static void main(String[] args) {
        new MyWindows();
    }
}
```
- 菜单


```java


import java.awt.*;
import java.awt.event.*;


class myMenu {
    private Frame f;
    private MenuBar mb;
    private Menu m, subm;
    private MenuItem closeItem, subItem;

    myMenu() {
        init();
    }

    public void init() {
        f = new Frame("my");
        f.setBounds(300, 100, 500, 600);
        f.setLayout(new FlowLayout());
        mb = new MenuBar();
        m = new Menu("file");
        subm = new Menu("sub menu");
        closeItem = new MenuItem("exit");
        subItem = new MenuItem("sub");
        m.add(subm);
        subm.add(subItem);
        m.add(closeItem);
        mb.add(m);
        f.setMenuBar(mb);
        myEvent();
        f.setVisible(true);
    }

    public void myEvent() {
        closeItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public static void main(String[] args) {
        new myMenu();
    }
}
```

- 打开读取文件

```java
import java.awt.*;
import java.awt.event.*;
import java.io.*;


class myMenu {
    private Frame f;
    private MenuBar mb;
    private Menu m, subm;
    private MenuItem closeItem, openItem, saveItem;
    private FileDialog open, save;
    private TextArea ta;
    private File file;

    myMenu() {
        init();
    }

    public void init() {
        f = new Frame("my");
        f.setBounds(300, 100, 650, 600);
//        f.setLayout(new FlowLayout());
        mb = new MenuBar();
        m = new Menu("file");
        subm = new Menu("sub menu");
        closeItem = new MenuItem("exit");
        openItem = new MenuItem("open");
        saveItem = new MenuItem("save");
        open = new FileDialog(f, "open", FileDialog.LOAD);
        save = new FileDialog(f, "save", FileDialog.SAVE);
        ta = new TextArea();
        m.add(openItem);
        m.add(saveItem);
        m.add(closeItem);
        mb.add(m);
        f.setMenuBar(mb);
        f.add(ta);
        myEvent();
        f.setVisible(true);
    }

    public void myEvent() {
        openItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                open.setVisible(true);
                String file1 = open.getFile();
                String dir = open.getDirectory();
                if (dir == null || file1 == null)
                    return;
                ta.setText("");
                file = new File(dir, file1);
                try {
                    BufferedReader bufr = new BufferedReader(new FileReader(file));
                    String line = null;
                    while ((line = bufr.readLine()) != null) {
                        ta.append(line + "\r\n");
                    }
                } catch (IOException er) {
                    er.printStackTrace();
                }
            }
        });

        saveItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (file == null) {
                    save.setVisible(true);
                    String file1 = save.getFile();
                    String dir = save.getDirectory();
                    if (dir == null || file1 == null)
                        return;
                    file = new File(dir, file1);
                }
                try {
                    BufferedWriter bfw = new BufferedWriter(new FileWriter(file));
                    String text = ta.getText();
                    bfw.write(text);
                    bfw.close();
                } catch (IOException ex) {
                    ex.printStackTrace();
                }

            }
        });
        closeItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public static void main(String[] args) {
        new myMenu();
    }
}
```
#### 网络编程
- ip地址主机对应关系
```java
package Demo;
import java.net.*;
public class TCPDemo {
    public static void main(String[] args)throws Exception {
        InetAddress i=InetAddress.getLocalHost();
        System.out.println(i.getHostAddress());
        System.out.println(i.getHostName());
        InetAddress[] is=InetAddress.getAllByName("www.baidu.com");
        for (InetAddress ia :is) {
            System.out.println(ia.getHostAddress());
            System.out.println(ia.getHostName());
        }
    }
}
````
- UDP通讯

```java
package Demo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.*;

class Send {
    public static void main(String[] args) throws Exception {
        //1:创建UDP服务
        DatagramSocket ds = new DatagramSocket(8888);
        //2:封装数据
        BufferedReader bfr = new BufferedReader(new InputStreamReader(System.in));
        String line = null;
        while ((line = bfr.readLine()) != null) {
            if ("886".equals(line))
                break;
            byte[] buf = line.getBytes();//3:发送数据
            DatagramPacket dp = new DatagramPacket(buf, 0, buf.length, InetAddress.getByName("192.168.4.219"), 10000);
            ds.send(dp);
        }
        //4:关闭资源
        ds.close();
    }
}

class UDPrec {
    public static void main(String[] args) throws Exception {
//1:创建UDP服务，建立端点
        DatagramSocket ds = new DatagramSocket(10000);
//2:定义数据包
        while (true) {
            byte[] data = new byte[1024];
            DatagramPacket dp = new DatagramPacket(data, data.length);
//3:通过receive方法方法存入数据
            ds.receive(dp);
//4:获取数据
            String ip = dp.getAddress().getHostAddress();
            String da = new String(dp.getData(), 0, dp.getLength());
            int port = dp.getPort();
            System.out.println(ip + "::" + da + "::" + port);
        }
    }
}
```
- 多线程完成聊天程序

```java
package Demo;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

class Send implements Runnable{
    private DatagramSocket ds;
    public Send(DatagramSocket ds)
    {
        this.ds=ds;
    }
    public void run() {
        try{
            BufferedReader bfr=new BufferedReader(new InputStreamReader(System.in));
            String line=null;
            while ((line=bfr.readLine())!=null)
            {
                if ("886".equals(line))
                    break;
                byte[] buf=line.getBytes();
                DatagramPacket data=new DatagramPacket(buf,buf.length, InetAddress.getByName("192.168.4.255"),10001);
                ds.send(data);
            }
        }
        catch (Exception e)
        {
            throw new RuntimeException("发送失败");
        }
    }

}
class Rece implements Runnable
{
    private DatagramSocket ds;
    private Rece(DatagramSocket ds)
    {
        this.ds=ds;
    }
    public void run() {
        try{
            while (true)
            {
                byte[] buf=new byte[1024];
                DatagramPacket dp=new DatagramPacket(buf,buf.length);
                ds.receive(dp);
                String ip=dp.getAddress().getHostAddress();
                String data=new String(dp.getData(),0,dp.getLength());
                System.out.println(ip+"::"+data);
            }
        }
        catch (Exception e)
        {
            throw new RuntimeException("接收失败");
        }
    }

    public static void main(String[] args)throws Exception {
        DatagramSocket sendSocket=new DatagramSocket();
        DatagramSocket receSocket=new DatagramSocket(10001);
        new Thread(new Send(sendSocket)).start();
        new Thread(new Rece(receSocket)).start();
    }
}
```

###### TCP演示

```java
package Demo;
/*
TCP演示：
客户端：
Socket
服务端：
serverSocket
 */

import java.io.InputStream;
import java.io.OutputStream;
import java.net.ServerSocket;
import java.net.Socket;

class TCPClient{
    public static void main(String[] args) throws Exception{
        Socket s=new Socket("192.168.4.219",10003);
        OutputStream out=s.getOutputStream();
        out.write("TCP recived".getBytes());
        s.close();
    }
}
class TCPServer
{
    public static void main(String[] args) throws Exception{
        ServerSocket ss=new ServerSocket(10003);//建立服务
        Socket s=ss.accept();//获取客户端对象
        String ip=s.getInetAddress().getHostAddress();
        System.out.println(ip+"is connected");
        InputStream in =s.getInputStream();
        byte []buf=new byte[1024];
        int len=in.read(buf);
        System.out.println(new String(buf,0,len));
        s.close();
        ss.close();
    }
}
```