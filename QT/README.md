# Qt��Ƶ�� https://www.bilibili.com/video/BV1g4411H78N?p=1

* Qt ���
    + ��ƽ̨ͼ�ν�������
    + �ŵ�
        - ��ƽ̨
        - �ӿڼ򵥣���������
        - һ���̶ȼ����ڴ����
    + �汾
        - ��ҵ��
        - ��Դ��
    + �ɹ�����
        - Linux ���滷�� KDE
        - �ȸ��ͼ
        - VLC ��ý�岥����

* ������һ�� Qt ����
    + ���������Ŀ��ѡ����Ŀ·�������������ģ��Լ�����Ŀ�����ƣ����Ʋ��������ġ��ո�
    + Ĭ�ϴ����д����࣬myWidget������������ѡ��QWidget��QMainWindow��QDialog
    + main ����
        - 
        - QApplication Ӧ�ó����������ֻ��һ��
        - myWidget w ʵ�������ڶ���
        - w.show() ����show��������ʾ����
        - return a.exec() ��Ӧ�ó��������뵽��Ϣѭ�������У�������������ǰ��

* ��ť�ؼ�����API
    + ���� QPushButton *btn = new QPushButton
    + ���ø��� setParent(this) [�ť�ܹ�����ڵ�ǰ������]
    + �����ı� setText("����")
    + ����λ�� move(����)
    + ����ָ�����ڴ�С resize()
    + ���ô��ڱ��� setWindowTitle
    + ���ô��ڹ̶���С setFixedSize

* ������ QObject
    + �������Ķ����ڶ���ʱ�����ָ���ĸ�����QObject�����������������QObject���������������࣬���Բ��ù����ͷŵĲ������ö������뵽������
    + һ���̶ȼ����ڴ���ջ���

* Qt �е�����ϵ
    + ���Ͻ�Ϊԭ�㣨0��0��
    + x ���ұ�Ϊ������ y����Ϊ������

* �źźͲ�
    + ���Ӻ��� connect
    + ���� ���źŷ����ߣ����͵��źţ�������ַ�����źŵĽ����ߣ�����Ĳۺ�����������ַ����
    + ��ɢ���
    + ʵ�� �����ť �رմ��ڵİ���[connect(btn, &QPushButton::click, this, &QWidget::close)]

* �Զ����źźͲ�
    + �Զ����ź�
        - д�� signals ��
        - ���� void 
        - ��Ҫ����������Ҫʵ��
        - �����в�������������
    + �Զ����
        - ���� void
        - ��Ҫ������ʵ��
        - �����в�������������
        - д�� public slot �»��� public ���� ȫ�ֺ���
    + �����Զ�����ź�
        - emit �Զ����ź�
    + ����-�¿κ���ʦ���������źţ�ѧ����Ӧ�źţ���ͳԷ�

* ���Զ����źźͲ۳�������
    + ��Ҫ���ú���ָ�� ��ȷָ�����ĵ�ַ
    + void(Techer::* tSignal)(QString) = &Teacher::hungry;
    + QString ת�� char *
        - ToUtf8() תΪ QByteArray
        - .Data() תΪ char *
    + �źſ��������ź�
    + �Ͽ��ź� disconnect

* ��չ
    + һ���źſ������Ӷ���ۺ���
    + ����źſ�������ͬһ���ۺ���
    + �źźͲۺ����Ĳ��� ��������һһ��Ӧ
    + �źŵĲ������Զ��ڲۺ����ĸ���
    + �źŲۿ��ԶϿ����� disconnect

* Qt4�汾д��
    + connect(�źŷ����ߣ����͵��ź� SIGNAL���źţ����źŽ����ߣ��ۺ��� SLOT���ۺ�����)
    + �ŵ� ����ֱ��
    + ȱ�� �������������������

* Lambda ���ʽ
    + []��ʶ�� ��������
        - ֵ����
        - ���ô���
    + () ����
    + {} ʵ����
    + mutable ���� ֵ���ݱ����������޸Ŀ����������ݣ��ı䲻�˱���
    + ����ֵ []()->int {}

