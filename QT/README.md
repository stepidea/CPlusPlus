# Qt 简要概括

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
        - Q
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
