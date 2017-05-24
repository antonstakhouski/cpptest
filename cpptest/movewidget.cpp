#include "movewidget.h"

MoveLeft::MoveLeft(int _btnWidth, int _btnHeight, int _trickyOffset):
    MoveWidget(_btnWidth, _btnHeight, _trickyOffset)
{

}

MoveRight::MoveRight(int _btnWidth, int _btnHeight, int _trickyOffset):
    MoveWidget(_btnWidth, _btnHeight, _trickyOffset)
{

}

MoveUp::MoveUp(int _btnWidth, int _btnHeight, int _trickyOffset):
    MoveWidget(_btnWidth, _btnHeight, _trickyOffset)
{

}

MoveDown::MoveDown(int _btnWidth, int _btnHeight, int _trickyOffset):
    MoveWidget(_btnWidth, _btnHeight, _trickyOffset)
{

}

MoveTopLeft::MoveTopLeft(int _btnWidth, int _btnHeight, int _trickyOffset):
    MoveWidget(_btnWidth, _btnHeight, _trickyOffset)
{

}

MoveTopRight::MoveTopRight(int _btnWidth, int _btnHeight, int _trickyOffset):
    MoveWidget(_btnWidth, _btnHeight, _trickyOffset)
{

}

MoveBottomLeft::MoveBottomLeft(int _btnWidth, int _btnHeight, int _trickyOffset):
    MoveWidget(_btnWidth, _btnHeight, _trickyOffset)
{

}

MoveBottomRight::MoveBottomRight(int _btnWidth, int _btnHeight, int _trickyOffset):
    MoveWidget(_btnWidth, _btnHeight, _trickyOffset)
{

}

MoveNull::MoveNull(int _btnWidth, int _btnHeight, int _trickyOffset):
    MoveWidget(_btnWidth, _btnHeight, _trickyOffset)
{

}

void MoveLeft::move(int btnX, int btnY, int *res)
{
    res[0] = btnX - btnWidth - trickyOffset;
    res[1] = btnY;
}

void MoveRight::move(int btnX, int btnY, int *res)
{
    res[0] = btnX + btnWidth + trickyOffset;
    res[1] = btnY;
}

void MoveUp::move(int btnX, int btnY, int *res)
{
    res[0] = btnX;
    res[1] = btnY - btnHeight - trickyOffset;
}

void MoveDown::move(int btnX, int btnY, int *res)
{
    res[0] = btnX;
    res[1] = btnY + btnHeight + trickyOffset;
}

void MoveTopRight::move(int btnX, int btnY, int *res)
{
    res[0] = btnX + btnWidth + trickyOffset;
    res[1] = btnY - btnHeight - trickyOffset;
}

void MoveTopLeft::move(int btnX, int btnY, int *res)
{
    res[0] = btnX - btnWidth - trickyOffset;
    res[1] = btnY - btnHeight - trickyOffset;
}

void MoveBottomRight::move(int btnX, int btnY, int *res)
{
    res[0] = btnX + btnWidth + trickyOffset;
    res[1] = btnY + btnHeight + trickyOffset;
}

void MoveBottomLeft::move(int btnX, int btnY, int *res)
{
    res[0] = btnX - btnWidth - trickyOffset;
    res[1] = btnY + btnHeight + trickyOffset;
}

void MoveNull::move(int btnX, int btnY, int *res)
{
    res[0] = btnX;
    res[1] = btnY;
}

MoveWidget::MoveWidget(int _btnWidth, int _btnHeight, int _trickyOffset):
    btnWidth(_btnWidth), btnHeight(_btnHeight), trickyOffset(_trickyOffset)
{

}

MoveWidget::MoveWidget()
{

}
