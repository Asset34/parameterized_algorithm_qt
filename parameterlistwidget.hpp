#ifndef PARAMETERLISTWIDGET_HPP
#define PARAMETERLISTWIDGET_HPP

#include <QWidget>

#include "guicreatingvisitor.hpp"

class ParameterListWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ParameterListWidget(QWidget *parent = nullptr);

    void updateParameters(const std::vector<Parameter*> &parameters);
    void updateParameters(Algorithm &algorithm);

private:
    GuiCreatingVisitor m_visitor;

};

#endif // PARAMETERLISTWIDGET_HPP
