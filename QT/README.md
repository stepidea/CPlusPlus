# Qt视频： https://www.bilibili.com/video/BV1g4411H78N?p=1

* Qt 简介
    + 跨平台图形界面引擎
    + 优点
        - 跨平台
        - 接口简单，容易上手
        - 一定程度简化了内存回收
    + 版本
        - 商业版
        - 开源版
    + 成功案例
        - Linux 桌面环境 KDE
        - 谷歌地图
        - VLC 多媒体播放器

* 创建第一个 Qt 程序
    + 点击创建项目后，选择项目路径（不能有中文）以及给项目起名称（名称不能有中文、空格）
    + 默认创建有窗口类，myWidget，基类有三种选择：QWidget、QMainWindow、QDialog
    + main 函数
        - 
        - QApplication 应用程序对象，有且只有一个
        - myWidget w 实例化窗口对象
        - w.show() 调用show函数，显示窗口
        - return a.exec() 让应用程序对象进入到消息循环机制中，代码阻塞到当前行

* 按钮控件常用API
    + 创建 QPushButton *btn = new QPushButton
    + 设置父亲 setParent(this) [令按钮能够存放在当前窗口中]
    + 设置文本 setText("文字")
    + 设置位置 move(宽，高)
    + 重新指定窗口大小 resize()
    + 设置窗口标题 setWindowTitle
    + 设置窗口固定大小 setFixedSize

* 对象树 QObject
    + 当创建的对象在堆区时，如果指定的父亲是QObject派生下来的类或者是QObject子类派生下来的类，可以不用管理释放的操作，该对象会放入到对象树
    + 一定程度简化了内存回收机制

* Qt 中的坐标系
    + 左上角为原点（0，0）
    + x 以右边为正方向， y以下为正方向

* 信号和槽
    + 链接函数 connect
    + 参数 （信号发送者，发送的信号（函数地址），信号的接收者，处理的槽函数（函数地址））
    + 松散耦合
    + 实现 点击按钮 关闭窗口的案例[connect(btn, &QPushButton::click, this, &QWidget::close)]

* 自定义信号和槽
    + 自定义信号
        - 写到 signals 下
        - 返回 void 
        - 需要声明，不需要实现
        - 可以有参数，可以重载
    + 自定义槽
        - 返回 void
        - 需要声明和实现
        - 可以有参数，可以重载
        - 写到 public slot 下或者 public 或者 全局函数
    + 触发自定义的信号
        - emit 自定义信号
    + 案例-下课后，老师触发饿了信号，学生响应信号，请客吃饭

* 当自定义信号和槽出现重载
    + 需要利用函数指针 明确指向函数的地址
    + void(Techer::* tSignal)(QString) = &Teacher::hungry;
    + QString 转成 char *
        - ToUtf8() 转为 QByteArray
        - .Data() 转为 char *
    + 信号可以连接信号
    + 断开信号 disconnect

* 拓展
    + 一个信号可以连接多个槽函数
    + 多个信号可以连接同一个槽函数
    + 信号和槽函数的参数 必须类型一一对应
    + 信号的参数可以多于槽函数的个数
    + 信号槽可以断开连接 disconnect

* Qt4版本写法
    + connect(信号发送者，发送的信号 SIGNAL（信号），信号接收者，槽函数 SLOT（槽函数）)
    + 优点 参数直观
    + 缺点 编译器不会检测参数类型

* Lambda 表达式
    + []标识符 匿名函数
        - 值传递
        - 引用传递
    + () 参数
    + {} 实现体
    + mutable 修饰 值传递变量，可以修改拷贝出的数据，改变不了本体
    + 返回值 []()->int {}

