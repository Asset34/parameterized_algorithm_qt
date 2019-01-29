#ifndef ALGORITHMSELECTOR_HPP
#define ALGORITHMSELECTOR_HPP

#include <QComboBox>

#include <vector>
#include <memory>

#include "../core/algorithm.hpp"

class AlgorithmSelector : public QComboBox
{
    Q_OBJECT

public:
    explicit AlgorithmSelector(QWidget *parent = nullptr);

    int getCount() const;
    bool isEmpty() const;

    Algorithm *getAlgorithm(int index) const;
    Algorithm *getCurrentAlgorithm() const;

    void addAlgorithm(std::unique_ptr<Algorithm> algorithm);
    void removeAlgorithm(int index);
    void clear();

public slots:
    void selectFirstAlgorithm();
    void selectLastAlgorithm();
    void selectAlgorithm(int index);

private:
    bool checkIndex(int index) const;

    std::vector< std::unique_ptr<Algorithm> > m_algorithms;

signals:
    void algorithmAdded(Algorithm *algorithm);
    void algorithmRemoved();
    void algorithmSelected(Algorithm *algorithm);

    void cleared();

};

#endif // ALGORITHMSELECTOR_HPP
