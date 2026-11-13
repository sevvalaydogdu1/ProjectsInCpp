#pragma once

#include <QElapsedTimer>
#include <QImage>
#include <QTimer>
#include <QWidget>

class GameWindow : public QWidget {
    Q_OBJECT

public:
    explicit GameWindow(QWidget* parent = nullptr);

protected:
    void resizeEvent(QResizeEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    void frame();

    QImage buffer_;
    QTimer timer_;
    QElapsedTimer clock_;
    float deltaTime_ = 0.016666f;
};
