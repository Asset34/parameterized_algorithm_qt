#include "algorithmselector.hpp"

AlgorithmSelector::AlgorithmSelector(QWidget *parent)
    : QComboBox(parent)
{
    connect(
        this,
        static_cast<void (AlgorithmSelector::*)(int)>(&AlgorithmSelector::currentIndexChanged),
        this,
        &AlgorithmSelector::selectAlgorithm
                );
}

int AlgorithmSelector::getCount() const
{
    return m_algorithms.size();
}

Algorithm *AlgorithmSelector::getAlgorithm(int index) const
{
    if (checkIndex(index)) {
        return m_algorithms[index];
    }

    return nullptr;
}

Algorithm *AlgorithmSelector::getCurrentAlgorithm() const
{
    int index = currentIndex();
    return getAlgorithm(index);
}

void AlgorithmSelector::addAlgorithm(Algorithm &algorithm)
{
    m_algorithms.push_back(&algorithm);
    addItem(QString::fromStdString(algorithm.getName()));
}

void AlgorithmSelector::removeAlgorithm(Algorithm &algorithm)
{
    m_algorithms.removeOne(&algorithm);
}

void AlgorithmSelector::removeAlgorithm(int index)
{
    if (checkIndex(index)) {
        m_algorithms.removeAt(index);
    }
}

void AlgorithmSelector::selectAlgorithm(int index)
{
    if (checkIndex(index)) {
        setCurrentIndex(index);

        emit algorithmSelected(m_algorithms[index]);
    }
}

bool AlgorithmSelector::checkIndex(int index) const
{
    if (index >= 0 && index < m_algorithms.size()) {
        return true;
    }

    return false;
}
