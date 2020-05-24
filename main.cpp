#include <QtWidgets>
#include <FenPrincipale.h>

int main(int argc, char *argv[])

{
    QApplication app(argc,argv);
    WinBody mainWindow;
    mainWindow.setWindowTitle("Paint");
    mainWindow.show();

    return app.exec();
}
