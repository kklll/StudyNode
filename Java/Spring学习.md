## <center>Spring框架的学习</center>

Spring的两大重要特性:  
- AOP 面向切片编程
- IOC 控制反转

#### Spring的Bean装配：  
1. 通过xml文件进行装配
2. 通过注解进行装配


##### 使用xml文件进行装配
示例代码：
```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:util="http://www.springframework.org/schema/util"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
        http://www.springframework.org/schema/beans/spring-beans-4.3.xsd http://www.springframework.org/schema/util http://www.springframework.org/schema/util/spring-util.xsd">
    <bean id="userDao" class="com.itheima.ioc.UserDaoImp"></bean>
    <bean class="com.itheima.ioc.BeanPostProcessImp" id="beanPostProcess"/>
    <bean class="com.itheima.ioc.Bean" id="Bean">
        <constructor-arg value="bean" index="0"/>
        <constructor-arg value="呵呵" index="1"/>
    </bean>
    <bean id="userServer" class="com.itheima.ioc.UserServerImp">
        <property name="userDao" ref="userDao"/>
    </bean>
    <bean id="source" class="com.itheima.ioc.Source">
        <property name="fruit" value="橙汁"/>
        <property name="sizi" value="大杯"/>
        <property name="suger" value="少糖"/>
    </bean>
    <bean id="juiceMaker2" class="com.itheima.ioc.JuiceMaker2" init-method="init" destroy-method="myDestroy">
        <property name="beverageShop" value="贡茶"/>
        <property name="source" ref="source"/>
    </bean>

    <bean id="role1" class="com.itheima.ioc.Role">
        <property name="id" value="1"/>
        <property name="note" value="我的备注"/>
        <property name="roleName" value="role_note_1"/>
    </bean>
    <bean id="role2" class="com.itheima.ioc.Role">
        <property name="id" value="2"/>
        <property name="note" value="我的备注2"/>
        <property name="roleName" value="role_note_2"/>
    </bean>
    <bean class="com.itheima.ioc.User" id="user1">
        <property name="id" value="1"/>
        <property name="userNumber" value="userNumber_1"/>
    </bean>
    <bean class="com.itheima.ioc.User" id="user2">
        <property name="id" value="2"/>
        <property name="userNumber" value="userNumber_2"/>
    </bean>
    <bean id="userRole" class="com.itheima.ioc.UserRole">
        <property name="id" value="1"/>
        <property name="list">
        <list>
            <ref bean="role1"/>
            <ref bean="role2"/>
        </list>
        </property>
        <property name="map">
            <map>
                <entry key-ref="role1" value="user1"/>
                <entry key-ref="role2" value="user2"/>
            </map>
        </property>
        <property name="set">
            <set>
                <ref bean="role1"/>
                <ref bean="role2"/>
            </set>
        </property>
    </bean>
</beans>
```

##### 使用注解进行装配
1.使用@compoment装配Bean  
将Bean此类进行装配，name字段设置为xxx，id字段设置为1
```java
package com.itheima.ioc;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component
public class Bean {
    @Value("xxxx")
    private String name;
    @Value("1")
    private String id;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Bean{" +
                "name='" + name + '\'' +
                ", id='" + id + '\'' +
                '}';
    }

    public String getId() {

        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public Bean(String name, String id) {
        this.name = name;
        this.id = id;
    }
}
```
此时Spring IOC不知道去哪里寻找这个Bean，所以还需要进行扫描。  
类如下所示：
```java
package com.itheima.ioc;

import org.springframework.context.annotation.ComponentScan;

@ComponentScan
public class Scan {
}
```
此时就可以通过`AnnotationConfigApplicationContext` 进行获取
```java
    @Test
    public void scan()
    {
        ApplicationContext applicationContext=new AnnotationConfigApplicationContext(Role.class);
        Role role= (Role) applicationContext.getBean("role");
        System.out.println(role);
    }
}
```
但是此方法存在弊端：  
1.只能扫描本package下的类  
2.只能注入一些值，不能注入对象  

解决问题1:  
使用@ComponentScan(basePackageClasses = {Role.class,RoleServerImP.class}),其实就是先定义一个接口方法，然后去实现此方法，将参数类型的类通过getBean方法进行获取后传入类方法。  


2.自动装配---@Autowired

