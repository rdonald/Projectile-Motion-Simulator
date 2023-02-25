#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>

class Question : public QObject
{
    Q_OBJECT
public:
    explicit Question(QObject *parent = nullptr);

    // the question
    QString question;
    // answer to the question
    QString answer;

    //  Each multiple choice answers maps to a hint.
    QVector<QString> multipleChoiceAnswers;
    QVector<QString> hints;
};

#endif // QUESTION_H
