#ifndef PARAMETERLISTWIDGET_HPP
#define PARAMETERLISTWIDGET_HPP

#include <QWidget>

#include "guicreatingvisitor.hpp"

class ParameterListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ParameterListWidget(QWidget *parent = nullptr);

    void updateWith(const std::vector<Parameter*> &parameters);
    void updateWith(Algorithm &algorithm);

public slots:
    void clear();

private:
    GuiCreatingVisitor m_visitor;

};

#endif // PARAMETERLISTWIDGET_HPP
