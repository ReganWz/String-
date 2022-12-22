class String
{
    friend std::ostream& operator<<(ostream& os, const String& str);
    friend std::istream& operator >>(istream& is, String& str);
 
public:
    String(const char* str = NULL);
    ~String(void);
 
    String(const String& str);
    String& operator=(const String& str);
    String operator+(const String& str);
    bool operator==(const String& str);
    char& operator[](unsigned int e);
 
    int getLength();
 
private:
    char *m_data;    
};
 
String::String(const char* str)
{
    if(str == NULL)
    {
        m_data = new char[1];    //对空字符串申请存放‘0’
        *m_data = '\0';
    }
    else
    {
        m_data = new char[strlen(str) + 1];
        strcpy(m_data, str);
    }
}
 
String::~String()
{
    if(m_data)
    {
        delete[] m_data;
        m_data = NULL;
    }
}
 
String::String(const String& str)
{
    if(str.data == NULL)
    {
        m_data = NULL;
    }
    else
    {
        m_data = new char[strlen(str.m_data) + 1];
        strcpy(m_data, str.m_data);
    }
}
 
String& String::operator=(const String& str)
{
    if(this != &str)        //检查自赋值
    {
        delete[] m_data;
        m_data = NULL;
        
        if(str.m_data == NULL)
            m_data = NULL;
        else
        {
            m_data = new char[strlen(str.m_data) + 1];
            strcpy(m_data, str.m_data);
        }
    }
 
    return *this;       
}
 
String String::operator+(const String& str)
{
	String newString;
	if (str.m_data == NULL)
		return *this;
	else if(m_data == NULL)
	{
		newString = str;
	}
	else
	{
		newString.m_data = new char[strlen(str.m_data) + 1 + strlen(m_data) + 1];
		strcpy(newString.m_data, m_data);
		strcpy(newString.m_data, str.m_data);
	}
	return newString;
}
 
bool String::operator==(const String& str)
{
	if (strlen(m_data) != strlen(str.m_data))
		return false;
	else
	{
		return strcmp(m_data, str.m_data) ? false : true;
	}
}
 
char& String::operator[](unsigned int e)
{
    if(e >=0 && e <= strlen(m_data))
        return m_data[e];
}
 
int String::getLength()
{
	return strlen(m_data);
}
 
ostream& operator<<(ostream& os, const String& str)
{
	os << str.m_data;
	return os;
}
 
istream& operator>>(istream& is, String& str)
{
    char buffer[4096];
    is >> buffer;
	str.m_data = buffer;
	return is;
}
