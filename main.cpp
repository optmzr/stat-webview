#include <QApplication>
#include <QWebEngineView>

int main(int argc, char *argv[])
{
    const QUrl url = QUrl::fromUserInput(QString("https://example.org"));
    const QSize resolution = QSize(1920, 1080);

    QApplication app(argc, argv);
    app.setAttribute(Qt::AA_EnableHighDpiScaling);

    QWebEngineView view;
    view.page()->setBackgroundColor(Qt::black);
    view.setUrl(url);
    view.resize(resolution);
    view.show();

    return app.exec();
}
