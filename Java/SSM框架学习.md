## <center>SSM框架学习</center>

### [mybatis](./mybatis.md)
### [Spring MVC](./spring_mvc.md)
### [Spring](./Spring学习.md)
[TOC]

### java设计模式

- 反射
[java反射](./java反射.md)

#### 动态代理和责任链模式( `需要进行接口的定义` )
- JDK动态代理  
JDK动态代理代理演示

`接口`
```java
package com.SpringLearn;

public interface HelloWorld {
    public void sayHello();
}
```
`实现部分`
```java
package com.SpringLearn;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

class Hello implements HelloWorld {
    @Override
    public void sayHello() {
        System.err.println("Hello world !");
    }
}


public class JDKproxyDemo implements InvocationHandler {

    private Object taret = null;

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        //第一个参数代理对象
        //第二个参数当前调度的方法
        //第三个调度方法的参数
        System.out.println("进入代理方法之前");
        System.out.println("在调度真实对象之前的服务");
        Object obj = method.invoke(taret, args);
        System.out.println("调用真实服务之后");
        return obj;
    }

    public Object bind(Object taret) { //绑定对象
        this.taret = taret;
        return Proxy.newProxyInstance(taret.getClass().getClassLoader(), taret.getClass().getInterfaces(), this);
        //第一个参数是类加载器
        //第二个参数为动态代理实现的接口
        //第三个是实现方法逻辑的代理类

    }


    public static void main(String[] args) {
        JDKproxyDemo jdk = new JDKproxyDemo();
        HelloWorld proxy = (HelloWorld) jdk.bind(new Hello());
        proxy.sayHello();
    }

}
```
- CGLIB代理模式（`不需要提供接口`）
```java
package com.SpringLearn;

import org.junit.Test;
import org.springframework.cglib.proxy.Enhancer;
import org.springframework.cglib.proxy.MethodInterceptor;
import org.springframework.cglib.proxy.MethodProxy;

import java.lang.reflect.Method;

public class CGLIBproxyDemo implements MethodInterceptor {
    /*
    生成CGLIB对象
    */
    public Object getProxy(Class cls) {
        Enhancer enhancer = new Enhancer();//增强类对象
        enhancer.setSuperclass(cls);//设置增强类型
        enhancer.setCallback(this);//定义代理逻辑对象为当前对象，要求实现MethodIntercept
        return enhancer.create();
    }

    @Override
    public Object intercept(Object o, Method method, Object[] objects, MethodProxy methodProxy) throws Throwable {
        System.out.println("调用真实对象前");
        Object obj = methodProxy.invokeSuper(o, objects);
        System.out.println("调用真实对象后");
        return obj;
    }

    @Test
    public void testCGLIBproxy() {
        CGLIBproxyDemo cpe = new CGLIBproxyDemo();
        ReflectDemo obj = (ReflectDemo) cpe.getProxy(ReflectDemo.class);
        obj.sayHello("张三");
    }
}
```
###### 拦截器

1.拦截器的接口声明
```java
package com.SpringLearn;

import java.lang.reflect.Method;

//拦截器类
public interface Intercepter {
    //before在返回真是对象前进行调用，为True时调用真实对象的方法，false则调用around方法
    public boolean before(Object proxy, Object target, Method method,Object args[]);
    public void around(Object proxy, Object target, Method method,Object args[]);
    public void after(Object proxy, Object target, Method method,Object args[]);
}
```
2.设置拦截器及逻辑
```java
package com.SpringLearn;

import org.junit.Test;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;
import java.lang.reflect.Proxy;

public class MyInterceptor implements Intercepter {

    @Override
    public boolean before(Object proxy, Object target, Method method, Object[] args) {
        System.err.println("反射方法前的逻辑");
        return false;
    }

    @Override
    public void around(Object proxy, Object target, Method method, Object[] args) {
        System.out.println("取代了被代理对象的方法");
    }

    @Override
    public void after(Object proxy, Object target, Method method, Object[] args) {
        System.out.println("反射方法后的逻辑");
    }
}
//在JDK动态代理中使用拦截器

class InterceptorJDKDemo implements InvocationHandler {
    private Object target = null;//真实对象
    private String interceptorClass = null;//拦截器的全类名

    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        if (interceptorClass == null) {
            return method.invoke(target, args);
        }
        Object result = null;
        Intercepter intercepter = (Intercepter) Class.forName(interceptorClass).newInstance();
        if (intercepter.before(proxy, target, method, args)) {
            result = method.invoke(target, args);
        } else {
            intercepter.around(proxy, target, method, args);
        }
        intercepter.after(proxy, target, method, args);
        return result;
    }

    public InterceptorJDKDemo(Object target, String interceptorClass) {
        this.target = target;
        this.interceptorClass = interceptorClass;
    }

    public static Object bind(Object target, String interceptorClass) {
        return Proxy.newProxyInstance(target.getClass().getClassLoader(),
                target.getClass().getInterfaces(), new InterceptorJDKDemo(target, interceptorClass));
    }
}
```
3.单元测试(使用上面的类进行测试)
```java
package com.SpringLearn;

public class Test {
    @org.junit.Test
    public void testForJDKProxy() {
        HelloWorld proxy = (HelloWorld) InterceptorJDKDemo.bind(new Hello(), "com.SpringLearn.MyInterceptor");
        proxy.sayHello();
    }
}
```
##### 责任链模式

