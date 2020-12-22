#include <windows.h>
#include "kaedetranslate.h"
#include "ui_kaedetranslate.h"

KaedeTranslate::KaedeTranslate(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::KaedeTranslate)
{
    ui->setupUi(this);
}

KaedeTranslate::~KaedeTranslate()
{
    delete ui;
}

