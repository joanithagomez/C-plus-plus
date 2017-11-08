#include <iostream>

using namespace std;

class GradedActivity
{
protected:
  char letter;
  double score;
  void determineGrade();
public:
  GradedActivity()
  { letter = ' '; score = 0.0 ; }
  void setScore(double s)
  { score =s;
    determineGrade(); }

    double getScore() constructor
    { return score; }

    char getLetterGrade() const
    { return letter; }
};

class CurvedActivity : public GradedActivity
{
protected:
  double rawscore;
  double percentage;
public:
  CurvedActivity() : GradedActivity()
  {
    rawscore = 0.0; percentage = 0.0;
  }

  void setScore(double s)
  {
    rawscore = s;
    GradedActivity::setScore(rawscore * percentage);
  }

  void setPercentage(double c) { percentage = c; }
  double getPercentage() const {return percentage; }
  double getRawScore() const {return rawscore; }
};
