#include "BetMatch.h"
#include "json/writer.h"
namespace iwinmesage
{
	
	BetMatch:: BetMatch ()
	{

	}

	BetMatch::~BetMatch()
	{

	}

	rapidjson::Document BetMatch::toJson()
	{

		rapidjson::Document document;
		document.SetObject();
		rapidjson::Document::AllocatorType& locator = document.GetAllocator();
				document.AddMember("matchID", matchID,locator);
		document.AddMember("teamID", teamID,locator);
		document.AddMember("tickets", tickets,locator);
		document.AddMember("isSucceed", isSucceed,locator);
rapidjson::Value vmessage(message.c_str(), message.size());
		document.AddMember("message", vmessage,locator);

		rapidjson::StringBuffer buffer;
		buffer.Clear();
		rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
		document.Accept(writer);
		return document;
	}
	void BetMatch::toData(std::string json)
	{
		rapidjson::Document document;
		document.Parse(json.c_str());
		toData(document);
	}
	void BetMatch::toData(rapidjson::Document & document)
	{
				if(document.HasMember("matchID"))
		{
			setMatchID(document["matchID"].GetInt());
		}
		if(document.HasMember("teamID"))
		{
			setTeamID(document["teamID"].GetInt());
		}
		if(document.HasMember("tickets"))
		{
			setTickets(document["tickets"].GetInt());
		}
		if(document.HasMember("isSucceed"))
		{
			setIsSucceed(document["isSucceed"].GetBool());
		}
		if(document.HasMember("message"))
		{
			setMessage(document["message"].GetString());
		}


	}
}
