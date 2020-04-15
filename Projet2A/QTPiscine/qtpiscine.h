#ifndef QTPISCINE_H
#define QTPISCINE_H

#include <QMainWindow>

namespace Ui {
class QTPiscine;
}

class QTPiscine : public QMainWindow
{
    Q_OBJECT

public:
    explicit QTPiscine(QWidget *parent = nullptr);
    ~QTPiscine();

private:
    Ui::QTPiscine *ui;
};

#endif // QTPISCINE_H
