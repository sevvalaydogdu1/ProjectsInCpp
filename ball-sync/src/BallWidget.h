#pragma once

#include <QElapsedTimer>
#include <QPointF>
#include <QSet>
#include <QTimer>
#include <QWidget>

class BallWidget : public QWidget {
    Q_OBJECT

public:
    explicit BallWidget(QWidget* parent = nullptr);

    QPointF ballPosition() const { return ball_; }
    void setBallPosition(QPointF pos);

signals:
    void ballMoved(QPointF pos);

protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void focusOutEvent(QFocusEvent* event) override;

private:
    void tick();
    QPointF inputDirection() const;

    static constexpr int kWidth = 640;
    static constexpr int kHeight = 480;
    static constexpr int kGridStep = 32;
    static constexpr double kRadius = 24.0;
    static constexpr double kSpeed = 250.0; // piksel/saniye

    QPointF ball_{kWidth / 2.0, kHeight / 2.0};
    QSet<int> pressedKeys_;
    QTimer timer_;
    QElapsedTimer clock_;
};
