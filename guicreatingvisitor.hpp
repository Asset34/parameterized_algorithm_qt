#ifndef GUICREATINGVISITOR_HPP
#define GUICREATINGVISITOR_HPP

#include <vector>

#include "parameterized_algorithm_base/algorithm.hpp"
#include "parameterized_algorithm_base/parametervisitor.hpp"
#include "parameterized_algorithm_base/Parameters/parameter.hpp"

class QWidget;
class QFormLayout;

class GuiCreatingVisitor : public ParameterVisitor
{
public:
    explicit GuiCreatingVisitor(QWidget *processedWidget);

    void update(const std::vector<Parameter*> &parameters);
    void update(Algorithm &algorithm);

    virtual void visit(IntParameter  &p) override;
    virtual void visit(RealParameter &p) override;
    virtual void visit(FlagParameter &p) override;

private:
    void clear();

    QWidget *m_processedWidget;
    QFormLayout *m_layout;

};

#endif // GUICREATINGVISITOR_HPP
