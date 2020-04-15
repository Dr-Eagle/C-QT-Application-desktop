#ifndef SPERSOPISCINE_H
#define SPERSOPISCINE_H

#include <QWidget>

namespace Ui {
class SPersoPiscine;
}

class SPersoPiscine : public QWidget
{
    Q_OBJECT

public:
    explicit SPersoPiscine(QWidget *parent = nullptr);
    ~SPersoPiscine();

private slots:
    void on_Abonne_clicked();

    void on_Cours_clicked();

    void on_Stock_clicked();

    void on_Back_clicked();

private:
    Ui::SPersoPiscine *ui;
};

#endif // SPERSOPISCINE_H
