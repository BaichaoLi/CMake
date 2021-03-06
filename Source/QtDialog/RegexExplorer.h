/* Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
   file Copyright.txt or https://cmake.org/licensing for details.  */
#ifndef RegexExplorer_h
#define RegexExplorer_h

#include <QDialog>
#include <cmsys/RegularExpression.hxx>
#include <string>

#include "ui_RegexExplorer.h"

class QString;
class QWidget;

class RegexExplorer : public QDialog, public Ui::RegexExplorer
{
  Q_OBJECT
public:
  RegexExplorer(QWidget* p);

private slots:
  void on_regularExpression_textChanged(const QString& text);
  void on_inputText_textChanged();
  void on_matchNumber_currentIndexChanged(int index);

private:
  static void setStatusColor(QWidget* widget, bool successful);
  static bool stripEscapes(std::string& regex);

  void clearMatch();

  cmsys::RegularExpression m_regexParser;
  std::string m_text;
  std::string m_regex;
  bool m_matched;
};

#endif
