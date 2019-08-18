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

#### 转换器的使用
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