@autowired将会自动装配类中对象
```java
package com.itheima.ioc;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component("RoleServerImp2")
public class RoleServerImp2 implements RoleServer2 {
    @Autowired
    private Role role = null;

    public Role getRole() {
        return role;
    }

    //    @Autowired
    public void setRole(Role role) {
        System.out.println("调用set方法");
        this.role = role;
    }

    @Override
    public void print() {
        System.out.println("print方法");
        System.out.println(role.toString());
    }
}
```
但是同时又会产生问题，当一个接口有多个实现类的时候会出现二义性，spring不知道应该将注入到哪个接口对象中:   
比如如下配置:
```java
package com.itheima.ioc;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component("role")
public class Role {
    @Value("1")
    private Integer id;
    @Value("myname")
    private String roleName;
    @Value("我的备注")
    private String note;

    @Override
    public String toString() {
        return "Role{" +
                "id=" + id +
                ", roleName='" + roleName + '\'' +
                ", note='" + note + '\'' +
                '}';
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getRoleName() {
        return roleName;
    }

    public void setRoleName(String roleName) {
        this.roleName = roleName;
    }

    public String getNote() {
        return note;
    }

    public void setNote(String note) {
        this.note = note;
    }
}

```
```java
package com.itheima.ioc;

public interface RoleServer {
    public void printRoles(Role role);
}
```
```java
package com.itheima.ioc;

import org.springframework.stereotype.Component;

@Component
public class RoleServerImp implements RoleServer {
    @Override
    public void printRoles(Role role) {
        System.out.println(role.toString());
    }
}
```
```java
package com.itheima.ioc;


import org.springframework.stereotype.Component;

@Component
public class RoleServerImp3 implements RoleServer {
    @Override
    public void printRoles(Role role) {
        System.out.println(role);
    }
}
```
```java
package com.itheima.ioc;


import org.springframework.context.annotation.ComponentScan;
import org.springframework.stereotype.Component;

@ComponentScan()
public class Beans {
}
```
```java
    @Test
    public void test2()
    {
        ApplicationContext applicationContext=new AnnotationConfigApplicationContext(Beans.class);
        applicationContext.getBean(RoleServer.class);

    }
```
此时进行测试将会出现不知道是哪个实现类的异常，则此时需要进行`@Primary`或者
`@Qualifier`进行解决。  
`@Primary`是选定两个接口实现类中优先的注入，如两个实现类中对其中一个实现类进行@Primary修饰，则发现多个实现类时优先对此实现类进行注入。


- profile（配置）  
比如有两个数据库配置类，一个用于数据库的测试，另一个用于开发使用使用profile可以指定两个不同的数据库类的注入。  
- `@ImportResource({"classpath:spring-config.xml"})`此注释可以用于将xml文件引入  
- 在xml文件中引入可以使用\<import resource="spring-config.xml">来实现多个配置文件之间的链接


1.在注释中使用profile  
```java
public class DataSourceConfig {

  //Spring 引入@Profile 制定某个bean属于哪个profile
  //在方法级别上使用@Profile注解
  @Bean
  @Profile("dev")
  public DataSource embeddedDataSource() {
    return new EmbeddedDatabaseBuilder()
        .setType(EmbeddedDatabaseType.H2)
        .addScript("classpath:schema.sql")
        .addScript("classpath:dev-data.sql")
        .build();
  }

  @Bean
  @Profile("prod")
  public DataSource embeddedDataSourceDev() {
    return new EmbeddedDatabaseBuilder()
            .setType(EmbeddedDatabaseType.H2)
            .addScript("classpath:schema.sql")
            .addScript("classpath:prod-data.sql")
            .build();
  }
}
```
2.在xml文件中配置profile  
```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
  xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:jdbc="http://www.springframework.org/schema/jdbc"
  xmlns:jee="http://www.springframework.org/schema/jee" xmlns:p="http://www.springframework.org/schema/p"
  xsi:schemaLocation="
    http://www.springframework.org/schema/jee
    http://www.springframework.org/schema/jee/spring-jee.xsd
    http://www.springframework.org/schema/jdbc
    http://www.springframework.org/schema/jdbc/spring-jdbc.xsd
    http://www.springframework.org/schema/beans
    http://www.springframework.org/schema/beans/spring-beans.xsd">

  <beans profile="dev">
    <jdbc:embedded-database id="dataSource" type="H2">
      <jdbc:script location="classpath:schema.sql" />
      <jdbc:script location="classpath:dev-data.sql" />
    </jdbc:embedded-database>
  </beans>

  <beans profile="prod">
    <jdbc:embedded-database id="dataSource" type="H2">
      <jdbc:script location="classpath:schema.sql" />
      <jdbc:script location="classpath:prod-data.sql" />
    </jdbc:embedded-database>
  </beans>
</beans>
```
- 启动profile
```java
  @RunWith(SpringJUnit4ClassRunner.class)
  @ContextConfiguration("classpath:datasource-config.xml")
  @ActiveProfiles("prod")
  public static class ProductionDataSourceTest_XMLConfig {
    @Autowired
    private DataSource dataSource;

    @Test
    public void shouldBeEmbeddedDatasource() {
      assertNotNull(dataSource);
      JdbcTemplate jdbc = new JdbcTemplate(dataSource);
      List<String> results = jdbc.query("select id, name from Things", new RowMapper<String>() {
        @Override
        public String mapRow(ResultSet rs, int rowNum) throws SQLException {
          return rs.getLong("id") + ":" + rs.getString("name");
        }
      });

      assertEquals(1, results.size());
      assertEquals("1:B", results.get(0));
    }
  }
```
使用@ActivateProfiles来指定加载哪个Profile这样程序就会加载相应的Profile，但是程序如果在服务器上的Java虚拟机中，需要在运行时找到相应配置
配置为：

