#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QShortcut>
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTimer();
    void onStartClicked();
    void onResetClicked();
    void cycleCornerPosition();
    void openColorPicker();

private:
    Ui::MainWindow *ui;
    QTimer timer;
    int elapsedSeconds = 0;
    bool paused = true;
    QPoint dragPos;
    int cornerState = 0;  // 0=top-left, 1=top-right, 2=bottom-left, 3=bottom-right

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
};
#endif // MAINWINDOW_H
