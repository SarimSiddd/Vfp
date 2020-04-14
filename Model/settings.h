#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QString>
#include <QDir>
#include <QFile>
#include <utility>
#include <QJsonParseError>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QJsonArray>
#include <QStringListModel>
#include <QStandardPaths>

typedef std::pair<QJsonObject, QJsonParseError> JsonObjErrorPair;

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent, QString filename);
    void ParseJsonData();

signals:
    void NotifyStatusMessage(QString);
private:
    QString m_filename;
    QString m_applicationName;
    QString m_appShortName;
    QString m_hostName;
    quint16 m_portNumber;
    int m_longWaitMs;
    int m_shortWaitMs;

    QStringListModel& m_modelCommands;
    QString getApplicationName() const {return m_applicationName;}
    QString getAppShortName() const {return m_appShortName;}
    QString getHostName() const {return m_hostName;}
    quint16 getPortNumber()  const {return m_portNumber;}
    int getShortWaitMs() const { return m_shortWaitMs;}
    int getLongWaitMs() const {return m_longWaitMs;}
    QStringListModel& getCommandsAsModel() const {return m_modelCommands;}
    QString ReadJsonFile();
    QString ReadJsonFromInternalResource();
    JsonObjErrorPair GetJsonObject(const QString &json);
    void SendErrorMessage(const QString &msg);
    void ShowJsonParseError(QJsonParseError JsonErr);
    void SetupCommands(QJsonObject json_obj);
    void WriteDefaultsToStdConfigFile(QFile &stdConfigFile, const QString &settings);
    QDir OpenConfigDirectory();




};

#endif // SETTINGS_H
