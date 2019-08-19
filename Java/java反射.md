# Java反射
[TOC]
### 代码的运行的三个阶段
1. 源代码阶段
2. class类对象阶段
3. 运行时阶段

### 加载Class类的`三种`方式

1.Class.forName("全类名"):将字节码加载进入内存中(用于配置文件)  
2.类名.Class:通过类名的class属性进行获取(多用于参数的传递)  
3.对象.getClass:获取对象类的class属性(多用于获取字节码)  

```java
package com.SpringLearn;

public class ReflectDemo {
    public static void main(String[] args) throws Exception{
        //1：Class.forName();
        Class cls=Class.forName("com.SpringLearn.HelloWorld");
        System.out.println(cls);
        //2:类名.class
        Class cls2=HelloWorld.class;
        System.out.println(cls2);
        //3:对象.getClass()
        HelloWorld he=new HelloWorld();
        Class cls3=he.getClass();
        System.out.println(cls3);
        System.out.println(cls==cls2);
        System.out.println(cls==cls3);
        System.out.println(cls2==cls3);

    }
}
```
结论:
- 同一个class文见在程序运行的时候只加载一次

#### Class对象的功能

1:获取成员变量们  
2:获取构造方法们   
3:获取成员方法们  
4:获取类名  


`Person类代码`
```java
package com.SpringLearn;
class  Person{
    public String message;
    public String name;
    private String sex;

    @Override
    public String toString() {
        return "HelloWorld{" +
                "message='" + message + '\'' +
                ", name='" + name + '\'' +
                ", sex='" + sex + '\'' +
                '}';
    }

    public Person() {
    }

    public Person(String message, String name, String sex) {
        this.message = message;
        this.name = name;
        this.sex = sex;
    }

    public Person(String message, String name) {
        this.message = message;
        this.name = name;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        System.out.println("You message is: " + message);
    }
}
```
- 成员变量
```java
package com.SpringLearn;

import java.lang.reflect.Field;

class ReflectDemo2 {
    public static void main(String[] args) throws Exception {
        Class cls = HelloWorld.class;
        //获取成员变量
        Field[] fl = cls.getFields();//获取Public修饰的成员变量
        Field f2 = cls.getField("message");//获取指定名称的成员变量
        HelloWorld h = new HelloWorld();
        f2.set(h, "123");
        Object value = f2.get(h);//获取值,必须有对象
        System.out.println(value);
        System.out.println(f2);
        for (Field f : fl) {
            System.out.println(f);
        }
        System.out.println("-----------------------");
        Field[] fs = HelloWorld.class.getDeclaredFields();//获取所有的修饰符不考虑成员变量
        for (Field ss : fs)
            System.out.println(ss);
        //同时可以修改私有的值
        Field ff=cls.getDeclaredField("sex");
        ff.setAccessible(true);//暴力反射，不考虑修饰符
        Object ob=ff.get(h);//直接访问会报异常，因为无法访问私有，需要忽略修饰符权限
        System.out.println(ob);
    }
}
```
- 构造方法
```java
package com.SpringLearn;

import java.lang.reflect.Constructor;

class ReflectDemo2 {
    public static void main(String[] args) throws Exception {
        Class personclass = Person.class;
        Constructor cons = personclass.getConstructor(String.class, String.class);//获取有参数的构造方法
        System.out.println(cons);
        Object person = cons.newInstance("张三", "hehe");
        System.out.println(person);
        System.out.println("------------------------------");
        Constructor cons1 = personclass.getConstructor();//获取无参数的构造方法
        //可以简化为Class对象的newInstance,如下
        personclass.newInstance();
        System.out.println(cons1);
        Object person1 = cons1.newInstance();
        System.out.println(person1);
    }
}
```
- 成员方法
```java
package com.SpringLearn;

import java.lang.reflect.Method;

class ReflectDemo3 {
    public static void main(String[] args) throws Exception {
        //成员方法
        Class personClass = Person.class;
        //获取指定名称方法
        Method function = personClass.getMethod("eat");
        //执行方法
        Person p=new Person();
        function.invoke(p);//执行
        Method function2=personClass.getMethod("eat",String.class);
        function2.invoke(p,"吃饭");
        System.out.println("-------------------------------------");
        //获取所有public方法
        Method [] methods=personClass.getMethods();
        function.setAccessible(true);
        function2.setAccessible(true);
        for (Method m:methods)
            System.out.println(m);
    }
}
```
- 获取类名

```java
System.out.println(personClass.getName());  
```
