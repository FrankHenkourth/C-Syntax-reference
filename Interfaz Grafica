#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

class MiVentana : public QMainWindow {
    Q_OBJECT

public:
    MiVentana() {
        // Establecer el titulo de la ventana
        setWindowTitle("Mi Aplicación GUI");
        // Establecer la geometría de la ventana
        setGeometry(100, 100, 400, 300);

        // Crear el diseño principal
        QVBoxLayout* diseñoPrincipal = new QVBoxLayout();

        // Crear la etiqueta
        QLabel* etiqueta = new QLabel("¡Hola, Mundo!");
        diseñoPrincipal->addWidget(etiqueta);

        // Crear el boton
        QPushButton* boton = new QPushButton("¡Haz clic en mí!");
        // Conectar la señal de clic del boton a un slot personalizado
        connect(boton, &QPushButton::clicked, this, &MiVentana::manejarClicEnBoton);
        diseñoPrincipal->addWidget(boton);

        // Establecer el diseño principal
        QWidget* widgetCentral = new QWidget();
        widgetCentral->setLayout(diseñoPrincipal);
        setCentralWidget(widgetCentral);
    }

private slots:
    void manejarClicEnBoton() {
        // Cambiar el texto de la etiqueta
        etiqueta->setText("¡Se hizo clic en el botón!");
    }

private:
    QLabel* etiqueta;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MiVentana ventana;
    ventana.show();
    return app.exec();
}