在一个处理过程中有多个拦截器我们成为责任链模式

- 责任链模式可以比作一个员工共请假但是要经过多个部门进行审批的设计模式
三个拦截器
1.
```java
package com.SpringLearn;

import java.lang.reflect.Method;

public class Intercepter1 implements Intercepter{
    @Override
    public boolean before(Object proxy, Object target, Method method, Object[] args) {
        System.out.println("拦截器一的before方法");
        return true;
    }

    @Override
    public void around(Object proxy, Object target, Method method, Object[] args) {
    }

    @Override
    public void after(Object proxy, Object target, Method method, Object[] args) {
        System.out.println("拦截器一的after方法");
    }
}
```
2.
```java
package com.SpringLearn;

import java.lang.reflect.Method;

public class Intercepter2 implements Intercepter{
    @Override
    public boolean before(Object proxy, Object target, Method method, Object[] args) {
        System.out.println("拦截器二的before方法");
        return true;
    }

    @Override
    public void around(Object proxy, Object target, Method method, Object[] args) {

    }

    @Override
    public void after(Object proxy, Object target, Method method, Object[] args) {
        System.out.println("拦截器二的after方法");
    }
}
```
3.
```java
package com.SpringLearn;

import org.junit.Test;

import java.lang.reflect.Method;

public class Intercept3 implements Intercepter{
    @Override
    public boolean before(Object proxy, Object target, Method method, Object[] args) {
        System.out.println("拦截器三的before方法");
        return true;
    }

    @Override
    public void around(Object proxy, Object target, Method method, Object[] args) {

    }

    @Override
    public void after(Object proxy, Object target, Method method, Object[] args) {
        System.out.println("拦截器一的after方法");
    }
    @Test
    public void test()
    {
        HelloWorld proxy1= (HelloWorld) InterceptorJDKDemo.bind(new Hello(),"com.SpringLearn.Intercepter1");
        HelloWorld proxy2= (HelloWorld) InterceptorJDKDemo.bind(proxy1,"com.SpringLearn.Intercepter2");
        HelloWorld proxy3= (HelloWorld) InterceptorJDKDemo.bind(proxy2,"com.SpringLearn.Intercept3");
        proxy3.sayHello();
    }
}
```
- 运行结果
```
拦截器三的before方法
拦截器二的before方法
拦截器一的before方法
Hello world !
拦截器一的after方法
拦截器二的after方法
拦截器一的after方法
```

##### 观察者模式
- 让多个观察者观察被观察者的状态，当被观察者的行为发生变化时，通知所有的观察者

执行部分
```java
package com.SpringLearn;

import com.SpringLearn.DesignModel.*;

public class Test {
//    @org.junit.Test
//    public void testForJDKProxy() {
//        HelloWorld proxy = (HelloWorld) InterceptorJDKDemo.bind(new Hello(), "com.SpringLearn.DesignModel.MyInterceptor");
//        proxy.sayHello();
//    }
    @org.junit.Test
    public void productTest()
    {
        ProductList productList=ProductList.getInstance();
        TBObserver tbObserver=new TBObserver();
        JDObserver jdObserver=new JDObserver();
        productList.addProductListObserver(tbObserver);
        productList.addProductListObserver(jdObserver);
        productList.addProduct("电脑2");
    }
}
```
两个配置
```java
package com.SpringLearn.DesignModel;

import java.util.Observable;
import java.util.Observer;

public class JDObserver implements Observer {
    @Override
    public void update(Observable o, Object arg) {
        String newProduct=(String)arg;
        System.out.println("新产品: "+newProduct+"同步到JD");
    }
}
------------------------------------------------------------
package com.SpringLearn.DesignModel;

import org.junit.Test;

import java.util.Observable;
import java.util.Observer;

public class TBObserver implements Observer {
    @Override
    public void update(Observable o, Object arg) {
        String newProduct=(String)arg;
        System.out.println("新产品: "+newProduct+"同步到TB");
    }
}
```