---
```java
JAVA_OPTS="-D spring.profiles.active=test"
```
- 使用注解来装配properties文件  
使用

```java
package com.itheima.ioc;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.PropertySource;
import org.springframework.context.support.PropertySourcesPlaceholderConfigurer;
import org.springframework.stereotype.Component;

@ComponentScan()
@Configuration
@PropertySource(value = {"database-config.properties"})
public class Beans {
    @Bean
    public PropertySourcesPlaceholderConfigurer propertySourcesPlaceholderConfigurer(){
        return new PropertySourcesPlaceholderConfigurer();
    }
}
```



- 使用xml文件装配properties文件
```xml
<context:property-placeholder ignore-resource-not-found="true" location="classpath*:database-config.properties"/>
```

#### spring表达式注入
```java
package com.learn.test;

import org.springframework.context.annotation.ComponentScan;

@ComponentScan
public class Beans {
}
```
```java
package com.learn.test;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;
import org.springframework.validation.annotation.Validated;

@Component("role")
public class Role {
    @Value("#{1}")
    private Integer id;
    @Value("#{'role1'}")
    private String roleName;
    @Value("#{'mynote'}")
    private String note;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    @Override
    public String toString() {
        return "Role{" +
                "id=" + id +
                ", roleName='" + roleName + '\'' +
                ", note='" + note + '\'' +
                '}';
    }

    public String getRoleName() {
        return roleName;
    }

    public void setRoleName(String roleName) {
        this.roleName = roleName;
    }

    public String getNote() {
        return note;
    }

    public void setNote(String note) {
        this.note = note;
    }
}
```
```java
package com.learn.test;
import com.learn.test.Role;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component("eirole")
public class EIRole {
    @Override
    public String toString() {
        return "EIRole{" +
                "role=" + role +
                ", note='" + note + '\'' +
                '}';
    }

    @Value("#{role}")
    private Role role;
    @Value("#{role.toString()}")
    private String note;

    public Role getRole() {
        return role;
    }

    public void setRole(Role role) {
        this.role = role;
    }
}
```




##### Spring AOP实例
`在使用Aspect注解之前需要导入包aspectjweaver-1.6.2.jar`  
`在使用Aspect注解之前需要导入包aspectjweaver-1.6.2.jar`  
`在使用Aspect注解之前需要导入包aspectjweaver-1.6.2.jar`  
`在使用Aspect注解之前需要导入包aspectjweaver-1.6.2.jar`  

