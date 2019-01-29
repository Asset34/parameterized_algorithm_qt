#ifndef ALGORITHMWIDGET_HPP
#define ALGORITHMWIDGET_HPP

#include <QWidget>

#include <memory>

#include "../core/algorithm.hpp"

class QVBoxLayout;
class AlgorithmSelector;
class ParameterListWidget;

class AlgorithmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlgorithmWidget(QWidget *parent = nullptr);

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
    QVBoxLayout *m_layout;

    AlgorithmSelector *m_algorithmSelector;
    ParameterListWidget *m_parameterListWidget;

private slots:
    void updateParameters(Algorithm &algorithm);

signals:
    void algorithmAdded(Algorithm &algorithm);
    void algorithmRemoved();
    void algorithmSelected(Algorithm &algorithm);

    void cleared();

};

#endif // ALGORITHMWIDGET_HPP
