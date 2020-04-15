#ifndef ABONNEMENTETUDIANT_H
#define ABONNEMENTETUDIANT_H

#include <QWidget>

namespace Ui {
class AbonnementEtudiant;
}

class AbonnementEtudiant : public QWidget
{
    Q_OBJECT

public:
    explicit AbonnementEtudiant(QWidget *parent = nullptr);
    ~AbonnementEtudiant();

private:
    Ui::AbonnementEtudiant *ui;
};

#endif // ABONNEMENTETUDIANT_H
