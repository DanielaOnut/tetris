//
// Created by vladl on 3/20/2021.
//

#include "Popup.h"
#include "Util.h"

Popup::Popup(QWidget *parent, QPoint p, QSize s) noexcept :
    QWidget(parent),
    x (p.x()),
    y (p.y()),
    width (s.width()),
    height (s.height()) {
    this->init();
}

void Popup::init() noexcept {
    this->createComponents();
    this->alignComponents();
    this->adjustComponents();
    this->styleComponents();
    this->connectComponents();

    this->show();
}

void Popup::createComponents() noexcept {
    this->generalLayout = new QVBoxLayout(nullptr);
    this->buttonsLayout = new QHBoxLayout(nullptr);

    this->closeButton = new QPushButton(this);
}

void Popup::alignComponents() noexcept {
    this->setLayout(this->generalLayout);
    this->generalLayout->addItem(this->buttonsLayout);

    this->buttonsLayout->addWidget(this->closeButton);
    
    this->generalLayout->setAlignment(this->buttonsLayout, Qt::AlignTop);
    this->buttonsLayout->setAlignment(this->closeButton, Qt::AlignRight);
}

void Popup::setContent ( QWidget * widget ) noexcept {
    this->popupContent = widget;
    this->popupContent->setParent(this);

    this->generalLayout->addWidget(this->popupContent);
}

void Popup::adjustComponents() noexcept {
    this->setGeometry( this->x, this->y, this->width, this->height );

    this->closeButton->setMaximumWidth(20);
    this->closeButton->setMinimumWidth(20);
}

void Popup::styleComponents() noexcept {
    this->setStyleSheet("QWidget{\n"
                        "background-color: #6692c4;}");
    auto buttonStyle = Util::getStyle("GeneralButton.css");

    this->closeButton->setStyleSheet(buttonStyle.c_str());

    this->closeButton->setIcon(Util::getIcon("close.png", 20, 20));
    this->closeButton->setIconSize(QSize (20, 20));
}

void Popup::connectComponents() noexcept {
    connect ( this->closeButton, & QPushButton::clicked, [this](){emit this->close();} );
}

Popup::~Popup() noexcept {
    this->generalLayout->removeItem(this->buttonsLayout);
    if ( this->popupContent != nullptr ) {
        this->generalLayout->removeWidget(this->popupContent);
        delete this->popupContent;
    }

    this->buttonsLayout->removeWidget(this->closeButton);

    delete this->closeButton;

    delete this->generalLayout;
    delete this->buttonsLayout;
}

#include <QStyleOption>
#include <QPainter>
void Popup::paintEvent(QPaintEvent * event ) noexcept {
    QStyleOption option;
    option.initFrom( this );
    QPainter painter ( this );

    this->style()->drawPrimitive( QStyle::PE_Widget, & option, & painter, this );

    QWidget::paintEvent( event );
}
