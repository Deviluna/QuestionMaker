#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int update_preview();
    void fresh_window();
    void save_question();
    struct question{
        QString stem="",A="",B="",C="",D="",analysis="";
        int choice=-1;
    }que;
    void load_question();
    int max_number=5;
    QVector<question> vector;


private slots:

    void on_plainTextEdit_textChanged();

    void on_lineEdit_5_textChanged(const QString &arg1);

    void on_lineEdit_6_textChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_plainTextEdit_2_textChanged();

    void on_lineEdit_1_textChanged(const QString &arg1);

    void on_radioButton_toggled(bool checked);

    void on_radioButton_3_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_radioButton_4_toggled(bool checked);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int current_id;
};

#endif // MAINWINDOW_H
