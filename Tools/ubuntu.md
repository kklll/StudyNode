## ubuntu18.04安装及使用遇到的一些问题解决方法

### 编程工具安装的问题
- Java环境
建议安装方法: openjdk
```shell
sudo apt-get install openjdk-8-jre 
```
8为版本号，可指定jdk8，jdk11等。

- Python环境Anaconda
   - 先去网页下载相应的安装包。地址：https://www.anaconda.com/distribution/
   - 解压
   - 运行.sh文件
   - 等待安装完成
重要的一点是安装完成后添加环境变量
```shell
sudo gedit ~/.bashrc
export PATH="/home/deepblue/anaconda3/bin:$PATH"
```
路径填自己的路径即可

- IDEA，Pycharm，Android Studio的安装
    - 最简便的方法才是最好的方法。所以我们用jetbrains全家桶（最好不要用Ubuntu本机的软件商店，下载速度慢还容易出问题）用工具的话速度很快的
    - jetbrains Develop Tool安装 地址：https://www.jetbrains.com/toolbox/app/
    - 下载后直接双击打开即可以安装以上所有IDE

### 安装mysql
```shell
sudo apt-get install mysql-server
```
运行安全脚本设置密码
```shell
sudo mysql_secure_installation
```
#### Android Studio 无法打开虚拟机的解决方法
- 问题：创建和运行时都提示："/dev/kvm device: permission denied" 或者 "/dev/kvm device: open failed"

这是因为没有运行权限
解决方法：
```shell
sudo chown <你系统当前的登陆用户名> -R /dev/kvm
```
- 如果提醒是VT错误需要在主板开启虚拟服务，具体操作参见 https://zhidao.baidu.com/question/55662873.html

### CLion导包方法

参见 https://blog.csdn.net/u013870094/article/details/78153408

### ssh的连接方法

```shell
 ssh ubuntu@deepblue.datsec.cn -p 8887
```
-p指定端口号，Ubuntu为用户名，deepblue.datsec.cn为ip地址 