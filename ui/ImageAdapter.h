#pragma once


class CImageAdapter : public SAdapterBase
{
	enum {kMaxCache=20};
public:
	CImageAdapter(void);
	~CImageAdapter(void);

	void setCategory(int nCategory);
	void OnDownloadFinish(const std::string &uri, const std::string &data, long type, long category, IBitmap * pImg);
protected:
	virtual int getCount();

	virtual void getView(int position, SWindow * pItem, pugi::xml_node xmlTemplate);

private:
	int url2index(const string &url,int category) const;
private:
	struct IMGINFO
	{
		int id;
		string uriThumb;
		string uriBig;
	};
	typedef map<string,SAutoRefPtr<IBitmap> > URL2IMGMAP;
	typedef vector<IMGINFO> IMGS;
	typedef map<int,IMGS * > DATAMAP;
	typedef map<uint64_t,string> IMGTSMAP;
	DATAMAP m_dataMap;
	URL2IMGMAP m_imgMap;
	int    m_category;
	IMGTSMAP	m_imgTsMap;
};
