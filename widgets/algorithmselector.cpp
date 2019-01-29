#include "algorithmselector.hpp"

#include <utility>

#include <QDebug>

AlgorithmSelector::AlgorithmSelector(QWidget *parent)
    : QComboBox(parent)
{
    connect(
        this,
        static_cast<void (AlgorithmSelector::*)(int)>(&AlgorithmSelector::activated),
        this,
        &AlgorithmSelector::selectAlgorithm
    );
}

int AlgorithmSelector::getCount() const
{
    return m_algorithms.size();
}

bool AlgorithmSelector::isEmpty() const
{
    return m_algorithms.empty();
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

    // Update selection
    selectLastAlgorithm();

    emit algorithmAdded(m_algorithms.back().get());
}

void AlgorithmSelector::removeAlgorithm(int index)
{
    if (checkIndex(index)) {
        removeItem(index);
        m_algorithms.erase(m_algorithms.begin() + index);

        // Update selection
        selectLastAlgorithm();

        if (isEmpty()) {
            emit cleared();
        }
        emit algorithmRemoved();
    }
}

void AlgorithmSelector::selectFirstAlgorithm()
{
    if (!isEmpty()) {
        selectAlgorithm(0);
    }
}

void AlgorithmSelector::selectLastAlgorithm()
{
    if (!isEmpty()) {
        selectAlgorithm(getCount() - 1);
    }
}

void AlgorithmSelector::selectAlgorithm(int index)
{
    if (checkIndex(index)) {
        setCurrentIndex(index);

        emit algorithmSelected(m_algorithms[index].get());
    }
}

void AlgorithmSelector::clear()
{
    m_algorithms.clear();

    emit cleared();
}

bool AlgorithmSelector::checkIndex(int index) const
{
    if (index >= 0 && index < m_algorithms.size()) {
        return true;
    }

    return false;
}
