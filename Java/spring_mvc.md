<center>Spring MVC</center>   

* [spring mvc的入门实例](#spring mvc的入门实例)
       * [参数的传递以及mybaties的综合](#参数的传递以及mybaties的综合)
         * [传递json信息](#传递json信息)
         * [@SessionAttributes和@SessionAttribute](#@SessionAttributes和@SessionAttribute)
         * [注解@cookieValue和@RequestHeader](#注解@cookieValue和@RequestHeader)
     * [拦截器](#拦截器)
       * [配置拦截器](#配置拦截器)
         * [多个拦截器的执行顺序](#多个拦截器的执行顺序)
       * [验证表单](#验证表单)
         * [使用验证器验证数据源](#使用验证器验证数据源)
       * [数据模型](#数据模型)
       * [视图和视图解析器](#视图和视图解析器)
     * [文件上传](#文件上传)
         * [文件上传步骤](#文件上传步骤)
     * [文件下载](#文件下载)
     * [转换器的使用](#转换器的使用)
       * [一对一转换器（Conerter）](#一对一转换器（Conerter）)
         * [自定义转换器](#自定义转换器)
       * [数组和集合转换器](#数组和集合转换器)
       * [使用格式化器（Formatter）](#使用格式化器（Formatter）)
       * [为控制器添加通知](#为控制器添加通知)
     * [处理异常](#处理异常)
       * [自定义异常](#自定义异常)
     * [国际化](#国际化)
       * [1.MessageSource接口](#1.MessageSource接口)
       * [2.创建CookieLocaleResolver或SessionLocaleResolve  ](#2.创建CookieLocaleResolver或SessionLocaleResolve  )
       * [3.国际化拦截器](#3.国际化拦截器)
       * [国际化的开发](#国际化的开发)
   * [Redis概述](#Redis概述)
       * [在spring中使用Redis](#在spring中使用Redis)
       * [   配置JedisConnectionFactory](#   配置JedisConnectionFactory)
       * [配置Spring Redis Template](#配置Spring Redis Template)
       * [Redis的六种数据类型](#Redis的六种数据类型)
   * [Redis数据结构以及常用命令](#Redis数据结构以及常用命令)
     * [字符串](#字符串)
       * [使用Spring测试Redis字符串操作](#使用Spring测试Redis字符串操作)
     * [哈希](#哈希)
       * [Spring操作hash结构的演示](#Spring操作hash结构的演示)
     * [链表（Linked-list）](#链表（Linked-list）)
       * [使用Spring操作Redis的链表结构](#使用Spring操作Redis的链表结构)
     * [集合](#集合)
     * [有序集合](#有序集合)
       * [使用spring操作有序集合](#使用spring操作有序集合)
     * [基数(HyperLogLog)](#基数(HyperLogLog))
       * [在spring中操作基数](#在spring中操作基数)
     * [Redis的一些常用技术   ](#Redis的一些常用技术   )
       * [Redis的基础事务](#Redis的基础事务)
       * [在Spring中使用Redis事务命令](#在Spring中使用Redis事务命令)
       * [使用Watch命令监控事务](#使用Watch命令监控事务)
       * [流水线](#流水线)
         * [使用流水线操作Redis命令](#使用流水线操作Redis命令)
       * [发布订阅](#发布订阅)
       * [超时命令](#超时命令)
         * [使用Spring操作Redis命令](#使用Spring操作Redis命令)


#### spring mvc的入门实例
web.xml


```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app version="3.1" xmlns="http://xmlns.jcp.org/xml/ns/javaee" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_3_1.xsd">
    <!-- 配置Spring IoC配置文件路径 -->
    <context-param>
        <param-name>contextConfigLocation</param-name>
        <param-value>/WEB-INF/applicationContext.xml</param-value>
    </context-param>
    <!-- 配置ContextLoaderListener用以初始化Spring IoC容器 -->
    <listener>
        <listener-class>org.springframework.web.context.ContextLoaderListener</listener-class>
    </listener>
    <!-- 配置DispatcherServlet -->
    <servlet>
        <!-- 注意：Spring MVC框架会根据servlet-name配置，找到/WEB-INF/dispatcher-servlet.xml作为配置文件载入Web工程中 -->
        <servlet-name>dispatcher</servlet-name>
        <servlet-class>org.springframework.web.servlet.DispatcherServlet</servlet-class>
        <!-- 使得Dispatcher在服务器启动的时候就初始化 -->
        <load-on-startup>2</load-on-startup>
    </servlet>
    <!-- Servlet拦截配置 -->
    <servlet-mapping>
        <servlet-name>dispatcher</servlet-name>
        <url-pattern>/</url-pattern>
    </servlet-mapping>
</web-app>
```
dispatcher-servlet.xml
```xml
<?xml version='1.0' encoding='UTF-8' ?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:p="http://www.springframework.org/schema/p"
       xmlns:tx="http://www.springframework.org/schema/tx" xmlns:context="http://www.springframework.org/schema/context"
       xmlns:mvc="http://www.springframework.org/schema/mvc"
       xsi:schemaLocation="http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans-4.0.xsd
       http://www.springframework.org/schema/tx http://www.springframework.org/schema/tx/spring-tx-4.0.xsd
       http://www.springframework.org/schema/context http://www.springframework.org/schema/context/spring-context-4.0.xsd
       http://www.springframework.org/schema/mvc http://www.springframework.org/schema/mvc/spring-mvc-4.0.xsd">
    <!-- 使用注解驱动 -->
    <mvc:annotation-driven />
    <!-- 定义扫描装载的包 -->
    <context:component-scan base-package="com.*" />
    <!-- 定义视图解析器 -->
    <!-- 找到Web工程/WEB-INF/JSP文件夹，且文件结尾为jsp的文件作为映射 -->
    <bean id="viewResolver"
          class="org.springframework.web.servlet.view.InternalResourceViewResolver"
          p:prefix="/WEB-INF/jsp/" p:suffix=".jsp" />
    <!-- 如果有配置数据库事务,需要开启注解事务的，需要开启这段代码 -->
<!--    <tx:annotation-driven transaction-manager="transactionManager" />-->
</beans>
```
视图解析
```java
package com.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.portlet.ModelAndView;

@Controller("myController")
//@RequestMapping("/my/")
public class MyController {
    @RequestMapping("/index")
    public ModelAndView index() {
        ModelAndView mv = new ModelAndView();
        mv.setView("index");
        return mv;
    }

    @RequestMapping("/index2")
    public ModelAndView index2() {
        ModelAndView mv = new ModelAndView();
        mv.setView("index2");
        return mv;
    }
}
```
目录结构  

![pic](./munu.jpg)

#### 参数的传递以及mybaties的综合
目录结构
![pic](./menu2.jpg)

PersonController  
注意导包为`org.springframework.web.servlet.ModelAndView`切记！！！！
```java
package com.controller;

import com.Pojo.Person;
import com.mapper.PersonMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.view.json.MappingJackson2JsonView;

@Controller

public class PersonController {
    @Autowired
    private PersonMapper personMapper = null;

    @RequestMapping("/person")
    public ModelAndView person(@RequestParam int id)  {
        Person p = personMapper.getRole(id);
        ModelAndView person = new ModelAndView("person");
        person.addObject("person", p);
        return person;
    }
}
```
web.xml和其他相关配置同上，增加PersonMapper文件和PersonMapper.xml文件  
PersonMapper
```java
package com.mapper;

import com.Pojo.Person;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Repository;

@Repository
public interface PersonMapper {
    public int insertRole(Person role);

    public Person getRole(@Param("id") int id);
}
```

PersonMapper.xml
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.mapper.PersonMapper">
    <sql id="roles">id,name,birth,money</sql>
    <insert id="insertRole" useGeneratedKeys="true" keyProperty="id">
        insert into person(name,birth,money)value (#{name},#{birth},#{money})
    </insert>
    <delete id="deleteRole" parameterType="int">
        delete from person where id=#{id}
    </delete>
    <update id="updateRole" parameterType="person">
        update person
        <set>
            <if test="name!=null and name!=''">
                name =#{name },
            </if>
            <if test="birth!=null and birth!=''">
                birth=#{birth},
            </if>
            <if test="money!=null and money!=''">
                money=#{money}
            </if>
            where id=#{id}
        </set>
    </update>
    <select id="getRole" parameterType="int" resultType="person">
        select * from person where id =#{id}
    </select>
</mapper>
```
Person.jsp
```jsp
<html>
<head>
    <title>perosn</title>
</head>
<body>
    <span>${person.name}</span>
</body>
</html>
```

ApplicationContext.xml
```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:context="http://www.springframework.org/schema/cache"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
       http://www.springframework.org/schema/beans/spring-beans.xsd">

    <!--    <bean class="org.springframework.cache.ehcache.EhCacheManagerFactoryBean"/>-->
    <bean class="org.mybatis.spring.SqlSessionFactoryBean" id="sqlSessionFactory">
        <property name="dataSource" ref="dataSource2"/>
        <property name="configLocation" value="classpath:/mybatis/configx.xml"/>
    </bean>
    <bean id="dataSource2" class="org.apache.commons.dbcp2.BasicDataSource">
        <property name="driverClassName" value="com.mysql.jdbc.Driver"/>
        <property name="url" value="jdbc:mysql://deepblue.datsec.cn:3306/learn"/>
        <property name="username" value="root"/>
        <property name="password" value="xx"/>
        <property name="maxTotal" value="255"/>
        <property name="maxIdle" value="5"/>
        <property name="maxWaitMillis" value="10000"/>
    </bean>
    <!--使用注解驱动-->
    <!--    <context:annotation-config/>-->

    <!--    配置数据库事务管理器-->
    <bean id="transactionManager" class="org.springframework.jdbc.datasource.DataSourceTransactionManager">
        <property name="dataSource" ref="dataSource2"/>
    </bean>
    <bean class="org.mybatis.spring.mapper.MapperScannerConfigurer">
        <property name="basePackage" value="com.mapper"/>
        <property name="sqlSessionFactory" ref="sqlSessionFactory"/>
        <property name="annotationClass" value="org.springframework.stereotype.Repository"/>
    </bean>
</beans>
```

##### 传递json信息

依赖包:  
- jackson-databind-2.8.5
- jackson-core-asl-1.9.13
- jackson-core-2.8.5
- jackson-annotations-2.8.5
- jackson-mapper-asl-1.9.13

利用json向后端传输数据  
controller
```java
@RequestMapping(value = "/findroles")
    public ModelAndView findPerson(@RequestBody PersonParam personParam) {
        List<Person> list = personMapper.findRoles(personParam);
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.addObject(list);
        modelAndView.setView(new MappingJackson2JsonView());    
        return modelAndView;
    }
```
请求网页
```html
<%@ taglib prefix="form" uri="http://www.springframework.org/tags/form" %>
<%@page contentType="text/html" pageEncoding="UTF-8" %>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>参数</title>
    <!-- 加载Query文件-->
    <script src="https://code.jquery.com/jquery-3.2.0.js"></script>

    <script type="text/javascript">
        function test() {
            //JSON参数和类RoleParams一一对应
            // var idList = [1, 2, 3];
            var data={
                name:"role",
                birth:"1997-1-1",
                money:100.5,
                pageParam:{
                    start:1,
                    limit:20
                }
            }
            //角色查询参数
            //Jquery的post请求
            $.post({
                url: "./findroles",
                //将JSON转化为字符串传递
                data: JSON.stringify(data),
                //此处需要告知传递参数类型为JSON，不能缺少
                contentType: "application/json",
                //成功后的方法
                success: function (data) {
                    alert(data.toString())
                }
            });
        };
    </script>
<body>
<form>
    <input type="button" onclick="test()">
</form>
</body>
</head>
</html>
```
- 提交表单

jsp文件
```html
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>参数</title>
    <!-- 加载Query文件-->
    <script type="text/javascript" src="https://code.jquery.com/jquery-3.2.0.js">
    </script>
    <script type="text/javascript">
        $(document).ready(function () {
            $("#commit").click(function() {
                var str = $("form").serialize();
                //提交表单
                $.post({
                    url: "./test2",
                    //将form数据序列化，传递给后台，则将数据以roleName=xxx&&note=xxx传递
                    data: $("form").serialize(),
                    //成功后的方法
                    success: function (result) {
                    }
                });
            });
        });
    </script>
</head>
<body>
<form id="form">
    <table>
        <tr>
            <td>角色名称</td>
            <td><input id="roleName" name="name" value="" /></td>
        </tr>
        <tr>
            <td>备注</td>
            <td><input id="note" name="note" /></td>
        </tr>
        <tr>
            <td></td>
            <td align="right"><input id="commit" type="button" value="提交" /></td>
        </tr>
    </table>
</form>
</body>
</html>
```
- 重定向
```java
    @RequestMapping("/test2")
    public ModelAndView tetsx(ModelAndView model, String name, String money) {
        Person p = new Person();
        p.setName("张三");
        p.setMoney(Float.parseFloat(money));
        personMapper.insertRole(p);
        model.addObject("name", name);
        model.addObject("money", money);
        model.addObject("id", p.getId());
        model.setViewName("redirect:./showrolejson");
        return model;
    }
```
也可以使用Model对象调用其对象的addAttribute方法将要重定向的值传递给重定向的url中
- 使用重定向传递对象
```java
@RequestMapping("/test2")
    public String tetsx(RedirectAttributes ra,Person person) {
        Person p = new Person();
        p.setName("张三");
        p.setMoney(person.getMoney());
        personMapper.insertRole(p);
        ra.addAttribute(p);
        return "redirect:./showrolejson";
    }
```
这样做将会将对象的值保存到session中，这样就可以将数据床送到下一个重定向的地址。

##### @SessionAttributes和@SessionAttribute
```java
package com.controller;

import com.Pojo.Person;
import com.mapper.PersonMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.SessionAttribute;
import org.springframework.web.bind.annotation.SessionAttributes;
import org.springframework.web.servlet.ModelAndView;

@Controller
@SessionAttributes(value = "id",types = {Person.class})
public class Session {
    @Autowired
    private PersonMapper personMapper=null;
    @RequestMapping("/haha")
    public ModelAndView session(@SessionAttribute("id") int id)
    {
        ModelAndView mv=new ModelAndView();
        Person p=personMapper.getRole(id);
        mv.addObject("person",p);
        mv.addObject("id",id);
        mv.setViewName("shax");
        return mv;
    }
    @RequestMapping("/123")
    public ModelAndView xx(){
        ModelAndView mv=new ModelAndView();
        mv.setViewName("fuck");
        return mv;

    }
}
```
其中@SessionAttributes用来进行标注键值对，不过不能标注方法，只能对类进行标识。可以设置属性名称或者属性类型。
```html
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>Insert title here</title>
</head>
<body>
<%
    //设置请求属性
    session.setAttribute("id",35);
    //转发给控制器
    response.sendRedirect("./haha");
%>
</body>
</html>
```

```html
<%@ page import="com.Pojo.Person" %><%--
  Created by IntelliJ IDEA.
  User: DeepBlue
  Date: 2019/7/31
  Time: 17:23
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>Title</title>
</head>
<body>
<% Person p= (Person) session.getAttribute("person");
out.println(p.getName());
out.println(p.getMoney());
out.println(p.getBirth());
int id= (int) session.getAttribute("id");
out.println(id);
%>
</body>
</html>
```

##### 注解@cookieValue和@RequestHeader
用来获取cookie和请求头  
```java
 @RequestMapping("234")
    public void xsxs(@RequestHeader(value = "User-Agent", required = false, defaultValue = "morende")
                                         String userAgent, @CookieValue(value = "JSESSIONID",required = false,defaultValue = "mys" +
            "")String cookie) {
        System.out.println(userAgent);
        System.out.println(cookie);
    }
```


### 拦截器

使用拦截器必须实现`org.springframework.web.servlet.HandleerIntercepter`接口，拦截器接口有三个方法:  
1.preHandle    
处理器执行之前的方法，返回布尔值  
2.postHandle  
处理器之后执行的方法，处理器的逻辑完成后执行这个方法   
3.afterCompletion   
无论是否存在异常都会执行此方法。  

#### 配置拦截器

```xml
<mvc:interceptors>
        <mvc:interceptor>
            <mvc:mapping path="/**"/>
            <bean class="com.Interceptor.RoleInterceptor"/>
        </mvc:interceptor>
</mvc:interceptors>
```
其中 `<mvc:mapping path="/**"/>`表示匹配所有请求，也可以通过正则表达式来匹配比如：`<mvc:mapping path="/index"/>`表示所有以index结尾的请求，也可以通过            `<mvc:exclude-mapping path=""/>`设置不匹配的方法。
##### 多个拦截器的执行顺序

配置三个拦截器，其中定义为RoleIntercepter，RoleIntercepter2，RoleIntercepter3
执行结过为:  
```java
preHandle 启动
preHandle2 启动
preHandle3 启动
postHandle3 启动
postHandle2 启动
postHandle 启动
afterCompletion3 启动
afterCompletion2 启动
afterHandle 启动
```
拦截器
```java
package com.Interceptor;

import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.handler.HandlerInterceptorAdapter;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

public class RoleInterceptor extends HandlerInterceptorAdapter {
    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {
        System.out.println("preHandle 启动");
        return true;
    }

    @Override
    public void postHandle(HttpServletRequest request, HttpServletResponse response, Object handler, ModelAndView modelAndView) throws Exception {
        super.postHandle(request, response, handler, modelAndView);
        System.out.println("postHandle 启动");
    }

    @Override
    public void afterCompletion(HttpServletRequest request, HttpServletResponse response, Object handler, Exception ex) throws Exception {
        super.afterCompletion(request, response, handler, ex);
        System.out.println("afterHandle 启动");
    }
}
```
这是当preHandle返回true时的方法调用，可见前置方法在按顺序进行执行，注意后置方法和完成方法是在按照逆序进行执行。  


- 将RoleIntercepter2中的前置方法返回值改为false，可以发现，在返回false之后，此拦截器后面的拦截器的前置方法都不会再执行，且控制器后的所有后置方法也不会再进行执行，而且完成方法中只有返回为true的方法会执行。

```java
preHandle 启动
preHandle2 启动
afterHandle 启动
```
#### 验证表单
验证表单需要的jar包
```
classmate-1.5.0.jar
jboss-logging-3.4.0.Final.jar
hibernate-validator-6.0.14.Final.jar
Bean Validation API- 2.0.1.Final.jar
```
后台验证数据实例  
参数类  
```java
package com.controller;

import org.springframework.format.annotation.DateTimeFormat;

import javax.validation.constraints.*;
import java.util.Date;

public class TestForSale {
    @NotNull
    private int productId;

    @NotNull
    private int userId;

    @Future//只能是将来的日期
    @NotNull
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private Date date;

    @NotNull
    @DecimalMin(value = "0.1")
    private double price;

    @Min(1)
    @Max(100)
    @NotNull
    private int quantity;

    @NotNull
    @DecimalMax("500000.0")
    @DecimalMin("1.0")
    private double amount;

    @Pattern(regexp = "^([a-zA-Z0-9]*[-_]?[a-zA-Z0-9]+)*@"
            + "([a-zA-Z0-9]*[-_]?[a-zA-Z0-9]+)+[\\.][A-Za-z]{2,3}([\\.][A-Za-z]{2})?$",message = "邮件不符合模式")
    private String email;

    @Size(min = 0,max = 256)
    private String note;

    public int getProductId() {
        return productId;
    }

    public void setProductId(int productId) {
        this.productId = productId;
    }

    public int getUserId() {
        return userId;
    }

    public void setUserId(int userId) {
        this.userId = userId;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public int getQuantity() {
        return quantity;
    }

    public void setQuantity(int quantity) {
        this.quantity = quantity;
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getNote() {
        return note;
    }

    public void setNote(String note) {
        this.note = note;
    }
}
```

jsp文件
```html
<%@ page language="java" contentType="text/html; charset=UTF-8"
         pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
"http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    <title>validate</title>
</head>
<body>

<form action = "./testfor">
    <!--
    <form action = "./validate/validator.do">
    -->
    <table>
        <tr>
            <td>产品编号：</td>
            <td><input name="productId" id="productId"/></td>
        </tr>
        <tr>
            <td>用户编号：</td>
            <td><input name="userId" id="userId"/></td>
        </tr>
        <tr>
            <td>交易日期：</td>
            <td><input name="date" id="date"/></td>
        </tr>
        <tr>
            <td>价格：</td>
            <td><input name="price" id="price"/></td>
        </tr>
        <tr>
            <td>数量：</td>
            <td><input name="quantity" id="quantity"/> </td>
        </tr>
        <tr>
            <td>交易金额：</td>
            <td><input name="amount" id="amount"/></td>
        </tr>
        <tr>
            <td>用户邮件：</td>
            <td><input name="email" id="email"/></td>
        </tr>
        <tr>
            <td>备注：</td>
            <td><textarea id="note"  name="note" cols="20" rows="5"></textarea></td>
        </tr>
        <tr><td colspan="2" align="right"> <input type="submit" value="提交"/> </tr>
    </table>
    </form>
</body>
</html>
```
逻辑类(方法)
```java
package com.controller;

import org.springframework.stereotype.Controller;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.validation.Errors;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

import javax.validation.Valid;
import java.util.List;

@Controller
public class TestMapper {
    @RequestMapping("/testfor")
    public ModelAndView forthis(@Valid TestForSale transactional, Errors errors)
    {
        if (errors.hasErrors())
        {
            List<FieldError> errorList=errors.getFieldErrors();
            for (FieldError f: errorList)
            {
                System.out.println("fied: "+f.getField()+"\t"+" msg: "+f.getDefaultMessage());
            }
        }
        ModelAndView modelAndView=new ModelAndView();
        modelAndView.setViewName("jiaoyi");
        return modelAndView;
    }
}
```
##### 使用验证器验证数据源
验证器接口定义在`org.springframework.validation`包下的Validator接口  
- 建立接口
```java
package com.validator;

import com.controller.TestForSale;
import org.apache.ibatis.transaction.Transaction;
import org.springframework.validation.Errors;
import org.springframework.validation.Validator;

public class TransactionValidator implements Validator {

    @Override
    public boolean supports(Class<?> clazz) {
        System.out.println(TestForSale.class.equals(clazz));
        return TestForSale.class.equals(clazz);
    }

    @Override
    public void validate(Object target, Errors errors) {
        TestForSale transaction = (TestForSale) target;
        double dis = transaction.getAmount() - (transaction.getPrice() * transaction.getQuantity());
        if (Math.abs(dis) > 0.01)
            errors.rejectValue("amount", null, "交易金额不匹配");
    }
}
```
加入验证器
```java
package com.controller;

import com.validator.TransactionValidator;
import org.springframework.stereotype.Controller;
import org.springframework.validation.DataBinder;
import org.springframework.validation.Errors;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.InitBinder;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.ModelAndView;

import javax.validation.Valid;
import java.util.List;

@Controller
public class TestMapper {

    @InitBinder
    public void initBinder(DataBinder binder)
    {
        //数据绑定加入验证器
        binder.setValidator(new TransactionValidator());
    }
    @RequestMapping("/testfor")
    public ModelAndView forthis(@Valid TestForSale transactional, Errors errors) {
        if (errors.hasErrors()) {
            List<FieldError> errorList = errors.getFieldErrors();
            for (FieldError f : errorList) {
                System.out.println("fied: " + f.getField() + "\t" + " msg: " + f.getDefaultMessage());
            }
        }
        ModelAndView modelAndView = new ModelAndView();
        modelAndView.setViewName("jiaoyi");
        return modelAndView;
    }
}
```
使用InitBinder注解将验证器和控制器绑定到一起，这样就可以对请求表单进行验证

#### 数据模型
```java
package com.controller;

import com.Pojo.Person;
import com.mapper.PersonMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.servlet.ModelAndView;

@Controller
public class New_Controller {
    @Autowired
    PersonMapper personMapper = null;

    //通过ModelMap进行数据的传递
    @RequestMapping(value = "/getRoleByModelMap")
    public ModelAndView getRoleByModelMap(@RequestParam("id") Integer id, ModelMap modelMap) {
        Person p = personMapper.getRole(id);
        ModelAndView mv = new ModelAndView();
        mv.setViewName("roleDetails");
        modelMap.addAttribute("person", p);
        return mv;
    }

    //通过Model进行数据的传递
    @RequestMapping("/getRoleByModel")
    public ModelAndView getRoleByModel(@RequestParam("id") int id, Model model) {
        Person p = personMapper.getRole(id);
        ModelAndView mv = new ModelAndView();
        mv.setViewName("roleDetails");
        model.addAttribute("person", p);
        return mv;
    }
}
```
#### 视图和视图解析器

实例:  
1.转JSON实例，见之前的返回JSON方法  
2.返回Excel表（利用POI库）
自定义导出接口定义
```java
package com.Interface;

import org.apache.poi.ss.usermodel.Workbook;

import java.util.Map;

public interface ExcelExportService {
    public void makeWorkBook(Map<String, Object> model, Workbook workbook);
}
```
定义Excel视图
```java
package com.View;

import com.Interface.ExcelExportService;
import org.apache.poi.ss.usermodel.Workbook;
import org.springframework.util.StringUtils;
import org.springframework.web.servlet.view.document.AbstractXlsView;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.Map;

public class ExcelView extends AbstractXlsView {
    //文件名
    private String fileName = null;
    //导出视图自定义接口
    private ExcelExportService excelExportService = null;

    //构造方法1
    public ExcelView(ExcelExportService excelExportService) {
        this.excelExportService = excelExportService;
    }

    //构造方法2
    public ExcelView(String viewName, ExcelExportService excelExportService) {
        this.setBeanName(viewName);
    }

    public String getFileName() {
        return fileName;
    }

    public void setFileName(String fileName) {
        this.fileName = fileName;
    }

    public ExcelExportService getExcelExportService() {
        return excelExportService;
    }

    public void setExcelExportService(ExcelExportService excelExportService) {
        this.excelExportService = excelExportService;
    }


    @Override
    protected void buildExcelDocument(Map<String, Object> model, Workbook workbook,
                                      HttpServletRequest request, HttpServletResponse response) throws Exception {
        if (excelExportService == null) {
            throw new RuntimeException("导出服务接口不能为空");
        }
        //文件名不为空,为空则使用请求路径中的字符串为文件名
        if (!StringUtils.isEmpty(fileName)) {
            String reqCharset = request.getCharacterEncoding();
            reqCharset = reqCharset == null ? "UTF-8" : reqCharset;
            fileName = new String(fileName.getBytes(reqCharset), "ISO8859-1");
            response.setHeader("Content-disposition", "attachment;filename=" + fileName);
        }
        excelExportService.makeWorkBook(model, workbook);
    }
}
```
服务端
```java
    @RequestMapping("/export")
    public ModelAndView export() {
        //模型和视图
        ModelAndView mv = new ModelAndView();
        //excel视图
        ExcelView ev = new ExcelView(excelExportService());
        ev.setFileName("juese.xls");
        PersonParam personParam = new PersonParam();
        PageParam pageParam = new PageParam();
        pageParam.setStart(0);
        pageParam.setLimit(1000);
        personParam.setPageParam(pageParam);
        List<Person> list = personMapper.findRoles();
        mv.addObject("personList", list);
        mv.setView(ev);
        return mv;
    }

    @SuppressWarnings({"unchecked"})
    private ExcelExportService excelExportService() {
        return (Map<String, Object> model, Workbook workbook) -> {
            //获取用户列表
            List<Person> personList = (List<Person>) model.get("personList");
            //生成sheet
            Sheet sheet = workbook.createSheet("所有角色");
            Row title = sheet.createRow(0);
            title.createCell(0).setCellValue("id");
            title.createCell(1).setCellValue("name");
            title.createCell(2).setCellValue("birth");
            title.createCell(3).setCellValue("money");
            for (int i = 0; i < personList.size(); i++) {
                Person p = personList.get(i);
                int rowIdx = i + 1;
                Row row = sheet.createRow(rowIdx);
                row.createCell(0).setCellValue(p.getId());
                row.createCell(1).setCellValue(p.getName());
                row.createCell(2).setCellValue(p.getBirth());
                row.createCell(3).setCellValue(p.getMoney());
            }
        };
    }
```
### 文件上传
Spring MVC的文件上传是通过MultipartResolver实现的，对于MultipartResolver而言有两个实现类`CommonsMultipartResolver` `StandarServeletMutipartResolver`其中CommonsMultipartResolver是需要依赖第三方包`jakarta Common FileUpload 项目`而StandarServeletMutipartResolver则是在`spring mvc 3.1`后的产物，不需要依赖第三方包。  
无论在项目中使用哪一种方法，都需要在spring容器中注册MultipartResolver  
方法一:(通过@Bean注解)
```java
package com.Interceptor;

import org.springframework.context.annotation.Bean;
import org.springframework.web.multipart.MultipartResolver;
import org.springframework.web.multipart.support.StandardServletMultipartResolver;

public class Init {
    @Bean(name = "multipartResolver")
    public MultipartResolver initMultipartResolver() {
        return new StandardServletMultipartResolver();
    }
}
```
方法二：(通过配置spring MVC初始化器)
```java
package com.Other;

import org.springframework.web.servlet.support.AbstractAnnotationConfigDispatcherServletInitializer;

import javax.servlet.ServletRegistration;
import javax.servlet.MultipartConfigElement;

public class MyWebAppInit extends AbstractAnnotationConfigDispatcherServletInitializer {
    //spring IOC容器配置
    @Override
    protected Class<?>[] getRootConfigClasses() {
        //配置spring的Java配置文件数组
        return new Class<?>[]{};
    }

    //Servlet的映射关系配置
    @Override
    protected Class<?>[] getServletConfigClasses() {
        return new Class[0];
    }


    @Override
    protected String[] getServletMappings() {
        return new String[]{"*"};
    }

    @Override
    protected void customizeRegistration(ServletRegistration.Dynamic registration) {
        String filePath="F:/uploads";
        long singMax= (long) (5*Math.pow(2,20));
        long totalMax= (long) (10*Math.pow(2,20));
        registration.setMultipartConfig(new MultipartConfigElement(filePath,singMax,totalMax,0));
    }
}
```
方法三（XML注解）:
```xml
<?xml version="1.0" encoding="UTF-8"?>
<web-app version="3.1" xmlns="http://xmlns.jcp.org/xml/ns/javaee" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://xmlns.jcp.org/xml/ns/javaee http://xmlns.jcp.org/xml/ns/javaee/web-app_3_1.xsd">
    <!-- 配置Spring IoC配置文件路径 -->
    <context-param>
        <param-name>contextConfigLocation</param-name>
        <param-value>/WEB-INF/applicationContext.xml</param-value>
    </context-param>
    <!-- 配置ContextLoaderListener用以初始化Spring IoC容器 -->
    <listener>
        <listener-class>org.springframework.web.context.ContextLoaderListener</listener-class>
    </listener>
    <!-- 配置DispatcherServlet -->
    <servlet>
        <!-- 注意：Spring MVC框架会根据servlet-name配置，找到/WEB-INF/dispatcher-servlet.xml作为配置文件载入Web工程中 -->
        <servlet-name>dispatcher</servlet-name>
        <servlet-class>org.springframework.web.servlet.DispatcherServlet</servlet-class>
        <!-- 使得Dispatcher在服务器启动的时候就初始化 -->
        <load-on-startup>2</load-on-startup>

        <!--        MultipartResolver参数-->
        <multipart-config>
            <location>e:/upload/</location>
            <max-file-size>5242880</max-file-size>
            <max-request-size>10485760‬</max-request-size>
            <file-size-threshold>0</file-size-threshold>
        </multipart-config>
    </servlet>
    <!-- Servlet拦截配置 -->
    <servlet-mapping>
        <servlet-name>dispatcher</servlet-name>
        <url-pattern>/</url-pattern>
    </servlet-mapping>
</web-app>
```
##### 文件上传步骤
1.将Bean加入spring IOC容器中（可以使用多种方式，比如xml配置《如上代码》，或者注释，本例使用注释方法）  
```java
package com.Interceptor;

import org.springframework.context.annotation.Bean;
import org.springframework.web.multipart.MultipartResolver;
import org.springframework.web.multipart.support.StandardServletMultipartResolver;

public class Init {
    @Bean(name = "multipartResolver")
    public MultipartResolver initMultipartResolver() {
        return new StandardServletMultipartResolver();
    }
}
```
2.配置`multipartResoulver`
```xml
<!--        MultipartResolver参数-->
        <multipart-config>
            <location>F:/upload/</location>
            <max-file-size>5242880</max-file-size>
            <max-request-size>10485760</max-request-size>
            <file-size-threshold>0</file-size-threshold>
        </multipart-config>
```
3.进行请求映射配置
```java
@RequestMapping(value = "/file")
    public ModelAndView upload(MultipartFile file) {
        //请求转换
//        MultipartHttpServletRequest multipartHttpServletRequest = (MultipartHttpServletRequest) request;
//        获取上传的文件
//        MultipartFile file = multipartHttpServletRequest.getFile("file");
        //设置视图
        if (file==null)
        {
            ModelAndView mv = new ModelAndView();
            mv.setViewName("fileUpload");
            return mv;
        }
        ModelAndView mv = new ModelAndView();
        mv.setView(new MappingJackson2JsonView());
        //获取原始文件名
        String fileName = file.getOriginalFilename();
        //目标文件
        file.getContentType();
        File dest = new File(fileName);
        try {
            //保存文件
            file.transferTo(dest);
            mv.addObject("success", true);
            mv.addObject("msg", "上传文件成功");

        } catch (IllegalStateException | IOException e) {
            mv.addObject("success", false);
            mv.addObject("msg", "上传文件失败");
            e.printStackTrace();
        }
        return mv;
    }
```
需要注意当`第一次访问无参数的时候需要额外进行考虑`。

### 文件下载
```java
    @RequestMapping("/download_")
    public ModelAndView index() {
        ModelAndView mv=new ModelAndView();
        mv.setViewName("download");
        return mv;
    }

    @RequestMapping("/download")
    public ResponseEntity<byte[]> fileDownload(HttpServletRequest request, String filename) throws Exception {
        if (filename == null) {

        }
        //指定文件下载路径
        String path = "F:\\学习资料\\ssm\\mvc\\web\\WEB-INF\\upload";
        //目标文件
        File target = new File(path + File.separator + filename);
        //设置响应头
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment", filename);
        //定义以流的方式返回下载数据
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        //使用Spring MVC的ResponseEntity对象封装返回下载数据
        return new ResponseEntity<byte[]>(FileUtil.readAsByteArray(target), headers, HttpStatus.OK);
    }
```
文件下载html文件
```html
<%--
  Created by IntelliJ IDEA.
  User: DeepBlue
  Date: 2019/8/18
  Time: 19:28
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>文件下载</title>
</head>
<body>
<a href="${pageContext.request.contextPath}/download?filename=1.jpg">文件下载</a>
</body>
</html>
```

### 转换器的使用
实例:将消息转换为json消息  
首先需要将Json转换器添加到Http请求转换器中
```java
    @Bean("requestMappingHandlerAdapter")
    public HandlerAdapter initHandler() {
        //创建转换器
        RequestMappingHandlerAdapter requestMappingHandlerAdapter=new RequestMappingHandlerAdapter();
        //http-》Json转换器
        MappingJackson2HttpMessageConverter jsonConverter=new MappingJackson2HttpMessageConverter();
        MediaType mediaType=MediaType.APPLICATION_JSON_UTF8;
        List<MediaType> mediaTypes =new ArrayList<MediaType>();
        mediaTypes.add(mediaType);
        //加入转换器支持的转换格式
        jsonConverter.setSupportedMediaTypes(mediaTypes);
        //往适配器加入Json转换器
        requestMappingHandlerAdapter.getMessageConverters().add(jsonConverter);
        return requestMappingHandlerAdapter;
    }
```
也可以使用xml进行配置
```xml
<bean class="org.springframework.web.servlet.mvc.method.annotation.RequestMappingHandlerAdapter">
        <property name="messageConverters">
            <list>
                <ref bean="jsonConverter"/>
            </list>
        </property>
    </bean>
    <bean id="jsonConverter" class="org.springframework.http.converter.json.MappingJackson2HttpMessageConverter">
        <property name="supportedMediaTypes">
            <list>
                <value>application/json;charset=UTF-8</value>
            </list>
        </property>
</bean>
```
配置转换器之后只需要在映射方法上加入注解`ResponseBody`即可实现转换为Json格式
```java
    @ResponseBody
    @RequestMapping("/forjson")
    public Person forJson(@Param("id")Integer id)
    {
        Person person=personMapper.getRole(id);
        return person;
    }
```

#### 一对一转换器（Conerter）
spring-core的部分转换器 

转换器 |说明
-|-
characterToNumber|将字符转换为数字
IntegerToEnum|整数转换为枚举类型
ObjectToStringConverter|将对象转换为字符串
SerializingConverter|序列化转换器
DeserializingConverter|反序列化转换器
StringToBooleanConverter|将字符串转换为布尔值
StringToEnum|将字符串转换为枚举格式
StringToCurrencyConverter|将字符串转换为金额
EnumToStrongConverter|将枚举转换为字符串  


##### 自定义转换器
1.首先创建自定义转换器类，实现Converter接口的方法。
```java
package com.Converter;

import com.Pojo.Person;
import org.springframework.core.convert.converter.Converter;
import org.springframework.util.StringUtils;

public class StringToMy implements Converter<String, Person> {
    @Override
    public Person convert(String s) {
        //判断空串
        if (StringUtils.isEmpty(s)) {
            return null;
        }
        if (s.indexOf("-") == -1) {
            return null;
        }
        String[] arr = s.split("-");
        if (arr.length != 3) {
            return null;
        }
        Person person = new Person();
        person.setId(Integer.parseInt(arr[0]));
        person.setName(arr[1]);
        person.setBirth(arr[2]);
        person.setMoney(Float.parseFloat(arr[3]));
        return person;
    }
}
```
2.注册自定义的转换器
```java
package com.Other;

import com.Converter.StringToMy;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.core.convert.converter.Converter;
import org.springframework.format.support.FormattingConversionServiceFactoryBean;

import java.util.ArrayList;
import java.util.List;

public class Register {
    //自定义转换器列表
    private List<Converter> myConverter = null;
    //依赖注入FormattingConversionServiceFactoryBean
    @Autowired
    //此类在MVC初始化时载入
    FormattingConversionServiceFactoryBean fcsfb = null;

    @Bean(name = "myConverter")
    public List<Converter> init() {
        if (myConverter == null) {
            myConverter = new ArrayList<>();
        }
        //自定义的角色转换器
        Converter personConverter=new StringToMy();
        myConverter.add(personConverter);
        //向转换服务类注册转换器哦
        fcsfb.getObject().addConverter(personConverter);
        return myConverter;
    }
}
```
同时也可以通过xml进行配置
```xml
    <!--    自定义转换器-->
    <!--    第一句的意思为指定转换服务类，然后配置器属性加载对应的转换器-->
    <mvc:annotation-driven conversion-service="conversionService"/>
    <bean id="conversionService" class="org.springframework.format.support.FormattingConversionServiceFactoryBean">
        <property name="converters">
            <list>
                <bean class="com.Converter.StringToMy"/>
            </list>
        </property>
    </bean>
```
然后就可以进行测试了
```java
    @ResponseBody
    @RequestMapping("/insertPerson")
    public Map<String, Object> insert(Person person) {
        Map<String, Object> result = new HashMap<>();
        boolean updateFlag = (personMapper.updateRole(person) == 1);
        result.put("success", updateFlag);
        if (updateFlag == true) {
            result.put("msg", "更新成功");
        } else
            result.put("msg", "更新失败");
        return result;
    }
```
#### 数组和集合转换器
上面的转换器只能是一对一的转换器，只能从一个类型转换到另一个类型，这就出现了弊端，所以出现了数组集合转换器`ConditionnalGenericConverter`

此处省略代码

#### 使用格式化器（Formatter）
网页代码
```html
<%--
  Created by IntelliJ IDEA.
  User: DeepBlue
  Date: 2019/8/18
  Time: 17:22
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>时间</title>
</head>
<body>
<form id="form" action="/date">
    <table>
        <tr>
            <td>日期</td>
            <td>
                <label for="date"></label><input id="date" name="date1" type="text" value="2019-01-20">
            </td>
        </tr>
        <tr>
            <td>日期</td>
            <td>
                <label for="amount"></label><input id="amount" name="amount1" type="text" value="200000">
            </td>
        </tr>
        <tr>
            <td>
            </td>
            <td align="right"><input id="commit" type="submit" value="提交"></td>
        </tr>
    </table>
</form>
</body>
</html>
```
逻辑代码
```java
    @RequestMapping("/date")
    public ModelAndView format(@RequestParam("date1") @DateTimeFormat(iso = DateTimeFormat.ISO.DATE) Date date,
                               @RequestParam("amount1") @NumberFormat(pattern = "#,###.##") Double amount) {
        if (date==null)
        {
            ModelAndView mv = new ModelAndView();
            mv.setViewName("date");
            return mv;
        }
        ModelAndView mv = new ModelAndView();
        mv.addObject("date", date);
        mv.addObject("amount", amount);
        return mv;
    }
```

#### 为控制器添加通知

与`Spring AOP`一样`Spring MVC`也能给控制器加入通知主要涉及四个注解
- `@ControllerAdvice`作用于类，用以表示全局性的控制器的拦截器，将用于对应的控制器
- `@InitBinder`是一个允许构建POJO参数的方法，允许在构造控制器参数的时候加入一个自定义构造器
- `@ExceptionHandler`通过它可以注册一个控制器异常，当控制器异常发生时，就会跳转到该方法上
- `ModelAttribute`针对数据模型的注解，先于控制器方法运行，当标注方法返回对象时，会保存在数据模型中。

1.通知类的定义
```java
package com.advice;

import org.springframework.beans.propertyeditors.CustomDateEditor;
import org.springframework.ui.Model;
import org.springframework.web.bind.WebDataBinder;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.InitBinder;
import org.springframework.web.bind.annotation.ModelAttribute;
import sun.util.calendar.BaseCalendar;

import java.text.SimpleDateFormat;
import java.util.Date;

@ControllerAdvice(basePackages = {"com.controller"})
public class MyAdvice {
    @InitBinder
    public void initBinder(WebDataBinder binder) {
        //针对日期的格式化，其中CustomDateEditor是客户自定义的编辑器
        //Boolean参数表示是否允许为空
        binder.registerCustomEditor(Date.class, new CustomDateEditor(new SimpleDateFormat("yyyy-MM-dd"), false));
    }

    @ModelAttribute
    public void populateModel(Model model) {
        model.addAttribute("projectName", "test");
    }

    @ExceptionHandler(RuntimeException.class)
    public String exception() {
        return "exception";
    }
}
```
2.测试代码
```java
@RequestMapping("/advice")
    @ResponseBody
    public Map<String, Object> testForAdvice(Date date, @NumberFormat(pattern = "##,##.00")
            BigDecimal amount, Model model) {
        Map<String, Object> map = new HashMap<>();
        //由于@ModelAttribute会在控制器之前运行，所以，这样也会取到数据
        map.put("projectName", model.asMap().get("projectName"));
        map.put("date", new SimpleDateFormat("yyyy-MM-dd").format(date));
        map.put("amount", amount);
        return map;
    }

    //异常测试
    @RequestMapping("/error")
    public void exception() {
        throw new RuntimeException("异常跳转");
    }
```
当然，控制器也可以使用注解`@InitBinder``@ExceptionHandler`使用这个注解可添加数据绑定和异常处理，但是不指定ControllerAdvicee的话指定的注释只是在本Controller有效而不是对basePackges有效  
测试用例：
```java
@Controller
public class Test {
    @Autowired
    private PersonMapper personMapper = null;

    @InitBinder
    public void initBinder(WebDataBinder binder) {
        //针对日期的格式化，其中CustomDateEditor是客户自定义的编辑器
        //Boolean参数表示是否允许为空
        binder.registerCustomEditor(Date.class, new CustomDateEditor(new SimpleDateFormat("yyyy-MM-dd"), false));
    }

    @ModelAttribute("person")
    public Person initPerson(@RequestParam(value = "id", required = false) Integer id) {
        if (id == null || id < 1) {
            return null;
        }
        Person person = personMapper.getRole(id);
        return person;
    }

    @RequestMapping("/testss")
    @ResponseBody
    public Person tsdsjab(@ModelAttribute("person") Person person) {
        return person;
    }
}
```
### 处理异常
spring中一部分异常默认的映射码

Spring异常|HTTP状态码|备注
-|-|-
BindException|400|数据绑定异常
ConversionNotSupportedException|500|数据转换异常
HttpMediaTypeNotAcceptableException|406|HTTP媒体类型不可接受异常
HttpMediaTypeNotSupportedException|415|HTTP媒体类型不支持异常
HttpMessageNotReadableException|400|HTTP消息不可读异常
HttpMessageNotWritableException|500|HTTP消息不可写异常
HttpRequestMethodNotSupportedException|405|请求找不到异常
MethodArgumentNotValidException|400|控制器方法参数无效异常
MissingServletRequestParameterException|400|缺失参数异常
MissingServletRequestPartException|400|方法采用了"文件上传头"但实际不是该请求异常
NoSuchRequestHandlingMethodException|404|无请求处理器异常
TypeMismatchException|400|POJO类型出错异常

#### 自定义异常
定义部分（使用`@ResponseStatus`）
```java
package com.exception;

import org.springframework.http.HttpStatus;
import org.springframework.web.bind.annotation.ResponseStatus;

@ResponseStatus(code = HttpStatus.NOT_FOUND,reason = "找不到角色信息异常")
public class MyException extends RuntimeException{

}
```
使用部分
```java
package com.Converter;

import com.Pojo.Person;
import com.exception.MyException;
import com.mapper.PersonMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.propertyeditors.CustomDateEditor;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.WebDataBinder;
import org.springframework.web.bind.annotation.*;

import java.text.SimpleDateFormat;
import java.util.Date;

@Controller
public class Test {
    @Autowired
    private PersonMapper personMapper = null;

    @InitBinder
    public void initBinder(WebDataBinder binder) {
        //针对日期的格式化，其中CustomDateEditor是客户自定义的编辑器
        //Boolean参数表示是否允许为空
        binder.registerCustomEditor(Date.class, new CustomDateEditor(new SimpleDateFormat("yyyy-MM-dd"), false));
    }

    @ModelAttribute("person")
    public Person initPerson(@RequestParam(value = "id", required = false) Integer id) {
        if (id == null || id < 1) {
            return null;
        }
        Person person = personMapper.getRole(id);
        return person;
    }

    @RequestMapping("/testss")
    @ResponseBody
    public Person tsdsjab(@ModelAttribute("person") Person person) {
        return person;
    }

    @RequestMapping("/myerror")
    @ResponseBody
    public Person myError(int id) {
        Person person = personMapper.getRole(id);
        if (person == null) {
            throw new MyException();
        }
        return person;
    }

    @ExceptionHandler(MyException.class)
    public String re() {
        return "exception";
    }
}
```
### 国际化
国际化过程：  
首先：DispatchServelet会解析一个LocaleResover接口对象，通过它来确定用户的区域。  
一般使用两个实现类来实现国际化
1.`CookieLocaleResolver`（通过Cookie来进行用户地区标识）
2.`SessionLocaleResolver`（通过Session来进行用户地区标识）  

为了实现修改国际化，Spring MVC实现了国际化拦截器--LocaleChangeInterceptor。  

但是在实现国际化之前需要加载国际化文件，在SpringMVC中就就是实现MessageSource接口
#### 1.MessageSource接口
MessageSource接口实为了加载消息所实现的接口，我们可以用它来记载国际化配置文件
 
其中`ResourceBundleMessageSource`和`ReloadableResourceBundleMessageSource`使用较多。
ResourceBundleMessageSource和ReloadableResourceBundleMessageSource的区别是ResourceBundleMessageSource使用的是JDK提供的ResourceBundle，他只是把文件放在对应的文件路径下，不具备加载功能，需要重启系统才能加载，而ReloadableResourceBundleMessageSource则不需要

1.创建ResourceBundleMessageSource实例(注意Beanname必须为"messageSource")
```java
    @Bean("messageSource")
    public MessageSource initMessage() {
        ResourceBundleMessageSource msgsrc = new ResourceBundleMessageSource();
        //设置编码
        msgsrc.setDefaultEncoding("UTF-8");
        //设置文件路径，如果有classPath从ClassPath算起
        msgsrc.setBasename("msg");
        return msgsrc;
    }

    @Bean("messageSource")
    public MessageSource initMessageSource2() {
        ReloadableResourceBundleMessageSource messageSource = new ReloadableResourceBundleMessageSource();
        messageSource.setDefaultEncoding("UTF-8");
        messageSource.setBasename("classpath:msg");
        //缓存时间设置，缓存时间结束后重新刷新
        messageSource.setCacheSeconds(3600);
        //任意一个都可以
        messageSource.setCacheMillis(3600 * 1000);
        return messageSource;
    }
```
xml配置
```xml
<bean id="messageSource" class="org.springframework.context.support.ResourceBundleMessageSource">
        <property name="defaultEncoding" value="UTF-8"/>
        <property name="basename" value="msg"/>
    </bean>
    
    <bean id="messageSource" class="org.springframework.context.support.ReloadableResourceBundleMessageSource">
        <property name="defaultEncoding" value="UTF-8"/>
        <property name="basename" value="classpath:msg"/>
        <property name="cacheSeconds" value="3600"/>
</bean>
```
#### 2.创建CookieLocaleResolver或SessionLocaleResolve  
```java
    @Bean("localeResolver")
    public LocaleResolver initCookie() {
        CookieLocaleResolver cookieLocaleResolver = new CookieLocaleResolver();
        //名称
        cookieLocaleResolver.setCookieName("lang");
        //设置超时Cookie超时时间
        cookieLocaleResolver.setCookieMaxAge(1800);
        //设置默认
        cookieLocaleResolver.setDefaultLocale(Locale.SIMPLIFIED_CHINESE);
        return cookieLocaleResolver;
    }

    @Bean("localeResolver")
    public LocaleResolver initSession() {
        SessionLocaleResolver sessionLocaleResolver=new SessionLocaleResolver();
        sessionLocaleResolver.setDefaultLocale(Locale.SIMPLIFIED_CHINESE);
        return sessionLocaleResolver;
    }
```
XML同理，就不写了
#### 3.国际化拦截器
通过参数来改变国际化的值时，我们可以使用Spring提供的的拦截器`LocaleChangeInterceptor`，其配置为  
```xml
    <mvc:interceptor>
            <mvc:mapping path="/message/**"/>
            <bean class="org.springframework.web.servlet.i18n.LocaleChangeInterceptor">
                <property name="paramName" value="language"/>
            </bean>
    </mvc:interceptor>
```

#### 国际化的开发
开发国际化首先需要两个国际化的属性文件
msg_en_US.properties
```properties
welcome=the project name is guojihua
```
msg_zh_CN.properties
```properties
welcome=汉语
```
然后通过参数language来设置国际化时区

## Redis概述
redis下载[下载地址](https://github-production-release-asset-2e65be.s3.amazonaws.com/3402186/bb47f4a2-3fac-11e6-9e71-9a4261699bd5?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIAIWNJYAX4CSVEH53A%2F20190820%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20190820T122205Z&X-Amz-Expires=300&X-Amz-Signature=f641bddeb78d638e1cd310fadf9bff85a88e41857e60e2c3e5e5bc8bfbce5082&X-Amz-SignedHeaders=host&actor_id=36097012&response-content-disposition=attachment%3B%20filename%3DRedis-x64-3.2.100.zip&response-content-type=application%2Foctet-stream)下载后可以通过Windows版的.exe文件进行启动  

在JAVA程序中使用Redis程序需要下载`Redis.jar`包，加入工程中

Redis测试程序
```java
package com.advice;

import redis.clients.jedis.Jedis;

public class Main {

    public static void main(String[] args) {
        Jedis jedis = new Jedis("127.0.0.1", 6379);
        int i = 0;
        try {
            long start = System.currentTimeMillis();
            while (true) {
                long end = System.currentTimeMillis();
                if (end - start >= 1000) {
                    break;
                }
                i++;
                jedis.set("test" + i, i + "");
            }

        } finally {
            jedis.close();
        }
        System.out.println("每秒操作数:" + i + "次");
    }
}
```
- Redis连接池的使用
```java
JedisPoolConfig jedisPoolConfig=new JedisPoolConfig();
//设置最大空闲数
jedisPoolConfig.setMaxIdle(50);
//最大连接数
jedisPoolConfig.setMaxTotal(100);
//最大等待毫秒数
jedisPoolConfig.setMaxWaitMillis(20000);
//使用配置创建连接池
JedisPool pool=new JedisPool(jedisPoolConfig,"127.0.0.1");
Jedis jedis=pool.getResource();
```
#### 在spring中使用Redis
需要添加包`spring-data-redis.jar`后配置`JedisPoolConfig`对象
```xml
    <!--RedisConfig配置-->
    <bean id="poolConfig" class="redis.clients.jedis.JedisPoolConfig">
        <property name="maxWaitMillis" value="20000"/>
        <property name="maxIdle" value="50"/>
        <property name="maxTotal" value="100"/>
    </bean>
```
在使用RedisTemplate之前需要配置spring所提供的连接工厂，在spring-Data-Redis中提供了四种工厂模型:  
- JredisConnectionFactory
- JedisConnectionFactory
  - LettuceConnectionFactory
- SrpConnectionFactory
虽然这四种工厂模式都是可以使用的但是要根据环境测试，验证哪个工厂环境是性能最好的。  

####    配置JedisConnectionFactory
```xml
    <!--配置工厂-->
    <bean id="connectionFactory" class="org.springframework.data.redis.connection.jedis.JedisConnectionFactory">
        <property name="hostName" value="localhost"/>
        <property name="port" value="6379"/>
        <property name="poolConfig" ref="poolConfig"/>
    </bean>
```
由于普通的链接使用没有办法把Java对象直接存入Redis，而需要我们自己进行序列化，序列化后的对象取出都是问题，spring提供了对象序列化的封装:  
- GenericJacson2JsonRedisSerializer,通用的Json2.jar的包，将Redis对象的序列化器
- Jackson2JsonRedisSerializer<T>，通过Jackson2.jar包进行转换
- JdkSerializationRedisSerializer<T>，使用Jdk的序列化器进行序列化
- OxmSerializer，使用spring O/X对象和xml相互转换
- StringRedisSerializer，使用字符串序列化
- GenericToStringSerializer，通过通用的字符串序列化进行相互转换

上面的序列化容器是将对象序列化后存入到Redis容器中，也可以把容器中的序列化对象取出，为此Spring提供的RedisTemplate还有两个属性
- key-Serializer，键序列化器
- value-Serializer，值序列化器


#### 配置Spring Redis Template
```xml
    <!--spring Redis Template配置-->
    <bean id="jdkSerializationRedisSerializer"
          class="org.springframework.data.redis.serializer.JdkSerializationRedisSerializer"/>
    <bean id="stringRedisSerializer" class="org.springframework.data.redis.serializer.StringRedisSerializer"/>
    <bean id="redisTemplate" class="org.springframework.data.redis.core.RedisTemplate">
        <property name="connectionFactory" ref="connectionFactory"/>
        <property name="keySerializer" ref="stringRedisSerializer"/>
        <property name="valueSerializer" ref="jdkSerializationRedisSerializer"/>
    </bean>
```
这样就就创建了一个RedisTemplate对象  
例子：(使用Redis保存一个对象)  
- 首先被保存的对象要实现可序列化接口
```java
package com.Pojo;

import java.io.Serializable;

public class Person implements Serializable {
    private int id;
    private String name;
    private String birth;
    private float money;

    public int getId() {
        return id;
    }

    @Override
    public String toString() {
        return "Person{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", birth='" + birth + '\'' +
                ", money=" + money +
                '}';
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getBirth() {
        return birth;
    }

    public void setBirth(String birth) {
        this.birth = birth;
    }

    public float getMoney() {
        return money;
    }

    public void setMoney(float money) {
        this.money = money;
    }
}
```
使用RedisTemplate存储对象
```java
package com.controller;


import com.Pojo.Person;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.data.redis.core.RedisTemplate;

class Test {
    public static void main(String[] args) {
        ApplicationContext applicationContext=new ClassPathXmlApplicationContext("applicationContext.xml");
        RedisTemplate redisTemplate=applicationContext.getBean(RedisTemplate.class);
        Person person=new Person();
        person.setMoney((float) 100.22);
        person.setBirth("2019-1-1");
        person.setName("张三");
        person.setId(1);
        redisTemplate.opsForValue().set("person",person);
        Person person1= (Person) redisTemplate.opsForValue().get("person");
        System.out.println(person1.getMoney());
    }
}
```
因为使用了连接池所以set和get两个操作可能来自两个不同的Redis连接，为了使两个操作来自一个链接可以使用SessionCallback或者RedisCallback，由于使用RedisCallback是来自底层，使用不太友好所以使用SessionCallback接口
```java
    @org.junit.Test
    public void test() {
        ApplicationContext applicationContext =
                new ClassPathXmlApplicationContext("applicationContext.xml");
        RedisTemplate redisTemplate = applicationContext.getBean(RedisTemplate.class);
        Person person = new Person();
        person.setMoney((float) 100.22);
        person.setBirth("2019-1-1");
        person.setName("张三");
        person.setId(1);
        SessionCallback callback=new SessionCallback() {
            @Override
            public Object execute(RedisOperations redisOperations) throws DataAccessException {
                redisOperations.boundValueOps("person").set(person);
                return redisOperations.boundValueOps("person").get();
            }
        };
        Person savedPerson= (Person) redisTemplate.execute(callback);
        System.out.println(savedPerson.getBirth());
    }
```
#### Redis的六种数据类型

数据类型|储存的值
-|-
STRING(字符串)|可以保存字符串，整数和浮点小数，如果是数的话可以进行计算
LIST(列表)|数据结构为链表，内部结构为字符串
SET(集合)|无序的收集器，每个元素都是独一无二的
HASH(散列表)|键值对应的无序列表
ZSET(有序集合)|有序的集合，可以包含字符串、证书、浮点数、分值、元素的排列根据分值大小来决定
HyperLogLog(基数)|作用是计算重复的值，以确定存储的数量


## Redis数据结构以及常用命令
### 字符串
字符串是Redis里面最基本的数据结构，犹如Java的Map结构，让Redis通过键找到值。   
一些基本命令：  

命令|说明|
-|-
set key value|设置键值对
get key |获取键值对
del key|通过key删除键值对
strlen key|求key指向value的字符串长度
getset key value|修改原来key的对应值，并将旧值返回
getrange key start end |获取子串
append key value|将新的字符串value加入到原字符串的结尾  

- 打开命令行测试Redis:  
打开redis-cli.exe  

#### 使用Spring测试Redis字符串操作
```java
    @org.junit.Test
    public void testString() {
        ApplicationContext applicationContext =
                new ClassPathXmlApplicationContext("applicationContext.xml");
        RedisTemplate redisTemplate=applicationContext.getBean(RedisTemplate.class);
        redisTemplate.opsForValue().set("key","value");
        redisTemplate.opsForValue().set("key2","value2");
        String value= (String) redisTemplate.opsForValue().get("key");
        System.out.println(value);
        redisTemplate.delete("key");
        int length= Math.toIntExact(redisTemplate.opsForValue().size("key2"));
        System.out.println(length);
        String old= (String) redisTemplate.opsForValue().getAndSet("key2","new_value");
        System.out.println(old);
        String value2= (String) redisTemplate.opsForValue().get("key2");
        System.out.println(value2);
        int newline=redisTemplate.opsForValue().append("key2","haha");
        System.out.println(newline);
        System.out.println(redisTemplate.opsForValue().get("key2"));
    }
```
上面演示了字符串的操作，但是String类型不但支持字符串类型，还支持数字，另外提供了对这些数字的一些功能。  
- Redis支持的简单运算：  

命令|说明|备注
-|-|-
incr key|在原字段上加一|只能对整数操作
incrby key increment|在原字段上加整数(increment)|只能对整数操作
decr key|在原字段上减一|只能对整数操作
decrby key decrement|在原字段上减去整数(decrement)|只能对整数操作
incrbyfloat keyincrement|在原字段上加入浮点数(keyincrement)|都可以进行操作


下面进行测试(需要注意的是需要将Spring Redis Template中的value的序列化器改为`stringRedisSerializer`)
```java
@org.junit.Test
    public void testForCal() {
        ApplicationContext applicationContext =
                new ClassPathXmlApplicationContext("applicationContext.xml");
        RedisTemplate redisTemplate = applicationContext.getBean(RedisTemplate.class);
        redisTemplate.opsForValue().set("i", "9" );
        print(redisTemplate, "i");
        redisTemplate.opsForValue().increment("i",1);
        print(redisTemplate,"i");
        redisTemplate.getConnectionFactory().getConnection().decr(redisTemplate.getKeySerializer().serialize("i"));
        print(redisTemplate,"i");
        redisTemplate.getConnectionFactory().getConnection().decrBy(redisTemplate.getKeySerializer().serialize("i"),6);
        print(redisTemplate,"i");
        redisTemplate.opsForValue().increment("i",2.3);
        print(redisTemplate,"i");

    }

    public static void print(RedisTemplate redisTemplate, String key) {
        String result= (String) redisTemplate.opsForValue().get(key);
        System.out.println(result);
    }
```
### 哈希
哈希数据结构相当于我们Java中的Map  
Redis Hash结构命令
命令|说明|备注
-|-|-
hdel key field1 [field2...]|删除hash结构某个字段|可以删除多个
hexists key field |判断是否存在field字段|有=1，无=0
hgetall key|获取所有hash结构中的键|返回键和值
hincrby key field increment|给定某个字段加上一个整数|该字段为整数
hincrbyfloat key field increment|给hash结构某字段加上一个浮点数|要求该字段是数字
hkeys key|返回hash所有的键|-
hlen key|返回hash中键值对的个数|-
hmget key field1 [field2]|返回中指定的键的值，可以是多个|依次返回
hmset key filed1 value1[field2 value2 ..]|向hash结构设置多个键值对|-
hset key field value | 向hash结构设置键值对|单个
hsernx field value |向hash结构设置键值对，如果键不存在|-
hvals key|获取hash结构的所有值|-

#### Spring操作hash结构的演示
- 首先需要将默认的序列化器指定为`stringRedisSerializer`
```xml
    <!--spring Redis Template配置-->
    <bean id="jdkSerializationRedisSerializer"
          class="org.springframework.data.redis.serializer.JdkSerializationRedisSerializer"/>
    <bean id="stringRedisSerializer" class="org.springframework.data.redis.serializer.StringRedisSerializer"/>
    <bean id="redisTemplate" class="org.springframework.data.redis.core.RedisTemplate">
        <property name="connectionFactory" ref="connectionFactory"/>
        <property name="defaultSerializer" ref="stringRedisSerializer"/>
        <property name="keySerializer" ref="stringRedisSerializer"/>
        <property name="valueSerializer" ref="stringRedisSerializer"/>
    </bean>
```
```java
    @org.junit.Test
    public void testForHash() {
        ApplicationContext applicationContext =
                new ClassPathXmlApplicationContext("applicationContext.xml");
        RedisTemplate redisTemplate = applicationContext.getBean(RedisTemplate.class);
        String key = "hash";
        Map<String, String> map = new HashMap<>();
        map.put("f1", "value1");
        map.put("f2", "value2");
        //放入数据，相当于hmset
        redisTemplate.opsForHash().putAll(key, map);
        //相当于hset
        redisTemplate.opsForHash().put(key, "f3", "3");
        printHash(redisTemplate, key, "f3");
        boolean exists = redisTemplate.opsForHash().hasKey(key, "f3");
        System.out.println(exists);
        //相当于hgetAll命令
        Map keyValueMap = redisTemplate.opsForHash().entries(key);
        //相当于hincyby
        redisTemplate.opsForHash().increment(key, "f3", 2);
        printHash(redisTemplate, key, "f3");
        //相当于hincyfloat
        redisTemplate.opsForHash().increment(key, "f3", 0.88);
        printHash(redisTemplate, key, "f3");
        //相当于hvals
        List<String> list = redisTemplate.opsForHash().values(key);
        //相当于hkeys
        Set keylist = redisTemplate.opsForHash().keys(key);
        List<String> fields = new ArrayList<>();
        fields.add("f1");
        fields.add("f2");
        //相当与hmget命令
        List valueList2 = redisTemplate.opsForHash().multiGet(key, keylist);
        boolean success = redisTemplate.opsForHash().putIfAbsent(key, "f4", "value4");
        System.out.println(success);
        Long result = redisTemplate.opsForHash().delete(key, "f1", "f2");
        System.out.println(result);
    }

    public void printHash(RedisTemplate redisTemplate, String key, String field) {
        String index = (String) redisTemplate.opsForHash().get(key, field);
        System.out.println(index);
    }
```

### 链表（Linked-list）
Redis链表为双向链表   
Redis关于链表的操作命令:  

命令|说明|备注
-|-|-
lpush key node1[node2...]|把节点node1加入到链表的最左边|如果是node1、node2、... noden那么顺序为noden...nide2、node1
rpush key node1[node2...]|把节点node1加入到链表的最右面|同上
lindex key index|读取下表为index的节点|返回节点字符串，以0开始计算
llen key|求链表的长度|返回链表节点长度
lpop key|删除左边第一个节点并将其值返回|-
rpop key|删除右边第一个节点并将其值返回|-
linsert key befor\|after pivot node|插入一个节点node，并且可以指定在pivot节点的前面还是后面|弱国list不存在，报错，如果没有pivot则会插入失败返回-1
lpushx list node|如果存在key为list的链表，则插入节点node,并做作为从左到右的第一个节点|如果list不存在则报错
rpushx list node|如果存在key为list的链表，则插入节点node,并做作为从左到右的最后一个节点|如果list不存在则报错
lrange list start end|获取链表list从start开始到end下标的节点值|包含end和start
lrem list count value|如果count为0，则删除所有值等于value的节点；如果count不为0，则先对count取abs(count)，然后从左到右删除不大于abs(count)个等于value的节点|count为整数，如果为负数则取绝对值
lset key index node|设置链表下标为index的节点值为node|-
ltrim key start stop|修剪链表，只保留充start到stop区间的节点，其他的都删除掉|包含start到end的下表的节点会保留


- 上面这些命令是线程不安全的，尤其是当操作数据量比较大时的链表结构时常常会遇到这样的问题。为了克服这些问题，Redis提供了链表的阻塞命令，他们在运行的时候会给链表加锁。保证数据的安全性
    
- 链表的阻塞命令

命令|说明|备注
-|-|-
blpop key timeout|移除获取列表的第一个元素，如果列表没有元素会阻塞列表直到等待超时或发现可弹出元素为止|相对于lpop命令，它的操作是线程安全的
brpop|移除获取列表的最后一个元素，如果列表没有元素会阻塞列表直到等待超时或发现可弹出元素为止|相对于rpop，它的操作是进程安全的。
rpoppush key set dest|按从左到右的顺寻，将一个链表的最后一个元素除移，并插入到目标链表最左边|不能设置超时时间
brpoplpush key src dest|按从左到右的顺序，将一个链表的最后一个元素除移并插入到目标链表最左边，并可以设置超时时间|可以设置超时时间

#### 使用Spring操作Redis的链表结构
```java
@org.junit.Test
    public void testForLinked() {
        ApplicationContext applicationContext =
                new ClassPathXmlApplicationContext("applicationContext.xml");
        RedisTemplate redisTemplate = applicationContext.getBean(RedisTemplate.class);
        try {
            //删除链表
            redisTemplate.delete("list");
            redisTemplate.opsForList().leftPush("list", "node3");
            List<String> nodeList = new ArrayList<>();
            for (int i = 2; i >= 1; i--) {
                nodeList.add("node" + i);
            }
            redisTemplate.opsForList().leftPushAll("list", nodeList);
            redisTemplate.opsForList().rightPush("list", "node4");
            //获取节点值
            String node = (String) redisTemplate.opsForList().index("list", 0);
            long size = redisTemplate.opsForList().size("list");
            //从左边弹出节点
            String lpop = (String) redisTemplate.opsForList().leftPop("list");
            //右边弹出
            String rpop = (String) redisTemplate.opsForList().rightPop("list");
            //需要底层命令才能操作linsert命令
            //使用linsert命令在node2前插入一个节点
            redisTemplate.getConnectionFactory().getConnection().lInsert("list".getBytes("UTF-8"),
                    RedisListCommands.Position.BEFORE,
                    "node2".getBytes("UTF-8"), "before_node".getBytes("UTF-8"));
            redisTemplate.opsForList().leftPushIfPresent("list","head");
            redisTemplate.opsForList().rightPushIfPresent("list","end");
            //从左到右，或者下表从0到10的节点
            List valueList=redisTemplate.opsForList().range("list",0,10);
            nodeList.clear();
            for (int i = 0; i <= 3; i++) {
                nodeList.add("node");
            }
            redisTemplate.opsForList().leftPushAll("list",nodeList);
            //删除三个节点，从左到右
            redisTemplate.opsForList().remove("list",3,"node");
            redisTemplate.opsForList().set("list",0,"new_head_list");

        } catch (Exception e) {
            e.printStackTrace();
        }
        printLinked(redisTemplate,"list");
    }

    public static void printLinked(RedisTemplate redisTemplate, String key) {
        Long size = redisTemplate.opsForList().size(key);
        List valueList=redisTemplate.opsForList().range(key,0,size);
        System.out.println(valueList);
        System.out.println("size=" + size);
    }
```
阻塞命的测试
```java
    @org.junit.Test
    public void testList() {
        ApplicationContext applicationContext =
                new ClassPathXmlApplicationContext("applicationContext.xml");
        RedisTemplate redisTemplate = applicationContext.getBean(RedisTemplate.class);
        redisTemplate.delete("list1");
        redisTemplate.delete("list2");
        List<String> nodeList = new ArrayList<>();
        for (int i = 0; i <= 5; i++) {
            nodeList.add("node" + i);
        }
        redisTemplate.opsForList().leftPushAll("list1", nodeList);
        //spring使用超时时间作为阻塞命令区分，等价于blpop命令，并且可以设置时间参数
        redisTemplate.opsForList().leftPop("list1", 1, TimeUnit.SECONDS);
        redisTemplate.opsForList().rightPop("list1", 1, TimeUnit.SECONDS);
        nodeList.clear();
        for (int i = 1; i <= 3; i++) {
            nodeList.add("data" + i);
        }
        redisTemplate.opsForList().leftPushAll("list2", nodeList);
        //相当于rpoplpush命令，弹出list1最右边的节点，插入到list2的最左边
        redisTemplate.opsForList().rightPopAndLeftPush("list1", "list2");
        //相当于brpoplpush命令，注意在spring中使用超时参数区分
        redisTemplate.opsForList().rightPopAndLeftPush("list1", "list2",
                1, TimeUnit.SECONDS);
        printLinked(redisTemplate, "list1");
        printLinked(redisTemplate, "list2");
    }
```
### 集合
Redis的集合不是线性结构，而是哈希结构，他得内部会根据hash分子来查找元素。
- 集合命令  

命令|说明|备注
-|-|-
sadd key member1[memeber2,member3...]|给键key增加成员|可以同时增加多个
sdiff key1 [key2]|找出两个集合之间的差集|如果是单个参数，则返回全部
dcard key|统计键位key的集合成员数|-
sdiffstore des key1 [key2]|先按sdiff命令的规则，找出key1和key2key2两个集合的差集，然后将其保存到des集合中|-
sinter key1 [key2]|求key1和key2的交集|参数如果是单key，那么redis就返回这个key的所有元素
sinterstore des key1 [key2]|先按sinter命令规则，找出交集，然年后保存到des中|-
sismember key member|判断member是不是key集合中的成员|如果是返回1，否则返回0
smembers key|返回集合所有成员|如果数据量大的话，要考虑迭代遍历问题
smove src des member|将member元素从src移动到des集合中|-
spop key|随机弹出一个元素|弹出的元素是无序的
srandmember key [count]|随机弹出集合中count个元素，如果count为负数，则先求绝对值|count必须为整数，不填则默认为1
srem key member1[member2..]|移除集合中的元素，可以是多个|可以通过此命令减少数据数量，使运行更高效
sunion key1 [key2]|求两个集合的并集|如果是单个蚕食，则返回所有元素
sunionstore des key1 key2|先执行sunion，然后保存到键为des的集合中|-

- Spring操作Redis集合  

```java
@org.junit.Test
    public void testForSet() {
        ApplicationContext applicationContext =
                new ClassPathXmlApplicationContext("applicationContext.xml");
        RedisTemplate redisTemplate = applicationContext.getBean(RedisTemplate.class);
        Set set = null;
        //将元素加入列表
        redisTemplate.boundSetOps("set1").add("v1", "v2", "v3", "v4", "v5", "v6");
        redisTemplate.boundSetOps("set2").add("v0", "v2", "v4", "v6", "v8");
        //求集合长度
        redisTemplate.boundSetOps("set1").size();
        //求差集
        set = redisTemplate.opsForSet().difference("set1", "set2");
        System.out.println(set);
        //求并集
        set = redisTemplate.opsForSet().intersect("set1", "set2");
        System.out.println(set);
        //判断是否存在集合中的元素
        boolean exists = redisTemplate.opsForSet().isMember("set1", "v1");
        System.out.println(exists);
        set = redisTemplate.opsForSet().members("set1");
        System.out.println(set);
        //随机弹出一个元素从集合中
        String val = (String) redisTemplate.opsForSet().pop("set1");
        System.out.println(val);
        String val2 = (String) redisTemplate.opsForSet().randomMember("set1");
        System.out.println(val2);
        //随机获取两个集合的元素
        List list = redisTemplate.opsForSet().randomMembers("set1", 2);
        System.out.println(list);
        //删除一个集合的元素，参数可以是多个
        redisTemplate.opsForSet().remove("set1", "v1");
        //求并集
        set = redisTemplate.opsForSet().union("set1", "set2");
        System.out.println(set);
        //求两个集合的差集，并将结果保存到diff_set中
        redisTemplate.opsForSet().differenceAndStore("set1", "set2", "diff_set");
        System.out.println(redisTemplate.opsForSet().members("diff_set"));
        //求两个集合的交集
        redisTemplate.opsForSet().intersectAndStore("set1", "set2", "inter_set");
        System.out.println(redisTemplate.opsForSet().members("inter_set"));
        //两个集合的并集，并保存
        redisTemplate.opsForSet().unionAndStore("set1", "set2", "union_set");
        System.out.println(redisTemplate.opsForSet().members("union_set"));
    }
```
### 有序集合

有序集合和集合类似，只能说它是有序的，和无序集合相比起来最大的特点是除了值之外还会有一个分数。  
- redis有序集合的部分命令
 
命令|说明|备注
-|-|-
zadd key score1 value1 [score2 value2 ...]|向有序集合key，增加一个或多个成员|如果不存在key，则创建key
zcard key|获取有序集合的成员数|-
zcount key min max|根据分数返回相应成员|默认为包含min和max，如果不需要包含则再分数前加(，注意不支持[表示
zincyby key increment member|给有序集合成员值为member的分数增加increment|-
zinterstore desKey numkeys key1[key2 key3..]|求多个有序集合的交集，比那个将结果保存在deskey中|numkeys是一个正式，表示多少个有序集合
zlexcount key min max|求有序集合key成员值在min和max的范围内的值|这里范围是key的成员值，Redis借助数据取键的表示方法"["表示包含"("表示不包含该值
zrange key start stop [withscores]|按照分值的大小（从大到小）返回成员，加入start和stop则截取一段，输入可选项whthscores则连分数一起返回|将star和end在内的值返回
zrank key mamber|按从小到大求有序集合的排行|排名第一为0，第二为1
zrangebylex key min max[limit offset count]|根据值的大小，从小到大排序，通过字典区间返回有序集合的成员|包含min，max关系同上
ZRANGEBYSCORE key min max [WITHSCORES] [LIMIT]|通过分数返回有序集合指定区间内的成员|包含min，max关系同上
ZREMRANGEBYSCORE key min max|移除有序集合中给定的分数区间的所有成员|-
ZREMRANGEBYRANK key start stop |移除有序集合中给定的排名区间的所有成员|-
ZREMRANGEBYLEX key min max|移除有序集合中给定的字典区间的所有成员|-
ZREVRANGE key start stop [WITHSCORES]|返回有序集中指定区间内的成员，通过索引，分数从高到底|与zrange相同，只不过是从高到低排序
ZREVRANGEBYSCORE key max min [WITHSCORES] |返回有序集中指定分数区间内的成员，分数从高到低排序|-
ZREVRANK key member|返回有序集合中指定成员的排名，有序集成员按分数值递减(从大到小)排序|-
ZSCORE key member|返回有序集中，成员的分数值|-
ZUNIONSTORE destination numkeys key [key ...]|计算给定的一个或多个有序集的并集，并存储在新的 key 中|-

- spring-data-redis对有序集合的封装  
在spring中使用Redis的有序集合，需要注意的是Spring对有序集合的元素的值和分数的范围(range)和限制(limit)进行了封装  
#### 使用spring操作有序集合
```java
    @org.junit.Test
    public void testZset() {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
        RedisTemplate redisTemplate = applicationContext.getBean(RedisTemplate.class);
        // Spring提供接口TypedTuple操作有序集合
        Set<TypedTuple> set1 = new HashSet<TypedTuple>();
        Set<TypedTuple> set2 = new HashSet<TypedTuple>();
        int j = 9;
        for (int i = 1; i <= 9; i++) {
            j--;
            // 计算分数和值
            Double score1 = Double.valueOf(i);
            String value1 = "x" + i;
            Double score2 = Double.valueOf(j);
            String value2 = j % 2 == 1 ? "y" + j : "x" + j;
            // 使用Spring提供的默认TypedTuple——DefaultTypedTuple
            TypedTuple typedTuple1 = new DefaultTypedTuple(value1, score1);
            set1.add(typedTuple1);
            TypedTuple typedTuple2 = new DefaultTypedTuple(value2, score2);
            set2.add(typedTuple2);
        }
        // 将元素插入有序集合zset1
        redisTemplate.opsForZSet().add("zset1", set1);
        redisTemplate.opsForZSet().add("zset2", set2);
        // 统计总数
        Long size = null;
        size = redisTemplate.opsForZSet().zCard("zset1");
        // 计分数为score，那么下面的方法就是求3<=score<=6的元素
        size = redisTemplate.opsForZSet().count("zset1", 3, 6);
        Set set = null;
        // 从下标一开始截取5个元素，但是不返回分数,每一个元素是String
        set = redisTemplate.opsForZSet().range("zset1", 1, 5);
        printSet(set);
        // 截取集合所有元素，并且对集合按分数排序，并返回分数,每一个元素是TypedTuple
        set = redisTemplate.opsForZSet().rangeWithScores("zset1", 0, -1);
        printTypedTuple(set);
        // 将zset1和zset2两个集合的交集放入集合inter_zset
        size = redisTemplate.opsForZSet().intersectAndStore("zset1", "zset2", "inter_zset");
        // 区间
        Range range = Range.range();
        range.lt("x8");// 小于
        range.gt("x1");// 大于
        set = redisTemplate.opsForZSet().rangeByLex("zset1", range);
        printSet(set);
        range.lte("x8");// 小于等于
        range.gte("x1");// 大于等于
        set = redisTemplate.opsForZSet().rangeByLex("zset1", range);
        printSet(set);
        // 限制返回个数
        Limit limit = Limit.limit();
        // 限制返回个数
        limit.count(4);
        // 限制从第五个开始截取
        limit.offset(5);
        // 求区间内的元素，并限制返回4条
        set = redisTemplate.opsForZSet().rangeByLex("zset1", range, limit);
        printSet(set);
        // 求排行，排名第1返回0，第2返回1
        Long rank = redisTemplate.opsForZSet().rank("zset1", "x4");
        System.err.println("rank = " + rank);
        // 删除元素，返回删除个数
        size = redisTemplate.opsForZSet().remove("zset1", "x5", "x6");
        System.err.println("delete = " + size);
        // 按照排行删除从0开始算起，这里将删除第排名第2和第3的元素
        size = redisTemplate.opsForZSet().removeRange("zset2", 1, 2);
        // 获取所有集合的元素和分数，以-1代表全部元素
        set = redisTemplate.opsForZSet().rangeWithScores("zset2", 0, -1);
        printTypedTuple(set);
        // 删除指定的元素
        size = redisTemplate.opsForZSet().remove("zset2", "y5", "y3");
        System.err.println(size);
        // 给集合中的一个元素的分数加上11
        Double dbl = redisTemplate.opsForZSet().incrementScore("zset1", "x1", 11);
        redisTemplate.opsForZSet().removeRangeByScore("zset1", 1, 2);
        set = redisTemplate.opsForZSet().reverseRangeWithScores("zset2", 1, 10);
        printTypedTuple(set);
    }

    /**
     * 打印TypedTuple集合
     */
    public static void printTypedTuple(Set<
            TypedTuple> set) {
        if (set != null && set.isEmpty()) {
            return;
        }
        Iterator iterator = set.iterator();
        while (iterator.hasNext()) {

            TypedTuple val = (TypedTuple) iterator.next();
            System.err.print("{value = " + val.getValue() + ", score = " + val.getScore() + "}\n");
        }
    }

    /**
     * 打印普通集合
     */
    public static void printSet(Set set) {
        if (set != null && set.isEmpty()) {
            return;
        }
        Iterator iterator = set.iterator();
        while (iterator.hasNext()) {
            Object val = iterator.next();
            System.out.print(val + "\t");
        }
        System.out.println();
    }
```


### 基数(HyperLogLog)

基数的作用是评估需要准备多少个储存空间去存储数据，但是技术的算法一般会存在一些误差  
- Redis的基数命令

命令|说明|备注
-|-|-
pfadd key element|添加指定元素到HyperLogLog中|如果已经存储元素则返回0
pfcount key|返回hyperLogLog的基数值|-
pfmerge desKey key1 [key2 key3...]|合并多个基数，并将其保存到desKey中|-

#### 在spring中操作基数
```java
    @org.junit.Test
    public void TestForHyperLogLog() {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
        RedisTemplate redisTemplate = applicationContext.getBean(RedisTemplate.class);
        redisTemplate.opsForHyperLogLog().add("log","a","b","c");
        redisTemplate.opsForHyperLogLog().add("log2","a");
        redisTemplate.opsForHyperLogLog().add("log2","z");
        Long size=redisTemplate.opsForHyperLogLog().size("log");
        System.out.println(size);
        size=redisTemplate.opsForHyperLogLog().size("log2");
        System.out.println(size);
        redisTemplate.opsForHyperLogLog().union("des_key","log1","log2");
        size=redisTemplate.opsForHyperLogLog().size("des_key");
        System.out.println(size);
    }
```

### Redis的一些常用技术   
为了应对Redis并发下的数据一致的问题，为了保证异性数据安全性，Redis提供了事务方案，Redis使用的事务时MuITI-EXEC的命令组合，它可以提供两个重要的保证：  
- 事务是被隔离的操作，，事务中的方法会被Redis进行序列化并顺序执行，事务在执行过程中不会被其他客户端的命令打断
- 事务时原子性的操作，要么都执行，要么都不执行  
在使用Rdis事务的过程中会经过三个过程：  
1.开启事务  
2.命令进入队列  
3.执行事务  

- Redis的事务命令  
  

命令|说明|备注
-|-|-
multi|开启事务命令，之后的命令进入队列不会被立马执行|在生存期间，所有的命令都会在队列
watch key1 [key2...]|监听某些键，当被监听的键在事务执行前被修改，则事务会被回滚|使用乐观锁
unwatch key1 [key2...]|取消监听某些键|-
exec |执行事务，如果被监听的键没有被修改，则执行命令，否则回滚|在执行事务队列存储的命令前，REdis会检测被监听的键值是否发达生变化
discard|回滚事务|回滚进入队列的事务命令，之后就不能再使用exec进行提交了


#### Redis的基础事务

![pic](./ssm/redis_1.jpg)

在事务中如果使用了`discard`进行了回滚，则不能进行再次提交


#### 在Spring中使用Redis事务命令
```java
    @org.junit.Test
    public void TestForAffair() {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
        RedisTemplate redisTemplate = applicationContext.getBean(RedisTemplate.class);
        SessionCallback sessionCallback = (RedisOperations ops) -> {
            ops.multi();
            ops.boundValueOps("key1").set("value1");
//            注意命令进入了队列但是没有被执行，所以此时value的值时null
            String value = (String) redisTemplate.boundValueOps("key1").get();
            System.out.println("在队列的时候：value=" + value);
            //此时使用List来接受之前队列中执行完成后的所有命令的结果
            List list = ops.exec();
            value = (String) redisTemplate.opsForValue().get("key1");
            System.out.println("执行后的value:" + value);
            return value;
        };
        //上面为Lambda表达式，下面的是接口实现逻辑
        SessionCallback sessionCallback1=new SessionCallback() {
            @Override
            public Object execute(RedisOperations ops) throws DataAccessException {
                ops.multi();
                ops.boundValueOps("key1").set("value1");
//            注意命令进入了队列但是没有被执行，所以此时value的值时null
                String value = (String) redisTemplate.boundValueOps("key1").get();
                System.out.println("在队列的时候：value=" + value);
                //此时使用List来接受之前队列中执行完成后的所有命令的结果
                List list = ops.exec();
                value = (String) redisTemplate.opsForValue().get("key1");
                System.out.println("执行后的value:" + value);
                return value;
            }
        };
        String value = (String) redisTemplate.execute(sessionCallback);
        System.out.println(value);
    }
```
Rdis事务中如果出现错误就会回滚整个事务，而不是回滚出错的事务。
#### 使用Watch命令监控事务
在Redis食物中，watch命令可以决定事务是执行还是回滚，一般在执行事务之前，使用watch来监控键值对，当执行事务的时候，如果被监控的键值对发生了变化则会回滚事务，否则执行事务，然后取消监控。  


#### 流水线
为了解决希望在没有任何附加条件的情况下去使用队列批量执行一系列的命令，从而提高系统性能。

##### 使用流水线操作Redis命令
进行测试
```java
 @org.junit.Test
    public void TestForPipe() {
        Jedis jedis = getPool().getResource();
        long start = System.currentTimeMillis();
        //开启流水线
        Pipeline pipeline = jedis.pipelined();
        //测试10万读/写两个操作
        for (int i = 0; i < 100000; i++) {
            int j = i + 1;
            pipeline.set("pipeline_key" + j, "pipeline_value" + j);
            pipeline.get("pipeline_key" + j);
        }
//        pipeline.sync();//这里只执行同步，不返回结果
//        pipeline.syncAndReturnAll();//将执行的命令同步且全部返回（List）;
        List list=pipeline.syncAndReturnAll();
        long end=System.currentTimeMillis();
        System.out.println("耗时"+(end-start)+"毫秒");
    }
```
在Redis中执行那个流水线和事务的方法如出一辙都比较简单，使用RedisTemplate的`executePipelined`方法  
```java
    @org.junit.Test
    public void TestPipe() {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
        RedisTemplate redisTemplate=applicationContext.getBean(RedisTemplate.class);
        SessionCallback callback=new SessionCallback() {
            @Override
            public Object execute(RedisOperations operations) throws DataAccessException {
                for (int i = 0; i < 100000; i++) {
                    int j=i+1;
                    operations.boundValueOps("pipeline_key"+j).set("pipeline_value"+j);
                    operations.boundValueOps("pipeline_key"+j).get();
                }
                    return null;
            }
        };
        long start=System.currentTimeMillis();
        List resultList=redisTemplate.executePipelined(callback);
        long end=System.currentTimeMillis();
        System.out.println(end-start);
    }
```
#### 发布订阅
当我们使用银行卡进行消费的时候，一行往往会通过微信，短信或者邮件的方法进行信息的发送。同时Reis也支持订阅消息

比如监听一个chat的渠道我们先打开一个客户端，然后输入命令
```cmd
SUBSCRIBE chat
```
这个时候客户端就会订阅了名叫chat渠道的消息  
这个时候我们在打开另外一个客户端2，输入：
```cmd
publish chat "hahah!"
```
这个时候客户端2就会给chat信道发布一个消息，客户端依旧会接收到订阅的消息  
下面我们演示在Spring中进行订阅模式的使用:  
首先定义订阅监听类  
```java
package com.Inter;

import org.springframework.data.redis.connection.Message;
import org.springframework.data.redis.connection.MessageListener;
import org.springframework.data.redis.core.RedisTemplate;

public class RedisMessageListener implements MessageListener {
    RedisTemplate redisTemplate;
    @Override
    public void onMessage(Message message, byte[] pattern) {
        byte[] body=message.getBody();
        String msgBody= (String) getRedisTemplate().getValueSerializer().deserialize(body);
        System.out.println(msgBody);
        //获取信道
        byte[] channel=message.getChannel();
        //转换为字符串
        String channelString= (String) getRedisTemplate().getStringSerializer().deserialize(channel);
        System.out.println(channelString);
        String byteString=new String(pattern);
        System.out.println(byteString);
    }

    public RedisTemplate getRedisTemplate() {
        return redisTemplate;
    }

    public void setRedisTemplate(RedisTemplate redisTemplate) {
        this.redisTemplate = redisTemplate;
    }
}
```
然后配置Bean  
```xml
<bean id="redisMsgListener" class="com.Inter.RedisMessageListener">
        <property name="redisTemplate" ref="redisTemplate"/>
</bean>
```
有了监听类还需要有叫你听容器，接下来配置监听容器,再RedisMssageListenerContainer,可以用于监听Redis的发布订阅消息
```xml
<!--    监听容器-->
    <bean id="topicContainer" class="org.springframework.data.redis.listener.RedisMessageListenerContainer"
          destroy-method="destroy">
        <!--    连接工厂-->
        <property name="connectionFactory" ref="connectionFactory"/>
        <!--        连接池,需要连接池的生存才能进行监听-->
        <property name="taskExecutor">
            <bean class="org.springframework.scheduling.concurrent.ThreadPoolTaskScheduler">
                <property name="poolSize" value="3"/>
            </bean>
        </property>
        <!--        配置监听者-->
        <property name="messageListeners">
            <map>
                <entry key-ref="redisMsgListener">
                    <!--                    监听类-->
                    <bean class="org.springframework.data.redis.listener.ChannelTopic">
                        <constructor-arg value="chat"/>
                    </bean>
                </entry>
            </map>
        </property>
    </bean>
```
测试发布订阅
```java
    @org.junit.Test
    public void TestForListener() {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
        RedisTemplate redisTemplate = applicationContext.getBean(RedisTemplate.class);
        String channel="chat";
        redisTemplate.convertAndSend(channel,"i am good !");
    }
```
#### 超时命令
与JVM一样Redis也具有GC机制，在谈论Redis的GC命令时需要介绍Redis的超时命令。  

命令|说明|备注
-|-|-
persist|持久化key，取消超时时间|移除key的超时时间
ttl key|查看key的超时时间|以秒计算，-1表示没有超时时间，如果不存在key或者key已经超时则为-2
expire key seconds|设置超时时间戳|以秒为单位
pptl key milliseconds|查看key的超时时间戳|以毫秒为单位
expireat key timestamp|设置超时时间点|用uninx时间戳确定
pexpire key|设置键超时的时间|以毫秒为单位
pexpireat key stamptimes|设置超时时间点|以毫秒为单位的uninx时间戳

##### 使用Spring操作Redis命令
```java
    @org.junit.Test
    public void testForTimeout() {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("applicationContext.xml");
        RedisTemplate redisTemplate = applicationContext.getBean(RedisTemplate.class);
        redisTemplate.execute((RedisOperations ops) ->
        {
            ops.boundValueOps("key1").set("value1");
            String keyValue = (String) ops.boundValueOps("key1").get();
            System.out.println(keyValue);
            Long expSecond = ops.getExpire("key1");
            System.out.println(expSecond);
            boolean b=false;
            b=ops.expire("key1",120L,TimeUnit.SECONDS);
            System.out.println(b);
            b=ops.persist("key1");
            System.out.println(b);
            long l=0L;
            l=ops.getExpire("key1");
            System.out.println(l);
            long now=System.currentTimeMillis();
            Date date=new Date();
            date.setTime(now+120000);
            ops.expireAt("key",date);
            return null;
        });
```


### Redis配置

#### Redis基础配置文件

- windows:redis.windows.conf  
- linux:redis.conf  

对于快照模式的备份，配置如下:  
```
save 900 1
save 300 10
save 60 10000
```
含义为:  
当九百秒执行一个写命令的时候，启用快照备份
当三百秒执行十个个写命令的时候，启用快照备份
.......
```
stop-writes-on-bgsave-error yes
```
意思为当执行save命令的时候，禁止写入命令


```
rdbchecksum yes
```
此命令为是否检查是否对rbd文件进行校验


- Redis的使用一般有主从式和哨兵模式，一般情况下使用哨兵模式，因为哨兵模式下的配置可以实现当主服务器断线后的自动重新选举从服务器为主服务器，减少配置的繁琐

### Spring缓存机制和Redis的结合

#### 使用Spring缓存机制整合Redis
1.首先先定义一个简单的角色POJO
```java
package com.Pojo;

import java.io.Serializable;

public class Person implements Serializable {
    private int id;
    private String name;
    private String birth;
    private float money;

    public int getId() {
        return id;
    }

    @Override
    public String toString() {
        return "Person{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", birth='" + birth + '\'' +
                ", money=" + money +
                '}';
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getBirth() {
        return birth;
    }

    public void setBirth(String birth) {
        this.birth = birth;
    }

    public float getMoney() {
        return money;
    }

    public void setMoney(float money) {
        this.money = money;
    }
}
```
2.创建mybatis的映射文件
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.mapper.PersonMapper">
    <sql id="roles">id,name,birth,money</sql>
    <insert id="insertRole" useGeneratedKeys="true" keyProperty="id">
        insert into person(name,birth,money)value (#{name},#{birth},#{money})
    </insert>
    <delete id="deleteRole" parameterType="int">
        delete from person where id=#{id}
    </delete>
    <update id="updateRole" parameterType="person">
        update person
        <set>
            <if test="name!=null and name!=''">
                name =#{name },
            </if>
            <if test="birth!=null and birth!=''">
                birth=#{birth},
            </if>
            <if test="money!=null and money!=''">
                money=#{money}
            </if>
            where id=#{id}
        </set>
    </update>
    <select id="getRole" parameterType="int" resultType="person">
        select * from person where id =#{id}
    </select>

    <select id="findRoles"  resultType="Person">
        select * from person
    </select>

</mapper>
```
3.角色的接口
```java
package com.mapper;

import com.Pojo.Person;
import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Repository;

import java.util.List;


@Repository
public interface PersonMapper {
    public int insertRole(Person role);

    public int updateRole(Person role);

    public int deleteRole(@Param("id") int id);

    public Person getRole(@Param("id") int id);

    public List<Person> findRoles();
}
```
其中的`@Repository`注释表示该接口为持久层的接口，通过扫描和注解联合就完成了映射器的内容  
3.POJO服务接口
```java
package com.server;


import com.Pojo.Person;

import java.util.List;

public interface PersonServer {
    public int insertRole(Person role);

    public int updateRole(Person role);

    public int deleteRole(int id);

    public Person getRole(int id);

    public List<Person> findRoles();
}
```
4.通过Java配置定义数据库和相关的扫描内容
```java
package com.config;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.jdbc.datasource.DataSourceTransactionManager;
import org.springframework.transaction.PlatformTransactionManager;
import org.springframework.transaction.annotation.EnableTransactionManagement;
import org.springframework.transaction.annotation.TransactionManagementConfigurer;

import javax.sql.DataSource;
import java.util.Properties;


@Configuration
//定义扫描的包
@ComponentScan("com.*")
//使用事务驱动管理器
@EnableTransactionManagement
public class RootConfig implements TransactionManagementConfigurer {
    //由于在xml文件中进行了配置，则使用自动装配
    @Autowired
    private DataSource dataSource = null;


    /*
    配置数据库
     */
    //由于配置过数据库的配置此处省略配置

    /*
    配置SqlSessionFactoryBean
     */
    //此处也进行了配置，省略

    /*
    配置自动包扫描
     */
    //也进行了配置此处省略


    /*
    注解驱动配置，当使用@Transactional注释的时候产生数据库事务
     */
    @Bean
    @Override
    public PlatformTransactionManager annotationDrivenTransactionManager() {
        DataSourceTransactionManager manager=new DataSourceTransactionManager();
        manager.setDataSource(dataSource);
        return manager;
    }
}
```
上面未配置的配置在xml文件中
```xml
<!--    数据源-->
<bean id="dataSource2" class="org.apache.commons.dbcp2.BasicDataSource">
        <property name="driverClassName" value="com.mysql.jdbc.Driver"/>
        <property name="url" value="jdbc:mysql://deepblue.datsec.cn:3306/learn?characterEncoding=UTF-8"/>
        <property name="username" value="root"/>
        <property name="password" value="xxx"/>
        <property name="maxTotal" value="255"/>
        <property name="maxIdle" value="5"/>
        <property name="maxWaitMillis" value="10000"/>
</bean>
<!--    sqlSessionFactory-->
    <bean class="org.mybatis.spring.SqlSessionFactoryBean" id="sqlSessionFactory">
        <property name="dataSource" ref="dataSource2"/>
        <property name="configLocation" value="classpath:/mybatis/configx.xml"/>
    </bean>
<!--    自动包扫描-->
    <bean class="org.mybatis.spring.mapper.MapperScannerConfigurer">
        <property name="basePackage" value="com.mapper"/>
        <property name="sqlSessionFactory" ref="sqlSessionFactory"/>
        <property name="annotationClass" value="org.springframework.stereotype.Repository"/>
    </bean>
```
5.配置mybatis
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE configuration
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-config.dtd">
<configuration>
    <settings>
        <!--        全局缓存-->
        <setting name="cacheEnabled" value="true"/>
        <!--        主键回填-->
        <setting name="useGeneratedKeys" value="true"/>
        <!--        配置默认的执行器，SIMPLE没特别之处，REUSE执行预处理语句，BATCH执行器重用语句和批量更新-->
        <setting name="defaultExecutorType" value="REUSE"/>
        <!--        延迟加载-->
        <setting name="lazyLoadingEnabled" value="true"/>
        <!--        超时时间-->
        <setting name="defaultStatementTimeout" value="25000"/>
    </settings>
    <typeAliases>
        <package name="com.Pojo"/>
    </typeAliases>
<!--    <mappers>-->
<!--                <mapper resource="com/learn/test/PersonMapper.xml"/>-->
<!--    </mappers>-->
</configuration>
```
此处使用了自动扫描映射器所以未配置`mapper`属性  

#### Spring的缓存管理器
Spring使用了CacheManager来定义缓存管理器，这样各个不同的缓存就可以实现它并提供功能了
```java
package com.config;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cache.CacheManager;
import org.springframework.cache.annotation.EnableCaching;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.data.redis.cache.RedisCacheManager;
import org.springframework.data.redis.connection.jedis.JedisConnectionFactory;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.serializer.JdkSerializationRedisSerializer;
import org.springframework.data.redis.serializer.RedisSerializer;
import org.springframework.data.redis.serializer.StringRedisSerializer;
import redis.clients.jedis.JedisPoolConfig;

import java.util.ArrayList;
import java.util.List;

@Configuration
@EnableCaching
public class RedisConfig {

    @Bean(name = "redisTemplate")
    public RedisTemplate initRedisTemplate() {
        JedisPoolConfig jedisPoolConfig = new JedisPoolConfig();
        //最大空闲数
        jedisPoolConfig.setMaxIdle(50);
        //最大连接数
        jedisPoolConfig.setMaxTotal(100);
        //最大等待毫秒
        jedisPoolConfig.setMaxWaitMillis(20000);
        //创建Jedis连接工厂
        JedisConnectionFactory connectionFactory = new JedisConnectionFactory(jedisPoolConfig);
        connectionFactory.setHostName("localhost");
        connectionFactory.setPort(6379);
        //调用后初始化方法，没有将抛出异常
        connectionFactory.afterPropertiesSet();
        //Jedis序列化器
        RedisSerializer jdkSerializer = new JdkSerializationRedisSerializer();
        RedisSerializer stringSerializer = new StringRedisSerializer();
        //定义RedisTemplate
        RedisTemplate redisTemplate = new RedisTemplate();
        redisTemplate.setConnectionFactory(connectionFactory);
        redisTemplate.setDefaultSerializer(stringSerializer);
        redisTemplate.setKeySerializer(stringSerializer);
        redisTemplate.setValueSerializer(jdkSerializer);
        redisTemplate.setHashKeySerializer(stringSerializer);
        redisTemplate.setHashValueSerializer(jdkSerializer);
        return redisTemplate;
    }

    @Bean(name = "redisCacheManager")
    public CacheManager initCacheManager(@Autowired RedisTemplate redisTemplate) {
        RedisCacheManager cacheManager = new RedisCacheManager(redisTemplate);
        //设置超时时间，秒
        cacheManager.setDefaultExpiration(600);
        //设置缓存名称
        List<String> cacheNames = new ArrayList<>();
        cacheNames.add("redisCacheManager");
        cacheManager.setCacheNames(cacheNames);
        return cacheManager;
    }
}
```
- 上面的配置在xml中也可以完成，此处省略  

这样配置后就可以使用注解的方式使用缓存了，这里的缓存注解有四个xml夜里可以使用
- `Cacheable`  
表明在进入方法之前，spring先去缓存服务器中找该key-value，如果找到了，那么不会调用该方法，而是读取缓存值，如果没找到，则执行方法，将结果缓存到Redis缓存服务器中  
- `CachePut`  
Spring会直接调用方法，将方法的返回值缓存到缓存服务器  
- `CacheEvict`  
移除缓存值  

- `Caching`  
这是一个分组注解，它能运用到其他缓存的注解  

- 一般而言，对于查询我们会使用`@Cacheable`对于插入和修改我们使用`@CachePut`对于删除我们使用`CacheEvict`

#### 缓存注解

- @Cacheable和@CachePut属性  

属性|配置类型|描述
-|-|-
value|String[]|使用缓存的名字
condition|String|spring表达式，如果返回值为false，则不会将缓存应用到方法上，true则会
key|String|spring表达式，通过它来计算对应缓存的key
unless|String|spring表达式，返回true，则不会将方法结果放到缓存上


其中，value是一个数组，可以设置多个缓存管理器，key是用来缓存的键

- 表达式值的引用  

表达式|描述|备注
-|-|-
\#root.args|定义给缓存方法的参数|不常用
\#root.caches|该方执行上级对应的缓存名称，是一个数组|同上
\#root.target|执行缓存的目标文件|同上
\#root.targetClass|目标对象的类|同上
\#root.method|缓存方法|同上
\#root.methodName|缓存方法的名称|同上
\#resulte|方法返回值结果集,还可以用Spring表达式进一步读取属性|该表达式不能用于@Cacheable，因为可能不会被执行，这样就没返回值了
\#Argument|任意方法的参数，也可以用方法本身的名称或者下标定义|比如getRole(int id)方法，要获取id这个参数，可以写为#id,#a0，\#p0，建议写id

为了直观看到现象，我们使用log4j来打印，log4j配置如图:  
```properties
log4j.rootLogger=DEBUG , stdout
log4j.logger.org.springframework=DEBUG
log4j.appender.stdout=org.apache.log4j.ConsoleAppender
log4j.appender.stdout.layout=org.apache.log4j.PatternLayout
log4j.appender.stdout.layout.ConversionPattern=%5p %d %C :%m%n
```
- 此处记录整合所需要的各版本jar包，避免以后踩坑，MAVEN文件
```xml
<?xml version="1.0" encoding="UTF-8"?>

<project xmlns="http://maven.apache.org/POM/4.0.0" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
         xsi:schemaLocation="http://maven.apache.org/POM/4.0.0 http://maven.apache.org/xsd/maven-4.0.0.xsd">
    <modelVersion>4.0.0</modelVersion>

    <groupId>com.learn</groupId>
    <artifactId>MySSM</artifactId>
    <version>1.0-SNAPSHOT</version>
    <packaging>war</packaging>

    <name>MySSM Maven Webapp</name>
    <!-- FIXME change it to the project's website -->
    <url>http://www.example.com</url>

    <properties>
        <!-- spring版本号 -->
        <spring.version>5.1.9.RELEASE</spring.version>
        <!-- mybatis版本号 -->
        <mybatis.version>3.5.2</mybatis.version>
        <project.build.sourceEncoding>UTF-8</project.build.sourceEncoding>
        <maven.compiler.source>1.7</maven.compiler.source>
        <maven.compiler.target>1.7</maven.compiler.target>
    </properties>

    <dependencies>
        <dependency>
            <groupId>junit</groupId>
            <artifactId>junit</artifactId>
            <version>4.12</version>
        </dependency>
        <!-- spring核心包 -->
        <dependency>
            <groupId>org.springframework</groupId>
            <artifactId>spring-core</artifactId>
            <version>${spring.version}</version>
        </dependency>
        <dependency>
            <groupId>org.springframework</groupId>
            <artifactId>spring-web</artifactId>
            <version>${spring.version}</version>
        </dependency>
        <dependency>
            <groupId>org.springframework</groupId>
            <artifactId>spring-oxm</artifactId>
            <version>${spring.version}</version>
        </dependency>
        <dependency>
            <groupId>org.springframework</groupId>
            <artifactId>spring-tx</artifactId>
            <version>${spring.version}</version>
        </dependency>
        <dependency>
            <groupId>org.springframework</groupId>
            <artifactId>spring-jdbc</artifactId>
            <version>${spring.version}</version>
        </dependency>
        <dependency>
            <groupId>org.springframework</groupId>
            <artifactId>spring-webmvc</artifactId>
            <version>${spring.version}</version>
        </dependency>
        <dependency>
            <groupId>org.springframework</groupId>
            <artifactId>spring-aop</artifactId>
            <version>${spring.version}</version>
        </dependency>
        <dependency>
            <groupId>org.springframework</groupId>
            <artifactId>spring-context-support</artifactId>
            <version>${spring.version}</version>
        </dependency>
        <dependency>
            <groupId>org.springframework</groupId>
            <artifactId>spring-test</artifactId>
            <version>${spring.version}</version>
        </dependency>
        <!-- mybatis核心包 -->
        <dependency>
            <groupId>org.mybatis</groupId>
            <artifactId>mybatis</artifactId>
            <version>${mybatis.version}</version>
        </dependency>

        <!-- mybatis/spring包 -->
        <dependency>
            <groupId>org.mybatis</groupId>
            <artifactId>mybatis-spring</artifactId>
            <version>2.0.2</version>
        </dependency>
        <!-- 导入Mysql数据库链接jar包 -->
        <dependency>
            <groupId>mysql</groupId>
            <artifactId>mysql-connector-java</artifactId>
            <version>8.0.16</version>
        </dependency>
        <!-- 导入dbcp的jar包，用来在applicationContext.xml中配置数据库 -->
        <dependency>
            <groupId>org.apache.commons</groupId>
            <artifactId>commons-dbcp2</artifactId>
            <version>2.6.0</version>
        </dependency>
        <!-- JSTL标签类 -->
        <dependency>
            <groupId>jstl</groupId>
            <artifactId>jstl</artifactId>
            <version>1.2</version>
        </dependency>
        <!--    spring Data Redis-->
        <dependency>
            <groupId>org.springframework.data</groupId>
            <artifactId>spring-data-redis</artifactId>
            <version>1.8.3.RELEASE</version>
        </dependency>
        <dependency>
            <groupId>redis.clients</groupId>
            <artifactId>jedis</artifactId>
            <version>2.9.0</version>
        </dependency>
        <dependency>
            <groupId>org.apache.commons</groupId>
            <artifactId>commons-pool2</artifactId>
            <version>2.6.2</version>
        </dependency>
        <!--        log4j-->
        <dependency>
            <groupId>log4j</groupId>
            <artifactId>log4j</artifactId>
            <version>1.2.17</version>
        </dependency>
        <dependency>
            <groupId>org.slf4j</groupId>
            <artifactId>slf4j-simple</artifactId>
            <version>1.7.28</version>
        </dependency>
    </dependencies>


    <build>
        <finalName>MySSM</finalName>
        <pluginManagement><!-- lock down plugins versions to avoid using Maven defaults (may be moved to parent pom) -->
            <plugins>
                <plugin>
                    <artifactId>maven-clean-plugin</artifactId>
                    <version>3.1.0</version>
                </plugin>
                <!-- see http://maven.apache.org/ref/current/maven-core/default-bindings.html#Plugin_bindings_for_war_packaging -->
                <plugin>
                    <artifactId>maven-resources-plugin</artifactId>
                    <version>3.0.2</version>
                </plugin>
                <plugin>
                    <artifactId>maven-compiler-plugin</artifactId>
                    <version>3.8.0</version>
                </plugin>
                <plugin>
                    <artifactId>maven-surefire-plugin</artifa除一
                    <version>2.22.1</version>
                </plugin>
                <plugin>
                    <artifactId>maven-war-plugin</artifactId>
                    <version>3.2.2</version>
                </plugin>
                <plugin>
                    <artifactId>maven-install-plugin</artifactId>
                    <version>2.5.2</version>
                </plugin>
                <plugin>
                    <artifactId>maven-deploy-plugin</artifactId>
                    <version>2.8.2</version>
                </plugin>
            </plugins>
        </pluginManagement>

        <resources>
            <resource>
                <directory>src/main/java</directory>
                <includes>
                    <include>**/*.properties</include>
                    <include>**/*.xml</include>
                </includes>
                <filtering>true</filtering>
            </resource>
        </resources>
    </build>
</project>
```

#### 缓存删除注解

Redis的删除缓存注解`@CacheEvict`主要是为了除移对应的键值对，对于删除的操作。查看参数:    

属性|类型|描述
-|-|-
value|String[]|要使用的缓存的名称
key|String|制定Spring表达式返回缓存的key
condition|String|制定spring表达式，如果返回true执行，否则不执行
allEntries|Boolean|如果为True，则删除服务器上所有缓存的键值对，默认为false,谨慎使用。
beforeInvocation|Boolean|指定在方法前除移缓存，如果为true，则在方法前删除缓存，如果false，则在方法后删除缓存。


缓存删除注解的使用:  
```java
@Transactional(isolation = Isolation.READ_COMMITTED, propagation = Propagation.REQUIRED)
    @CacheEvict(value = "redisCacheManager", key = "'redis_person_'+#id")
    @Override
    public int deleteRole(int id) {
        return personMapper.deleteRole(id);
    }
```


#### 不适宜使用缓存的方法

比如文件中的public List<Person> findRoles()方法就不适用于使用缓存来进行装载，因为使用缓存的前提是-高命中率，而该方法是根据备注等信息来查询信息，数据多样化，不能做到高命中率，所以不适用Redis高速缓存来缓存这些数据。

#### Redis的实例
- 使用RedisTemplate实现Redis的各种操作
1.首先需要定义接口
```java
package com.inter;

public interface RedisTemplateServer {
    /*
    执行多个命令
     */
    public void execMultiCommand();
    /*
    执行Redis事务
     */
    public void execTransaction();
    /*
    执行Redis流水线
     */
    public void execPipeline();
}
```
然后实现该借口来实现自己想要的功能  
```java
package com.imp;

import com.inter.RedisTemplateServer;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.dao.DataAccessException;
import org.springframework.data.redis.core.RedisOperations;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.core.SessionCallback;
import org.springframework.stereotype.Service;

import java.util.List;


@Service
public class RedisTemplateImp implements RedisTemplateServer {

    @Autowired
    private RedisTemplate redisTemplate=null;
    /*
    使用SessionCallBack接口来实现多个命令在同一个Redis连接中执行
     */
    @Override
    public void execMultiCommand() {
        Object obj=redisTemplate.execute(new SessionCallback() {
            @Override
            public Object execute(RedisOperations ops) throws DataAccessException {
                ops.boundValueOps("key1").set("abc");
                ops.boundHashOps("hash").put("hash-key-1","hash-value-1");
                return ops.boundValueOps("key1").get();
            }
        });
        System.out.println(obj);
    }

    /*
    失误在一个Redis连接中执行
     */
    @Override
    public void execTransaction() {
        List list= (List) redisTemplate.execute(new SessionCallback() {
            @Override
            public Object execute(RedisOperations ops) throws DataAccessException {
                ops.watch("key1");
                //开启事务
                ops.multi();
                //此时所有的命令都会放到队列中，不会立即执行
                ops.boundValueOps("key1").set("abc");
                ops.boundHashOps("hash").put("hash-key-1", "hash-value-1");
                List result = ops.exec();
                return result;
            }
        });
        System.out.println(list);
    }

    @Override
    public void execPipeline() {
        List list=redisTemplate.executePipelined(new SessionCallback<Object>() {
            @Override
            public <K, V> Object execute(RedisOperations<K, V> ops) throws DataAccessException {
                ops.opsForValue().set((K)"key",(V)"value");
                ops.opsForHash().put((K)"hash","key-hash-1","value-hash-1");
                ops.opsForValue().get("key1");
                return null;
            }
        });
        System.out.println(list);
    }
}
```

### SSM框架+Redis实践应用

- 对数据库的优化  
1.比如更新用户的生日，可以使用以下两个命令的任意一条
```sql
update t_user set birthday=#{birthday} where id=#{id}
update t_user set birthday=#{birthday} where iusername=#{username}
```
这两条逻辑都是正确的，但是优先选择使用主键进行更新，因为在MYSQL的运行过程中，第二条语句会将整个表都锁住，影响并发，而如果使用主键的话则只会锁住该行，从而提高并发量

同时，可以使用连接查询来代替子查询，比如查询一个没有分配角色的用户
```sql
select u.id from t_user u where u.id not in (select ur.user_id from t_user_role ur);
```
这是一个not in语句，查询效率十分的低下，这个not in语句可以修改为：
```sql
select  u.id from t_user u left join t_user_role ur on u.id =ur.id where ur.user_id is null;
```

#### 搭建抢红包开发环境
1.搭建Service和DAO层  
-首先需要进行抢红包数据库的建立表操作
```sql
create table T_RED_PACKET
(
   id                   int(12)                        not null auto_increment,
   user_id              int(12)                        not null,
   amount               decimal(16,2)                  not null,
   send_date            timestamp                      not null,
   total                int(12)                        not null,
   unit_amount          decimal(12)                    not null,
   stock                int(12)                        not null,
   version              int(12) default 0              not null,
   note                 varchar(256)                    null,
   primary key clustered (id)
);

create table T_USER_RED_PACKET 
(
   id                   int(12)                        not null auto_increment,
   red_packet_id        int(12)                        not null,
   user_id              int(12)                        not null,
   amount               decimal(16,2)                  not null,
   grab_time            timestamp                      not null,
   note                 varchar(256)                   null,
    primary key clustered (id)
);

insert into T_RED_PACKET(user_id, amount, send_date, total, unit_amount, stock, note)
 values(1, 200000.00, now(), 20000, 10.00, 20000,'20万元金额，2万个红包，每个10元');
```
2.建立角色POJO
```java
package com.pojo;

import java.io.Serializable;
import java.sql.Timestamp;

public class RedPacket implements Serializable {
    private long id;
    private long userId;
    private double amount;
    private Timestamp sendDate;
    private int total;
    private double unitAmount;
    private int stock;
    private int version;

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public long getUserId() {
        return userId;
    }

    public void setUserId(long userId) {
        this.userId = userId;
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public Timestamp getSendDate() {
        return sendDate;
    }

    public void setSendDate(Timestamp sendDate) {
        this.sendDate = sendDate;
    }

    public int getTotal() {
        return total;
    }

    public void setTotal(int total) {
        this.total = total;
    }

    public double getUnitAmount() {
        return unitAmount;
    }

    public void setUnitAmount(double unitAmount) {
        this.unitAmount = unitAmount;
    }

    public int getStock() {
        return stock;
    }

    public void setStock(int stock) {
        this.stock = stock;
    }

    public int getVersion() {
        return version;
    }

    public void setVersion(int version) {
        this.version = version;
    }

    public String getNote() {
        return note;
    }

    public void setNote(String note) {
        this.note = note;
    }

    private String note;
}
------------------------------------------------------
package com.pojo;

import java.io.Serializable;
import java.sql.Timestamp;

public class UserRedPacket implements Serializable {
    private long id;
    private long redPacketId;
    private long userId;
    private double amount;
    private Timestamp grabTime;
    private String note;

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public long getRedPacketId() {
        return redPacketId;
    }

    public void setRedPacketId(long redPacketId) {
        this.redPacketId = redPacketId;
    }

    public long getUserId() {
        return userId;
    }

    public void setUserId(long userId) {
        this.userId = userId;
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public Timestamp getGrabTime() {
        return grabTime;
    }

    public void setGrabTime(Timestamp grabTime) {
        this.grabTime = grabTime;
    }

    public String getNote() {
        return note;
    }

    public void setNote(String note) {
        this.note = note;
    }
}
```
可以看出这两个一个是红包信息，另一个是抢红包信息  

3.此时需要进行开发红包服务接口
```java
package com.dao;

import com.pojo.RedPacket;
import org.springframework.stereotype.Repository;

@Repository
public interface RedPacketDao {
    /*
     * 获取红包信息
     * @Return 红包具体信息
     */
    public RedPacket getRedPacket(long id);

    /*
    扣减红包
     */
    public int decreaseRedPacket(long id);
}
```
- 配置文件
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.dao.RedPacketDao">
    <!--    查询红包信息-->
    <select id="getRedPacket" parameterType="long" resultMap="com.pojo.RedPacket">
        select id,user_id as userId,amount,send_date as sendDate,total,unit_amount as
         unitAmount,stock,version,note from T_RED_PACKET where id=#{id}
    </select>
    <!--    扣除红包的操作-->
    <update id="decreaseRedPacket">
        update T_RED_PACKET set stock=stock-1 where id=#{id}
    </update>
</mapper>
```
4.设置抢红包的DAO
```java
package com.dao;

import com.pojo.UserRedPacket;
import org.springframework.stereotype.Repository;

@Repository
public interface UserRedPacketDao {
    /*
    抢红包
     */
    public int grapRedPacket(UserRedPacket userRedPacket);
}
```
- 配置mapper文件
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.dao.UserRedPacketDao">
    <insert id="grapRedPacket" useGeneratedKeys="true" keyProperty="id" parameterType="com.pojo.UserRedPacket">
        insert into T_USER_RED_PACKET(red_packet_id,user_id,amount,grab_time,note)
        value (#{redPacketId},#{userId},#{amount},#{grabTime},#{note})
    </insert>
</mapper>
```
此时DAO配置基本结束。    
5.接下来进行Sevice的开发  
```java
package com.server;

import com.pojo.RedPacket;

public interface RedPacketService {
    /*
    获取红包
     */
    public RedPacket getRedPacket(long id);

    /*
    扣除红包
     */
    public int decreaseRedPacket(long id);
}
-----------------------------------------------
package com.server;

public interface UserRedPacketService {
    /*
    保存抢红包的信息
    userId 抢红包的用户编号
    RedPacketId 红包编号
     */
    public int grapRedPacket(long redPacketId,long userId);
}
```
- 接下来进行红包服务类的实现
```java
package com.imp;

import com.dao.RedPacketDao;
import com.pojo.RedPacket;
import com.server.RedPacketService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

@Service
public class RedPacketServiceImp implements RedPacketService {
    @Autowired
    private RedPacketDao redPacketDao=null;

    @Override
    @Transactional(isolation = Isolation.READ_COMMITTED,propagation = Propagation.REQUIRED)
    public RedPacket getRedPacket(long id) {
        return redPacketDao.getRedPacket(id);
    }

    @Override
    @Transactional(isolation = Isolation.READ_COMMITTED,propagation = Propagation.REQUIRED)
    public int decreaseRedPacket(long id) {
        return redPacketDao.decreaseRedPacket(id);
    }
}
---------------------------------------------------------
package com.imp;

import com.dao.RedPacketDao;
import com.dao.UserRedPacketDao;
import com.pojo.RedPacket;
import com.pojo.UserRedPacket;
import com.server.UserRedPacketService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

@Service
public class UserRedPacketServiceImp implements UserRedPacketService {
    @Autowired
    private UserRedPacketDao userRedPacketDao = null;
    @Autowired
    private RedPacketDao redPacketDao = null;
    //失败的表示
    private static final int FAILED = 0;

    @Override
    @Transactional(isolation = Isolation.READ_COMMITTED, propagation = Propagation.REQUIRED)
    public int grapRedPacket(long redPacketId, long userId) {
        //获取红包信息
        RedPacket redPacket = redPacketDao.getRedPacket(redPacketId);
        //当前红包数量大于0
        if (redPacket.getStock() > 0) {
            UserRedPacket userRedPacket = new UserRedPacket();
            userRedPacket.setRedPacketId(redPacketId);
            userRedPacket.setUserId(userId);
            userRedPacket.setAmount(redPacket.getUnitAmount());
            userRedPacket.setNote("抢到红包" + redPacketId);
            int result = userRedPacketDao.grapRedPacket(userRedPacket);
            return result;
        }
        //如果不满足，返回失败
        return FAILED;
    }
}
```
6.使用全注解开发SSM环境
- 首先进行WebAppInitializer的配置  
- RootConfig.java
```java
package com.init;


import org.apache.commons.dbcp2.BasicDataSourceFactory;
import org.mybatis.spring.SqlSessionFactoryBean;
import org.mybatis.spring.mapper.MapperScannerConfigurer;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.FilterType;
import org.springframework.core.io.ClassPathResource;
import org.springframework.core.io.Resource;
import org.springframework.jdbc.datasource.DataSourceTransactionManager;
import org.springframework.stereotype.Repository;
import org.springframework.stereotype.Service;
import org.springframework.transaction.PlatformTransactionManager;
import org.springframework.transaction.annotation.EnableTransactionManagement;
import org.springframework.transaction.annotation.TransactionManagementConfigurer;

import javax.sql.DataSource;
import java.util.Properties;

@Configuration
@ComponentScan(value = "com.*", includeFilters = {
        @ComponentScan.Filter(type = FilterType.ANNOTATION, value = {Service.class})})
//启用事务管理器
@EnableTransactionManagement
//实现TransactionManagementConfigurer,配置注解驱动
public class RootConfig implements TransactionManagementConfigurer {
    private DataSource dataSource = null;


    /*
    数据库
     */
    @Bean(name = "dataSource")
    public DataSource initDataSource() {
        if (dataSource == null) {
            return dataSource;
        }
        Properties properties = new Properties();
        properties.setProperty("driverClassName", "com.mysql.jdbc.Driver");
        properties.setProperty("url", "jdbc:mysql://deepblue.datsec.cn:3306/learn");
        properties.setProperty("username", "root");
        properties.setProperty("password", "xx");
        properties.setProperty("maxTotal", "255");
        properties.setProperty("maxIdle", "5");
        properties.setProperty("maxWaitMillis", "10000");
        try {
            dataSource = BasicDataSourceFactory.createDataSource(properties);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return dataSource;
    }

    /*
    配置SqlSessionFactoryBean
     */
    @Bean(name = "sqlSessionFactory")
    public SqlSessionFactoryBean initSqlSessionFactory() {
        SqlSessionFactoryBean sqlSessionFactory = new SqlSessionFactoryBean();
        sqlSessionFactory.setDataSource(initDataSource());
        Resource resource = new ClassPathResource("mybatis-config.xml");
        sqlSessionFactory.setConfigLocation(resource);
        return sqlSessionFactory;
    }

    /*
    自动扫描，发现mybatis-mapper文件
     */
    @Bean
    public MapperScannerConfigurer initMapperScannerConfigurer() {
        MapperScannerConfigurer msc = new MapperScannerConfigurer();
        msc.setBasePackage("com.*");
        msc.setSqlSessionFactoryBeanName("sqlSessionFactory");
        msc.setAnnotationClass(Repository.class);
        return msc;
    }

    /*
    实现接口方法，注册注解事务，当使用@Transactional时产生数据库事务
     */
    @Override
    public PlatformTransactionManager annotationDrivenTransactionManager() {
        DataSourceTransactionManager manager = new DataSourceTransactionManager();
        manager.setDataSource(initDataSource());
        return manager;
    }

}
```
- WebConfig.java
```java
package com.init;


import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.FilterType;
import org.springframework.http.MediaType;
import org.springframework.http.converter.json.MappingJackson2HttpMessageConverter;
import org.springframework.stereotype.Controller;
import org.springframework.web.servlet.HandlerAdapter;
import org.springframework.web.servlet.ViewResolver;
import org.springframework.web.servlet.config.annotation.EnableWebMvc;
import org.springframework.web.servlet.mvc.method.annotation.RequestMappingHandlerAdapter;
import org.springframework.web.servlet.view.InternalResourceViewResolver;

import java.util.ArrayList;
import java.util.List;

@Configuration
//定义springmvc扫描的包
@ComponentScan(value = "com.*",
        includeFilters = {@ComponentScan.Filter(type = FilterType.ANNOTATION, value = Controller.class)})
//启动Spring MVC配置
@EnableWebMvc
public class WebConfig {
    /*
    通过注解来配置视图解析器
     */
    @Bean(name = "internalResourceViewResolver")
    public ViewResolver initViewResolver() {
        InternalResourceViewResolver resourceViewResolver = new InternalResourceViewResolver();
        resourceViewResolver.setPrefix("/WEB-INF/jsp/");
        resourceViewResolver.setSuffix(".jsp");
        return resourceViewResolver;
    }

    /*
    初始化RequestMappingHandlerAdapter，加在http的Json转换器
     */

    @Bean(name = "RequestMappingHandlerAdapter")
    public HandlerAdapter initHandlerAdapter() {
        //创建请求映射器
        RequestMappingHandlerAdapter requestMappingHandlerAdapter = new RequestMappingHandlerAdapter();
        //json转换器
        MappingJackson2HttpMessageConverter jsonConverter = new MappingJackson2HttpMessageConverter();
        MediaType mediaType = MediaType.APPLICATION_JSON_UTF8;
        List<MediaType> mediaTypes = new ArrayList<>();
        mediaTypes.add(mediaType);
        //加入转换器支持的类型
        jsonConverter.setSupportedMediaTypes(mediaTypes);
        //向适配器中增加json转换器
        requestMappingHandlerAdapter.getMessageConverters().add(jsonConverter);
        return requestMappingHandlerAdapter;
    }
}
```
- WebAppInitializer.java
```java
package com.init;

import javax.servlet.MultipartConfigElement;
import javax.servlet.ServletRegistration;

import org.springframework.web.servlet.support.AbstractAnnotationConfigDispatcherServletInitializer;

public class WebAppInitializer extends AbstractAnnotationConfigDispatcherServletInitializer {
    //配置SpringIoc源
    @Override
    protected Class<?>[] getRootConfigClasses() {
        return new Class<?>[]{RootConfig.class};
    }

    //servlet环境
    @Override
    protected Class<?>[] getServletConfigClasses() {
        return new Class<?>[]{WebConfig.class};
    }

    @Override
    protected String[] getServletMappings() {
        return new String[]{"*"};
    }

    /*
    文件上传配置
     */
    @Override
    protected void customizeRegistration(ServletRegistration.Dynamic dynamic) {
        String filepath = "f:/uploads";
        //5MB
        long singMax = (long) (5 * Math.pow(2, 20));
        //总文件大小
        long totalMax = (long) (10 * Math.pow(2, 20));
        dynamic.setMultipartConfig(new MultipartConfigElement(filepath, singMax, totalMax, 0));
    }
}
```
然后需要在mybatis-config.xml文件中加入两个mapper文件的位置。  
- 随后进行抢红包控制器的开发
```java
package com.controller;


import com.mapper.PersonMapper;
import com.pojo.Person;
import com.server.UserRedPacketService;
import org.apache.ibatis.annotations.Param;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.view.json.MappingJackson2JsonView;

import java.util.HashMap;
import java.util.Map;

@Controller
@RequestMapping("/user")
public class UserRedPacketController {

    @Autowired
    private PersonMapper personMapper = null;
    @Autowired
    private UserRedPacketService userRedPacketService = null;

    @RequestMapping(value = "/getredpacket")
    @ResponseBody
    public Map<String, Object> getRedPacket(@Param("redPacketId") long redPacketId, @Param("userId") long userId) {
        //抢红包
        int result = userRedPacketService.grapRedPacket(redPacketId, userId);
        Map<String, Object> resultMap = new HashMap<>();
        boolean flag = result > 0;
        resultMap.put("success", flag);
        resultMap.put("message", flag ? "抢红包成功" : "抢红包失败");
        return resultMap;
    }

    @RequestMapping(value = "/start")
    public ModelAndView page() {
        ModelAndView mv = new ModelAndView();
        mv.setViewName("start");
        return mv;
    }

    @RequestMapping(value = "/index")
    public ModelAndView index() {
        ModelAndView mv = new ModelAndView();
        mv.setViewName("index");
        return mv;
    }
    @RequestMapping(value = "/index2")
    public ModelAndView index2() {
        ModelAndView mv = new ModelAndView();
        mv.setViewName("index");
        return mv;
    }

    @RequestMapping("/person")
    public ModelAndView xx() {
        Person p = personMapper.getRole(1);
        ModelAndView mv = new ModelAndView();
        mv.setView(new MappingJackson2JsonView());
        mv.addObject(p);
        return mv;
    }
}
```
通过浏览器访问带Ajax的网站发现，等待网络请求完成后查看数据库发现出现了红包超发的现象。超发现象是由于多线程下的数据不同步造成的，为了解决超发现象，我们主要通过乐观锁和悲观锁进行测试。

#### 乐观锁