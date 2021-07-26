#include "widget.h"
#include <iostream>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    // 初始化MATLAB
    m_matlab = matlab::engine::startMATLAB();

    // 初始化界面和布局
    auto *showBarBtn = new QPushButton(u8"柱状图");
    connect(showBarBtn, &QPushButton::clicked, this, [=](){
        showBar(array_2_3());
    });
    auto *maxBtn = new QPushButton(u8"最大值");
    connect(maxBtn, &QPushButton::clicked, this, [=]() {
        findMax(array_2_3());
    });
    auto *mfileBtn = new QPushButton(u8"求和");
    connect(mfileBtn, &QPushButton::clicked, this, [=]() {
        callMFile();
    });

    auto layout = new QHBoxLayout(this);
    layout->addWidget(showBarBtn);
    layout->addWidget(maxBtn);
    layout->addWidget(mfileBtn);
}

/// 创建2行3列的数组
matlab::data::TypedArray<int32_t> Widget::array_2_3()
{
    matlab::data::ArrayFactory factory;
    matlab::data::TypedArray<int32_t> array = factory.createArray<int32_t>({2, 3});
    array[0][0] = 1;
    array[0][1] = 2;
    array[0][2] = 3;
    array[1][0] = 4;
    array[1][1] = 5;
    array[1][2] = 6;
    return array;
}

/// 将多维数组通过柱状图显示
void Widget::showBar(const matlab::data::TypedArray<int32_t> &array)
{
    m_matlab->setVariable(u"array", array);
    m_matlab->eval(u"bar(array)");
}

/// 从多维数组中找到最大值
void Widget::findMax(const matlab::data::TypedArray<int32_t> &array)
{
    m_matlab->setVariable(u"array", array);
    m_matlab->eval(u"maxValue = max(array, [], 'all');");
    auto tmp = m_matlab->getVariable(u"maxValue");
    int max = tmp[0];
    auto label = new QLabel;
    label->setText(u8"最大值：" + QString::number(max));
    label->show();
}

/// 执行.m文件
void Widget::callMFile()
{
    m_matlab->eval(u"sumValue = mysum(1, 2);");
    auto tmp = m_matlab->getVariable(u"sumValue");
    int sum = tmp[0];
    auto label = new QLabel;
    label->setText(u8"两数之和：" + QString::number(sum));
    label->show();
}