* QMainWindow
    + 菜单栏最多只有一个
        - QMenuBar *bar = MenuBar();
        - setMenunBar(bar)
        - QMenu *fileMenu = bar->addMenu("file") 创建菜单
        - QAction *newAction = fileMenu->addAction("create") 创建菜单项
        - 添加分割线 fileMenu->addSeparator();
    + 工具栏可以有多个
        - QToolBar *toolBar = new QToolBar(this);
        - addToolBar(默认停靠区域，toolBar); Qt::LeftToolBarArea
        - 设置后期停靠区域，设置浮动，设置移动
        - 添加菜单项 或者添加 小控件
    + 状态栏最多只有一个
        - QStatusBar *stBar = statusBar();
        - 设置到窗口中 setStatusBar(stBar);
        - stBar->addWidget(label); 放左侧信息
        - stBar->addPermanentWidget(label2); 放右侧信息
    + 铆接部件 浮动窗口可以多个
        - QDockWidget
        - addDockWidget(默认停靠区域, 浮动窗口指针)
        - 设置后期停靠区域
    + 设置核心部件 只能一个
        - setCentralWidget(edit);

* 资源文件
    + 将图片文件拷贝到项目位置下
    + 右键项目、添加新文件、Qt recourse file、给资源文件取名
    + res 生成 res.qrc
    + open in editor 编辑资源
    + 添加前缀 添加文件
    + 使用 “： + 前缀名 + 文件名” 

* 对话框
    + 模态对话框 不可以对其他窗口进行操作 阻塞
        - QDialog dlg(this)
        - dlg.exec()
    + 非模态对话框 可以对其他窗口进行操作
        - 防止一闪而过 创建到堆区
        - QDialog *dlg = new QDialog(this)
        - dlg->show();
        - dlg->setAttribute(Qt::WA_DeleteOnClose); 55号属性
    + 标准对话框 - 消息对话框
        - QMessageBox 静态成员函数 创建对话框
        - 错误、信息、 提问、警告
        - 参数（父亲， 标题， 显示内容， 按键类型， 默认关联回车按键）
        - 返回值也是 StandardButton 类型，利用返回值判断用户的输入
    + 其他标准对话框
        - 颜色对话框 QColorDialog::getClor
        - 文件对话框 QFileDialog::getOpenFileName(父亲，标题，默认路径，过滤文件)
        - 字体对话框 QFontDialog::getFont

* 界面布局
    + 实现登陆窗口
    + 利用布局方式 给窗口进行美化
    + 选取 widget 进行布局，水平布局，垂直布局，栅格布局
    + 给用户名、密码、登陆、退出进行布局
    + 默认窗口和控件之间有9间隙，可以调整 layoutLeftMargin
    + 利用弹簧进行布局

* 控件
    + 按钮组
        - QPushButton 常用按钮
        - QToolButton 工具按钮，用于显示图片，若图想显示文字，需要修改风格 toolButtonStyle 凸起风格 autoRaise
        - radioButton 单选按钮，设置默认 ui->BtnMan->setChecked(true)
        - checkbox 多选按钮，监听状态，2 选中，1 半选，0 未选中
    + QListWidget 列表容器
        - QListWidgetItem *item 一行内容
        - ui->listWidget->addItem(item)
        - 设置居中方式 item->setTextAlignment(Qt::AlignHCenter)
        - 可以利用 addItems 一次性添加整个诗内容
    + QTreeWidget 树控件
        - 设置头 ui->treeWidget->setHeaderLabels(QStringList()<<"first"<<"second");
        - 创建根节点 QTreeWidgetItem *item = new QTreeWidgetItem(QStringList()<<"first");
        - 添加根节点到树控件上 ui->treeWidget->addTopLevelItem(item);
        - 添加子节点 item->addChild(child);
    + TableWidget 表格控件
        - 设置列数 ui->tableWidget->setColumnCount(2)
        - 设置水平表头 ui->tableWidget->setHorizontalHeaderLabels()<<<<"first"<<"second";
        - 设置行数 ui->tableWidget->setRowCount(2)
        - 设置正文 ui->tableWidget->setItem(0,0,new QTableWidgetItem(""))