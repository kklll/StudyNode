# <center>Android Node</center>


#### Intent
* startActivity(Intent)/startActivityForResult(Intent)：来启动一个Activity
* 显式Intent：通过组件名指定启动的目标组件,比如startActivity(new Intent(A.this,B.class)); 每次启动的组件只有一个
* 隐式Intent:不指定组件名,而指定Intent的Action,Data,或Category,当我们启动组件时, 会去匹配AndroidManifest.xml相关组件的Intent-filter,逐一匹配出满足属性的组件,当不止一个满足时, 会弹出一个让我们选择启动哪个的对话框

* Intent参数问题: .class是获得这个类，类型是Class，this是这个类的实例，类型是这个类
只有Class.this和.class是同类型