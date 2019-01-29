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

    Algorithm &getAlgorithm(int index) const;
    Algorithm &getCurrentAlgorithm() const;
    Algorithm &getFirstAlgorithm() const;
    Algorithm &getLastAlgorithm() const;

    void addAlgorithm(std::unique_ptr<Algorithm> algorithm);
    void removeAlgorithm(int index);

public slots:
    void selectFirstAlgorithm();
    void selectLastAlgorithm();
    void selectAlgorithm(int index);

    void clear();

private:
    std::vector< std::unique_ptr<Algorithm> > m_algorithms;

signals:
    void algorithmAdded(Algorithm &algorithm);
    void algorithmRemoved();
    void algorithmSelected(Algorithm &algorithm);

    void cleared();

};

#endif // ALGORITHMSELECTOR_HPP
