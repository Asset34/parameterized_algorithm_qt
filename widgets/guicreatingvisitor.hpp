#ifndef GUICREATINGVISITOR_HPP
#define GUICREATINGVISITOR_HPP

#include <vector>

#include "../core/algorithm.hpp"
#include "../core/parametervisitor.hpp"

class QWidget;
class QFormLayout;

class GuiCreatingVisitor : public ParameterVisitor
{
public:
    explicit GuiCreatingVisitor(QWidget *processedWidget);

    void updateWith(const std::vector<Parameter*> &parameters);
    void updateWith(Algorithm &algorithm);

    void clear();

    virtual void visit(IntParameter  &p) override;
    virtual void visit(RealParameter &p) override;
    virtual void visit(FlagParameter &p) override;

private:

    QWidget *m_processedWidget;
    QFormLayout *m_layout;

};

#endif // GUICREATINGVISITOR_HPP
