#include "GameWindow.h"

#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    GameWindow window;
    window.resize(1280, 720);
    window.showFullScreen();

    return app.exec();
}
