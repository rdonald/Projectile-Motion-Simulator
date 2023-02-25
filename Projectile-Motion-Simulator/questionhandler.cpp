#include "questionhandler.h"

QuestionHandler::QuestionHandler(QObject *parent) : QObject(parent)
{
    questionNumber = 0;

    makeQuestions();
}

/**
 * @brief QuestionHandler::showInitialQuestion
 */
void QuestionHandler::showInitialQuestion()
{

    QString question = questions.at(0)->question;
    emit showQuestionSignal(question);

}

/**
 * @brief QuestionHandler::showInitialMultipleChoice
 */
void QuestionHandler::showInitialMultipleChoice()
{

    QVector<QString> choices = questions.at(0)->multipleChoiceAnswers;
    emit showMultipleChoiceSignal(choices);

}

/**
 * @brief QuestionHandler::incrementQuestionNumber
 */
void QuestionHandler::incrementQuestionNumber()
{
    questionNumber += 1;
}

void QuestionHandler::resetQuestionNumber()
{
    this->questionNumber = 0;
}

/**
 * @brief QuestionHandler::getTip
 * @param answerNum
 * @return
 */
QString QuestionHandler::getTip(int answerNum)
{
    return questions.at(questionNumber)->hints.at(answerNum);
}

/**
 * @brief QuestionHandler::getAnswer
 * @return
 */
QString QuestionHandler::getAnswer()
{
    return questions.at(questionNumber)->answer;
}

/**
 * @brief QuestionHandler::getQuestion
 * @return
 */
Question* QuestionHandler::getQuestion()
{

    return questions.at(questionNumber);
}

/**
 * @brief QuestionHandler::getQuestionNumber
 * @return
 */
int QuestionHandler::getQuestionNumber()
{
    return questionNumber;
}

/**
 * @brief QuestionHandler::makeQuestions
 */
