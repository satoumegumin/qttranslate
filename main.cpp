#include "kaedetranslate.h"
#include "kaedelabel.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    kaedeLabel k;
    k.show();
    //KaedeTranslate w;
    //w.show();
    return a.exec();
}
