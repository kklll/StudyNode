# <center>Android Node</center>

# 项目
- [酷欧天气](https://github.com/kklll/CoolWeather)
### Intent
* startActivity(Intent)/startActivityForResult(Intent)：来启动一个Activity
* 显式Intent：通过组件名指定启动的目标组件,比如startActivity(new Intent(A.this,B.class)); 每次启动的组件只有一个
* 隐式Intent:不指定组件名,而指定Intent的Action,Data,或Category,当我们启动组件时, 会去匹配AndroidManifest.xml相关组件的Intent-filter,逐一匹配出满足属性的组件,当不止一个满足时, 会弹出一个让我们选择启动哪个的对话框

* Intent参数问题: .class是获得这个类，类型是Class，this是这个类的实例，类型是这个类
只有Class.this和.class是同类型

### 常用控件
* AlertDialog  

![实例](http://www.runoob.com/wp-content/uploads/2015/09/79141888.jpg)
```java
package com.myapplication;

import android.content.DialogInterface;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private EditText editText;
    private ImageView imageView;
    private ProgressBar progressBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button_1 = findViewById(R.id.button_1);
        imageView = findViewById(R.id.pic);
        editText = findViewById(R.id.edit);
        progressBar = findViewById(R.id.bar);
        button_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                switch (v.getId()) {
                    case R.id.button_1:
                        AlertDialog.Builder dialog;
                        dialog = new AlertDialog.Builder(MainActivity.this);
                        dialog.setTitle("这是一个提醒");
                        dialog.setMessage("你要删除么？");
                        dialog.setCancelable(false);
                        dialog.setPositiveButton("ok", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                Toast.makeText(MainActivity.this,"you click ok",Toast.LENGTH_SHORT).show();

                            }
                        });
                        dialog.setNegativeButton("cancle", new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                Toast.makeText(MainActivity.this,"you click Cancle",Toast.LENGTH_SHORT).show();
                            }
                        });
                        dialog.show();
                        break;
                    default:
                        break;
                }

            }
        });
    }
}
```
* ProgressDialog
``` java
package com.myapplication;

import android.app.ProgressDialog;
import android.content.DialogInterface;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ProgressBar;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    private EditText editText;
    private ImageView imageView;
    private ProgressBar progressBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button button_1 = findViewById(R.id.button_1);
        imageView = findViewById(R.id.pic);
        editText = findViewById(R.id.edit);
        progressBar = findViewById(R.id.bar);
        button_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                switch (v.getId()) {
                    case R.id.button_1:
                        ProgressDialog progressDialog=new ProgressDialog(MainActivity.this);
                        progressDialog.setTitle("this is a progressdialog");
                        progressDialog.setMessage("Loading...");
                        progressDialog.setCancelable(true);;
                        progressDialog.show();
                        break;
                    default:
                        break;
                }

            }
        });
    }
}

```

### RelativeLayout（相对布局）
