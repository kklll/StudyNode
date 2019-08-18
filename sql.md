## <center>SQL学习及记录</center>

#### 下面的例子都是以mysql为例
- select distinct * from test; distinct筛选重复元素
- Order By DESC 倒序排列
- Order by ASC 正序排列
- 通配符 _匹配一个字符%匹配所有[abcd]匹配括号内单个字符[!abcd]匹配除了abcd的字符  
- SELECT * FROM Persons
WHERE LastName IN ('Adams','Carter'); 匹配lastname是Adams和Carter的数据  
- `between`:     SELECT * FROM Persons
WHERE LastName
BETWEEN 'Adams' AND 'Carter' 
```
表的 SQL Alias 语法:
SELECT column_name(s) FROM table_name AS alias_name
列的 SQL Alias 语法:
SELECT column_name AS alias_name FROM table_name
```
##### join
Person表  
Id_P | LastName | FirstName | Address | City |  
-|-|-|-|-
|1|	Adams|	John|	Oxford |Street|	London|
|2|	Bush|	George|	Fifth| Avenue	|New York|
|3	|Carter	|Thomas|	Changan |Street	|Beijing|  

Orders表    


Id_O	|OrderNo|	Id_P
-|-|-
1|	77895	|3
2	|44678|	3
3	|22456|	1
4	|24562|	1
5	|34764|	65  

`引用的sql语句:`  
SELECT Persons.LastName, Persons.FirstName, Orders.OrderNo
FROM Persons, Orders
WHERE Persons.Id_P = Orders.Id_P   

`join的sql语句:`  
SELECT Persons.LastName, Persons.FirstName, Orders.OrderNo
FROM Persons
INNER JOIN Orders
ON Persons.Id_P = Orders.Id_P
ORDER BY Persons.LastName

了我们在上面的例子中使用的 INNER JOIN（内连接），我们还可以使用其他几种连接。

下面列出了您可以使用的 JOIN 类型，以及它们之间的差异。

JOIN: 如果表中有至少一个匹配，则返回行  
LEFT JOIN: 即使右表中没有匹配，也从左表返回所有的行  
RIGHT JOIN: 即使左表中没有匹配，也从右表返回所有的行  
FULL JOIN: 只要其中一个表中存在匹配，就返回行  

- left join(左连接)  

    SELECT Persons.LastName, Persons.FirstName, Orders.OrderNo
    FROM Persons
    LEFT JOIN Orders
    ON Persons.Id_P=Orders.Id_P
    ORDER BY Persons.LastName  
      

    LastName|	FirstName|	OrderNo
    -|-|-
    Adams	|John|	22456
    Adams	|John|	24562
    Carter|	Thomas|	77895
    Carter|	Thomas|	44678
    Bush	|George	 |


##### UNION 操作符
`UNION 内部的 SELECT 语句必须拥有相同数量的列。列也必须拥有相似的数据类型。同时，每条 SELECT 语句中的列的顺序必须相同。`  
默认地，UNION 操作符选取不同的值。如果允许重复的值，请使用 UNION ALL。

- 语法:  
SELECT E_Name FROM Employees_China
UNION
SELECT E_Name FROM Employees_USA

##### select into

SELECT INTO 语句从一个表中选取数据，然后把数据插入另一个表中。

SELECT INTO 语句常用于创建表的备份复件或者用于对记录进行存档。




##### SQL UNIQUE 约束
UNIQUE 约束唯一标识数据库表中的每条记录。

UNIQUE 和 PRIMARY KEY 约束均为列或列集合提供了唯一性的保证。

PRIMARY KEY 拥有自动定义的 UNIQUE 约束。

请注意，每个表可以有多个 UNIQUE 约束，但是每个表只能有一个 PRIMARY KEY 约束。

创建unique约束（mysql）:  
```sql
CREATE TABLE Persons
(
Id_P int NOT NULL,
LastName varchar(255) NOT NULL,
FirstName varchar(255),
Address varchar(255),
City varchar(255),
UNIQUE (Id_P)
)
```
解除unique约束（mysql）:
```sql
ALTER TABLE Persons
DROP INDEX uc_PersonID
```

- 撤销主键
```sql
ALTER TABLE Persons
DROP PRIMARY KEY
```


#### SQL FOREIGN KEY 约束
一个表中的 FOREIGN KEY 指向另一个表中的 PRIMARY KEY。

例子：  
"Persons" 表：  

Id_P|	LastName|	FirstName	|Address	|City
-| - |- |- |-
1	|Adams	|John|	Oxford Street	|London
2	|Bush	|George|	Fifth Avenue	|New York
3	|Carter	|Thomas|	Changan Street|	Beijing  


