<center>Spring MVC</center> 


 * [spring mvc的入门实例](#spring%20mvc%E7%9A%84%E5%85%A5%E9%97%A8%E5%AE%9E%E4%BE%8B)
       * [参数的传递以及mybaties的综合](#%E5%8F%82%E6%95%B0%E7%9A%84%E4%BC%A0%E9%80%92%E4%BB%A5%E5%8F%8Amybaties%E7%9A%84%E7%BB%BC%E5%90%88)
         * [传递json信息](#%E4%BC%A0%E9%80%92json%E4%BF%A1%E6%81%AF)
         * [@SessionAttributes和@SessionAttribute](#%40SessionAttributes%E5%92%8C%40SessionAttribute)
         * [注解@cookieValue和@RequestHeader](#%E6%B3%A8%E8%A7%A3%40cookieValue%E5%92%8C%40RequestHeader)
     * [拦截器](#%E6%8B%A6%E6%88%AA%E5%99%A8)
       * [配置拦截器](#%E9%85%8D%E7%BD%AE%E6%8B%A6%E6%88%AA%E5%99%A8)
         * [多个拦截器的执行顺序](#%E5%A4%9A%E4%B8%AA%E6%8B%A6%E6%88%AA%E5%99%A8%E7%9A%84%E6%89%A7%E8%A1%8C%E9%A1%BA%E5%BA%8F)
       * [验证表单](#%E9%AA%8C%E8%AF%81%E8%A1%A8%E5%8D%95)
         * [使用验证器验证数据源](#%E4%BD%BF%E7%94%A8%E9%AA%8C%E8%AF%81%E5%99%A8%E9%AA%8C%E8%AF%81%E6%95%B0%E6%8D%AE%E6%BA%90)
       * [数据模型](#%E6%95%B0%E6%8D%AE%E6%A8%A1%E5%9E%8B)
       * [视图和视图解析器](#%E8%A7%86%E5%9B%BE%E5%92%8C%E8%A7%86%E5%9B%BE%E8%A7%A3%E6%9E%90%E5%99%A8)
     * [文件上传](#%E6%96%87%E4%BB%B6%E4%B8%8A%E4%BC%A0)
         * [文件上传步骤](#%E6%96%87%E4%BB%B6%E4%B8%8A%E4%BC%A0%E6%AD%A5%E9%AA%A4)
     * [文件下载](#%E6%96%87%E4%BB%B6%E4%B8%8B%E8%BD%BD)
     * [转换器的使用](#%E8%BD%AC%E6%8D%A2%E5%99%A8%E7%9A%84%E4%BD%BF%E7%94%A8)
       * [一对一转换器（Conerter）](#%E4%B8%80%E5%AF%B9%E4%B8%80%E8%BD%AC%E6%8D%A2%E5%99%A8%EF%BC%88Conerter%EF%BC%89)
         * [自定义转换器](#%E8%87%AA%E5%AE%9A%E4%B9%89%E8%BD%AC%E6%8D%A2%E5%99%A8)
       * [数组和集合转换器](#%E6%95%B0%E7%BB%84%E5%92%8C%E9%9B%86%E5%90%88%E8%BD%AC%E6%8D%A2%E5%99%A8)
       * [使用格式化器（Formatter）](#%E4%BD%BF%E7%94%A8%E6%A0%BC%E5%BC%8F%E5%8C%96%E5%99%A8%EF%BC%88Formatter%EF%BC%89)
       * [为控制器添加通知](#%E4%B8%BA%E6%8E%A7%E5%88%B6%E5%99%A8%E6%B7%BB%E5%8A%A0%E9%80%9A%E7%9F%A5)
     * [处理异常](#%E5%A4%84%E7%90%86%E5%BC%82%E5%B8%B8)
       * [自定义异常](#%E8%87%AA%E5%AE%9A%E4%B9%89%E5%BC%82%E5%B8%B8)
     * [国际化](#%E5%9B%BD%E9%99%85%E5%8C%96)
       * [1.MessageSource接口](#1.MessageSource%E6%8E%A5%E5%8F%A3)
       * [2.创建CookieLocaleResolver或SessionLocaleResolve  ](#2.%E5%88%9B%E5%BB%BACookieLocaleResolver%E6%88%96SessionLocaleResolve%20%20)
       * [3.国际化拦截器](#3.%E5%9B%BD%E9%99%85%E5%8C%96%E6%8B%A6%E6%88%AA%E5%99%A8)
       * [国际化的开发](#%E5%9B%BD%E9%99%85%E5%8C%96%E7%9A%84%E5%BC%80%E5%8F%91)
   * [Redis概述](#Redis%E6%A6%82%E8%BF%B0)
       * [在spring中使用Redis](#%E5%9C%A8spring%E4%B8%AD%E4%BD%BF%E7%94%A8Redis)
       * [   配置JedisConnectionFactory](#%20%20%20%E9%85%8D%E7%BD%AEJedisConnectionFactory)
       * [配置Spring Redis Template](#%E9%85%8D%E7%BD%AESpring%20Redis%20Template)
       * [Redis的六种数据类型](#Redis%E7%9A%84%E5%85%AD%E7%A7%8D%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B)
   * [Redis数据结构以及常用命令](#Redis%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%BB%A5%E5%8F%8A%E5%B8%B8%E7%94%A8%E5%91%BD%E4%BB%A4)
     * [字符串](#%E5%AD%97%E7%AC%A6%E4%B8%B2)
       * [使用Spring测试Redis字符串操作](#%E4%BD%BF%E7%94%A8Spring%E6%B5%8B%E8%AF%95Redis%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%93%8D%E4%BD%9C)
     * [哈希](#%E5%93%88%E5%B8%8C)
       * [Spring操作hash结构的演示](#Spring%E6%93%8D%E4%BD%9Chash%E7%BB%93%E6%9E%84%E7%9A%84%E6%BC%94%E7%A4%BA)
     * [链表（Linked-list）](#%E9%93%BE%E8%A1%A8%EF%BC%88Linked-list%EF%BC%89)
       * [使用Spring操作Redis的链表结构](#%E4%BD%BF%E7%94%A8Spring%E6%93%8D%E4%BD%9CRedis%E7%9A%84%E9%93%BE%E8%A1%A8%E7%BB%93%E6%9E%84)



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
        <property name="password" value="anzhuoshiyanshi"/>
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