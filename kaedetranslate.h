#ifndef KAEDETRANSLATE_H
#define KAEDETRANSLATE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class KaedeTranslate; }
QT_END_NAMESPACE

class KaedeTranslate : public QMainWindow
{
    Q_OBJECT

public:
    KaedeTranslate(QWidget *parent = nullptr);
    ~KaedeTranslate();

private:
    Ui::KaedeTranslate *ui;
};
#endif // KAEDETRANSLATE_H
