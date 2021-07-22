#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QImage>
#include <QPainter>
#include <QPaintEvent>
#include <QFileDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QColorDialog>
#include <QColor>
#include <QInputDialog>



QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

    const QColor &color() const;
    void setColor(const QColor &newColor);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
private slots:
    void on_actionColor_triggered();

    void on_actionLibres_triggered();

    void on_actionLIneas_triggered();

    void on_actionRectangulos_triggered();

    void on_actionCircunferencias_triggered();

    void on_actionGuardar_triggered();

    void on_actionNuevo_triggered();

    void on_actionSalir_triggered();

    void on_actionAnchura_triggered();

private:
    Ui::Principal *ui;
    QImage *m_imagen;    //Es la imgen sobre la cual se va a dibujar
    QPainter *m_painter;    //El objeto painter
    QPoint m_ptInicial; //Punto inicial para dibujar
    QPoint m_ptFinal;  //Punto final para dibujar
    QColor m_color;
    int m_ancho;
    int m_opcion;
    bool m_toogle=true;

};

#endif // PRINCIPAL_H
