#ifndef _STR_BUILDER_H__
#define _STR_BUILDER_H__

#include <random>
#include <string>
#include <vector>

typedef std::vector<std::string> v_strings;

class CStringBuilder
{
public:
	CStringBuilder() {}

	////////////////////////////////////////////////////////////////////////////////
	// generate nStrCount test strings in vector m_vStrings
	void CStringBuilder::GenerateTestData(size_t nStrCount)
	{
		m_vStrings.clear();
		m_vStrings.reserve(nStrCount);

		// generate random string length
		std::random_device rd;
		std::uniform_int_distribution<size_t> rnd_generator(1, 2000);

		std::string s;
		// generate nStrCount test strings
		for (size_t i = 0; i  < nStrCount; ++i)
		{
			size_t nStrLength = rnd_generator(rd);
			s.erase();
			s.append(nStrLength, 'a');
			m_vStrings.push_back(s);
		}
	}

	////////////////////////////////////////////////////////////////////////////////
	// returns string concatenated from m_vStrings
	std::string CStringBuilder::GetData() const
	{
		std::string s;
		for (auto str : m_vStrings) 
		{
			// printf("Adding string: " + str);
			s = s + str;
		}
		return s;
	}

private:
	v_strings m_vStrings;
};

#endif // _STR_BUILDER_H__
