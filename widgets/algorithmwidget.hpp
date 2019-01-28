#ifndef ALGORITHMWIDGET_HPP
#define ALGORITHMWIDGET_HPP

#include <QWidget>

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

    Algorithm *getAlgorithm(int index) const;
    Algorithm *getCurrentAlgorithm() const;

    void addAlgorithm(Algorithm &algorithm);
    void removeAlgorithm(int index);

public slots:
    void selectAlgorithm(int index);

private:
    QVBoxLayout *m_layout;

    AlgorithmSelector *m_algorithmSelector;
    ParameterListWidget *m_parameterListWidget;

private slots:
    void updateParameters(Algorithm *algorithm);

signals:
    void algorithmSelected(Algorithm *algorithm);

};

#endif // ALGORITHMWIDGET_HPP
