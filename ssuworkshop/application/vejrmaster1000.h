#ifndef VEJRMASTER1000_H
#define VEJRMASTER1000_H

#include <QMainWindow>

namespace Ui {
class VejrMaster1000;
}

class VejrMaster1000 : public QMainWindow
{
    Q_OBJECT

public:
    explicit VejrMaster1000(QWidget *parent = nullptr);
    ~VejrMaster1000();


private:
    Ui::VejrMaster1000 *ui;
};

#endif // VEJRMASTER1000_H
