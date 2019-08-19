#### GUI编程
[TOC]
###### 窗口事件
```java

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

class Demos {
    private Frame f;
    private Button butt;
    Demos()
    {
        init();
    }
    public void init()
    {
        f=new Frame();
        f.setBounds(200,300,500,400);//设置窗体
        f.setLayout(new FlowLayout());
        butt=new Button("my button");//设置按钮
        f.add(butt);
        myEvent();//加载窗体事件
        f.setVisible(true);
    }
    private void myEvent()
    {
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        butt.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("退出，按钮");
                System.exit(0);
            }
        });
    }
    public static void main(String[] args) {
        new Demos();
    }
}
```
###### 鼠标事件
```java

import java.awt.*;
import java.awt.event.*;

class Demos {
    private Frame f;
    private Button butt;
    Demos()
    {
        init();
    }
    public void init()
    {
        f=new Frame();
        f.setBounds(200,300,500,400);//设置窗体
        f.setLayout(new FlowLayout());
        butt=new Button("my button");//设置按钮
        f.add(butt);
        myEvent();//加载窗体事件
        f.setVisible(true);
    }
    private void myEvent()
    {
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        butt.addMouseListener(new MouseAdapter() {
            private int i=0;
            public void mouseClicked(MouseEvent e) {
                if (e.getClickCount()==2)
                    System.out.println("双击事件");
            }
        });
        butt.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("action");
            }
        });
        butt.addMouseListener(new MouseAdapter() {
            private int count=1;
            @Override
            public void mouseEntered(MouseEvent e) {
                System.out.println("鼠标进入"+count++);
            }
        });
    }
    public static void main(String[] args) {
        new Demos();
    }
}
```

###### 键盘事件

```java
import java.awt.*;
import java.awt.event.*;

class Demos {
    private Frame f;
    private Button butt;
    private TextField ts;

    Demos() {
        init();
    }

    public void init() {
        f = new Frame();
        f.setBounds(200, 300, 500, 400);//设置窗体
        f.setLayout(new FlowLayout());
        butt = new Button("my button");//设置按钮
        ts=new TextField(20);
        f.add(ts);
        f.add(butt);
        myEvent();//加载窗体事件
        f.setVisible(true);
    }

    private void myEvent() {
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        butt.addMouseListener(new MouseAdapter() {
            private int i = 0;
            public void mouseClicked(MouseEvent e) {
                if (e.getClickCount() == 2)
                    System.out.println("双击事件");
            }
        });
        ts.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (!(e.getKeyCode()>=KeyEvent.VK_0&&e.getKeyCode()<=KeyEvent.VK_9)) {
                    System.out.println("Wrong input");
                    e.consume();
                }
                else
                    System.out.println(e.getKeyChar()+"..."+e.getKeyCode());
            }
        });
        butt.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ESCAPE)
                    System.exit(0);
                if (e.isControlDown() && e.getKeyCode() == KeyEvent.VK_ENTER)
                    System.out.println("同时被按下");
                System.out.println(KeyEvent.getKeyText(e.getKeyCode()) + "...." + e.getKeyCode());
            }
        });
//        butt.addActionListener(new ActionListener() {
//            @Override
//            public void actionPerformed(ActionEvent e) {
//                System.out.println("action");
//            }
//        });
//        butt.addMouseListener(new MouseAdapter() {
//            private int count = 1;
//
//            @Override
//            public void mouseEntered(MouseEvent e) {
//                System.out.println("鼠标进入" + count++);
//            }
//        });
    }

    public static void main(String[] args) {
        new Demos();
    }
}
```
- 实现输入文件目录后直接输出文件夹中的文件名（GUI）
```java

import java.awt.*;
import java.awt.event.*;
import java.io.File;

class MyWindows extends Frame {
    private Frame f;
    private TextField tf;
    private Button but;
    private TextArea ta;
    private Dialog dialog;
    private Label lable;
    private Button okbu;

    MyWindows() {
        init();
    }

    public void init() {
        f = new Frame("my windows");
        f.setBounds(300, 100, 500, 700);
        f.setLayout(new FlowLayout());
        tf = new TextField(60);
        but = new Button("go to");
        ta = new TextArea(30, 60);
        lable = new Label();
        okbu = new Button("ok");
        dialog = new Dialog(f, "Error", true);
        dialog.setBounds(300, 100, 200, 300);
        dialog.setLayout(new FlowLayout());
        f.add(tf);
        f.add(but);
        f.add(ta);
        dialog.add(lable);
        dialog.add(okbu);
        f.setVisible(true);
        myEvent();
    }

    private void myEvent() {
        dialog.addWindowFocusListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                dialog.setVisible(false);
            }
        });
        okbu.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                dialog.setVisible(false);
            }
        });
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        tf.addKeyListener(new KeyAdapter() {
            @Override
            public void keyPressed(KeyEvent e) {
                if (e.getKeyCode() == KeyEvent.VK_ENTER) {
                    function();
                }
            }
        });
        but.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                function();
            }
        });
    }

    private void function() {
        String dir = tf.getText();
        System.out.println(dir);
        File file = new File(dir);
        if (file.exists() && file.isDirectory()) {
            ta.setText("");
            String[] names = file.list();
            for (String name : names) {
                ta.append(name + "\r\n");
            }
        } else {
            String info = "宁输入的路径:" + file.getName() + "请重新输入";
            lable.setText(info);
            dialog.setVisible(true);
        }
        tf.setText("");
    }

    public static void main(String[] args) {
        new MyWindows();
    }
}
```
- 菜单


