#ifndef PERSONNELPISCINE_H
#define PERSONNELPISCINE_H

#include <QWidget>

namespace Ui {
class PersonnelPiscine;
}

class PersonnelPiscine : public QWidget
{
    Q_OBJECT

public:
    explicit PersonnelPiscine(QWidget *parent = nullptr);
    ~PersonnelPiscine();

private slots:
    void on_Abonne_clicked();

    void on_Cours_clicked();

    void on_Salaire_clicked();

    void on_Stock_clicked();

    void on_Back_clicked();

private:
    Ui::PersonnelPiscine *ui;
};

#endif // PERSONNELPISCINE_H