* QMainWindow
    + �˵������ֻ��һ��
        - QMenuBar *bar = MenuBar();
        - setMenunBar(bar)
        - QMenu *fileMenu = bar->addMenu("file") �����˵�
        - QAction *newAction = fileMenu->addAction("create") �����˵���
        - ��ӷָ��� fileMenu->addSeparator();
    + �����������ж��
        - QToolBar *toolBar = new QToolBar(this);
        - addToolBar(Ĭ��ͣ������toolBar); Qt::LeftToolBarArea
        - ���ú���ͣ���������ø����������ƶ�
        - ��Ӳ˵��� ������� С�ؼ�
    + ״̬�����ֻ��һ��
        - QStatusBar *stBar = statusBar();
        - ���õ������� setStatusBar(stBar);
        - stBar->addWidget(label); �������Ϣ
        - stBar->addPermanentWidget(label2); ���Ҳ���Ϣ
    + í�Ӳ��� �������ڿ��Զ��
        - QDockWidget
        - addDockWidget(Ĭ��ͣ������, ��������ָ��)
        - ���ú���ͣ������
    + ���ú��Ĳ��� ֻ��һ��
        - setCentralWidget(edit);

* ��Դ�ļ�
    + ��ͼƬ�ļ���������Ŀλ����
    + �Ҽ���Ŀ��������ļ���Qt recourse file������Դ�ļ�ȡ��
    + res ���� res.qrc
    + open in editor �༭��Դ
    + ���ǰ׺ ����ļ�
    + ʹ�� ���� + ǰ׺�� + �ļ����� 

* �Ի���
    + ģ̬�Ի��� �����Զ��������ڽ��в��� ����
        - QDialog dlg(this)
        - dlg.exec()
    + ��ģ̬�Ի��� ���Զ��������ڽ��в���
        - ��ֹһ������ ����������
        - QDialog *dlg = new QDialog(this)
        - dlg->show();
        - dlg->setAttribute(Qt::WA_DeleteOnClose); 55������
    + ��׼�Ի��� - ��Ϣ�Ի���
        - QMessageBox ��̬��Ա���� �����Ի���
        - ������Ϣ�� ���ʡ�����
        - ���������ף� ���⣬ ��ʾ���ݣ� �������ͣ� Ĭ�Ϲ����س�������
        - ����ֵҲ�� StandardButton ���ͣ����÷���ֵ�ж��û�������
    + ������׼�Ի���
        - ��ɫ�Ի��� QColorDialog::getClor
        - �ļ��Ի��� QFileDialog::getOpenFileName(���ף����⣬Ĭ��·���������ļ�)
        - ����Ի��� QFontDialog::getFont

* ���沼��
    + ʵ�ֵ�½����
    + ���ò��ַ�ʽ �����ڽ�������
    + ѡȡ widget ���в��֣�ˮƽ���֣���ֱ���֣�դ�񲼾�
    + ���û��������롢��½���˳����в���
    + Ĭ�ϴ��ںͿؼ�֮����9��϶�����Ե��� layoutLeftMargin
    + ���õ��ɽ��в���

* �ؼ�
    + ��ť��
        - QPushButton ���ð�ť
        - QToolButton ���߰�ť��������ʾͼƬ����ͼ����ʾ���֣���Ҫ�޸ķ�� toolButtonStyle ͹���� autoRaise
        - radioButton ��ѡ��ť������Ĭ�� ui->BtnMan->setChecked(true)
        - checkbox ��ѡ��ť������״̬��2 ѡ�У�1 ��ѡ��0 δѡ��
    + QListWidget �б�����
        - QListWidgetItem *item һ������
        - ui->listWidget->addItem(item)
        - ���þ��з�ʽ item->setTextAlignment(Qt::AlignHCenter)
        - �������� addItems һ�����������ʫ����
    + QTreeWidget ���ؼ�
        - ����ͷ ui->treeWidget->setHeaderLabels(QStringList()<<"first"<<"second");
        - �������ڵ� QTreeWidgetItem *item = new QTreeWidgetItem(QStringList()<<"first");
        - ��Ӹ��ڵ㵽���ؼ��� ui->treeWidget->addTopLevelItem(item);
        - ����ӽڵ� item->addChild(child);
    + TableWidget ���ؼ�
        - �������� ui->tableWidget->setColumnCount(2)
        - ����ˮƽ��ͷ ui->tableWidget->setHorizontalHeaderLabels()<<<<"first"<<"second";
        - �������� ui->tableWidget->setRowCount(2)
        - �������� ui->tableWidget->setItem(0,0,new QTableWidgetItem(""))