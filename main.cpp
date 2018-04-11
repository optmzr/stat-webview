#include <QApplication>
#include <QWebEngineView>
#include <QCommandLineParser>
#include <QCommandLineOption>

int main(int argc, char *argv[])
{
    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QCommandLineParser parser;
    parser.setApplicationDescription("Just a simple webview");
    parser.addHelpOption();
    parser.addVersionOption();

    const QCommandLineOption urlOption("u", "URL to show.", "url");
    const QCommandLineOption resOption("r", "Resolution (e.g. 1920x1080).", "res");
    parser.addOption(urlOption);
    parser.addOption(resOption);

    if (!parser.parse(QApplication::arguments())) {
        qFatal("Invalid command line option.");
        return 1;
    }

    QUrl url = QUrl("https://example.org");
    if (parser.isSet(urlOption)) {
        url = QUrl::fromUserInput(parser.value(urlOption));
    }

    QSize res = QSize(1920, 1080);
    if (parser.isSet(resOption)) {
        QString resPair = parser.value(resOption);
        QStringList resList = resPair.split("x");
        res = QSize(resList[0].toInt(), resList[1].toInt());
    }

    QWebEngineView view;
    view.setUrl(url);
    view.resize(res);
    view.show();

    return app.exec();
}
