#include "algorithmwidget.hpp"

#include <QVBoxLayout>

#include "algorithmselector.hpp"
#include "parameterlistwidget.hpp"

AlgorithmWidget::AlgorithmWidget(QWidget *parent)
    : QWidget(parent)
{
    m_algorithmSelector = new AlgorithmSelector;
    m_parameterListWidget = new ParameterListWidget;

    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_algorithmSelector);
    m_layout->addWidget(m_parameterListWidget);

    setLayout(m_layout);

    connect(
        m_algorithmSelector,
        &AlgorithmSelector::algorithmSelected,
        this,
        &AlgorithmWidget::updateParameters
        );
}

int AlgorithmWidget::getCount() const
{
    return m_algorithmSelector->getCount();
}

Algorithm *AlgorithmWidget::getAlgorithm(int index) const
{
    return m_algorithmSelector->getAlgorithm(index);
}

Algorithm *AlgorithmWidget::getCurrentAlgorithm() const
{
    return m_algorithmSelector->getCurrentAlgorithm();
}

void AlgorithmWidget::addAlgorithm(Algorithm &algorithm)
{
    m_algorithmSelector->addAlgorithm(algorithm);
}

void AlgorithmWidget::removeAlgorithm(int index)
{
    m_algorithmSelector->removeAlgorithm(index);
}

void AlgorithmWidget::selectAlgorithm(int index)
{
    m_algorithmSelector->selectAlgorithm(index);
    updateParameters(m_algorithmSelector->getCurrentAlgorithm());
}

void AlgorithmWidget::updateParameters(Algorithm *algorithm)
{
    m_parameterListWidget->updateWith(*algorithm);
}
