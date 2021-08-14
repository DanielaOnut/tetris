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
#include <Game/SquareTexture.h>
#include <fstream>
#include <list>

class ShopListItem;

class Shop : public QWidget {
    Q_OBJECT

private:
    QLayout     * generalLayout    {nullptr};

    QListWidget * itemsList       {nullptr};
    std::list <ShopListItem *> purchasedItems;
public:
    Shop (QWidget * ) noexcept;

    void init () noexcept;

    void createComponents () noexcept;
    void alignComponents () noexcept;
    void addItem ( std::string const &, char const * , SquareTexture::TextureType) noexcept;
//    void adjustComponents() noexcept;
//    void styleComponents () noexcept;
    void connectComponents () noexcept;

    std::list <ShopListItem *> getPurchasedItemList () const noexcept {
        return this->purchasedItems;
    }

    static std::string verifyIfItemIsPurchased (const char *) noexcept;

    ~Shop () noexcept override;

signals:
    void itemPurchased (ShopListItem *);
    void itemEquipped ();
};

class ShopListItem : public QWidget {
    Q_OBJECT

private:
    QLayout * generalLayout {nullptr};
    QLabel  * itemNameLabel {nullptr};

    QPushButton  * coinButton   {nullptr};
    int itemPrice = 0;

    SquareTexture::TextureType textureType = SquareTexture::TextureType::STANDARD;

    bool itemIsEquipped = false;
public:
    explicit ShopListItem ( QWidget * pParent = nullptr ) noexcept : QWidget(pParent) { }

    void init () {
        this->createComponents();
        this->alignComponents();
        this->adjustComponents();
        this->styleComponents();
        this->connectComponents();
    }

    void setTextureType (SquareTexture::TextureType texture) noexcept {
        this->textureType = texture;
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
                SquareTexture::switchToTexture(SquareTexture::TextureType::STANDARD);
                this->itemIsEquipped = false;
                this->createEquipButton();
                emit this->itemEquipped();
            }
            else if (this->coinButton->text().contains("Equip")) {
                this->coinButton->setText("Equipped");
                this->coinButton->setMaximumWidth(80);
                SquareTexture::switchToTexture(this->textureType);
                this->itemIsEquipped = true;
                emit this->itemEquipped();
            }
            else
                emit this->itemPurchased(this);
        });
    }

    bool isItemEquipped () const noexcept {
        return this->itemIsEquipped;
    }

    void createEquipButton () {
        delete this->coinButton;
        this->coinButton = new QPushButton ("Equip", this);
        this->generalLayout->addWidget(this->coinButton);
        this->itemIsEquipped = false;
        this->adjustComponents();
        this->styleComponents();
        this->connectComponents();
    }

    void createEquippedButton () {
        delete this->coinButton;
        this->coinButton = new QPushButton ("Equipped", this);
        this->generalLayout->addWidget(this->coinButton);
        this->coinButton->setMaximumWidth(80);
        SquareTexture::switchToTexture(this->textureType);
        this->itemIsEquipped = true;
        this->styleComponents();
        this->connectComponents();
    }

    void setItemName ( const char * name ) noexcept {
        this->itemNameLabel->setText(name);
    }

    int getItemPrice() const {
        return itemPrice;
    }

    std::string getItemName () const {
        return this->itemNameLabel->text().toStdString();
    }

    void setPrice ( char const * price ) noexcept {
        this->coinButton->setText(price);
        this->itemPrice = atoi (price);
    }

    void setButton () noexcept {
        this->coinButton->setIcon(Util::getIcon("coin.png", 20, 20));
        this->coinButton->setIconSize(QSize (20, 20));
    }

    ~ShopListItem() noexcept override {
        this->generalLayout->removeWidget(this->itemNameLabel);
        this->generalLayout->removeWidget(this->coinButton);

        delete this->generalLayout;

        delete this->itemNameLabel;
        delete this->coinButton;
    }
signals:
    void itemPurchased (ShopListItem *);
    void itemEquipped ();
};

#endif //PROIECT_INBOX_H
