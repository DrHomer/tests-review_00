#ifndef _STR_BUILDER_H__
#define _STR_BUILDER_H__

#include <random>
#include <string>
#include <vector>

using v_strings = std::vector<std::string>; //K.Eremeev: just more modern

class CStringBuilder
{
public:
	CStringBuilder() {}
    virtual ~CStringBuilder() = default; //K.Eremeev: was missed

    CStringBuilder(const CStringBuilder&) = delete; //K.Eremeev: was missed
    CStringBuilder(CStringBuilder&&) noexcept = delete; //K.Eremeev: was missed
        
    CStringBuilder& operator=(const CStringBuilder& stream) = delete; //K.Eremeev: was missed
    CStringBuilder& operator=(CStringBuilder&&) noexcept = delete; //K.Eremeev: was missed

	////////////////////////////////////////////////////////////////////////////////
	// generate nStrCount test strings in vector m_vStrings
	void GenerateTestData(size_t nStrCount) // K.Eremeev: removed extra 'CStringBuilder::' in declaretion/definition (clang warn)
	{
		// generate random string length
		std::random_device rd;
		std::uniform_int_distribution<size_t> rnd_generator(1, 2000);

		m_vStrings.clear(); //K.Eremeev: moved nearest to cycle (for potentional cash usefull)
		m_vStrings.reserve(nStrCount); //K.Eremeev: moved nearest to cycle (for potentional cash usefull)

		// std::string s; //K.Eremeev: to remove

		// generate nStrCount test strings
		for (size_t i = 0; i  < nStrCount; ++i)
		{
			const size_t nStrLength = rnd_generator(rd); //K.Eremeev: add 'const' (prevent potentional problems)
			// s.erase(); //K.Eremeev: to remove
			// s.append(nStrLength, 'a'); //K.Eremeev: to remove
			// m_vStrings.push_back(s); //K.Eremeev: to remove
            const auto& res {
                m_vStrings.emplace_back(std::string (nStrLength, 'a')) //K.Eremeev: more optimized variant
            };
 
            m_allMemSize += res.size();
		}
	}

	////////////////////////////////////////////////////////////////////////////////
	// returns string concatenated from m_vStrings
	std::string GetData() const // K.Eremeev: removed extra 'CStringBuilder::' in declaretion/definition (clang warn)
	{
		std::string s;
        s.reserve(m_allMemSize); //K.Eremeev: for prevent reallocation in below cycle 
                                 // and prevent allocation big memory by standart allocator

        for (const auto& str : m_vStrings) //K.Eremeev: add const reference to prevnt extra copy
		{
			// printf("Adding string: " + str);
			s = s + str;
		}
		return s;
	}

private:
	v_strings m_vStrings;
    size_t m_allMemSize {0}; //K.Eremeev: add for keep size of all allocated data in 'm_vStrings'
};

#endif // _STR_BUILDER_H__