void QuestionHandler::makeQuestions()
{


    // First question

    Question *q1 = new Question();
    q1->question = "Given a projectile launched from ground height, "
                   "a 40 degree launch angle and an initial velocity of 20 m/s, "
                   "how far does the projectile go before it hits the ground?";

    q1->answer = "40.16 m";

    q1->multipleChoiceAnswers.push_back("47.86 m");
    q1->multipleChoiceAnswers.push_back("81.6 m");
    q1->multipleChoiceAnswers.push_back("40.16 m");
    q1->multipleChoiceAnswers.push_back("33.69 m");

    q1->hints.push_back("hint: You probably used the x component of initial velocity to calculate time");
    q1->hints.push_back("hint: You probably used the whole initial velocity without taking its x component first");
    q1->hints.push_back("That is the correct answer, nice!");
    q1->hints.push_back("hint: You probably got the right time but multiplied it by the y component of initial velocity");



    // second question

    Question *q2 = new Question();

    q2->question = "Given a projectile launched from a 4 m height, "
                   "a 40 degree launch angle and an initial velocity of 20 m/s, "
                   "how far does the projectile go before it hits the ground?";

    q2->answer = "44.5 m";

    // choices have to map to hints

    // choices
    q2->multipleChoiceAnswers.push_back("51.57 m");
    q2->multipleChoiceAnswers.push_back("37.29 m");
    q2->multipleChoiceAnswers.push_back("58 m");
    q2->multipleChoiceAnswers.push_back("44.5 m");

    // hints
    q2->hints.push_back("hint: You probably used the x component of initial velocity to calculate time");
    q2->hints.push_back("hint: You probably got the right time but multiplied it by the y component of initial velocity");
    q2->hints.push_back("hint: You probably used the whole initial velocity without taking its x component first");
    q2->hints.push_back("That is the correct answer, nice!");


    // third question

    Question *q3 = new Question();

    q3->question = "Given a projectile that is launched from a 4 meter height on mars with a gravity of 3.72 m/s, "
                   "a 40 degree launch angle and an initial velocity of 20 m/s, how far does the projectile go "
                   "before hitting the ground?";

    q3->answer = "110.5 m";

    // choices
    q3->multipleChoiceAnswers.push_back("110.5 m");
    q3->multipleChoiceAnswers.push_back("44.5 m");
    q3->multipleChoiceAnswers.push_back("92.72 m");
    q3->multipleChoiceAnswers.push_back("130.1 m");

    // hints
    q3->hints.push_back("That is the correct answer, nice!");
    q3->hints.push_back("hint: You would be right on earth but you forgot to account for the difference in mars gravity");
    q3->hints.push_back("hint: You probably got the right time but multiplied it by the y component of initial velocity");
    q3->hints.push_back("hint: You probably used the x component of initial velocity to calculate time");

    //fourth question
    Question *q4 = new Question();

    q4->question = "Given a projectile that is launched from a height of 4 m, has a 0 degree launch angle, "
                   "and an initial velocity of 40 m/s, how far does the projectile go before hitting the ground?";

    q4->answer = "36.1 m";

    // choices
    q4->multipleChoiceAnswers.push_back("0 m");
    q4->multipleChoiceAnswers.push_back("-36.1 m");
    q4->multipleChoiceAnswers.push_back("36.1 m");
    q4->multipleChoiceAnswers.push_back("330 m");

    // hints
    q4->hints.push_back("hint: You probably got the right time but multiplied it by the y component of initial velocity");
    q4->hints.push_back("hint: Since we're launching it forward, it's going to have a positive value");
    q4->hints.push_back("That is the correct answer, nice!");
    q4->hints.push_back("hint: You probably used the x component of initial velocity to calculate time");

    //fifth question
    Question *q5 = new Question();

    q5->question = "Given a projectile that is launched from ground height goes a distance of 30m and took 3.5 seconds to hit the ground, "
                   "what was the angle of launch and initial velocity?";
    q5->answer = "63.46 degrees, 19.18 m/s";

    // choices
    q5->multipleChoiceAnswers.push_back("63.46 degrees, 38.42 m/s");
    q5->multipleChoiceAnswers.push_back("65.53 degrees, 8.57 m/s");
    q5->multipleChoiceAnswers.push_back("60.21 degrees, 17.17 m/s");
    q5->multipleChoiceAnswers.push_back("63.46 degrees, 19.18 m/s");

    // hints
    q5->hints.push_back("hint: You got the degrees right but it looks like you divided the y component by cos(theta) instead of sin(theta) to get initial velocity");

    q5->hints.push_back("hint: Looks like you got the x component of initial velocity but got stuck on how to get the degree and initial velocity,"
                        " try arranging v_0_x = v_0 * cos(theta) to v_0 = v_0_x/cos(theta) and v_0_y = v_0 * sin(theta) to  v_0 = v_0_y/sin(theta),"
                        " then setting them equal to each other, and remember that sin(theta)/cos(theta) is equal to tan(theta)");

    q5->hints.push_back("hint: Looks like you got the y component of initial velocity but got stuck on how to get the degree and initial velocity, "
                        "try arranging v_0_x = v_0 * cos(theta) to v_0 = v_0_x/cos(theta) and v_0_y = v_0 * sin(theta) to  v_0 = v_0_y/sin(theta), "
                        "then setting them equal to each other to get theta, and remember that sin(theta)/cos(theta) is equal to tan(theta)");

    q5->hints.push_back("That is the correct answer, nice!");

    //sixth question
    Question *q6 = new Question();

    q6->question = "Given a projectile that is launched from a 3 m height goes a distance of 30m and took 3.5 seconds to hit the ground, "
                   "what was the angle of launch and initial velocity?";
    q6->answer = "62.28 degrees, 18.42 m/s";

    // choices
    q6->multipleChoiceAnswers.push_back("61.21 degrees, 16.3 m/s");
    q6->multipleChoiceAnswers.push_back("62.28 degrees, 18.42 m/s");
    q6->multipleChoiceAnswers.push_back("66.53 degrees, 8.57 m/s");
    q6->multipleChoiceAnswers.push_back("62.28 degrees, 35.03 m/s");

    // hints

    q6->hints.push_back("hint: Looks like you got the y component of initial velocity but got stuck on how to get the degree and initial velocity, "
                        "try arranging v_0_x = v_0 * cos(theta) to v_0 = v_0_x/cos(theta) and v_0_y = v_0 * sin(theta) to  v_0 = v_0_y/sin(theta), "
                        "then setting them equal to each other to get theta, and remember that sin(theta)/cos(theta) is equal to tan(theta)");

    q6->hints.push_back("That is the correct answer, nice!");

    q6->hints.push_back("hint: Looks like you got the x component of initial velocity but got stuck on how to get the degree and initial velocity,"
                        " try arranging v_0_x = v_0 * cos(theta) to v_0 = v_0_x/cos(theta) and v_0_y = v_0 * sin(theta) to  v_0 = v_0_y/sin(theta),"
                        " then setting them equal to each other, and remember that sin(theta)/cos(theta) is equal to tan(theta)");

    q6->hints.push_back("hint: You got the degrees right but it looks like you divided the y component by cos(theta) instead of sin(theta) to get initial velocity");

    //seventh question
    Question *q7 = new Question();

    q7->question = "Given a projectile that is launched from ground height, "
                   "has a 90 degree launch angle and has an initial velocity of 30 m/s, "
                   "what is the maximum height that the projectile will achieve?";

    q7->answer = "45.9 m";

    // choices
    q7->multipleChoiceAnswers.push_back("45.9 m");
    q7->multipleChoiceAnswers.push_back("0 m");
    q7->multipleChoiceAnswers.push_back("183.6 m");
    q7->multipleChoiceAnswers.push_back("91.8 m");

    // hints
    q7->hints.push_back("That is the correct answer, nice!");
    q7->hints.push_back("hint: While calculating the y position you used the full time instead of ½ of the time, "
                        "which is where the highest y position will be at in the case of launching from ground");

    q7->hints.push_back("hint: You multiplied the y component of initial velocity with full time, "
                        "which does not account for gravity, use y equation and divide time in half "
                        "because that is where the peak is");

    q7->hints.push_back("hint: You multiplied the y component of initial velocity with half time, "
                        "which does not account for gravity, use y equation");


    //eigth question
    Question *q8 = new Question();

    q8->question = "Given a projectile that is launched from a height of 2 m, "
                   "has a 90 degree launch angle and has an initial velocity of 30 m/s, "
                   "what is the maximum height that the projectile will achieve?";

    q8->answer = "47.9 m";

    // choices
    q8->multipleChoiceAnswers.push_back("0 m");
    q8->multipleChoiceAnswers.push_back("45.9 m");
    q8->multipleChoiceAnswers.push_back("47.9 m");
    q8->multipleChoiceAnswers.push_back("91.8 m");

    // hints

    q8->hints.push_back("hint: While calculating the y position you used the full time "
                        "instead of ½ of the time from when the projectile returns to 2 m");

    q8->hints.push_back("hint: You did not take into account height while calculating or you did but used "
                        "the half the full time until it hit the ground instead of half the time until it "
                        "got back to the same height, 2m");

    q8->hints.push_back("That is the correct answer, nice!");

    q8->hints.push_back("hint: You multiplied the y component of initial velocity with half time,"
                        " which does not account for gravity, use y equation");

    //ninth question
    Question *q9 = new Question();

    q9->question = "Given a projectile that is launched from ground height, "
                   "has a 60 degree launch angle and has an initial velocity of 10 m/s, "
                   "what is the height of the projectile going to be after ¼ of the time it "
                   "takes to hit the ground?";

    q9->answer = "25.84 m";

    // choices
    q9->multipleChoiceAnswers.push_back("0 m");
    q9->multipleChoiceAnswers.push_back("34.45 m");
    q9->multipleChoiceAnswers.push_back("25.84 m");
    q9->multipleChoiceAnswers.push_back("31.13 m");

    // hints

    q9->hints.push_back("hint: While calculating the y position "
                        "you used the full time instead of ¼ of it to get y position at ¼  of time");

    q9->hints.push_back("hint: You multiplied the y component of initial velocity by the ¼ the time, "
                        "which does not account for gravity, use y equation, or you calculated the height "
                        "at ½ time instead of ¼");

    q9->hints.push_back("That is the correct answer, nice!");

    q9->hints.push_back("hint: You used initial velocity instead of the y component of initial velocity to calculate the y position");


    //tenth question
    Question *q10 = new Question();

    q10->question = "Given a projectile that is launched from ground height, has a 60 degree launch angle "
                    "and has an initial velocity of 10 m/s, what is the height of the projectile going "
                    "to be after ¾ of the time it takes to hit the ground?";

    q10->answer = "25.84 m";

    // choices
    q10->multipleChoiceAnswers.push_back("25.84 m");
    q10->multipleChoiceAnswers.push_back("0 m");
    q10->multipleChoiceAnswers.push_back("103.35 m");
    q10->multipleChoiceAnswers.push_back("41.74 m");

    // hints

    q10->hints.push_back("That is the correct answer, nice!");

    q10->hints.push_back("hint: While calculating the y position you used the full time instead of ¼ of it to get y position at ¼  of time");

    q10->hints.push_back("hint: You multiplied the y component of initial velocity by the 3/4 the time, which does not account for gravity, use y equation");

    q10->hints.push_back("hint: You used initial velocity instead of the y component of initial velocity to calculate the y position");


    // include question objects in the vector for all questions
    questions.push_back(q1);
    questions.push_back(q2);
    questions.push_back(q3);
    questions.push_back(q4);
    questions.push_back(q5);
    questions.push_back(q6);
    questions.push_back(q7);
    questions.push_back(q8);
    questions.push_back(q9);
    questions.push_back(q10);
}
