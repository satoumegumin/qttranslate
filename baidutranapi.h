#ifndef BAIDUTRANAPI_H
#define BAIDUTRANAPI_H

#include <QObject>
#include <iostream>
#include <QtNetwork>


class BaiduTranApi : public QObject
{
    Q_OBJECT

private:
    QString request_url = "https://aip.baidubce.com/rest/2.0/ocr/v1/accurate_basic";
public:
    explicit BaiduTranApi(QObject *parent = nullptr);

    QString accurateBasic_result;
    /**
    * curl发送http请求调用的回调函数，回调函数中对返回的json格式的body进行了解析，解析结果储存在全局的静态变量当中
    * @param 参数定义见libcurl文档
    * @return 返回值定义见libcurl文档
    */
    static size_t callback(void *ptr, size_t size, size_t nmemb, void *stream) {
        // 获取到的body存放在ptr中，先将其转换为string格式
        accurateBasic_result = std::string((char *) ptr, size * nmemb);
        return size * nmemb;
    }
    /**
    * 通用文字识别（高精度版）
    * @return 调用成功返回0，发生错误返回其他错误码
    */
    int accurateBasic(QString &json_result, QString &access_token) ;

signals:

};

#endif // BAIDUTRANAPI_H
