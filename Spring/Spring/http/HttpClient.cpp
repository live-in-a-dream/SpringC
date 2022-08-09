#include "HttpClient.h"

HttpClient::HttpClient()
{

}

HttpClient::~HttpClient()
{
	//�߳����Ƴ�httpinfo
	std::map<std::thread::id, HttpInfo*>::iterator it = RequstProxy::getHttpInfoList()->find(clientRunThread->get_id());
	if (it != RequstProxy::getHttpInfoList()->end()) {
		RequstProxy::getHttpInfoList()->erase(it);
	}
}

void HttpClient::readData(std::string* data, std::string* error)
{
	/*
		�������
	*/
	HttpInfo httpInfo;
	httpInfo.httpRequest = HttpRequest(data);
	if ("" != httpInfo.httpRequest.error) {
		error = &httpInfo.httpRequest.error;
		//�쳣����
		return;
	}

	HttpInfo httpInfoNew = httpInfo;

	//�����߳�ID����httpinfo
	RequstProxy::addHttpInfo(clientRunThread->get_id(), &httpInfo);

	//�Ƿ����
	bool exist = false;
	for (auto it = RequstProxy::getRequstList()->begin(); it != RequstProxy::getRequstList()->end(); it++)
	{
		if (it->first == httpInfo.httpRequest.url) {
			/*
			if (!this) {
				continue;
			}*/
			exist = true;

			//ҵ���߼�����ǰ����
			for (int i =0;i< RequstProxy::getBusinessBeforeIntercept()->size();i++)
			{
				bool isBusinessBefore = RequstProxy::getBusinessBeforeIntercept()->at(i)(&httpInfoNew);
				//���سɹ�ֱ�ӷ���
				if (isBusinessBefore) {
					httpInfo = httpInfoNew;
					sendSocket(httpInfo.httpResponse.toString().c_str());
					return;
				}
			}

			//�ص�
			it->second();

			//ҵ���߼����к�-����ǰ-����
			for (int i = 0; i < RequstProxy::getSendBeforeIntercept()->size(); i++)
			{
				bool isSendBefore = RequstProxy::getSendBeforeIntercept()->at(i)(&httpInfoNew);
				//���سɹ�ֱ�ӷ���
				if (isSendBefore) {
					httpInfo = httpInfoNew;
					sendSocket(httpInfo.httpResponse.toString().c_str());
					return;
				}
			}
			//����
			sendSocket(httpInfo.httpResponse.toString().c_str());
		}
	}
	//�Ҳ�����ҳ
	if (!exist) {
		sendSocket(HttpResponse::to404().c_str());
	}
}
