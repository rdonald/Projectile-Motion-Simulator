#ifndef QUESTIONHANDLER_H
#define QUESTIONHANDLER_H

#include <QObject>
#include <question.h>

class QuestionHandler : public QObject
{
    Q_OBJECT
public:
    explicit QuestionHandler(QObject *parent = nullptr);

    void showInitialQuestion();
    void showInitialMultipleChoice();
    void incrementQuestionNumber();
    void resetQuestionNumber();

    QString getTip(int answerNum);
    QString getAnswer();
    Question* getQuestion();

    int getQuestionNumber();

signals:
    void showQuestionSignal(QString);
    void showMultipleChoiceSignal(QVector<QString>);

public slots:

private:
    void makeQuestions();

    // vector containing all of the questions
    QVector<Question*> questions;
    // current question, zero-based
    int questionNumber;
};

#endif // QUESTIONHANDLER_H
