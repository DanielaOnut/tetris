
#include "Shop.h"
#include <QLayout>

Shop::Shop (QWidget * parent) noexcept : QWidget(parent) {

}

void Shop::init() noexcept {
    this->createComponents();
    this->alignComponents();
//    this->adjustComponents();
//    this->styleComponents();
//    this->connectComponents();
    this->addItem("Rainbow  Square", "200", SquareTexture::TextureType::RAINBOW);
    this->addItem("Black Square", "150", SquareTexture::TextureType::BLACK);
    this->addItem("White Square", "80", SquareTexture::TextureType::WHITE);
    this->addItem("Brown Square", "75", SquareTexture::TextureType::BROWN);
}

void Shop::addItem(const std::string & item, const char * price, SquareTexture::TextureType type) noexcept {
    auto container = new QListWidgetItem (this->itemsList);

    auto pItem =  new ShopListItem(this);

    pItem->init();
    pItem->setItemName( item );
    pItem->setPrice(price);
    pItem->setButton();
    pItem->setTextureType(type);

    if (this->verifyIfItemIsPurchased(item.c_str())) {
        this->purchasedItems.push_back(pItem);
        pItem->createEquipButton();
    }

    container->setSizeHint(pItem->sizeHint());

    this->itemsList->setItemWidget(container, pItem);

    auto * pParent = dynamic_cast <Menu *> (this->parent());
    connect ( pItem, & ShopListItem::itemPurchased, [this, pParent](ShopListItem * pShopItem){
        if (pParent != nullptr)
            if (pShopItem->getItemPrice() <= pParent->getCoinsNumber())
                this->purchasedItems.push_back(pShopItem);
        emit this->itemPurchased (pShopItem);
    } );
}

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

void Shop::connectComponents () noexcept { }

bool Shop::verifyIfItemIsPurchased(const char * name) noexcept {
    std::fstream itemsFile;
    itemsFile.open("PurchasedItems.txt", std::ios::in);
    std::string buffer;
    std::getline (itemsFile, buffer);
    while (buffer.c_str()[0]) {
        if (! strcmp (buffer.c_str(), name))
            return true;
        std::getline (itemsFile, buffer);
    }
    return false;
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
