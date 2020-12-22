#include "baidutranapi.h"

BaiduTranApi::BaiduTranApi(QObject *parent) : QObject(parent)
{

}


/**
* 通用文字识别（高精度版）
* @return 调用成功返回0，发生错误返回其他错误码
*/
int BaiduTranApi::accurateBasic(QString &json_result, QString &access_token) {
    QString url=QString("%1 %2 %3").arg(request_url).arg("?access_token=").arg(access_token);

    QUrl qurl=QUrl(url);


    // create http request header
    QNetworkRequest request(url);

    // send GET request to get result
    QNetworkReply *reply = m_networkAccessManager->get(request);

    CURL *curl = NULL;
    CURLcode result_code;
    int is_success;
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.data());
        curl_easy_setopt(curl, CURLOPT_POST, 1);
        curl_httppost *post = NULL;
        curl_httppost *last = NULL;
        curl_formadd(&post, &last, CURLFORM_COPYNAME, "image", CURLFORM_COPYCONTENTS, "【base64_img】", CURLFORM_END);

        curl_easy_setopt(curl, CURLOPT_HTTPPOST, post);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
        result_code = curl_easy_perform(curl);
        if (result_code != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(result_code));
            is_success = 1;
            return is_success;
        }
        json_result = accurateBasic_result;
        curl_easy_cleanup(curl);
        is_success = 0;
    } else {
        fprintf(stderr, "curl_easy_init() failed.");
        is_success = 1;
    }
    return is_success;
}
