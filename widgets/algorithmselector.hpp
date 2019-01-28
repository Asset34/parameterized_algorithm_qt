#ifndef ALGORITHMSELECTOR_HPP
#define ALGORITHMSELECTOR_HPP

#include <QComboBox>

#include <QList>

#include "../core/algorithm.hpp"

class AlgorithmSelector : public QComboBox
{
    Q_OBJECT

public:
    explicit AlgorithmSelector(QWidget *parent = nullptr);

    int getCount() const;

    Algorithm *getAlgorithm(int index) const;
    Algorithm *getCurrentAlgorithm() const;

    void addAlgorithm(Algorithm &algorithm);
    void removeAlgorithm(int index);

public slots:
    void selectAlgorithm(int index);

private:
    bool checkIndex(int index) const;

    QList<Algorithm*> m_algorithms;

signals:
    void algorithmSelected(Algorithm *Algorithm);

};

#endif // ALGORITHMSELECTOR_HPP
