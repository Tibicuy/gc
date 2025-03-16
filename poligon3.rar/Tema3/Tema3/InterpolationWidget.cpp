#include "InterpolationWidget.h"
#include <algorithm> 
InterpolationWidget::InterpolationWidget(QWidget* parent) : QWidget(parent) {
    setMinimumSize(600, 400);
}

void InterpolationWidget::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Desenare puncte
    painter.setPen(Qt::black);
    painter.setBrush(Qt::red);
    for (const auto& point : points) {
        painter.drawEllipse(point, 5, 5);
    }

    // Desenare curba de interpolare după apăsarea click dreapta
    if (inputFinished && points.size() > 1) {
        painter.setPen(Qt::blue);
        for (double x = 0; x < width(); x += 1.0) {
            double y = lagrangeInterpolation(x);
            if (y >= 0 && y <= height()) {
                painter.drawPoint(QPointF(x, y));
            }
        }
    }
}

void InterpolationWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::RightButton) {
        inputFinished = true; // După click dreapta nu mai permitem adăugarea de puncte
        update();
        return;
    }

    if (event->button() == Qt::LeftButton) {
        if (!inputFinished) {
            // Adaugă puncte doar în ordine crescătoare pe axa X
            if (points.empty() || event->pos().x() > points.back().x()) {
                points.push_back(event->pos());
                update();
            }
        }
        else {
            // După click dreapta, permitem mutarea punctelor
            for (size_t i = 0; i < points.size(); ++i) {
                if (QLineF(event->pos(), points[i]).length() < 10) {
                    dragging = true;
                    draggedIndex = i;
                    return;
                }
            }
        }
    }
}

void InterpolationWidget::mouseMoveEvent(QMouseEvent* event) {
    if (dragging && draggedIndex >= 0) {
        // Limitează mutarea între punctele vecine
        double leftLimit = (draggedIndex > 0) ? points[draggedIndex - 1].x() + 1 : 0;
        double rightLimit = (draggedIndex < points.size() - 1) ? points[draggedIndex + 1].x() - 1 : width();



        double newX = std::clamp(static_cast<double>(event->pos().x()), leftLimit, rightLimit);
        double newY = std::clamp(static_cast<double>(event->pos().y()), 0.0, static_cast<double>(height()));

        points[draggedIndex] = QPointF(newX, newY);
        update();
    }
}

void InterpolationWidget::mouseReleaseEvent(QMouseEvent* event) {
    Q_UNUSED(event);
    dragging = false;
    draggedIndex = -1;
}

double InterpolationWidget::lagrangeInterpolation(double x) {
    double result = 0.0;
    int n = points.size();
    for (int i = 0; i < n; ++i) {
        double term = points[i].y();
        for (int j = 0; j < n; ++j) {
            if (i != j)
                term *= (x - points[j].x()) / (points[i].x() - points[j].x());
        }
        result += term;
    }
    return result;
}
