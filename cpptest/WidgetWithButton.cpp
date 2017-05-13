#include "WidgetWithButton.h"
#include "ui_WidgetWithButton.h"

WidgetWithButton::WidgetWithButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetWithButton)
{
    ui->setupUi(this);
}

WidgetWithButton::~WidgetWithButton()
{
    delete ui;
}
