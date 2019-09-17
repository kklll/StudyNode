<!--961032830987546d0e6d54829fc886f6-->

目录(Catalo)

* [<center>python学习笔记</center>](#%3Ccenter%3Epython%E5%AD%A6%E4%B9%A0%E7%AC%94%E8%AE%B0%3C/center%3E)
    * [pytho正则表达式](#pytho%E6%AD%A3%E5%88%99%E8%A1%A8%E8%BE%BE%E5%BC%8F)
* [删除注释](#%E5%88%A0%E9%99%A4%E6%B3%A8%E9%87%8A)
* [移除非数字的内容](#%E7%A7%BB%E9%99%A4%E9%9D%9E%E6%95%B0%E5%AD%97%E7%9A%84%E5%86%85%E5%AE%B9)
  * [python小实践](#python%E5%B0%8F%E5%AE%9E%E8%B7%B5)
    * [trutle库绘制日期](#trutle%E5%BA%93%E7%BB%98%E5%88%B6%E6%97%A5%E6%9C%9F)
      * [爬取国家医药卫生科学数据共享网--药学科学数据中心药物](#%E7%88%AC%E5%8F%96%E5%9B%BD%E5%AE%B6%E5%8C%BB%E8%8D%AF%E5%8D%AB%E7%94%9F%E7%A7%91%E5%AD%A6%E6%95%B0%E6%8D%AE%E5%85%B1%E4%BA%AB%E7%BD%91--%E8%8D%AF%E5%AD%A6%E7%A7%91%E5%AD%A6%E6%95%B0%E6%8D%AE%E4%B8%AD%E5%BF%83%E8%8D%AF%E7%89%A9)
      * [与此关联的图片信息](#%E4%B8%8E%E6%AD%A4%E5%85%B3%E8%81%94%E7%9A%84%E5%9B%BE%E7%89%87%E4%BF%A1%E6%81%AF)

<!--a46263f7a69f33f39fc26f907cdb773a-->

  

- 以下划线开头的标识符是有特殊意义的。以单下划线开头 _foo 的代表不能直接访问的类属性，需通过类提供的接口进行访问，不能用 from xxx import * 而导入；
- 以双下划线开头的__foo 代表类的私有成员；以双下划线开头和结尾的__foo__ 代表Python 里特殊方法专用的标识，如 __init__() 代表类的构造函数。


### pytho正则表达式
```
match方法：
match()方法，第一个参数传入了正则表达式，第二个参数传入了要匹配的字符串。
修饰符：
re.I使匹配对大小写不敏感
re.L做本地化识别（locale-aware）匹配
re.M多行匹配，影响 ^ 和 $
re.S使 . 匹配包括换行在内的所有字符
re.U根据Unicode字符集解析字符。这个标志影响 \w, \W, \b, \B.
re.X该标志通过给予你更灵活的格式以便你将正则表达式写得更易于理解。

re.search()方法是从字符串中寻找，不同于match方法字符串开头不匹配就无法匹配。(只寻找一个符合条件的正则表达式)
\s 是匹配[\n\t\r]的
re.sub()
Python 的re模块提供了re.sub用于替换字符串中的匹配项。
语法：
re.sub(pattern, repl, string, count=0)
返回的字符串是在字符串中用 RE 最左边不重复的匹配来替换。如果模式没有发现，字符将被没有改变地返回。
实例：
#!/usr/bin/python3
import re

phone = "2004-959-559 # 这是一个电话号码"

# 删除注释
num = re.sub(r'#.*$', "", phone)
print ("电话号码 : ", num)

# 移除非数字的内容
num = re.sub(r'\D', "", phone)
print ("电话号码 : ", num)
以上实例执行结果如下：
电话号码 :  2004-959-559 
电话号码 :  2004959559

re.findall()
寻找所有符合条件的字符。

```

## python小实践
### trutle库绘制日期
```python
import turtle, datetime
def drawgap():
    turtle.penup()
    turtle.fd(5)
def drawline(draw):
    drawgap()
    turtle.pendown() if draw else turtle.penup()
    turtle.fd(40)
    drawgap()
    turtle.right(90)
def drawdigit(d):
    drawline(True) if d in [2,3,4,5,6,8,9] else drawline(False)
    drawline(True) if d in [0,1,3,4,5,6,7,8,9] else drawline(False)
    drawline(True) if d in [0,2,3,5,6,8,9] else drawline(False)
    drawline(True) if d in [0,2,6,8] else drawline(False)
    turtle.left(90)
    drawline(True) if d in [0,4,5,6,8,9] else drawline(False)
    drawline(True) if d in [0,2,3,5,6,7,8,9] else drawline(False)
    drawline(True) if d in [0,1,2,3,4,7,8,9] else drawline(False)
    turtle.left(180)
    turtle.penup()
    turtle.fd(20)
def drawdate(date):
    turtle.pencolor("red")
    for i in date:
        if i == '-':
            turtle.write('年',font=("Arial", 18, "normal"))
            turtle.pencolor("green")
            turtle.fd(40)
        elif i == '=':
            turtle.write('月',font=("Arial", 18, "normal"))
            turtle.pencolor("blue")
            turtle.fd(40)
        elif i == '+':
            turtle.write('日',font=("Arial", 18, "normal"))
        else:
            drawdigit(eval(i))
def main():
    turtle.setup(800, 350, 200, 200)
    turtle.penup()
    turtle.fd(-350)
    turtle.pensize(5)
    drawdate(datetime.datetime.now().strftime('%Y-%m=%d+'))
    print(datetime.datetime.now().strftime('%Y-%m=%d+'))
    turtle.hideturtle()
    turtle.done()

main()
````

### 文本进度条刷新版
``` python
import time
scale=10
print('--------执行开始---------')
for i in range(scale+1):
    a,b='**'* i, '..'*(scale-i)
    c=(i/scale)*100
    print('\r{:.2f}%[{}->{}]'.format(c,a,b),end="")
    time.sleep(0.1)
print('\n--------执行结束---------')
```

#### 爬取国家医药卫生科学数据共享网--药学科学数据中心药物
    最近做项目需要一些关于药品适应症，用法用量，禁忌，注意事项等数据，于是去药学数据中心药物爬取了一些数据，就是用最简单的requests请求数据，
    使用BeautifulSoup进行数据的解析。
效果如图：  
![pic](https://github.com/kklll/Project2/blob/master/python/pic.png)

下面附上源代码。

```python
# -*- coding: utf-8 -*-
import pymysql
import requests,re
from bs4 import BeautifulSoup
headers={
    'Host' : 'pharm.ncmi.cn',
    'Upgrade-Insecure-Requests' : '1',
    'User-Agent' : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.86 Safari/537.36',
    'Accept' : 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3',
    'Referer' : 'http://pharm.ncmi.cn/pharm/jsp/index_site_on.jsp',
    'Accept-Encoding' : 'gzip, deflate',
    'Accept-Language' : 'zh-CN,zh;q=0.9',
    'Connection' : 'close',
}
cookie={'Hm_lpvt_3849dadba32c9735c8c87ef59de6783c':"1554378019",
        'Hm_lvt_3849dadba32c9735c8c87ef59de6783c':"1554300692,1554344080",'JSESSIONID':'0000hY5m6IInAB6E8CEWHivi9Ku:-1'}
db=pymysql.connect("127.0.0.1","root","root","med")
if(db):
    print("连接成功！")
else:
    print("连接失败！")
cursor = db.cursor()
cursor.execute("use med")
for i in range(198644,200058):
    requests_url="http://pharm.ncmi.cn/dataContent/dataSearch.do?method=viewpage&id="+str(i)+"&did=28"
    id=i
    print(id)
    # print(requests_url)
    # s=requests.Session()
    result=requests.get(requests_url,cookies=cookie).text
    soup=BeautifulSoup(result,"lxml")
    # res=soup.find_all("td","tdtilte")
    res2=soup.find_all("td","tdcontent")
    commit=[]
    # print(res)
    # for i in res:
    #     jieguo=i.get_text()
    #     jieguo=re.sub('[\r\n\t]', '', jieguo)
    #     if (jieguo == ''):
    #         jieguo = 'x'
    #     print(jieguo)
    for i in res2:
        jieguo2=i.get_text()
        jieguo2=re.sub('[\r\n\t]', '', jieguo2)
        commit.append(jieguo2)
    # print(commit)
    sql="set names utf8"
    cursor.execute(sql)

    try:
        sql="INSERT INTO `med`"+ \
        " VALUES (%d,'%s', '%s', '%s','%s', '%s','%s', '%s',  '%s',  '%s',  '%s','%s', '%s',  '%s',  " \
        "'%s',  '%s','%s', '%s',  '%s',  '%s',  '%s','%s', '%s', ' %s',  '%s',  '%s')" % \
        (id,commit[0],commit[1],commit[2],commit[3],commit[4],commit[5],commit[6],commit[7],commit[8],
         commit[9],commit[10],commit[11],commit[12],commit[13],commit[14],commit[15],
         commit[16],commit[17],commit[18],commit[19],commit[20],commit[21],commit[22],commit[23],commit[24])
        # 执行sql语句
        cursor.execute(sql)
        # 执行sql语句
        db.commit()
        print(str(id)+"Done")
    except:
        # 发生错误时回滚
        db.rollback()
# 关闭数据库连接
db.close()
```

#### 与此关联的图片信息
需要一些图片的链接于是又写了一个爬虫，原理更简单，使用百度图片的链接进行获取，从网页源代码中使用正则表达式匹配图片url,将图片的URL存到数据库内。
效果如图。  
![pic2](https://github.com/kklll/Project2/blob/master/python/pic2.png)

附上代码：
```python
import pymysql
import requests
import re
from bs4 import BeautifulSoup
try:
    db=pymysql.connect("127.0.0.1","root","root","med")
    print("连接成功！")
except:
    print("连接失败！")
    exit(0)
cursor = db.cursor()
cursor.execute("select id,药品名称 from med where id > 198255;")
data=cursor.fetchall()
print(data)
for i in data:
    id=i[0]
    i=i[1]
    print(id)
    print(i)
    # print("https://image.baidu.com/search/index?tn=baiduimage&ipn=r&ct="
    #              "201326592&cl=2&lm=-1&st=-1&fm=result&fr=&sf=1&fmq=1554433360821_R&pv="
    #              "&ic=&nc=1&z=&hd=&latest=&copyright=&se=1&showtab=0&fb=0&width=&height=&fa"
    #              "ce=0&istype=2&ie=utf-8&word="+i)
    a=requests.get("https://image.baidu.com/search/index?tn=baiduimage&ipn=r&ct="
                 "201326592&cl=2&lm=-1&st=-1&fm=result&fr=&sf=1&fmq=1554433360821_R&pv="
                 "&ic=&nc=1&z=&hd=&latest=&copyright=&se=1&showtab=0&fb=0&width=&height=&fa"
                 "ce=0&istype=2&ie=utf-8&word="+i)
    # print(a.text)
    result=re.findall('"thumbURL":"(.*?)"',a.text)

    try:
        sql = "UPDATE med SET image1= '%s', image2 = '%s',image3 = '%s' WHERE id = %d" \
              % (result[0],result[1],result[2],id)
        cursor.execute(sql)
        db.commit()
        print(result[0]+"-"+result[1]+"-"+result[2]+"上传数据完成！")
    except:
        print("上传数据失败！")
    #     db.rollback()
```