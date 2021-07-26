#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <MatlabEngine.hpp>
#include <MatlabDataArray.hpp>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);

private:
      matlab::data::TypedArray<int32_t> array_2_3();
      void showBar(const matlab::data::TypedArray<int32_t> &array);
      void findMax(const matlab::data::TypedArray<int32_t> &array);
      void callMFile();

private:
    std::unique_ptr<matlab::engine::MATLABEngine> m_matlab;
};

#endif // WIDGET_H
