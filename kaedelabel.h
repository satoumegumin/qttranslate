#ifndef KAEDELABEL_H
#define KAEDELABEL_H

#include <QWidget>

namespace Ui {
class kaedeLabel;
}

class kaedeLabel : public QWidget
{
    Q_OBJECT

public:
    explicit kaedeLabel(QWidget *parent = nullptr);
    ~kaedeLabel();

private:
    Ui::kaedeLabel *ui;
};

#endif // KAEDELABEL_H
