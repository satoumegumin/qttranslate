#include "kaedelabel.h"
#include "ui_kaedelabel.h"

kaedeLabel::kaedeLabel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::kaedeLabel)
{

    ui->setupUi(this);
    setWindowFlag(Qt::WindowMinMaxButtonsHint,false);
    setFixedSize(width(),height());
    setWindowTitle("KaedeTran");
    setWindowIcon(QIcon(":/res/kaede.png"));

}

kaedeLabel::~kaedeLabel()
{
    delete ui;
}