方法接口
```java
package com.learn.test;


public interface RoleServer {
    public void printRoles(Role role);
}
```
方法实现类
```java
package com.learn.test;
import org.springframework.stereotype.Component;

@Component
public class RoleServerImp implements RoleServer{
    @Override
    public void printRoles(Role role) {
        System.out.println(role.getId()+role.getNote());
    }
}
```
对象
```java
package com.learn.test;

import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;

@Component("role")
public class Role {
    @Value("#{1}")
    private Integer id;
    @Value("#{'role1'}")
    private String roleName;
    @Value("#{'mynote'}")
    private String note;

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }


    public String getRoleName() {
        return roleName;
    }

    public void setRoleName(String roleName) {
        this.roleName = roleName;
    }

    public String getNote() {
        return note;
    }

    public void setNote(String note) {
        this.note = note;
    }
}
```
代理类
```java
package com.learn.test;

import org.aspectj.lang.annotation.*;

@Aspect
public class RoleAspect {

    @Pointcut("execution(* com.learn.test.RoleServer.printRoles(..)) && within(com.learn.test.*)")
    public void print() {
    }

    @Before("print()")
    public void before() {
        System.out.println("before........");
    }

    @After("print()")
    public void after() {
        System.out.println("after..........");
    }

    @AfterReturning("print()")
    public void afterReturning() {
        System.out.println("afterReturning........");
    }

    @AfterThrowing("print()")
    public void afterThrowing() {
        System.out.println("afterThrowing........");
    }
}
```
整合类
```java
package com.learn.test;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.EnableAspectJAutoProxy;

@Configuration
@EnableAspectJAutoProxy
@ComponentScan("com.learn.test")
public class AopConfig {
    @Bean
    public RoleAspect getRoleAspect()
    {
        return new RoleAspect();
    }
}

```
测试类
```java
package com.learn.test;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class Main {
    public static void main(String[] args) {
        ApplicationContext applicationContext=new AnnotationConfigApplicationContext(AopConfig.class);
        RoleServer roleServer= (RoleServer) applicationContext.getBean(RoleServer.class);
        Role role1= new Role();
        role1.setNote("我的备注");
        role1.setRoleName("我的mingzi");
        role1.setId(1);
//        role1=null;
        roleServer.printRoles(role1);
        System.out.println("#######################");
    }
}
```
##### 环绕通知
```java
 public void around(ProceedingJoinPoint jp) {
        System.out.println("around before .....");
        try{
            jp.proceed();//使用这个后先调用前置通知然后调用切片，最后是后置方法。
        }catch (Throwable e)
        {
            e.printStackTrace();
        }
        System.out.println("around after.....");
    }
```
##### 用xml开发AOP

XML配置AOP的元素：

配置元素|用途|备注
-|-|-
aop:aspect|定义一个切面|-
aop:before|定义前置通知|-
aop:after|定义后置通知|-
aop:around|定义环绕方式|-
aop:after-returning|定义返回通知|-
aop:after-throwing|定义异常通知|-
aop:config|顶层AOP配置元素|AOP的配置以此为开始
aop:declare-parents|给通知额外的接口，以增强功能|- 
aop:pointcut|定义切点|-

同上代码的xml配置文件
```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:util="http://www.springframework.org/schema/util"
       xmlns:context="http://www.springframework.org/schema/context"
       xmlns:aop="http://www.springframework.org/schema/aop"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
       http://www.springframework.org/schema/beans/spring-beans-4.3.xsd http://www.springframework.org/schema/util http://www.springframework.org/schema/util/spring-util.xsd http://www.springframework.org/schema/context http://www.springframework.org/schema/context/spring-context.xsd http://www.springframework.org/schema/aop http://www.springframework.org/schema/aop/spring-aop.xsd">
    <bean id="roleAspect" class="com.learn.test.RoleAspect"/>
    <bean id="roleServer" class="com.learn.test.RoleServerImp"/>
    <aop:config>
        <aop:aspect ref="roleAspect">
            <aop:before method="before" pointcut="execution(* com.learn.test.RoleServerImp.printRoles(..))"/>
            <aop:before method="after" pointcut="execution(* com.learn.test.RoleServerImp.printRoles(..))"/>
            <aop:before method="afterReturning" pointcut="execution(* com.learn.test.RoleServerImp.printRoles(..))"/>
            <aop:before method="afterThrowing" pointcut="execution(* com.learn.test.RoleServerImp.printRoles(..))"/>
        </aop:aspect>
    </aop:config>
</beans>
```
当需要配置多个切面（相当于责任链模式）需要决定执行顺序的时候使用`@order(1)`注解来决定每一个切片的运行顺序


##### DBCP的使用（第三方数据连接库）
DBCP所依赖的jar包  
 `commons-dbcp2-2.1.1.jar`   
 `commons-logging-1.2.jar`  
 `commons-pool2-2.4.2.jar`

