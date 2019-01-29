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
    connect(
        m_algorithmSelector,
        &AlgorithmSelector::cleared,
        m_parameterListWidget,
        &ParameterListWidget::clear
        );
    connect(
        m_algorithmSelector,
        &AlgorithmSelector::cleared,
        this,
        &AlgorithmWidget::cleared
        );
    connect(
        m_algorithmSelector,
        &AlgorithmSelector::algorithmAdded,
        this,
        &AlgorithmWidget::algorithmAdded
        );
    connect(
        m_algorithmSelector,
        &AlgorithmSelector::algorithmRemoved,
        this,
        &AlgorithmWidget::algorithmRemoved
        );
    connect(
        m_algorithmSelector,
        &AlgorithmSelector::algorithmSelected,
        this,
        &AlgorithmWidget::algorithmSelected
        );
}

int AlgorithmWidget::getCount() const
{
    return m_algorithmSelector->getCount();
}

bool AlgorithmWidget::isEmpty() const
{
    return m_algorithmSelector->isEmpty();
}

Algorithm &AlgorithmWidget::getAlgorithm(int index) const
{
    return m_algorithmSelector->getAlgorithm(index);
}

Algorithm &AlgorithmWidget::getCurrentAlgorithm() const
{
    return m_algorithmSelector->getCurrentAlgorithm();
}

Algorithm &AlgorithmWidget::getFirstAlgorithm() const
{
    return m_algorithmSelector->getFirstAlgorithm();
}

Algorithm &AlgorithmWidget::getLastAlgorithm() const
{
    return m_algorithmSelector->getLastAlgorithm();
}

void AlgorithmWidget::addAlgorithm(std::unique_ptr<Algorithm> algorithm)
{
    m_algorithmSelector->addAlgorithm(std::move(algorithm));
}

void AlgorithmWidget::removeAlgorithm(int index)
{
    m_algorithmSelector->removeAlgorithm(index);
}

void AlgorithmWidget::selectFirstAlgorithm()
{
    m_algorithmSelector->selectFirstAlgorithm();
}

void AlgorithmWidget::selectLastAlgorithm()
{
    m_algorithmSelector->selectLastAlgorithm();
}

void AlgorithmWidget::selectAlgorithm(int index)
{
    m_algorithmSelector->selectAlgorithm(index);
    updateParameters(m_algorithmSelector->getCurrentAlgorithm());
}

void AlgorithmWidget::clear()
{
    m_algorithmSelector->clear();
}

void AlgorithmWidget::updateParameters(Algorithm &algorithm)
{
    m_parameterListWidget->updateWith(algorithm);
}
