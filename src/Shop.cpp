
#include "Shop.h"
#include <QLayout>

Shop::Shop (QWidget * parent) noexcept : QWidget(parent) {

}

void Shop::init() noexcept {
    this->createComponents();
    this->alignComponents();
//    this->adjustComponents();
//    this->styleComponents();
    this->connectComponents();
    this->addItem("Rainbow Square", "100");
    this->addItem("Black Square", "250");
}

void Shop::addItem(const std::string & item, const char * price) noexcept {
//    auto container = new QListWidgetItem (this->itemsList);
//    this->itemsList->addItem(container);

//    auto * parent = dynamic_cast <Menu *> (this->parent());

    auto container = new QListWidgetItem (this->itemsList);

    auto pItem =  new ShopListItem(this);

    pItem->init();
    pItem->setItemName( item );
    pItem->setPrice(price);
    pItem->setButton();

    container->setSizeHint(pItem->sizeHint());

    this->itemsList->setItemWidget(container, pItem);

//
//

//    auto widget = new ShopListItem(this);
//    widget->init();
//    widget->setItemName(item);
//    widget->setPrice(price);
//    widget->setButton();

//    this->itemsList->setItemWidget(container, widget);
//    this->itemsList->addItem(container);



    connect ( pItem, & ShopListItem::itemPurchased, [this](ShopListItem * pShopItem){
        emit this->itemPurchased (pShopItem);
    } );
}

QPushButton * pButton;
void Shop::createComponents() noexcept {
    this->generalLayout = new QVBoxLayout (nullptr);
    this->itemsList = new QListWidget (this);
}

void Shop::alignComponents() noexcept {
    this->setLayout(this->generalLayout);
    this->generalLayout->addWidget(this->itemsList);

    this->itemsList->setSelectionMode(QAbstractItemView::NoSelection);
    this->itemsList->setSelectionBehavior(QAbstractItemView::SelectItems);
    this->itemsList->setSelectionRectVisible(false);
}

void Shop::connectComponents () noexcept {
//    connect (dynamic_cast <ShopListItem *> )


}

Shop::~Shop () noexcept {
    for (int i = this->itemsList->count() - 1;i >= 0;i--) {
        auto container = this->itemsList->item(i);
        auto widget = this->itemsList->itemWidget(container);
        this->itemsList->removeItemWidget(container);
        delete widget;
        delete container;
    }

    this->generalLayout->removeWidget(this->itemsList);

    delete this->itemsList;
    delete this->generalLayout;
}
