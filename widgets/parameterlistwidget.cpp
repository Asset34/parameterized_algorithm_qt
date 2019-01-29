#include "parameterlistwidget.hpp"

ParameterListWidget::ParameterListWidget(QWidget *parent)
    : QWidget(parent),
      m_visitor(this)
{
}

void ParameterListWidget::updateWith(const std::vector<Parameter*> &parameters)
{
    m_visitor.updateWith(parameters);
}

void ParameterListWidget::updateWith(Algorithm &algorithm)
{
    m_visitor.updateWith(algorithm);
}

void ParameterListWidget::clear()
{
    m_visitor.clear();
}
