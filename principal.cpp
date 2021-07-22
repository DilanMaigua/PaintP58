#include "principal.h"
#include "ui_principal.h"



Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    //Instancias del objeto
    m_imagen = new QImage(this->size(),QImage::Format_ARGB32_Premultiplied);
    //Rellenar de blanco
    m_imagen->fill(Qt::white);
    //Instanciar el objeto painter
    m_painter = new QPainter(m_imagen);
    //Intanciar ancho
    m_ancho=5;
    //Dejar opcion por defecto
    m_opcion=1;
}

Principal::~Principal()
{
    delete ui;
}

void Principal::mousePressEvent(QMouseEvent *event)
{
    if(m_opcion == 1 ){

        m_ptInicial = event->pos();

    }else if (m_opcion==2){
        if(m_toogle){
            m_ptInicial=event->pos();
        }else{
            m_ptFinal=event->pos();
            //Creando el rectangulo
            QPen pincel;
            pincel.setColor(m_color);
             pincel.setWidth(m_ancho);
            m_painter->setPen(pincel);
            m_painter->drawLine(m_ptInicial, m_ptFinal);
            //Redibujar la interfaz grafica
            update();
        }

    }else if(m_opcion==3){
        if(m_toogle){
            m_ptInicial = event->pos();
        }else{
            m_ptFinal = event->pos();
            //creando el rectangulo
            int ancho=m_ptFinal.x() - m_ptInicial.x();
            int alto=m_ptFinal.y()-m_ptInicial.y();

            QPen pincel;
            pincel.setColor(m_color);
             pincel.setWidth(m_ancho);
            m_painter->setPen(pincel);
            m_painter->drawRect(m_ptInicial.x(),m_ptInicial.y(),ancho,alto);

            //Redibujar la interfaz grafica
            update();
        }
    }else if(m_opcion==4){
        if(m_toogle){
            m_ptInicial = event->pos();
        }else{
            m_ptFinal = event->pos();
            //Creando un circulo
            int anchox=m_ptFinal.x()-m_ptInicial.x();
            int anchoy=m_ptFinal.y()-m_ptInicial.y();

            QPen pincel;
            pincel.setColor(m_color);
            pincel.setWidth(m_ancho);
            m_painter->setPen(pincel);
            m_painter->drawEllipse(m_ptInicial.x(),m_ptInicial.y(),anchox,anchoy);

            //Redibujar la interfaz grafica
            update();
        }
    }
       m_toogle = !m_toogle;
}

/**
 * @brief Principal::paintEvent Se ejecuta cada vez que se redibuja la imagen
 * @param event
 */
void Principal::paintEvent(QPaintEvent *event)
{
    //Crear otro painter (local)
    QPainter painter(this);
    //Dibujar la imagern
    painter.drawImage(0,0, *m_imagen);
    //Aceptar el evento
    event->accept();

}

void Principal::mouseMoveEvent(QMouseEvent *event)
{
  m_ptFinal = event->pos();
  QPen pincel;

  pincel.setColor(m_color);
  pincel.setWidth(m_ancho);
  m_painter->setPen(pincel);
  m_painter->drawLine(m_ptInicial, m_ptFinal);
  //Redibujar la interfaz grafica
  update();
  m_ptInicial= m_ptFinal;
}


void Principal::on_actionColor_triggered()
{
        m_color = QColorDialog::getColor(Qt::white,this);
}


void Principal::on_actionLibres_triggered()
{
    m_opcion=1;
}


void Principal::on_actionLIneas_triggered()
{
    m_opcion=2;
}


void Principal::on_actionRectangulos_triggered()
{
    m_opcion=3;
}


void Principal::on_actionCircunferencias_triggered()
{
    m_opcion=4;
}


void Principal::on_actionGuardar_triggered()
{
    //Crear un objeto Qdir a partir del direcion del usario
      QDir directorio = QDir::home();
      //Agregrar al path absoluto del objeto, un nombre por defeto del archivo
      QString pathArchivo = directorio.absolutePath() + "/sin_nombre.jpg";
      //Abrir un cuadro de dialogo para selecionar el nombre y ubicacion del archivo y guardar.
      QString fileName = QFileDialog::getSaveFileName(this, "* Un nombre para la Ventana *",
                                                      pathArchivo,
                                                      "Archivo imagen (*.jpg)");
      m_imagen->save(fileName);
      ui->statusbar->showMessage("Archivo guarda en" + fileName,3000);
}


void Principal::on_actionNuevo_triggered()
{
    m_imagen->fill(Qt::white);
    update();
}


void Principal::on_actionSalir_triggered()
{
    this->close();
}


void Principal::on_actionAnchura_triggered()
{
     m_ancho = QInputDialog::getInt(this, "Ancho del pincel", "Ingrese el ancho del pincel", m_ancho, 1, 100);
}