"Orders" 表：  

Id_O|OrderNo|Id_P
-|-|-  
1	|77895|	3
2	|44678|	3
3	|22456|	1
4	|24562|	1  


"Orders" 中的 "Id_P" 列指向 "Persons" 表中的 "Id_P" 列。

"Persons" 表中的 "Id_P" 列是 "Persons" 表中的 PRIMARY KEY。

"Orders" 表中的 "Id_P" 列是 "Orders" 表中的 FOREIGN KEY。

FOREIGN KEY 约束用于预防破坏表之间连接的动作。

FOREIGN KEY 约束也能防止非法数据插入外键列，因为它必须是它指向的那个表中的值之一。

- 创建  
下面的 SQL 在 "Orders" 表创建时为 "Id_P" 列创建 FOREIGN KEY：
```sql
CREATE TABLE Orders
(
Id_O int NOT NULL,
OrderNo int NOT NULL,
Id_P int,
PRIMARY KEY (Id_O),
FOREIGN KEY (Id_P) REFERENCES Persons(Id_P)
)
```
如果需要命名 FOREIGN KEY 约束，以及为多个列定义 FOREIGN KEY 约束，请使用下面的 SQL 语法：  
constraint(约束)  
```sql
CREATE TABLE Orders
(
Id_O int NOT NULL,
OrderNo int NOT NULL,
Id_P int,
PRIMARY KEY (Id_O),
CONSTRAINT fk_PerOrders FOREIGN KEY (Id_P)
REFERENCES Persons(Id_P)
)
```
- 添加外键约束
```sql
alter table learn_sql add constraint fk_perorders foreign key(id) references just(id);
```
- 删除外键约束
```sql
 alter table learn_sql drop foreign key fk_perorders;
```

##### SQL CHECK 约束
下面的 SQL 在 "Persons" 表创建时为 "Id_P" 列创建 CHECK 约束。CHECK 约束规定 "Id_P" 列必须只包含大于 0 的整数。  
```sql
CREATE TABLE Persons
(
Id_P int NOT NULL,
LastName varchar(255) NOT NULL,
FirstName varchar(255),
Address varchar(255),
City varchar(255),
CHECK (Id_P>0)
)
```
- 添加
```sql
ALTER TABLE Persons
ADD CHECK (Id_P>0)
```
- 删除
```sql
ALTER TABLE Persons
DROP CHECK chk_Person
```
其中chk_person为check约束名


##### SQL DEFAULT 约束

创建默认约束
```sql
CREATE TABLE Persons
(
Id_P int NOT NULL,
LastName varchar(255) NOT NULL,
FirstName varchar(255),
Address varchar(255),
City varchar(255) DEFAULT 'Sandnes'
)
```
插入默认约束
```sql
ALTER TABLE Persons
ALTER City SET DEFAULT 'SANDNES'
```
删除默认约束
```sql
ALTER TABLE Persons
ALTER City DROP DEFAULT
```

#### SQL CREATE INDEX 
创建索引 
SQL CREATE INDEX:
```sql
CREATE INDEX index_name
ON table_name (column_name)


CREATE INDEX PersonIndex
ON Person (LastName, FirstName)
```
删除索引
```sql
ALTER TABLE table_name DROP INDEX index_name
```

##### SQL AUTO INCREMENT 字段

设置自增开始
```sql
ALTER TABLE Persons AUTO_INCREMENT=100
```

#### MySQL Date 函数
函数|	描述
-|-
NOW()	|返回当前的日期和时间
CURDATE()	|返回当前的日期
CURTIME()|	返回当前的时间
DATE()	|提取日期或日期/时间表达式的日期部分
EXTRACT()	|返回日期/时间按的单独部分
DATE_ADD()	|给日期添加指定的时间间隔
DATE_SUB()	|从日期减去指定的时间间隔
DATEDIFF()|	返回两个日期之间的天数
DATE_FORMAT()	|用不同的格式显示日期/时间

MySQL 使用下列数据类型在数据库中存储日期或日期/时间值：

DATE - 格式 YYYY-MM-DD  
DATETIME - 格式: YYYY-MM-DD HH:MM:SS  
TIMESTAMP - 格式: YYYY-MM-DD HH:MM:SS  
YEAR - 格式 YYYY 或 YY  


### 函数
- AVG函数（计算平均值）  
SELECT AVG(column_name) FROM table_name

- count函数（计算条数）
SELECT COUNT(DISTINCT column_name) FROM table_name

- sum函数(求和)  
select sum(id) as sumx  from just; 

MySQL函数 [https://www.runoob.com/mysql/mysql-functions.html](https://www.runoob.com/mysql/mysql-functions.html)
