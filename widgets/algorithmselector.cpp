#include "algorithmselector.hpp"

#include <utility>

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
        return m_algorithms[index].get();
    }

    return nullptr;
}

Algorithm *AlgorithmSelector::getCurrentAlgorithm() const
{
    int index = currentIndex();
    return getAlgorithm(index);
}

void AlgorithmSelector::addAlgorithm(std::unique_ptr<Algorithm> algorithm)
{
    addItem(QString::fromStdString(algorithm.get()->getName()));
    m_algorithms.push_back(std::move(algorithm));

    selectAlgorithm(getCount() - 1);
}

void AlgorithmSelector::removeAlgorithm(int index)
{
    if (checkIndex(index)) {
        m_algorithms.erase(m_algorithms.begin() + index);
    }
}

void AlgorithmSelector::selectAlgorithm(int index)
{
    if (checkIndex(index)) {
        setCurrentIndex(index);

        emit algorithmSelected(m_algorithms[index].get());
    }
}

bool AlgorithmSelector::checkIndex(int index) const
{
    if (index >= 0 && index < m_algorithms.size()) {
        return true;
    }

    return false;
}