xml文件
```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
       http://www.springframework.org/schema/beans/spring-beans-4.3.xsd">

    <bean id="dataSource2" class="org.springframework.jdbc.datasource.SimpleDriverDataSource">
        <property name="driverClass" value="com.mysql.jdbc.Driver"/>
        <property name="url" value="jdbc:mysql://deepblue.datsec.cn:3306/learn"/>
        <property name="username" value="root"/>
        <property name="password" value="xxxx"/>
    </bean>
    <bean id="dataSource1" class="org.apache.commons.dbcp2.BasicDataSource">
        <property name="driverClassName" value="com.mysql.jdbc.Driver"/>
        <property name="url" value="jdbc:mysql://localhost:3306/jdbc"/>
        <property name="username" value="root"/>
        <property name="password" value="root"/>
<!--        最大连接数-->
        <property name="maxTotal" value="255"/>
<!--        最大等待数量-->
        <property name="maxIdle" value="5"/>
<!--        最大等待时间-->
        <property name="maxWaitMillis" value="1000"/>
    </bean>
    <bean id="jdbcTemplate" class="org.springframework.jdbc.core.JdbcTemplate" >
        <property name="dataSource" ref="dataSource2"/>
    </bean>
</beans>
```
java测试类
```java
package com.learn.test;

import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.testng.annotations.Test;

import java.sql.ResultSet;
import java.sql.SQLException;

public class Main {
    public static void main(String[] args) {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("config2.xml");
        RoleServer roleServer = (RoleServer) applicationContext.getBean("roleServer");
        Role role1 = new Role();
        role1.setNote("我的备注");
        role1.setRoleName("我的mingzi");
        role1.setId(1);
//        role1=null;
        int x = 1;
        if (roleServer.roleNotNull(role1))
            roleServer.printRoles(role1, x);
        System.out.println("#######################");
    }

    @Test
    public void testfor() {
        ApplicationContext applicationContext=new AnnotationConfigApplicationContext(AopConfig.class);
        RoleServer roleServer=applicationContext.getBean(RoleServer.class);
        Role role= (Role) applicationContext.getBean("role");
        roleServer.printRoles(role,1);
    }

    @Test
    public void forSql()
    {
        ApplicationContext applicationContext=new ClassPathXmlApplicationContext("data-config.xml");
        JdbcTemplate jdbcTemplate=applicationContext.getBean(JdbcTemplate.class);
        int id=1;
        String sql="select id,name,birth,money from person where id ="+id;
        Person p=jdbcTemplate.queryForObject(sql, new RowMapper<Person>() {
            @Override
            public Person mapRow(ResultSet resultSet, int i) throws SQLException {
                Person person=new Person();
                person.setId(resultSet.getInt("id"));
                person.setName(resultSet.getString("name"));
                person.setBirth(resultSet.getString("birth"));
                person.setMoney(resultSet.getString("money"));
                return person;
            }
        });
        System.out.println(p);
    }
}
````
person类
```java
package com.learn.test;

public class Person {
    private int id;
    private String name;
    private String birth;
    private String money;

    public int getId() {
        return id;
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

    @Override
    public String toString() {
        return "Person{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", birth='" + birth + '\'' +
                ", money='" + money + '\'' +
                '}';
    }

    public String getMoney() {
        return money;
    }

    public void setMoney(String money) {
        this.money = money;
    }
}
```

spring-mybatis框架的使用
首先需要下载mybatis-spring.jar包：  
地址:https://mvnrepository.com/artifact/org.mybatis/mybatis-spring  
来一段示例代码（SqlSessionTemplate类）:  
Person类:  
```java
package com.learn.test;

public class Person {
    private int id;
    private String name;
    private String birth;
    private float money;

    public int getId() {
        return id;
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

    @Override
    public String toString() {
        return "Person{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", birth='" + birth + '\'' +
                ", money='" + money + '\'' +
                '}';
    }

    public float getMoney() {
        return money;
    }

    public void setMoney(float money) {
        this.money = money;
    }
}
```

```java
 @Test
    public void testSqlSession()
    {
        ApplicationContext applicationContext=new ClassPathXmlApplicationContext("data-config.xml");
        SqlSessionTemplate sqlSessionTemplate= applicationContext.getBean(SqlSessionTemplate.class);
        Person person=new Person();
        person.setName("张三");
        person.setMoney((float) 200.6);
        person.setBirth("1999-1-1");
        sqlSessionTemplate.insert("com.learn.test.RoleMapper.insertRole",person);

    }
```

spring配置文件
```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
       http://www.springframework.org/schema/beans/spring-beans-4.3.xsd">

