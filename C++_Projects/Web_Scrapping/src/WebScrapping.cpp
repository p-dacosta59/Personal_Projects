#include "WebScrapping.h"

////////////////////////////////////////////////////////////////////////////////
// PUBLIC METHODS

// Constructors
WebScrapping::WebScrapping() {
	curl_global_init(CURL_GLOBAL_ALL);
	this->curl = curl_easy_init();
	this->positionFile = 0;
}

// Destructors
WebScrapping::~WebScrapping() {
	curl_easy_cleanup(this->curl);
	curl_global_cleanup();
}

// Go to a web site return the HTML of site
string WebScrapping::accessSite(string nameSite, bool postData, string searchData){
	string data;
	if(this->curl){
		curl_easy_setopt(this->curl, CURLOPT_URL, nameSite.c_str());
		curl_easy_setopt(this->curl, CURLOPT_COOKIEJAR, "cookie.txt");
		curl_easy_setopt(this->curl, CURLOPT_COOKIEFILE, "cookie.txt");
		curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, &data);
		curl_easy_setopt(this->curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_6_8) AppleWebKit/534.30 (KHTML, like Gecko) Chrome/12.0.742.112 Safari/534.30");
		curl_easy_perform(this->curl);
		
		if(postData){
			curl_easy_setopt(this->curl, CURLOPT_POSTFIELDS, searchData.c_str());
			curl_easy_perform(this->curl);
		}
		if(data !="") 
			return data;
	}
	return "error";
}

// Access a web site anonymously using proxy rebound
string WebScrapping::accessSiteAnonyme(string nameSite, int profondeur, bool secur, string searchData, int latence){
	string data;
	if(this->curl){
        ifstream fichier("./listProxies.csv");
		string ligne("");
		vector<string> result(4);
		fichier.seekg(this->positionFile);
		curl_easy_setopt(this->curl, CURLOPT_URL, nameSite.c_str());
        string allProxies("");
		for (int i(0); i < profondeur; i++){
            string lastCountry("");
            bool securityProxie(false);
            do{
                lastCountry = result[2];
                for(int i(0); i < 4; i++){
                    getline(fichier, ligne, ',');
                    result[i] = ligne;
                }
                fichier.get();
                if(result[1] != "High") 
					securityProxie = 1;
            }while(i%2 != securityProxie && lastCountry != result[2] && secur);
            curl_easy_setopt(this->curl, CURLOPT_PROXY, result[0].c_str());
		}
        curl_easy_setopt(this->curl, CURLOPT_HTTPPROXYTUNNEL, profondeur);
		curl_easy_setopt(this->curl, CURLOPT_COOKIEJAR, "cookie.txt");
		curl_easy_setopt(this->curl, CURLOPT_COOKIEFILE, "cookie.txt");
		curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, &data);
		curl_easy_setopt(this->curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_6_8) AppleWebKit/534.30 (KHTML, like Gecko) Chrome/12.0.742.112 Safari/534.30");
		for(int x(0); x<2; x++){
            curl_easy_perform(this->curl);
            if(searchData != ""){
				curl_easy_setopt(this->curl, CURLOPT_POSTFIELDS, searchData.c_str());
                curl_easy_perform(this->curl);
			}
			if(data != "") 
				break;
		}
		result.clear();
		this->positionFile = fichier.tellg();
		fichier.close();
	}
	return data;
}

// Access in a web site using a proxie
string WebScrapping::simplyAccessSiteAnonyme(string nameSite, bool postData, string searchData){
	string data;
	if(this->curl){
		ifstream fichier("./listProxies.csv");
		string ligne("");
		vector<string> result(4);
		fichier.seekg(this->positionFile);
		curl_easy_setopt(this->curl, CURLOPT_URL, nameSite.c_str());
		for(int i(0); i < 4; i++){
			getline(fichier, ligne, ',');
			result[i] = ligne;
		}
		fichier.get();
		curl_easy_setopt(this->curl, CURLOPT_PROXY, result[0].c_str());
		curl_easy_setopt(this->curl, CURLOPT_COOKIEJAR, "cookie.txt");
		curl_easy_setopt(this->curl, CURLOPT_COOKIEFILE, "cookie.txt");
		curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, write_data);
		curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, &data);
		curl_easy_setopt(this->curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_6_8) AppleWebKit/534.30 (KHTML, like Gecko) Chrome/12.0.742.112 Safari/534.30");
		for(int x(0); x<2; x++){
			curl_easy_setopt(this->curl, CURLOPT_VERBOSE, 1L);
			curl_easy_perform(this->curl);
			if(postData){
				curl_easy_setopt(this->curl, CURLOPT_POSTFIELDS, searchData.c_str());
				curl_easy_perform(this->curl);
			}
			if(data != "") 
				break;
		}
		result.clear();
		this->positionFile = fichier.tellg();
		fichier.close();
	}
	return data;
}

