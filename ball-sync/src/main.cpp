#include "BallWidget.h"

#include <QApplication>
#include <QLabel>
#include <QVBoxLayout>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("Ball Sync");

    auto* board = new BallWidget;
    auto* status = new QLabel;

    auto showPosition = [status](QPointF pos) {
        status->setText(QString("Konum: (%1, %2)")
                            .arg(qRound(pos.x()))
                            .arg(qRound(pos.y())));
    };
    showPosition(board->ballPosition());
    QObject::connect(board, &BallWidget::ballMoved, status, showPosition);

    auto* layout = new QVBoxLayout(&window);
    layout->addWidget(board);
    layout->addWidget(status);

    window.show();
    board->setFocus();

    return app.exec();
}
