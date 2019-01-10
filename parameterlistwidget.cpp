#include "parameterlistwidget.hpp"

ParameterListWidget::ParameterListWidget(QWidget *parent)
    : QWidget(parent),
      m_visitor(this)
{
}

void ParameterListWidget::updateParameters(const std::vector<Parameter*> &parameters)
{
    m_visitor.update(parameters);
}

void ParameterListWidget::updateParameters(Algorithm &algorithm)
{
    m_visitor.update(algorithm);
}