    <bean id="dataSource2" class="org.springframework.jdbc.datasource.SimpleDriverDataSource">
        <property name="driverClass" value="com.mysql.jdbc.Driver"/>
        <property name="url" value="jdbc:mysql://deepblue.datsec.cn:3306/learn"/>
        <property name="username" value="root"/>
        <property name="password" value="xxx"/>
    </bean>
    <bean id="dataSource1" class="org.apache.commons.dbcp2.BasicDataSource">
        <property name="driverClassName" value="com.mysql.jdbc.Driver"/>
        <property name="url" value="jdbc:mysql://localhost:3306/jdbc"/>
        <property name="username" value="root"/>
        <property name="password" value="root"/>
<!--        最大连接数-->
        <property name="maxTotal" value="255"/>
<!--        最大等待数量-->
        <property name="maxIdle" value="5"/>
<!--        最大等待时间-->
        <property name="maxWaitMillis" value="1000"/>
    </bean>
    <bean id="jdbcTemplate" class="org.springframework.jdbc.core.JdbcTemplate" >
        <property name="dataSource" ref="dataSource2"/>
    </bean>
    <bean id="sqlSessionFactory" class="org.mybatis.spring.SqlSessionFactoryBean">
        <property name="dataSource" ref="dataSource2"/>
        <property name="configLocation" value="classpath:sqlMapConfig.xml"/>
    </bean>
    <bean id="sqlSessionTemplate" class="org.mybatis.spring.SqlSessionTemplate">
        <constructor-arg ref="sqlSessionFactory"/>
        <constructor-arg value="BATCH"/>
    </bean>
</beans>
```
mybatis配置文件
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE configuration
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-config.dtd">
<configuration>
    <settings>
        <setting name="cacheEnabled" value="true"/>
        <setting name="useGeneratedKeys" value="true"/>
        <setting name="defaultExecutorType" value="REUSE"/>
        <setting name="lazyLoadingEnabled" value="true"/>
        <setting name="defaultStatementTimeout" value="25000"/>
    </settings>
    <typeAliases>
        <package name="com.learn.test"/>
    </typeAliases>
    <mappers>
        <mapper resource="RoleMapper.xml"/>
    </mappers>
</configuration>
```
Mapper文件
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.learn.test.RoleMapper">
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
    <select id="selectRole" parameterType="int" resultType="person">
        select * from person where id =#{id}
    </select>

</mapper>
```
方法接口
```java
package com.learn.test;

import org.apache.ibatis.annotations.Param;

public interface RoleMapper {
    public int insertRole(Role role);

    public int updateRole(Role role);

    public int deleteRole(@Param("id") int id);