```java


import java.awt.*;
import java.awt.event.*;


class myMenu {
    private Frame f;
    private MenuBar mb;
    private Menu m, subm;
    private MenuItem closeItem, subItem;

    myMenu() {
        init();
    }

    public void init() {
        f = new Frame("my");
        f.setBounds(300, 100, 500, 600);
        f.setLayout(new FlowLayout());
        mb = new MenuBar();
        m = new Menu("file");
        subm = new Menu("sub menu");
        closeItem = new MenuItem("exit");
        subItem = new MenuItem("sub");
        m.add(subm);
        subm.add(subItem);
        m.add(closeItem);
        mb.add(m);
        f.setMenuBar(mb);
        myEvent();
        f.setVisible(true);
    }

    public void myEvent() {
        closeItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public static void main(String[] args) {
        new myMenu();
    }
}
```

- 打开读取文件

```java
import java.awt.*;
import java.awt.event.*;
import java.io.*;


class myMenu {
    private Frame f;
    private MenuBar mb;
    private Menu m, subm;
    private MenuItem closeItem, openItem, saveItem;
    private FileDialog open, save;
    private TextArea ta;
    private File file;

    myMenu() {
        init();
    }

    public void init() {
        f = new Frame("my");
        f.setBounds(300, 100, 650, 600);
//        f.setLayout(new FlowLayout());
        mb = new MenuBar();
        m = new Menu("file");
        subm = new Menu("sub menu");
        closeItem = new MenuItem("exit");
        openItem = new MenuItem("open");
        saveItem = new MenuItem("save");
        open = new FileDialog(f, "open", FileDialog.LOAD);
        save = new FileDialog(f, "save", FileDialog.SAVE);
        ta = new TextArea();
        m.add(openItem);
        m.add(saveItem);
        m.add(closeItem);
        mb.add(m);
        f.setMenuBar(mb);
        f.add(ta);
        myEvent();
        f.setVisible(true);
    }

    public void myEvent() {
        openItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                open.setVisible(true);
                String file1 = open.getFile();
                String dir = open.getDirectory();
                if (dir == null || file1 == null)
                    return;
                ta.setText("");
                file = new File(dir, file1);
                try {
                    BufferedReader bufr = new BufferedReader(new FileReader(file));
                    String line = null;
                    while ((line = bufr.readLine()) != null) {
                        ta.append(line + "\r\n");
                    }
                } catch (IOException er) {
                    er.printStackTrace();
                }
            }
        });

        saveItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (file == null) {
                    save.setVisible(true);
                    String file1 = save.getFile();
                    String dir = save.getDirectory();
                    if (dir == null || file1 == null)
                        return;
                    file = new File(dir, file1);
                }
                try {
                    BufferedWriter bfw = new BufferedWriter(new FileWriter(file));
                    String text = ta.getText();
                    bfw.write(text);
                    bfw.close();
                } catch (IOException ex) {
                    ex.printStackTrace();
                }

            }
        });
        closeItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });
        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public static void main(String[] args) {
        new myMenu();
    }
}
```