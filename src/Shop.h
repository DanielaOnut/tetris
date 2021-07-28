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
#include <iostream>
#include "Util.h"

class ShopListItem;

class Shop : public QWidget {
    Q_OBJECT

private:
    QLayout     * generalLayout    {nullptr};

    QListWidget * itemsList       {nullptr};
public:
    Shop (QWidget * ) noexcept;

    void init () noexcept;

    void createComponents () noexcept;
    void alignComponents () noexcept;
    void addItem ( std::string const &, char const * ) noexcept;
//    void adjustComponents() noexcept;
//    void styleComponents () noexcept;
    void connectComponents () noexcept;

    ~Shop () noexcept override;

signals:
    void itemPurchased (ShopListItem *);
    void itemEquipped();
    void itemUnequipped();
};

class ShopListItem : public QWidget {
    Q_OBJECT

private:
    QLayout * generalLayout {nullptr};
    QLabel  * itemNameLabel {nullptr};

    QPushButton  * coinButton   {nullptr};
    int itemPrice = 0;

public:
    explicit ShopListItem ( QWidget * pParent = nullptr ) noexcept : QWidget(pParent) { }

    void init () {
        this->createComponents();
        this->alignComponents();
        this->adjustComponents();
        this->styleComponents();
        this->connectComponents();
    }

    void createComponents () {
        this->generalLayout = new QHBoxLayout ();

        this->itemNameLabel = new QLabel (this);
        this->coinButton = new QPushButton (this);
    }

    void alignComponents () {
        this->setLayout(this->generalLayout);

        this->generalLayout->addWidget(this->itemNameLabel);
        this->generalLayout->addWidget(this->coinButton);

        this->generalLayout->setAlignment(this->itemNameLabel, Qt::AlignLeft);
        this->generalLayout->setAlignment(Qt::AlignTop);

//        this->coinButton->raise();
    }

    void adjustComponents () {
        this->coinButton->setMaximumWidth(60);
        this->coinButton->setFixedHeight(30);
    }

    void styleComponents () {
        this->coinButton->setStyleSheet ("QPushButton{\n"
                                         "    border-color: #96a2c3;\n"
                                         "    background-color: #f1f1f1;\n"
                                         "    border-width: 2px;\n"
                                         "    border-radius: 3px;\n"
                                         "    border-style: outset;\n"
                                         "    font-family: Arial, Helvetica, sans-serif;\n"
                                         "    margin: 3px;\n"
                                         "};");
    }

    void connectComponents () {
        connect (this->coinButton, & QPushButton::clicked, [this] {
            if (this->coinButton->text().contains("Equipped")) {
                this->coinButton->setText("Unequipped");
                this->coinButton->setMaximumWidth(100);
                emit this->itemUnequipped();
            }
            else if (this->coinButton->text().contains("Equip")) {
                this->coinButton->setText("Equipped");
                this->coinButton->setMaximumWidth(80);
                emit this->itemEquipped();
            }
            else if (this->coinButton->text().contains("Unequipped")) {
                this->coinButton->setText("Equipped");
                this->coinButton->setMaximumWidth(80);
                emit this->itemEquipped();
            }
            else
                emit this->itemPurchased(this);
        });
    }

    void createEquipButton () {
        delete this->coinButton;
        this->coinButton = new QPushButton ("Equip", this);
        this->generalLayout->addWidget(this->coinButton);
        this->adjustComponents();
        this->styleComponents();
        this->connectComponents();
    }

    void setItemName ( std::string const & name ) noexcept {
        this->itemNameLabel->setText(name.c_str());
    }

    int getItemPrice() const {
        return itemPrice;
    }

    void setPrice ( char const * price ) noexcept {
        this->coinButton->setText(price);
        this->itemPrice = atoi (price);
    }

    void setButton () noexcept {
        this->coinButton->setIcon(Util::getIcon("coin.png", 20, 20));
        this->coinButton->setIconSize(QSize (20, 20));
    }
signals:
    void itemPurchased (ShopListItem *);
    void itemEquipped();
    void itemUnequipped();
};

#endif //PROIECT_INBOX_H
