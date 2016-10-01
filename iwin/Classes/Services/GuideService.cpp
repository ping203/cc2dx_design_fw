#include "GuideService.h"


using namespace cocos2d::network;

GuideService* GuideService::s_instance = nullptr;


GuideService* GuideService::getInstance()
{
	if (s_instance == nullptr) {
		s_instance = new GuideService();
	}
	return s_instance;
}

GuideService::GuideService()
{
	_isLoadDataFromServerOK = false;
}

void GuideService::requestAllHelp()
{
	/*final HttpRequest httpRequest = new HttpRequest(HttpMethods.GET);
	httpRequest.setUrl(URL_REQUEST_ALL_HELP);
	HttpRequestManager.getInstance().post(URL_REQUEST_ALL_HELP,
		httpRequest, this);*/

	HttpRequest* request = new (std::nothrow) HttpRequest();
	request->setUrl(URL_REQUEST_ALL_HELP);
	request->setRequestType(HttpRequest::Type::GET);
	request->setResponseCallback(CC_CALLBACK_2(GuideService::onHttpRequestCompleted, this));
	request->setTag(URL_REQUEST_ALL_HELP);
	HttpClient::getInstance()->send(request);
	request->release();
}

void GuideService::onHttpRequestCompleted(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response)
{
	if (strcmp(response->getHttpRequest()->getTag(), URL_REQUEST_ALL_HELP) == 0)
	{
		std::string jsonString;
		std::vector<char>* data_response = response->getResponseData();
		for (int i = 0; i < data_response->size(); i++)
		{
			jsonString += data_response->at(i);
		}
		//std::string jsonString = response->getResponseDataString();
		if (jsonString.size() > 0)
		{
			_isLoadDataFromServerOK = true;
			_guides.toData(jsonString);
		}
		//if (!Utility.isNullOrEmpty(jsonString)) {
		//	isLoadDataFromServerOK = true;
		//	setGuides(jsonString);
		//}
	}
}