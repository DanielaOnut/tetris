//
// Created by danie on 20.03.2021.
//

#ifndef PROIECT_SHOP_H
#define PROIECT_SHOP_H

#include <Popup.h>
#include <Menu.h>

#include <QWidget>
#include <QListWidget>
#include <QLabel>
#include "Util.h"

class Shop : public QWidget {
private:
    QLayout     * generalLayout    {nullptr};

    QListWidget * itemsList       {nullptr};
public:
    Shop (QWidget * ) noexcept;

    void init () noexcept;

    void createComponents () noexcept;
    void alignComponents () noexcept;
    void addItem ( std::string const &, std::string const & ) noexcept;
//    void adjustComponents() noexcept;
//    void styleComponents () noexcept;
//    void connectComponents () noexcept;

    ~Shop () noexcept;
};

class ShopListItem : public QWidget {
Q_OBJECT

private:
    QLayout * generalLayout {nullptr};
    QLabel  * itemNameLabel {nullptr};
    QLabel  * priceLabel  {nullptr};

    QPushButton  * coinButton   {nullptr};

public:
    explicit ShopListItem ( QWidget * pParent = nullptr ) noexcept : QWidget(nullptr) { }

    void init () {
        this->createComponents();
        this->alignComponents();
        this->adjustComponents();
        this->styleComponents();
        this->connectComponents();
    }

    void createComponents () {
        this->generalLayout = new QHBoxLayout (nullptr);

        this->itemNameLabel = new QLabel (this);
        this->priceLabel = new QLabel (this);
        this->coinButton = new QPushButton (this);
    }

    void alignComponents () {
        this->setLayout(this->generalLayout);

        this->generalLayout->addWidget(this->itemNameLabel);
        this->generalLayout->addWidget(this->priceLabel);
        this->generalLayout->addWidget(this->coinButton);

        this->itemNameLabel->setAlignment(Qt::AlignLeft);
        this->priceLabel->setAlignment(Qt::AlignRight);
        this->generalLayout->setAlignment(Qt::AlignTop);
    }

    void adjustComponents () {
        this->coinButton->setMaximumWidth(20);
        this->coinButton->setMinimumWidth(20);
        this->coinButton->setFixedHeight(20);
    }

    void styleComponents () {
        this->coinButton->setStyleSheet ("QPushButton {\n"
                                         "    border-color: #96a2c3;\n"
                                         "    background-color: #f1f1f1;\n"
                                         "    border-width: 2px;\n"
                                         "    border-radius: 3px;\n"
                                         "    border-style: outset;\n"
                                         "    margin: 3px;\n"
                                         "}");
    }

    void connectComponents () {

    }

    void setItemName ( std::string const & name ) noexcept {
        this->itemNameLabel->setText(name.c_str());
    }

    void setPrice ( std::string const & price ) noexcept {
        this->priceLabel->setText(price.c_str());
    }

    void setButton () noexcept {
        this->coinButton->setIcon(Util::getIcon("coin.png", 20, 20));
        this->coinButton->setIconSize(QSize (20, 20));
    }
};

#endif //PROIECT_INBOX_H
