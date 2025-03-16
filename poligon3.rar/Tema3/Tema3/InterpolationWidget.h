#ifndef INTERPOLATIONWIDGET_H
#define INTERPOLATIONWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <vector>

class InterpolationWidget : public QWidget {
    Q_OBJECT

public:
    explicit InterpolationWidget(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:
    std::vector<QPointF> points;
    bool dragging = false;
    int draggedIndex = -1;
    bool inputFinished = false; // True după apăsarea click dreapta

    double lagrangeInterpolation(double x);
};

#endif // INTERPOLATIONWIDGET_H
