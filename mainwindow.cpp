#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Qstring>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    current_id=1;
    ui->setupUi(this);

    for(int i=0;i<max_number;i++)
        vector.push_back(que);
    update_preview();
    fresh_window();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_question(){
    question now=vector[current_id-1];
    ui->plainTextEdit->setPlainText(now.stem);
    ui->lineEdit_1->setText(now.A);
    ui->lineEdit_5->setText(now.B);
    ui->lineEdit_6->setText(now.C);
    ui->lineEdit_2->setText(now.D);
    switch(now.choice){
    case 1:
        ui->radioButton->setChecked(true);
        break;
    case 2:
        ui->radioButton_3->setChecked(true);
    case 3:
        ui->radioButton_2->setChecked(true);
    case 4:
        ui->radioButton_4->setChecked(true);
    }
    ui->plainTextEdit_2->setPlainText(now.analysis);
}


void MainWindow::fresh_window(){
    ui->label_2->setText("第"+QString::number(current_id)+"题");
    if(current_id==1)
        ui->pushButton->setDisabled(true);
    else
        ui->pushButton->setDisabled(false);
    if(current_id==max_number)
        ui->pushButton_2->setDisabled(true);
    else
        ui->pushButton_2->setDisabled(false);
}

int MainWindow::update_preview(){
    QString final=ui->label_2->text()+"\n";
    final+=ui->plainTextEdit->toPlainText()+"\n";
    final+="A."+ui->lineEdit_1->text()+"\t";
    final+="B."+ui->lineEdit_5->text()+"\n";
    final+="C."+ui->lineEdit_6->text()+"\t";
    final+="D."+ui->lineEdit_2->text()+"\n";

    final+="标准答案:";
    if(ui->radioButton->isChecked())
        final+="A";
    if(ui->radioButton_3->isChecked())
        final+="B";
    if(ui->radioButton_2->isChecked())
        final+="C";
    if(ui->radioButton_4->isChecked())
        final+="D";
    final+="\n";

    final+="解析:"+ui->plainTextEdit_2->toPlainText();
    ui->textBrowser->setText(final);
    save_question();
    return 0;
}

void MainWindow::save_question(){
    que.stem=ui->plainTextEdit->toPlainText();
    que.A=ui->lineEdit_1->text();
    que.B=ui->lineEdit_5->text();
    que.C=ui->lineEdit_6->text();
    que.D=ui->lineEdit_2->text();
    if(ui->radioButton->isChecked())
        que.choice=1;
    if(ui->radioButton_3->isChecked())
        que.choice=2;
    if(ui->radioButton_2->isChecked())
        que.choice=3;
    if(ui->radioButton_4->isChecked())
        que.choice=4;
    que.analysis=ui->plainTextEdit_2->toPlainText();
    vector[current_id-1]=que;
}



void MainWindow::on_plainTextEdit_textChanged()
{
    update_preview();
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    update_preview();
}

void MainWindow::on_lineEdit_6_textChanged(const QString &arg1)
{
    update_preview();

}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    update_preview();

}

void MainWindow::on_plainTextEdit_2_textChanged()
{
    update_preview();

}

void MainWindow::on_lineEdit_1_textChanged(const QString &arg1)
{
    update_preview();

}

void MainWindow::on_radioButton_toggled(bool checked)
{
    update_preview();

}

void MainWindow::on_radioButton_3_toggled(bool checked)
{
    update_preview();

}

void MainWindow::on_radioButton_2_toggled(bool checked)
{
    update_preview();

}

void MainWindow::on_radioButton_4_toggled(bool checked)
{
    update_preview();

}

void MainWindow::on_pushButton_3_clicked()
{
    //打开新窗口，预览试卷，点击导出。要把这里面的值传给他。
}

void MainWindow::on_pushButton_clicked()
{
    current_id-=1;
    load_question();
    fresh_window();
    update_preview();

}

void MainWindow::on_pushButton_2_clicked()
{
    current_id+=1;
    load_question();
    fresh_window();
    update_preview();
}
