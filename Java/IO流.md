#### IO流
[TOC]
IO流体系
![io流体系](https://upload-images.jianshu.io/upload_images/3985563-38c3ea4562d6dbe3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/687/format/webp)

##### 字符流
- FileWriter
    ```java
    import java.io.FileWriter;
    import java.io.IOException;

    /*
    I/O流
    字节流有两个基类:
    InputStream OutPutStream
    */
    public class Test {
        public static void main(String[] args) throws IOException {
            FileWriter fw= new FileWriter("test.txt");
            fw.write("sakjdbasjkdas");
            fw.flush();
            fw.close();
        }
    }
    ```
    - IO异常处理
    ```java
    import java.io.FileWriter;
    import java.io.IOException;

    /*
    I/O流
    I/O异常处理
    */
    public class Test {
        public static void main(String[] args) {
            FileWriter fw = null;
            try {
                fw = new FileWriter("K:\\test.txt");
                fw.write("sakjdbasjkdas");
                fw.flush();
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    if (fw!=null)
                    fw.close();
                    else
                        System.out.println("目录错了！");
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
    ```
    - 追加写
    ```java
    import java.io.FileWriter;
    import java.io.IOException;

    /*
    I/O流
    I/O异常处理
    */
    public class Test {
        public static void main(String[] args) {
            FileWriter fw = null;
            try {
                fw = new FileWriter("test.txt",true);
                fw.write("我哦\n头");
                fw.flush();
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                try {
                    if (fw!=null)
                    fw.close();
                    else
                        System.out.println("目录错了！");
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
    ```
- FileReader
    ```java
    import java.io.FileNotFoundException;
    import java.io.FileReader;
    import java.io.IOException;

    /*
    */
    public class Test {
        public static void main(String[] args) throws IOException {
            //第一种方法
            FileReader fr = new FileReader("test.txt");
    //        int ch = 0;
    //        while ((ch = fr.read()) != -1) {
    //            System.out.print((char) ch);
    //        }
            //第二种方法
            char[] buff = new char[1024];
            int num = 0;
            while ((num=fr.read(buff))!=-1) {
                System.out.print(new String(buff,0,num));
            }
            fr.close();
        }
    }
    ```
- 字符流的缓冲区 

缓冲区的出现提高了数据的读写效率
对应类

`BufferWriter` 

`BufferReader`
- BufferWriter
```java
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

/*
 */
public class Test {
    public static void main(String[] args) throws IOException {
        FileWriter fw=new FileWriter("test.txt");
        //为了提高写入流的效率加入缓冲技术
        BufferedWriter bufw=new BufferedWriter(fw);
        bufw.write("abcdef");
        bufw.newLine();//换行方法
        bufw.write("abcdef");
        bufw.flush();//必须刷新
        bufw.close();//必须关闭
    }
}
```
- BufferReader
```java
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/*
 */
public class Test {
    public static void main(String[] args) throws IOException {
        FileReader fr=new FileReader("test.txt");
        //为了提高流的效率加入缓冲技术
        BufferedReader bufr=new BufferedReader(fr);
        String x;
        while ((x=bufr.readLine())!=null)
        System.out.println(x);
    }
}
```
###### 装饰设计模式
- 当想要对已有对象进行功能增强时,那么可以定义类，将已有对象传入，基于已有的功能并提供加强功能

- 装饰模式比继承灵活。避免了继承体系的臃肿而且降低了类与类之间的关系

- 装饰类因为增强已有对象，具备的功能和已有功能是相同的，只不过扩展的了其功能
```java
class Person {
    public void chifan() {
        System.out.println("吃饭");
    }
}

class SuperPerson {
    private Person p;

    SuperPerson(Person p) {
        this.p = p;
    }

    public void shuijiao() {
        p.chifan();
        System.out.println("睡觉");
    }
}

class Demo {
    public static void main(String[] args) {
        Person p = new Person();
        p.chifan();
        SuperPerson sp = new SuperPerson(p);
        sp.shuijiao();
    }
}
```
- LineNumberReader
```java
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.LineNumberReader;

class Demo {
    public static void main(String[] args) throws IOException {
        FileReader fr=new FileReader("test.txt");
        LineNumberReader lr=new LineNumberReader(fr);
        lr.setLineNumber(100);
        String line=null;
        while ((line=lr.readLine())!=null)
            System.out.println(lr.getLineNumber()+":"+line);
        lr.close();
    }
}
```
##### 字节流
`InputStream`  `OutputStream`

FileOutputStream
```java
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

class Demp {
    public static void main(String[] args) throws IOException {
//        write();
//        readFile();
        readFile_2();
        readFile_3();
    }

    public static void write() throws IOException {
        FileOutputStream fos = new FileOutputStream("test.txt");
        fos.write("abcdef".getBytes());
        fos.close();
    }

    public static void readFile() throws IOException {
        FileInputStream fis = new FileInputStream("test.txt");
        int ch = 0;
        while ((ch = fis.read()) != -1) {
            System.out.print((char) ch);
        }
        System.out.println();
        fis.close();
    }

    public static void readFile_3() throws IOException {
        FileInputStream fis = new FileInputStream("test.txt");
        byte[] buf = new byte[1024];//定义一个刚好的缓冲区数组
        int len = 0;
        while ((len = fis.read(buf)) != -1)
            System.out.println(new String(buf, 0, len));
        fis.close();

    }

    public static void readFile_2() throws IOException {
        FileInputStream fis = new FileInputStream("test.txt");
        byte[] buf = new byte[fis.available()];//定义一个刚好的缓冲区数组
        fis.read(buf);//需要注意内存溢出
        System.out.println(new String(buf));
        fis.close();
    }
}
```
练习：图片复制
```java
/*
复制图片
 */

import java.io.*;
class Demo100{
    public static void main(String[] args) {
        FileOutputStream fos=null;
        FileInputStream fis=null;
        try{
            fos=new FileOutputStream("2.jpeg");
            fis=new FileInputStream("C:\\Users\\DeepBlue\\Pictures\\Saved Pictures\\0GBxtiFvzXE.jpg");
            byte []buf=new byte[1024];
            int len=0;
            while ((len=fis.read(buf))!=-1)
                fos.write(buf,0,len);

        }
        catch (IOException e)
        {
            throw new RuntimeException("复制文件失败！");
        }
        finally {
            try {
                fis.close();
                fos.close();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            System.out.println("文件复制成功！");
        }
    }
}
```
通过缓冲区实现对MP3文件的拷贝
```java
/*
通过字节流完成MP3的拷贝

 */

import java.io.*;

class Demo100 {
    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        copy_1();
        long end = System.currentTimeMillis();
        System.out.println(end - start);
    }

    public static void copy_1() throws IOException {
        BufferedInputStream buffis = new BufferedInputStream(new FileInputStream("E:\\CloudMusic\\崔天琪 - 放过.mp3"));
        BufferedOutputStream buffos = new BufferedOutputStream(new FileOutputStream("test.mp3"));
        int by = 0;
        while ((by = buffis.read()) != -1)
            buffos.write(by);
        buffis.close();
        buffos.close();
    }
}
```
自己写的缓冲区
```java
import java.io.*;

class MyBufferedInputStream {
    private InputStream in;
    private byte[] buf = new byte[1024 * 4];
    private int pos = 0, count = 0;

    MyBufferedInputStream(InputStream in) {
        this.in = in;
    }

    //一个字节一个字节读数据
    public int myRead() throws IOException {
        //通过in对象读取数据
        if (count == 0) {
            count = in.read(buf);
            if (count < 0) {
                return -1;
            }
            pos = 0;
            byte b = buf[pos];
            count--;
            pos++;
            return b & 255;
        } else if (count > 0) {
            byte b = buf[pos];
            count--;
            pos++;
            return b & 255;//&255的原因是要int和byte之间的类型提升导致前四字节补1，
            //需要和00000000000000000000000011111111与过后将前三字节的1变成0，
            //使得判断条件-1变化
        }
        return -1;
    }

    public void myclose() throws IOException {
        in.close();
    }

    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        MyBufferedInputStream buffis = new MyBufferedInputStream(new FileInputStream("E:\\CloudMusic\\崔天琪 - 放过.mp3"));
        BufferedOutputStream buffos = new BufferedOutputStream(new FileOutputStream("test.mp3"));
        int by = 0;
        while ((by = buffis.myRead()) != -1)
            buffos.write(by);
        buffis.myclose();
        buffos.close();
        long end = System.currentTimeMillis();
        System.out.println(end - start);
    }
}
```

##### 键盘录入数据

```java
import java.io.*;

/*
System.out:输出
System.in:输入
 */
class ReadIn {
    public static void main(String[] args) throws IOException {
        InputStream in = System.in;//获取键盘输入流对象
        InputStreamReader isr=new InputStreamReader(in);//将字节流对象转换为字符流
        BufferedReader bufr=new BufferedReader(isr);
        String line=null;
        while ((line=bufr.readLine())!=null)
        {
            if (line.equals("over"))
                break;
            System.out.println(line.toUpperCase());
        }
    }
}
//        StringBuilder sb = new StringBuilder();
//        while (true) {
//            int ch = in.read();
//            if (ch == '\r')
//                continue;
//            if (ch == '\n') {
//                String s = sb.toString();
//                if (s.equals("over")) {
//                    break;
//                }
//                System.out.println(s.toUpperCase());
//                sb.delete(0, sb.length());
//            } else
//                sb.append((char) ch);
//        }

```
利用Scanner类进行录入
```java
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        while (sc.hasNext())
        {
            String s=sc.nextLine();
            System.out.println(s);
        }
    }
}
```
转换流对象
```java
import java.io.*;
/*
转换流对象
 */
class Main {
    public static void main(String[] args)throws IOException {
//        InputStream in = System.in;//获取键盘输入流对象
//        InputStreamReader isr=new InputStreamReader(in);//将字节流对象转换为字符流
//        BufferedReader bufr=new BufferedReader(isr);
        BufferedReader bufr=new BufferedReader(new InputStreamReader(System.in));
//        OutputStream out=System.out;
//        OutputStreamWriter osw=new OutputStreamWriter(out);
//        BufferedWriter bufw=new BufferedWriter(osw);
        BufferedWriter bufw=new BufferedWriter(new OutputStreamWriter(System.out));
        String line=null;
        while ((line=bufr.readLine())!=null)
        {
            if (line.equals("over"))
                break;
            bufw.write(line.toUpperCase());
            bufw.newLine();
            bufw.flush();
        }
    }
}
```
- 网络包log4j可以快速完成对日志的建立


- 利用IO流实现日志的打印
```java
import com.sun.xml.internal.ws.policy.privateutil.PolicyUtils;

import java.io.*;
import java.text.SimpleDateFormat;
import java.util.Date;

/*
转换流对象
 */
class Main {
    public static void main(String[] args) throws IOException {
        try {
            int arr[] = new int[2];
            System.out.println(arr[3]);
        } catch (Exception e) {
            try {
                PrintStream ps=new PrintStream("Exception.log");
                Date d=new Date();
                SimpleDateFormat sb=new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
                String time=sb.format(d);
                ps.println(time);
                System.setOut(ps);
            } catch (IOException x) {
                throw new RuntimeException("文件创建失败");
            }
            e.printStackTrace(System.out);
        }
    }
}
```
- 输出设备信息
```java
import java.io.*;
import java.util.Properties;

class Main {
    public static void main(String[] args) throws IOException{
        Properties ps = System.getProperties();
        System.setOut(new PrintStream("SystemInfo.txt"));
        ps.list(System.out);
    }
}
```
###### FIle 类
```java
import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;

/*
构造方法和常用方法
 */
/*
1:创建
    Boolean createNewFile();//指定位置创建文件，如果已经有文件则不创建返回false;
    createTempFile​(String prefix, String suffix);
    createTempFile​(String prefix, String suffix, File directory)
    mkdir();//只能创建一级目录
    mkdirs();//能创建多级目录
2:删除
    boolean delete();
    void deleteOnExit();
3:判断
    boolean canExecute();
    boolean canRead();
    boolean canWrite();
    boolean exists();
4:获取信息
    getName();
    getParent();//返回绝对路径中的父目录，如果为相对路径返回空
	getParentFile();
	getPath();
 */
class Main {
    public static void main(String[] args) throws IOException {
//        listDemo();
        listfileDemo();
    }

    public static void listfileDemo() {//listfile返回的类型是类
        //而list返回String
        File x = new File("c:\\");
        File[] files = x.listFiles();
        for (File f : files) {
            System.out.println(f.getName() + "::" + f.length());
        }
    }

    public static void func() {
        File dir = new File("F:\\javaCode\\javaLearn");
        String[] arr = dir.list(new FilenameFilter() {
            @Override
            public boolean accept(File dir, String name) {
                return name.endsWith(".txt");
            }
        });
        for (String name : arr) {
            System.out.println(name);
        }
    }

    public static void function_1() throws IOException {
        File f = new File("FIle.txt");
        f.deleteOnExit();
//        System.out.println(f.createNewFile());
        System.out.println(f.delete());
    }

    public static void function_2() {
        File f2 = new File("test.txt");
        System.out.println(f2.canExecute());
        System.out.println(f2.canWrite());
        System.out.println(f2.canRead());
    }

    public static void function_3() {
        File f = new File("File.txt");
        //都返回false，因为文件不存在，所以必须判断文件是否存在
        System.out.println(f.isDirectory());
        System.out.println(f.isFile());
    }

    public static void function_4() {
        File f1 = new File("test.txt");
        File f2 = new File("haha.java");
        System.out.println(f1.renameTo(f2));
    }

    public static void function_5() {
        File[] files = File.listRoots();
        for (File f :
                files) {
            System.out.println(f);
        }

    }

    public static void listDemo() {//列出目录下所有文件和文件夹（包含隐藏文件）
        File f = new File("C:\\");//必须封装成目录，该目录必须存在
        String[] names = f.list();
        for (String s :
                names) {
            System.out.println(s);
        }
    }

    public static void gouzaofangfa() {
        File x = new File("a.txt");//当前文件的创建
        File f = new File("F\\IOTest", "test.txt");//父与子
        File f2 = new File("F\\IOTest");
        File f4 = new File(f2, "tets2.txt");
        File f5 = new File("F" + File.separator + "IOTest" + File.separator + "testx.txt");
        System.out.println(x);
        System.out.println(f);
        System.out.println(f2);
        System.out.println(f4);
    }
}
```
- 递归显示文件夹
```java
import java.io.*;

/*
列出指定目录下的文件或文件夹，包含子目录中的内容

 */
class Demox {
    public static void main(String[] args) {
        File dir = new File("E:\\Dell");
        showDir(dir,0);
    }

    public static String getx(int lv) {
        StringBuilder sb = new StringBuilder();
        sb.append("|--");
        for (int x = 0; x < lv; x++) {
            sb.insert(0,"|  ");
        }
        return sb.toString();
    }

    public static void showDir(File dir,int x) {
        System.out.println(getx(x)+dir.getName());
        File[] files = dir.listFiles();
        x++;
        for (int i = 0; i < files.length; i++) {
            if (files[i].isDirectory()) {
                showDir(files[i],x);
            } else {
                System.out.println(getx(x)+files[i]);
            }
        }
    }
}
```
- 递归删除
```java
import java.io.*;


class Demox {
    public static void main(String[] args) {
        File f=new File("D:\\");
        del(f);
    }

    public static void del(File dir) {
        File[] files = dir.listFiles();
        for (int i = 0; i < files.length; i++) {
            if (files[i].isDirectory()) {
                del(files[i]);
            } else {
                System.out.println(files[i].toString() + "::" + files[i].delete());
            }
        }
        dir.delete();
    }
}
```
##### properties（属性）类
```java
import java.io.*;
import java.util.Properties;
import java.util.Set;
/*
properties 类(属性)
 */

class Demox {
    public static void main(String[] args) throws IOException {
//        setAndGet();
        load_data_2();
    }

    public static void setAndGet() {
        Properties prop = new Properties();
        prop.setProperty("张三", "100");
        prop.setProperty("李四", "101");
//        System.out.println(prop);
        prop.setProperty("王五", "1000");
        System.out.println(prop.getProperty("李四"));
        Set<String> names = prop.stringPropertyNames();
        for (String s : names) {
            System.out.println(s + "::" + prop.getProperty(s));
        }
    }

    public static void load_data_2() throws IOException {
        Properties pro = new Properties();
        FileInputStream fis = new FileInputStream("info.txt");
        InputStreamReader ss = new InputStreamReader(fis);
        pro.load(ss);
        pro.setProperty("王五", "20");
        FileOutputStream fos = new FileOutputStream("info.txt");
        OutputStreamWriter ss2=new OutputStreamWriter(fos);
        pro.store(ss2, "haha");//store方法将更改写到文件中去
        System.out.println(pro);
        fos.close();
        fis.close();
    }

    public static void load_data() throws IOException {
        BufferedReader bufr = new BufferedReader(new FileReader("info.txt"));
        String line = null;
        Properties ps = new Properties();
        while ((line = bufr.readLine()) != null) {
            String[] arr = line.split("=");
            System.out.println(arr[0] + "::" + arr[1]);
            ps.setProperty(arr[0], arr[1]);
        }
        bufr.close();
        System.out.println(ps);
    }
}
```

- printStream
```java

import java.io.*;
/*
打印流：
字符打印流：
printWrite
构造函数可以接受的类型：
1：file对象
2：字符串路径
3：字节输出流OutputStream
字节打印流：
printStream
构造函数可以接受的类型：
1：file对象
2：字符串路径
3：字节输出流OutputStream
4：字符输出流Writer
 */
class demox {
    public static void main(String[] args)throws IOException {
        BufferedReader bufr=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pr=new PrintWriter(System.out,true);
        String line=null;
        while ((line=bufr.readLine())!=null)
        {
            if("over".equals(line))
                break;
            pr.println(line.toUpperCase());
//            pr.flush();//如果为构造函数中的自动刷新为true可以不刷新
        }
        pr.close();
        bufr.close();
    }
}
```
- 合并流
```java
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.SequenceInputStream;
import java.util.Enumeration;
import java.util.Vector;
/*
合并流，将多个流合并成一个流
 */
class SequenceDemo {
    public static void main(String[] args) throws IOException {
        Vector<FileInputStream> v=new Vector<>();
        v.add(new FileInputStream("haha.java"));
        v.add(new FileInputStream("info.txt"));
        Enumeration<FileInputStream> en=v.elements();
        SequenceInputStream sis = new SequenceInputStream(en);
        FileOutputStream fos=new FileOutputStream("4.txt");
        byte[]buff=new byte[1024];
        int len=0;
        while ((len=sis.read(buff))!=-1)
        {
            fos.write(buff,0,len);

        }
        fos.close();
        sis.close();
    }

}
```
- 文件的合并
```java

import java.util.*;
import java.io.*;

/*
切割流
以及合并流
 */
class splitFile {
    public static void main(String[] args) throws IOException {
//        split();
        hebing();
    }

    public static void hebing() throws IOException {
        ArrayList<FileInputStream> a = new ArrayList<FileInputStream>();
        for (int i = 1; i <= 10; i++) {
            a.add(new FileInputStream("F:\\javaCode\\javaLearn\\splitFiles\\" + i + ".part"));
        }
        Iterator it = a.iterator();
        final Enumeration<FileInputStream> em = new Enumeration<FileInputStream>() {
            @Override
            public boolean hasMoreElements() {
                return it.hasNext();
            }

            @Override
            public FileInputStream nextElement() {
                return (FileInputStream) it.next();
            }
        };
        SequenceInputStream seq = new SequenceInputStream(em);
        FileOutputStream fos = new FileOutputStream("F:\\javaCode\\javaLearn\\splitFiles\\test2.mp3");
        int len = 0;
        byte[] buf = new byte[1024 * 1024];
        while ((len = seq.read(buf)) != -1) {
            fos.write(buf, 0, len);

        }
        fos.close();
        seq.close();
    }

    public static void split() throws IOException {
        FileInputStream fis = new FileInputStream("F:\\javaCode\\javaLearn\\test.mp3");
        FileOutputStream fos = null;
        byte[] buf = new byte[1024 * 1024];
        int len = 0;
        int count = 1;
        while ((len = fis.read(buf)) != -1) {
            fos = new FileOutputStream("F:\\javaCode\\javaLearn\\splitFiles\\" + count++ + ".part");
            fos.write(buf, 0, len);
            fos.close();
        }
        fis.close();
    }
}
```
- ObjectInputStream和ObjectOutputStream
```java
import java.io.*;

class ObjectInputDemo {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        writeObj();
//        load();
    }

    public static void writeObj() throws IOException {
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("obj.txt"));
        Person p = new Person("张三", 2);
        oos.writeObject(p);
        oos.close();
    }

    public static void load() throws IOException, ClassNotFoundException {
        ObjectInputStream in = new ObjectInputStream(new FileInputStream("obj.txt"));
        Person p = (Person) in.readObject();
        System.out.println(p.age);
        in.close();

    }
}

class Person implements Serializable {//必须实现序列化接口
    //静态无法被序列化

    private String name;
    transient int age; //部分成员不想被序列化的话可以加transient

    Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}
```
- 管道流
```java
import java.io.IOException;
import java.io.PipedInputStream;
import java.io.PipedOutputStream;

/*
管道输入流和管道输出流：

 */
class Demox {
    public static void main(String[] args) throws IOException {
        PipedOutputStream out = new PipedOutputStream();
        PipedInputStream in = new PipedInputStream();
        in.connect(out);
        Read r = new Read(in);
        Write w = new Write(out);
        new Thread(r).start();
        new Thread(w).start();

    }
}

class Read implements Runnable {
    private PipedInputStream in;

    Read(PipedInputStream in) {
        this.in = in;
    }

    public void run() {
        try {
            byte[] buf = new byte[1024];
            System.out.println("读取前准备");
            int len = in.read(buf);
            String s = new String(buf, 0, len);
            System.out.println(s);
            in.close();
        } catch (IOException e) {
            throw new RuntimeException("管道读取失败");
        }
    }
}

class Write implements Runnable {
    private PipedOutputStream out;

    Write(PipedOutputStream out) {
        this.out = out;
    }

    @Override
    public void run() {
        try {
            System.out.println("正在写，等待六秒");
            Thread.sleep(6000);
            out.write("管道".getBytes());
            out.close();
        } catch (Exception e) {
            throw new RuntimeException("管道写入失败");
        }
    }
}
```
- RandomAccessFile（随机访问流）
```java

/*
RandomAccessFile类:
直接继承自Object类，具备读写功能，内部封装数组
通过getFilePointer获取指针位置
seek改变指针位置
只能操作文件
可以实现多线程的下载

 */

import java.io.IOException;
import java.io.RandomAccessFile;

class Demox {
    public static void main(String[] args) throws IOException {
//        writeFile();
//        read();
//        randomWrite();
    }

    public static void writeFile() throws IOException {
        RandomAccessFile raf = new RandomAccessFile("a.txt", "rw");
        raf.write("李四".getBytes());
        raf.writeInt(97);
        raf.write("李二".getBytes());
        raf.writeInt(55);
        raf.close();
    }

    public static void read() throws IOException {
        RandomAccessFile raf = new RandomAccessFile("a.txt", "rw");
        raf.seek(6);//调整指针位置
        raf.skipBytes(12);//跳过的字节数
        byte[] buf = new byte[6];
        raf.read(buf);
        int age = raf.readInt();
        String s = new String(buf);
        System.out.println(s);
        System.out.println(age);
        raf.close();
    }

    public static void randomWrite() throws IOException {
        RandomAccessFile raf = new RandomAccessFile("a.txt", "rw");
        raf.seek(8*3);
        raf.write("周期".getBytes());
        raf.writeInt(103);
        raf.close();
    }
}
```
- DataInputStream和DataOutputStream
```java
import java.io.*;

/*
可以用于操作基本数据类型的流对象。

 */
class DataStreamDemo {
    public static void main(String[] args) throws IOException {
//        write();
//        read();
//        write_utf();
        read_utf();
    }
    public static void read() throws IOException
    {
        DataInputStream fis=new DataInputStream(new FileInputStream("data.txt"));
        int num=fis.readInt();
        boolean n=fis.readBoolean();
        double x=fis.readDouble();
        System.out.println(num);
        System.out.println(n);
        System.out.println(x);
        fis.close();
    }
    public static void write_utf() throws IOException {
        DataOutputStream out=new DataOutputStream(new FileOutputStream("UTF.txt"));
        out.writeUTF("我打算记得那时看见你");
        out.close();
    }
    public static void read_utf() throws IOException {
        DataInputStream in=new DataInputStream(new FileInputStream("UTF.txt"));
        String xx=in.readUTF();
        System.out.println(xx);

    }
        public static void write() throws IOException{
        DataOutputStream out=new DataOutputStream(new FileOutputStream("data.txt"));
        out.writeInt(123);
        out.writeBoolean(true);
        out.writeDouble(123.43);
        out.close();
    }
}
```
![流体系](..\Java\TIM截图20190620201411.jpg)
- 操作字节数组的流（byteArrayInputStream和ByteArrayOutputStream）
```java
import java.io.*;

/*
ByteArrayInputStream:在构造的时候。需要接受数据源，而且数据源是一个字节数组
ByteArrayOutputStream:在构造的时候不用定于数据目的，因为该对象中已经封装了一个可变长度的数组，即为数据目的地
所以不需要关闭。
 */
class Demoxx {
    public static void main(String[] args) {
        //数据源
        ByteArrayInputStream bis = new ByteArrayInputStream("ABHJASBDJAS".getBytes());
        //数据目的
        ByteArrayOutputStream bos = new ByteArrayOutputStream();
        int by = 0;
        while ((by = bis.read()) != -1) {
            bos.write(by);
        }
        bos.writeTo(new FileOutputStream("x.txt"));
        System.out.println(bos.size());//大小
        System.out.println(bos.toString());
    }
}
```
- 编码问题

```java
import java.io.*;

class Demoxx {
    public static void main(String[] args) throws IOException{
//        write();
        read();
    }

    public static void read() throws IOException {
        InputStreamReader isr=new InputStreamReader(new FileInputStream("gbk.txt"),"utf-8");
        char buf[] =new char[10];
        int len=isr.read(buf);
        String str=new String(buf,0,len);
        System.out.println(str);
        isr.close();
    }

    public static void write() throws IOException {
        OutputStreamWriter osw=new OutputStreamWriter(new FileOutputStream("gbk.txt"),"gbk");
        osw.write("你好");
        osw.close();
    }
}
```