##### 工厂模式和抽象工厂模式
- 工厂模式（Factory Pattern）是 Java 中最常用的设计模式之一。这种类型的设计模式属于创建型模式，它提供了一种创建对象的最佳方式。

    在工厂模式中，我们在创建对象时不会对客户端暴露创建逻辑，并且是通过使用一个共同的接口来指向新创建的对象。  
- 伪代码
```java
package com.SpringLearn.DesignModel;

public class IProduct {
    public static IProduct createProduct(String productNO){
        switch (productNO){
            case "1":
                return new Product1(xxx);
            case "2":
                return new Product2(xxx);
            case "3":
                return new Product3(xxx);
            case "4":
                return new Product4(xxx);
                default:
                    throw new Exception(); 
        }
    }
}
```

- 抽象工厂模式

抽象工厂模式可以向客户端提供共一个接口，使得客户端不必指定产品的具体情况下创建多个产品对象

```java
package com.SpringLearn.DesignModel;

public interface IProductFactory {
    IProduct createProduct(String productNo);
}

class Product1 implements IProductFactory{

    @Override
    public IProduct createProduct(String productNo) {
        IProduct product=xxx;//工厂一生成产品对象规则
        return product;
    }
}
class Product2 implements IProductFactory{

    @Override
    public IProduct createProduct(String productNo) {
        IProduct product=xxx;//工厂二生成产品对象规则
        return product;
    }
}
class Product3 implements IProductFactory{

    @Override
    public IProduct createProduct(String productNo) {
        IProduct product=xxx;//工厂三生成产品对象规则
        return product;
    }
}
class Product4 implements IProductFactory{

    @Override
    public IProduct createProduct(String productNo) {
        IProduct product=xxx;//工厂四生成产品对象规则
        return product;
    }
}
```
IProduct.java
```java
package com.SpringLearn.DesignModel;

public class IProduct {
    public static IProduct createProduct(String productNO) throws Exception {
        switch (productNO){
            case "1":
                return new Product1(xxx);
            case "2":
                return new Product2(xxx);
            case "3":
                return new Product3(xxx);
            case "4":
                return new Product4(xxx);
                default:
                    throw new Exception();
        }
    }
}
```
使用类
```java
package com.SpringLearn.DesignModel;

public class ProductFactory implements IProductFactory {
    @Override
    public IProduct createProduct(String productNo) {
        IProductFactory factory = null;
        char ch = productNo.charAt(0);
        switch (ch) {
            case '1':
                factory = new Product1();
                break;
            case '2':
                factory = new Product2();
                break;
            case '3':
                factory = new Product3();
                break;
            case '4':
                factory = new Product4();
                break;
            default:
                return factory.createProduct(productNo);
        }
        return null;
    }
}
```
##### 建造者模式
Builder模式的实例（以卖票为例子）

运行实例
```java
 @org.junit.Test
    public void testbuilder() {
        TicketHelper helper=new TicketHelper();
        helper.buildAdult("成年");
        helper.buildChildrenForNoSeat("无座儿童");
        helper.buildChildrenForSeat("有座儿童");
        helper.buildElderly("老人");
        helper.buildSoilder("军人");
    }
```
构建
```java
package com.SpringLearn.DesignModel;

public class TicketHelper {
    public void buildAdult(String info) {
        System.out.println("成年票的逻辑" + info);
    }

    public void buildChildrenForSeat(String info) {
        System.out.println("儿童有座逻辑" + info);
    }

    public void buildChildrenForNoSeat(String info) {
        System.out.println("儿童无座逻辑" + info);
    }

    public void buildElderly(String info) {
        System.out.println("老年人逻辑" + info);
    }

    public void buildSoilder(String info) {
        System.out.println("军人逻辑" + info);
    }
}

class TicketBuilder {
    public static Object builder(TicketHelper helper)
    {
        System.out.println("通过TicketHelper构建套票信息");
        return null;
    }
}
```
