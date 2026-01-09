#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QScreen>
#include <QShortcut>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setAttribute(Qt::WA_TranslucentBackground);

    QShortcut *shortcutClose = new QShortcut(QKeySequence(Qt::Key_F1), this);
    connect(shortcutClose, &QShortcut::activated, this, &MainWindow::close);

    QShortcut *shortcutToggle = new QShortcut(QKeySequence(Qt::Key_F2), this);
    connect(shortcutToggle, &QShortcut::activated, this, &MainWindow::onStartClicked);

    QShortcut *shortcutReset = new QShortcut(QKeySequence(Qt::Key_F3), this);
    connect(shortcutReset, &QShortcut::activated, this, &MainWindow::onResetClicked);

    QShortcut *shortcutMoveCorner  = new QShortcut(QKeySequence(Qt::Key_F4), this);
    connect(shortcutMoveCorner, &QShortcut::activated, this, &MainWindow::cycleCornerPosition);

    QShortcut *shortcutColor = new QShortcut(QKeySequence(Qt::Key_F5), this);
    connect(shortcutColor, &QShortcut::activated, this, &MainWindow::openColorPicker);

    connect(&timer, &QTimer::timeout, this, &MainWindow::updateTimer);
    timer.setInterval(1000);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStartClicked()
{
    if (paused)
    {
        timer.start();
        paused = false;
    }
    else
    {
        timer.stop();
        paused = true;
    }
}

void MainWindow::onResetClicked()
{
    timer.stop();
    paused = true;
    elapsedSeconds = 0;

    ui->label->setText("00:00:00");
}

void MainWindow::updateTimer()
{
    elapsedSeconds++;

    int hours = elapsedSeconds / 3600;
    int minutes = (elapsedSeconds % 3600) / 60;
    int seconds = elapsedSeconds % 60;

    QString timeString = QString("%1:%2:%3")
                             .arg(hours, 2, 10, QChar('0'))
                             .arg(minutes, 2, 10, QChar('0'))
                             .arg(seconds, 2, 10, QChar('0'));

    ui->label->setText(timeString);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    dragPos = event->globalPosition().toPoint();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        const QPoint diff = event->globalPosition().toPoint() - dragPos;
        move(x() + diff.x(), y() + diff.y());
        dragPos = event->globalPosition().toPoint();
    }
}

void MainWindow::cycleCornerPosition()
{
    QRect screen = QApplication::primaryScreen()->availableGeometry();

    int w = width();
    int h = height();

    switch (cornerState)
    {
    case 0: move(screen.left(), screen.top()); break;
    case 1: move(screen.right() - w, screen.top()); break;
    case 2: move(screen.left(), screen.bottom() - h); break;
    case 3: move(screen.right() - w, screen.bottom() - h); break;
    }

    cornerState = (cornerState + 1) % 4;
}

void MainWindow::openColorPicker()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Escolher cor do texto");

    if (color.isValid())
    {
        QString css = QString("color: %1;").arg(color.name());
        ui->label->setStyleSheet(css);
    }
}
