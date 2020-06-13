#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <qmath.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(800,600);
    this->setFixedSize(800,600);
    this->setWindowTitle("房贷计算器");

    //贷款类别
    ui->comboBox->addItem("商业贷款");
    ui->comboBox->addItem("公积金贷款");
    ui->comboBox->addItem("组合贷款");
    //计算方式
    ui->comboBox_2->addItem("1 根据面积、单价计算");
    ui->comboBox_2->addItem("2 根据贷款总额计算");
    //按揭成数
    ui->comboBox_3->addItem("8成");
    ui->comboBox_3->addItem("7.5成");
    ui->comboBox_3->addItem("7成");
    ui->comboBox_3->addItem("6.5成");
    ui->comboBox_3->addItem("6成");
    ui->comboBox_3->addItem("5.5成");
    ui->comboBox_3->addItem("5成");
    ui->comboBox_3->addItem("4.5成");
    ui->comboBox_3->addItem("4成");
    ui->comboBox_3->addItem("3.5成");
    ui->comboBox_3->addItem("3成");
    ui->comboBox_3->addItem("2.5成");
    ui->comboBox_3->addItem("2成");
    //按揭年数
    ui->comboBox_4->addItem("300期/月)");
    ui->comboBox_4->addItem("288期/月");
    ui->comboBox_4->addItem("376期/月");
    ui->comboBox_4->addItem("264期/月");
    ui->comboBox_4->addItem("252期/月");
    ui->comboBox_4->addItem("240期/月");
    ui->comboBox_4->addItem("228期/月");
    ui->comboBox_4->addItem("216期/月");
    ui->comboBox_4->addItem("204期/月");
    ui->comboBox_4->addItem("192期/月");
    ui->comboBox_4->addItem("180期/月");
    ui->comboBox_4->addItem("168期/月");
    ui->comboBox_4->addItem("156期/月");
    ui->comboBox_4->addItem("144期/月");
    ui->comboBox_4->addItem("132期/月");
    ui->comboBox_4->addItem("120期/月");
    ui->comboBox_4->addItem("108期/月");
    ui->comboBox_4->addItem("96期/月");
    ui->comboBox_4->addItem("84期/月");
    ui->comboBox_4->addItem("72期/月");
    ui->comboBox_4->addItem("60期/月");
    ui->comboBox_4->addItem("48期/月");
    ui->comboBox_4->addItem("36期/月");
    ui->comboBox_4->addItem("24期/月");
    ui->comboBox_4->addItem("12期/月");
    //贷款利率


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn1_clicked()
{
//    //selection_1是贷款类别选择，selection_2是计算方式选择，selection_3是还款方式
//    QString selection_1,selection_2,selection_3;
//    selection_1 = ui->lineEdit_13->text();
//    selection_2 = ui->lineEdit_14->text();
//    selection_3 = ui->lineEdit_12->text();
    //box1是贷款类别，box2是计算方式，box3是还款方式
    int box1 = this->ui->comboBox->currentIndex();
    int box2 = this->ui->comboBox_2->currentIndex();
    int box3 = this->ui->comboBox_6->currentIndex();
    //line1是房屋单价，line2是房屋面积，line3是首付，line4是按揭成数
    QString line1,line2,line3,line4;
    //line5是贷款总额, line6是还款总额，line7贷款利率，line8是每月月供，line9是支付利息，line10是还款月数
    QString line5,line6,line7,line8,line9,line10;
    //line11是首月月供，line12是每月递减,line13是商业贷款额，line14是公积金贷款额
    //line15是组合型贷款时的商贷利率，line16是组合型贷款时的公积金利率
    QString line11,line12,line13,line14,line15,line16;
    //读取lineedit上的内容
    line1 = ui->lineEdit->text();
    line2 = ui->lineEdit_2->text();
    line4 = ui->lineEdit_9->text();
    line7 = ui->lineEdit_3->text();
    line10 = ui->lineEdit_10->text();
    //x是房屋单价，y是房屋面积，z是按揭成数，t是首付，m是贷款总额
    double x,y,z,t,m;
    //a是每月月供,b是贷款利率,c是还款月数,d是支付利息,e是还款总额
    double a,b,c,d,e;
    //f是首月月供，g是每月递减,h是商业贷款额，i是公积金贷款额
    //j是组合型贷款时的商贷利率,k是组合型贷款时的公积金利率
    double f,g,h,i,j,k;
    //将lineedit上的内容转化为double
    x= line1.toDouble();
    y= line2.toDouble();
    z= line4.toDouble();
    b= line7.toDouble();
    c= line10.toDouble();

    //如果是商业贷款或者公积金贷款
    //if(selection_1=="1"||selection_1=="2")
    if(box1==0||box1==1)
    {
        //等额本息
        //if(selection_3=="1")
        if(box3==0)
        {
            //根据面积，单价计算
            //if(selection_2=="1")
            if(box2==0)
            {
                //首付计算
                t= x*y*(1-z*0.1);
                //贷款总额计算
                m= x*y*z*0.1;
                //每月月供计算
                a= (m*b*0.01/12*qPow(1+b*0.01/12,c))/(qPow(1+b*0.01/12,c)-1);
                //支付利息计算
                d= (m*c*b*0.01/12*qPow(1+b*0.01/12,c))/(qPow(1+b*0.01/12,c)-1)-m;
                //还款总额计算
                e= m+d;
                //再转回QString类型
                line3= QString::number(t);
                line5= QString::number(m);
                line8= QString::number(a);
                line10= QString::number(c);
                line9= QString::number(d);
                line6= QString::number(e);
                //在lineedit上显示
                ui->lineEdit_11->setText(line3);
                ui->lineEdit_5->setText(line5);
                ui->lineEdit_4->setText(line8);
                ui->lineEdit_8->setText(line10);
                ui->lineEdit_6->setText(line9);
                ui->lineEdit_7->setText(line6);
            }
            //根据贷款总额计算
            //else if(selection_2=="2")
            else if(box2==1)
            {
                //读取贷款总额
                line5 = ui->lineEdit_15->text();
                //转化double类型
                m = line5.toDouble();

                //每月月供计算
                a= (m*10000*b*0.01/12*qPow(1+b*0.01/12,c))/(qPow(1+b*0.01/12,c)-1);
                //支付利息计算
                d= (m*10000*c*b*0.01/12*qPow(1+b*0.01/12,c))/(qPow(1+b*0.01/12,c)-1)-m*10000;
                //还款总额计算
                e= m*10000+d;
                //再转回QString类型

                line5= QString::number(m*10000);
                line8= QString::number(a);
                line10= QString::number(c);
                line9= QString::number(d);
                line6= QString::number(e);
                //在lineedit上显示

                ui->lineEdit_5->setText(line5);

                ui->lineEdit_4->setText(line8);
                ui->lineEdit_8->setText(line10);
                ui->lineEdit_6->setText(line9);
                ui->lineEdit_7->setText(line6);
            }
        }
        //等额本金
        //else if(selection_3=="2")
        else if(box3==1)
        {
            //根据面积单价计算
            //if(selection_2=="1")
            if(box2==0)
            {
                //首付计算
                t= x*y*(1-z*0.1);
                //贷款总额计算
                m= x*y*z*0.1;
                //首月月供计算
                f= (m/c)+m*b*0.01/12;
                //每月递减计算
                g= (m/c)*b*0.01/12;
                //支付利息计算
                d= ((m/c+m*b*0.01/12)+m/c*(1+b*0.01/12))/2*c-m;
                //还款总额计算
                e= m+d;
                //再转回QString类型
                line3= QString::number(t);
                line5= QString::number(m);
                line10= QString::number(c);
                line9= QString::number(d);
                line6= QString::number(e);
                line11= QString::number(f);
                line12= QString::number(g);
                //在lineedit上显示
                ui->lineEdit_11->setText(line3);
                ui->lineEdit_5->setText(line5);
                ui->lineEdit_8->setText(line10);
                ui->lineEdit_6->setText(line9);
                ui->lineEdit_7->setText(line6);
                ui->lineEdit_18->setText(line11);
                ui->lineEdit_19->setText(line12);
            }
            //根据贷款总额计算
            //else if(selection_2=="2")
            else if(box2==1)
            {
                //读取贷款总额
                line5 = ui->lineEdit_15->text();
                //转化double类型
                m = line5.toDouble();
                //首月月供计算
                f= (m*10000/c)+m*10000*b*0.01/12;
                //每月递减计算
                g= (m*10000/c)*b*0.01/12;
                //支付利息计算
                d= ((m*10000/c+m*10000*b*0.01/12)+m*10000/c*(1+b*0.01/12))/2*c-m*10000;
                //还款总额计算
                e= m*10000+d;
                //再转回QString类型

                line5= QString::number(m*10000);
                line10= QString::number(c);
                line9= QString::number(d);
                line6= QString::number(e);
                line11= QString::number(f);
                line12= QString::number(g);
                //在lineedit上显示

                ui->lineEdit_5->setText(line5);
                ui->lineEdit_8->setText(line10);
                ui->lineEdit_6->setText(line9);
                ui->lineEdit_7->setText(line6);
                ui->lineEdit_18->setText(line11);
                ui->lineEdit_19->setText(line12);
            }
        }
    }
    //如果是组合型贷款
    //else if(selection_1=="3")
    else if(box1==2)
    {
        //读取lineedit上的内容
        line13 = ui->lineEdit_20->text();
        line14 = ui->lineEdit_21->text();
        line15 = ui->lineEdit_16->text();
        line16 = ui->lineEdit_17->text();
        //将lineedit上的内容转化为double
        h= line13.toDouble();
        i= line14.toDouble();
        j= line15.toDouble();
        k= line16.toDouble();
        //计算方式为等额本息
        //if(selection_3=="1")
        if(box3==0)
        {
            //贷款总额计算
            m= h+i;
            //每月月供计算
            a= (h*10000*j*0.01/12*qPow(1+j*0.01/12,c))/(qPow(1+j*0.01/12,c)-1)+(i*10000*k*0.01/12*qPow(1+k*0.01/12,c))/(qPow(1+k*0.01/12,c)-1);
            //支付利息计算
            d= ((h*10000*c*j*0.01/12*qPow(1+j*0.01/12,c))/(qPow(1+j*0.01/12,c)-1)-h*10000)+((i*10000*c*k*0.01/12*qPow(1+k*0.01/12,c))/(qPow(1+k*0.01/12,c)-1)-i*10000);
            //还款总额计算
            e= m*10000+d;
            //再转回QString类型

            line5= QString::number(m*10000);
            line8= QString::number(a);
            line10= QString::number(c);
            line9= QString::number(d);
            line6= QString::number(e);
            //在lineedit上显示

            ui->lineEdit_5->setText(line5);

            ui->lineEdit_4->setText(line8);
            ui->lineEdit_8->setText(line10);
            ui->lineEdit_6->setText(line9);
            ui->lineEdit_7->setText(line6);
        }
        //计算方式为等额本金
        //if(selection_3=="2")
        if(box3==1)
        {
            //贷款总额计算
            m= h+i;
            //首月月供计算
            f= ((h*10000/c)+h*10000*j*0.01/12)+((i*10000/c)+i*10000*k*0.01/12);
            //每月递减计算
            g= ((h*10000/c)*j*0.01/12)+((i*10000/c)*k*0.01/12);
            //支付利息计算
            d= (((h/c+h*j*0.01/12)+h/c*(1+j*0.01/12))/2*c-h)+(((i/c+i*k*0.01/12)+i/c*(1+k*0.01/12))/2*c-i);
            //还款总额计算
            e= m*10000+d*10000;
            //再转回QString类型

            line5= QString::number(m*10000);
            line10= QString::number(c);
            line9= QString::number(d*10000);
            line6= QString::number(e);
            line11= QString::number(f);
            line12= QString::number(g);
            //在lineedit上显示

            ui->lineEdit_5->setText(line5);
            ui->lineEdit_8->setText(line10);
            ui->lineEdit_6->setText(line9);
            ui->lineEdit_7->setText(line6);
            ui->lineEdit_18->setText(line11);
            ui->lineEdit_19->setText(line12);
        }
    }

}
void MainWindow::on_btn2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
//    ui->lineEdit_12->clear();
//    ui->lineEdit_13->clear();
//    ui->lineEdit_14->clear();
    ui->lineEdit_15->clear();
    ui->lineEdit_16->clear();
    ui->lineEdit_17->clear();
    ui->lineEdit_18->clear();
    ui->lineEdit_19->clear();
    ui->lineEdit_20->clear();
    ui->lineEdit_21->clear();
}


