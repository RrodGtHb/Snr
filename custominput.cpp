#include "custominput.h"
#include "ui_custominput.h"
#include "inventorychange.h"
#include <QStyle>

CustomInput::CustomInput(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CustomInput)
{
    ui->setupUi(this);
    //QPixmap pixFruits (":/ImagesAndIcons/fru_fin.png");
    //ui->labelFruit->setPixmap(pixFruits);
   // ui->labelFruit->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

    //QPixmap pixVegetables (":/ImagesAndIcons/vegg_fin.png");
    //ui->labelVegetable->setPixmap(pixVegetables);
    //ui->labelVegetable->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

        //This is an example of how to make a button clickable with an image
        QPixmap pixmap (":/ImagesAndIcons/fru_fin.png");
        QIcon ButtonIconFruit(pixmap);
        ui->btn_fruits_input->setIcon(ButtonIconFruit);
        ui->btn_fruits_input->setIconSize(pixmap.rect().size());

        QPixmap pixmap1 (":/ImagesAndIcons/vegg_fin.png");
        QIcon ButtonIconVegetable(pixmap1);
        ui->btn_vegetables_input->setIcon(ButtonIconVegetable);
        ui->btn_vegetables_input->setIconSize(pixmap.rect().size());

}

CustomInput::~CustomInput()
{
    delete ui;
}

void CustomInput::on_btn_vegetables_input_clicked()
{
    //vegetables
    InventoryChange *inventoryChange = new InventoryChange;
    inventoryChange->setModal(true);
    inventoryChange->exec();
}

void CustomInput::on_btn_fruits_input_clicked()
{
    //fruits
    InventoryChange *inventoryChange = new InventoryChange;
    inventoryChange->setModal(true);
    inventoryChange->exec();



}
