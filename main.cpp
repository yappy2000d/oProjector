#include <QApplication>
#include <QUrl>
#include <QWebEngineView>
#include <QWebEnginePage>
#include <QWebEngineCertificateError>
#include <QAuthenticator>
#include <QFile>
#include <QSettings>
#include <QDebug>

// Define the path to the settings file
const QString SETTINGS_FILE = "settings.ini";

static QUrl URL;
static QString USER;
static QString PASSWORD;

class WebEnginePage : public QWebEnginePage {
    Q_OBJECT

public:
    using QWebEnginePage::QWebEnginePage;

    explicit WebEnginePage(QObject* parent = nullptr)
        : QWebEnginePage(parent) {
        connect(this, &QWebEnginePage::authenticationRequired,
                this, &WebEnginePage::onAuthenticationRequired);
        connect(this, &QWebEnginePage::certificateError,
            [=](QWebEngineCertificateError error) {
                error.acceptCertificate();
            });
    }

    private slots:
        void onAuthenticationRequired(const QUrl& requestUrl, QAuthenticator* authenticator) {
        qDebug() << "Authentication Required";
        authenticator->setUser(USER);
        authenticator->setPassword(PASSWORD);
    }
};

class WebBrowser : public QWebEngineView {
    Q_OBJECT
public:
    using QWebEngineView::QWebEngineView;

    WebBrowser() {
        this->setAttribute(Qt::WA_DeleteOnClose);
        this->setWindowTitle("\u6295\u5f71\u6a5f\u63a7\u5236");

        page = new WebEnginePage(this);
        setPage(page);
        setUrl(URL);
    }

private:
    WebEnginePage* page;
};

void initializeSettings() {
    if (!QFile::exists(SETTINGS_FILE)) {
        QSettings settings(SETTINGS_FILE, QSettings::IniFormat);
        settings.beginGroup("SETTINGS");
        settings.setValue("username", "EPSONWEB");
        settings.setValue("password", "");
        settings.setValue("url", "http://192.168.0.205/cgi-bin/Remote/Basic_Control");
        settings.endGroup();
    }
    const QSettings settings(SETTINGS_FILE, QSettings::IniFormat);
    URL = QUrl(settings.value("SETTINGS/url").toString());
    USER = settings.value("SETTINGS/username").toString();
    PASSWORD = settings.value("SETTINGS/password").toString();

    qDebug() << "User: " << USER;
    qDebug() << "Password: " << PASSWORD;
    qDebug() << "URL: " << URL;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    initializeSettings();

    WebBrowser browser;
    browser.show();

    return QApplication::exec();
}

#include "main.moc"