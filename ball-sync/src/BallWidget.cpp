#include "BallWidget.h"

#include <QKeyEvent>
#include <QPainter>
#include <cmath>

BallWidget::BallWidget(QWidget* parent) : QWidget(parent)
{
    setFixedSize(kWidth, kHeight);
    setFocusPolicy(Qt::StrongFocus);

    connect(&timer_, &QTimer::timeout, this, &BallWidget::tick);
    timer_.start(16);
    clock_.start();
}

void BallWidget::setBallPosition(QPointF pos)
{
    pos.setX(qBound(kRadius, pos.x(), kWidth - kRadius));
    pos.setY(qBound(kRadius, pos.y(), kHeight - kRadius));

    if (pos == ball_)
        return;

    ball_ = pos;
    update();
    emit ballMoved(ball_);
}

void BallWidget::tick()
{
    // Timer tam 16 ms'de tetiklenmeyebilir
    const double dt = clock_.restart() / 1000.0;

    const QPointF dir = inputDirection();
    if (dir.isNull())
        return;

    setBallPosition(ball_ + dir * kSpeed * dt);
}

QPointF BallWidget::inputDirection() const
{
    QPointF dir;
    if (pressedKeys_.contains(Qt::Key_Left))  dir.rx() -= 1;
    if (pressedKeys_.contains(Qt::Key_Right)) dir.rx() += 1;
    if (pressedKeys_.contains(Qt::Key_Up))    dir.ry() -= 1;
    if (pressedKeys_.contains(Qt::Key_Down))  dir.ry() += 1;

    // Çaprazda hızlanmasın
    const double len = std::hypot(dir.x(), dir.y());
    return len > 0 ? dir / len : dir;
}

void BallWidget::keyPressEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat())
        pressedKeys_.insert(event->key());
    QWidget::keyPressEvent(event);
}

void BallWidget::keyReleaseEvent(QKeyEvent* event)
{
    if (!event->isAutoRepeat())
        pressedKeys_.remove(event->key());
    QWidget::keyReleaseEvent(event);
}

void BallWidget::focusOutEvent(QFocusEvent* event)
{
    pressedKeys_.clear();
    QWidget::focusOutEvent(event);
}

void BallWidget::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    p.fillRect(rect(), QColor(30, 34, 40));

    p.setPen(QColor(45, 50, 58));
    for (int x = 0; x <= kWidth; x += kGridStep)
        p.drawLine(x, 0, x, kHeight);
    for (int y = 0; y <= kHeight; y += kGridStep)
        p.drawLine(0, y, kWidth, y);

    p.setPen(Qt::NoPen);
    p.setBrush(QColor(230, 120, 40));
    p.drawEllipse(ball_, kRadius, kRadius);
}
