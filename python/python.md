# <center>python学习笔记</center>

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
```
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
```
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
