<center>Spring MVC</center>

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
