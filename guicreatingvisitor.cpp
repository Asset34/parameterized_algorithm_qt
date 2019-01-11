#include "guicreatingvisitor.hpp"

#include <QWidget>
#include <QFormLayout>

#include <QSpinBox>
#include <QLineEdit>
#include <QCheckBox>

#include <QDoubleValidator>

GuiCreatingVisitor::GuiCreatingVisitor(QWidget *processedWidget)
    : m_processedWidget(processedWidget)
{
    m_layout = new QFormLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);

    m_processedWidget->setLayout(m_layout);
}

void GuiCreatingVisitor::updateWith(const std::vector<Parameter*> &parameters)
{
    clear();

    for (Parameter *p : parameters) {
        p->accept(*this);
    }
}

void GuiCreatingVisitor::updateWith(Algorithm &algorithm)
{
     updateWith(algorithm.getParameters());
}

void GuiCreatingVisitor::visit(IntParameter &p)
{
    // Create appropriate box
    QSpinBox *box = new QSpinBox;
    box->setMinimum(p.getMin());
    box->setMaximum(p.getMax());
    box->setValue(p);

    // Connect created box with parameter
    QWidget::connect(
        box,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        [&p](int value){
            p = value;
    });

    // Add box to layout
    m_layout->addRow(QString::fromStdString(p.getName()) + ":", box);
}

void GuiCreatingVisitor::visit(RealParameter &p)
{
    // Create appropriate box
    QLineEdit *box = new QLineEdit;
    box->setText(QString::number(p));

    // Create validator
    QDoubleValidator *validator = new QDoubleValidator(p.getMin(), p.getMax(), 100, box);
    box->setValidator(validator);

    // Connect created box to parameter
    QWidget::connect(
        box,
        &QLineEdit::textChanged,
        [&p](const QString &text){
            bool check;
            double value = text.toDouble(&check);
            if (check) {
                p = value;
            }
    });

    // Add box to layout
    m_layout->addRow(QString::fromStdString(p.getName()) + ":", box);
}

void GuiCreatingVisitor::visit(FlagParameter &p)
{
    // Create appropriate box
    QCheckBox *box = new QCheckBox;
    box->setChecked(p);

    // Connect creaed box to parameter
    QWidget::connect(
        box,
        &QCheckBox::clicked,
        [&p](bool checked){
            p = checked;
    }
    );

    // Add box to layoyt
    m_layout->addRow(QString::fromStdString(p.getName()) + ":", box);
}

void GuiCreatingVisitor::clear()
{
    QLayoutItem *item;
    while (m_layout->count()) {
        item = m_layout->takeAt(0);

        delete item->widget();
        delete item;
    }
}
