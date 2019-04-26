#include "vejrmaster1000.h"
#include "ui_vejrmaster1000.h"

VejrMaster1000::VejrMaster1000(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VejrMaster1000)
{
    ui->setupUi(this);

}

VejrMaster1000::~VejrMaster1000()
{
    delete ui;
}
