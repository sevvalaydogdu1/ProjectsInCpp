#include "GameWindow.h"

#include "colors.h"
#include "renderer.h"

#include <QPainter>

GameWindow::GameWindow(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("Pong");
    setAttribute(Qt::WA_OpaquePaintEvent);
    setCursor(Qt::BlankCursor);

    timer_.setTimerType(Qt::PreciseTimer);
    connect(&timer_, &QTimer::timeout, this, &GameWindow::frame);
    timer_.start(16);
    clock_.start();
}

void GameWindow::resizeEvent(QResizeEvent*)
{
    buffer_ = QImage(size(), QImage::Format_RGB32);

    render_state.width = buffer_.width();
    render_state.height = buffer_.height();
    render_state.pixels = reinterpret_cast<u32*>(buffer_.bits());
}

void GameWindow::frame()
{
    if (render_state.pixels)
        clear_screen(kBorderColor);

    update();

    deltaTime_ = clock_.nsecsElapsed() / 1e9f;
    clock_.restart();
}

void GameWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);

    // Oyun koordinatlarında y yukarı doğru artıyor
    p.translate(0, height());
    p.scale(1, -1);
    p.drawImage(0, 0, buffer_);
}
