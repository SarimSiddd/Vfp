#ifndef UTILS_H
#define UTILS_H
#include <QString>
#include <QDebug>
#include <memory>

class Utils
{
public:
    Utils();
    static void DestructorMsg(const QString &msg);
    static void DestructorMsg(const QObject * const obj);
    template <typename T, typename...Args>
    static std::unique_ptr<T> make_unique(Args&&... args){

        return std::unique_ptr<T> (new T(std::forward<Args>(args)...));
    }
};

#endif // UTILS_H