    public int getRole(@Param("id") int id);
}
```

mybatis-spring操作数据库:  
1.配置datasource如下:
```xml
<bean id="dataSource1" class="org.apache.commons.dbcp2.BasicDataSource">
        <property name="driverClassName" value="com.mysql.jdbc.Driver"/>
        <property name="url" value="jdbc:mysql://localhost:3306/jdbc"/>
        <property name="username" value="root"/>
        <property name="password" value="root"/>
        <!--        最大连接数-->
        <property name="maxTotal" value="255"/>
        <!--        最大等待数量-->
        <property name="maxIdle" value="5"/>
        <!--        最大等待时间-->
        <property name="maxWaitMillis" value="1000"/>
</bean>
```
2.配置SqlsessionFactory
```xml
<bean id="sqlSessionFactory" class="org.mybatis.spring.SqlSessionFactoryBean">
        <property name="dataSource" ref="dataSource2"/>
        <property name="configLocation" value="classpath:sqlMapConfig.xml"/>
</bean>
```
同时需要配置本地参数  
sqlMapConfig.xml
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
        <package name="com.learn.test"/>
    </typeAliases>
    <mappers>
        <mapper resource="RoleMapper.xml"/>
    </mappers>
</configuration>
```
这时就要进行映射器的配置了:  
```xml
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE mapper
        PUBLIC "-//mybatis.org//DTD Mapper 3.0//EN"
        "http://mybatis.org/dtd/mybatis-3-mapper.dtd">
<mapper namespace="com.learn.test.RoleMapper">
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
    <select id="selectRole" parameterType="int" resultType="person">
        select * from person where id =#{id}
    </select>
</mapper>
```
3.配置MapperFactoryBean
```xml
<bean id="roleMapper" class="org.mybatis.spring.mapper.MapperFactoryBean">
        <property name="sqlSessionFactory" ref="sqlSessionFactory"/>
        <property name="mapperInterface" value="com.learn.test.RoleMapper"/>
</bean>
```

###### 进行多Mapper文件扫描

如果进行多个mapper文件扫描的话需要将mapper的定义文件与接口文件放在统一包下，然后在配置MapperFactoryBean的地方更改为：
```xml
<bean class="org.mybatis.spring.mapper.MapperScannerConfigurer">
        <property name="basePackage" value="com.learn.test"/>
</bean>
```
此时不用再配置mybatis配置中的Mapper文件，如果文件不在一个包下但是想自动配置的话需要在定义的接口类中加入`@Repository`注解，同时将上面配置文件改为:
```xml
<bean class="org.mybatis.spring.mapper.MapperScannerConfigurer">
        <property name="basePackage" value="com.learn.test"/>
        <property name="annotationClass" value="org.springframework.stereotype.Repository"/>
</bean>
```
即可实现自动扫描，但是建议将mapper接口类与实现文件放在同一个包下。

##### spring数据库事务管理器
需要在xml配置文件中加入
```xml
http://www.springframework.org/schema/tx
http://www.springframework.org/schema/tx/spring-tx-4.3.xsd
```
还需要加入
```xml
<bean id="transaction" class="org.springframework.jdbc.datasource.DataSourceTransactionManager">
        <property name="dataSource" ref="dataSource2"/>
```
这是通过xml文件配置，也可以通过Java代码进行配置
###### xml配置过程
0.配置数据源  
1.配置数据源事务管理器（如上）   
2.配置事务拦截器
```xml
<bean id="transactionInterceptor" class="org.springframework.transaction.interceptor.TransactionInterceptor">
        <property name="transactionManager" ref="transaction"/>
        <!--        配置事务属性-->
        <property name="transactionAttributes">
            <props>
                <!--                使用正则匹配业务方法-->
                <prop key="insert*">PROPAGATION_REQUIRED,ISOLATION_READ_UNCOMMITTED</prop>
                <prop key="save*">PROPAGATION_REQUIRED,ISOLATION_READ_UNCOMMITTED</prop>
                <prop key="add*">PROPAGATION_REQUIRED,ISOLATION_READ_UNCOMMITTED</prop>
                <prop key="select*">PROPAGATION_REQUIRED,readOnly</prop>
                <prop key="get*">PROPAGATION_REQUIRED,readOnly</prop>
                <prop key="find*">PROPAGATION_REQUIRED,readOnly</prop>
                <prop key="del*">PROPAGATION_REQUIRED,ISOLATION_READ_UNCOMMITTED</prop>
                <prop key="remove*">PROPAGATION_REQUIRED,ISOLATION_READ_UNCOMMITTED</prop>
                <prop key="update*">PROPAGATION_REQUIRED,ISOLATION_READ_UNCOMMITTED</prop>
            </props>
        </property>
    </bean>
```
3.指名事务拦截器拦截哪些类
```xml
<bean class="org.springframework.aop.framework.autoproxy.BeanNameAutoProxyCreator">
        <property name="beanNames">
            <list>
                <value>*serverImp</value>
            </list>
        </property>
        <property name="interceptorNames">
            <list>
                <value>transactionInterceptor</value>
            </list>
        </property>
</bean>
```
###### 注解配置过程 
1.配置数据源  
2.配置事务管理器  
3.配置使用注解定义事务  
```xml
<!--    定义事务使用注解方式-->
<tx:annotation-driven transaction-manager="transaction"/>
```

示例代码:  
Person类和接口就不写了  
主程序配置文件:
```xml
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:tx="http://www.springframework.org/schema/tx"
       xmlns:context="http://www.springframework.org/schema/context"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
       http://www.springframework.org/schema/beans/spring-beans-4.3.xsd
       http://www.springframework.org/schema/tx
       http://www.springframework.org/schema/tx/spring-tx-4.3.xsd http://www.springframework.org/schema/context http://www.springframework.org/schema/context/spring-context.xsd">
<!--    <context:annotation-config/>-->
<!--    <context:component-scan base-package="com.learn.test.*"/>-->
    <!--    扫描Mapper Bean-->
    <bean class="com.learn.test.Mapper2Imp" id="mapper2Imp"/>
<!--    <context:component-scan base-package="com.learn.test"/>-->
    <bean class="org.mybatis.spring.mapper.MapperScannerConfigurer">
        <property name="basePackage" value="com.learn.test"/>
        <property name="annotationClass" value="org.springframework.stereotype.Repository"/>
    </bean>
    <!--    事务管理器-->
    <bean id="transaction" class="org.springframework.jdbc.datasource.DataSourceTransactionManager">
        <property name="dataSource" ref="dataSource2"/>
    </bean>
    <!--    定义事务使用注解方式-->
    <tx:annotation-driven transaction-manager="transaction"/>
    <bean id="sqlSessionFactory" class="org.mybatis.spring.SqlSessionFactoryBean">
        <property name="dataSource" ref="dataSource2"/>
        <property name="configLocation" value="classpath:sqlMapConfig.xml"/>
    </bean>
    <bean id="dataSource2" class="org.springframework.jdbc.datasource.SimpleDriverDataSource">
        <property name="driverClass" value="com.mysql.jdbc.Driver"/>
        <property name="url" value="jdbc:mysql://deepblue.datsec.cn:3306/learn"/>
        <property name="username" value="root"/>
        <property name="password" value="anzhuoshiyanshi"/>
    </bean>
    <bean id="dataSource1" class="org.apache.commons.dbcp2.BasicDataSource">
        <property name="driverClassName" value="com.mysql.jdbc.Driver"/>
        <property name="url" value="jdbc:mysql://localhost:3306/jdbc"/>
        <property name="username" value="root"/>
        <property name="password" value="root"/>
        <!--        最大连接数-->
        <property name="maxTotal" value="255"/>
        <!--        最大等待数量-->
        <property name="maxIdle" value="5"/>
        <!--        最大等待时间-->
        <property name="maxWaitMillis" value="1000"/>
    </bean>
</beans>
```
插入list的接口
```java
package com.learn.test;

import org.springframework.stereotype.Component;

import java.util.List;


public interface Mapper2 {
    public int insertRoleList(List<Person> roleList);
}
```
实现类
```java
package com.learn.test;

import org.apache.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Propagation;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;

@Component
public class Mapper2Imp implements Mapper2 {
    Logger logger = Logger.getLogger(Mapper2.class);

    @Autowired
    RoleMapper roleMapper = null;

    @Override
    @Transactional(isolation = Isolation.READ_COMMITTED, propagation = Propagation.REQUIRED)
    public int insertRoleList(List<Person> roleList) {
        int count = 0;
        for (Person p : roleList) {
            try {
                if (p==null)
                    throw new Exception();
                count += roleMapper.insertRole(p);
            } catch (Exception e) {
                logger.info(e.toString());
            }
        }
        return count;
    }
}
```
测试类:
```java
   @Test
    public void testForManager(){
        ApplicationContext applicationContext=new ClassPathXmlApplicationContext("data-config.xml");
        RoleMapper roleMapper=applicationContext.getBean(RoleMapper.class);
        Person p=new Person();
        p.setName("呵呵");
        p.setBirth("2019-7-1");
        p.setMoney((float) 200.55);
        Person p2=new Person();
        p2.setName("呵呵2");
        p2.setBirth("2019-7-2");
        p2.setMoney((float) 250);
        List<Person> list=new ArrayList<>();
        list.add(p);
        list.add(p2);
        list.add(null);
        list.add(p2);
//        roleMapper.insertRole(p);
        Mapper2 mapper2=applicationContext.getBean(Mapper2.class);
        int count=mapper2.insertRoleList(list);
        System.out.println(count);
    }
```


###### 过长占用事务时间的解决方法
```java
package com.learn.test;

import org.springframework.stereotype.Controller;

import org.springframework.beans.factory.annotation.Autowired;

@Controller
public class RoleController {
    @Autowired
    private RoleServer roleServer = null;

    @RequestMapping("/addRole")
    @ResponseBody
    public Role addRole(Role role) {
        roleServer.printRoles();
        dosomething();
    }
}
```
这样dosomething就会在事务结束后进行操作