// Go in a website to get a proxie to use
bool WebScrapping::takeProxies(int i){
	string siteName("");
	string data("");
    ofstream monFlux("./listProxies.csv");
	for(int x = 1; x < i; x+=64){
        siteName = "https://hidemy.name/en/proxy-list/?start=" + Utils::toString(x) + "#list";
		data = this->accessSite(siteName);
		data.erase(data.find("</table>"), data.length());
		data.erase(0, data.find("<table>"));
		data.erase(0, data.find("</tr>")+5);
		while(data.find("<tr>") != string::npos){
			data.erase(0, data.find("<tr>")+4);
			string proxies = "";
			proxies = data.substr(data.find("<td>"), data.find("</tr>"));
			data.erase(0, data.find("</tr>")+5);
			proxies = cutOutString(proxies);
			monFlux << proxies << endl;
		}
	}
	return true;
}

// Cut a string to get a target name
string WebScrapping::cutOutString(string &data){
	vector <string> myData;
	string dataToReturn("");
	if(data.find("High") != string::npos) myData.push_back("High");
	else myData.push_back("no");
	if(data.find("SOCKS5") != string::npos) dataToReturn = "socks5://";
	else if(data.find("SOCKS4") != string::npos)dataToReturn = "socks4://";
	else if(data.find("HTTPS") != string::npos)dataToReturn = "https://";
	else dataToReturn  = "http://";
	while(data.find(">") != string::npos){
		if((data.find("<") - data.find(">")) > 4){
			int p(0);
			while(data.find(">", p) != string::npos && data.find(">", p) < data.find("<"))
				p = data.find(">", p) + 1;
			if((p-data.find("<", p) )!= 0){
				if(data.substr(p, data.find("<")) != " "){
					myData.push_back(data.substr(p, data.find("<")));
				}
			}
		}
		data = data.substr(data.find("<")+1);
		data = data.substr(data.find(">")+1);
	}
	dataToReturn += myData[1] + ":" + myData[2] + "," + myData[0] + "," + myData[3] + ",";
	if (myData[4].find(" ms") != string::npos) 
		dataToReturn += myData[4] + ",";
	else 
		dataToReturn += myData[5] + ",";

	return dataToReturn;
}

// Get a URL in a web page
string WebScrapping::getUrl(string &data, string searchData){
    string hostname;
	int found2(0);
	int found(data.find(searchData));
	int size(searchData.length());
	for(int i(0); i < size; i++) if(searchData[i] == ' ') 
		found2 = i+1;
	searchData = "";
	for(int i(found2); i < size; i++) 
		searchData += searchData[i];
	size -= found2;
	found += found2;
	found = data.find(searchData, found);
	for(int i(0); i < size; i++) 
		if(searchData[i] == '=') 
			found2 = i+1;
	searchData = "";
	for(int i(found2); i < size; i++) 
		searchData += searchData[i];
	found = data.find(searchData, found);
	if (found != string::npos){
        for (int i(found+1); i < data.length(); i++){
			if(data[i] == '\"') 
				break;
			hostname += data[i];
		}
	}
	return hostname;	

}

// Dowloaad a file by a website
void WebScrapping::dowloadFiles(string nameSite, string nameFile){
	ofstream monFlux;
    monFlux.open(nameFile.c_str());
	string emploiDuTemps("");
	curl_easy_setopt(this->curl, CURLOPT_URL, nameSite.c_str());
	curl_easy_setopt(this->curl, CURLOPT_COOKIEJAR, "cookie.txt");
	curl_easy_setopt(this->curl, CURLOPT_COOKIEFILE, "cookie.txt");
	curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, write_data);
	curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, &emploiDuTemps);
	curl_easy_setopt(this->curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_6_8) AppleWebKit/534.30 (KHTML, like Gecko) Chrome/12.0.742.112 Safari/534.30");
	curl_easy_perform(this->curl);
	monFlux << emploiDuTemps;
	monFlux.close();
}

// Take my agenda in a website
void WebScrapping::takeAgendas(){
    string data("");
    data = this->accessSite("https://moodle.iut-kourou.fr/login/index.php", true, "<input type=\"hidden\" name=\"logintoken\" value=\"");
	data = this->accessSite("https://moodle.iut-kourou.fr/course/view.php?id=142");
	data = this->accessSite(this->getUrl(data, "id=\"module-6709\"><div><div class=\"mod-indent-outer w-100\"><div class=\"mod-indent\"></div><div><div class=\"activityinstance\"><a class=\"aalink\" onclick=\"\" href=\""));
	this->dowloadFiles(this->getUrl(data, " href=\""), "/Users/bg/Desktop/emploiDuTemps.pdf");
}

////////////////////////////////////////////////////////////////////////////////
// INDEPENDENT METHODS
size_t write_data (void* buffer, size_t size, size_t nmemb, void * userp){
	((std::string*)userp)->append((char*)buffer, size * nmemb);
    return size * nmemb;
}
